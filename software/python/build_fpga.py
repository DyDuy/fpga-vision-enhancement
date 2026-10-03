"""Fresh-source FPGA runs: stage -> Qsys generation -> optional Quartus compile.

Each invocation creates a unique ignored run. Never reuses generated HDL or deletes
source/history. Set QUARTUS_ROOTDIR or pass --quartus-root for vendor tools.
"""
import argparse
from datetime import datetime, timezone
import hashlib
import json
import os
from pathlib import Path
import re
import shutil
import subprocess
import sys
import uuid
import xml.etree.ElementTree as ET

ROOT = Path(__file__).resolve().parents[2]


def checksum(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def within_root(relative):
    path = (ROOT / relative).resolve()
    if not path.is_relative_to(ROOT.resolve()):
        raise ValueError(f"Path escapes repository: {relative}")
    return path


def load_config(path):
    config = json.loads(path.read_text(encoding="utf-8"))
    if not re.fullmatch(r"[A-Za-z0-9_-]+", config["name"]):
        raise ValueError("Invalid design name")
    within_root(config["source_root"])
    return config


def stage_inputs(config, stage):
    source = within_root(config["source_root"])
    candidates = []
    for directory in config["stage_directories"]:
        folder = (source / directory).resolve()
        if not folder.is_relative_to(source):
            raise ValueError("Input directory escapes design")
        candidates.extend(path for path in folder.iterdir() if path.is_file())
    if config.get("ip_directory"):
        candidates.extend(path for path in (source / config["ip_directory"]).iterdir() if path.is_file())
    candidates = [path for path in candidates if path.suffix.lower() in {".v", ".sv", ".qsys", ".qpf", ".qsf", ".sdc", ".tcl", ".hex", ".mif"}]
    names = [path.name for path in candidates]
    if len(names) != len(set(names)):
        raise ValueError("Flat stage filename collision; use unique input names")
    missing = set(config["required_inputs"]) - set(names)
    if missing:
        raise ValueError(f"Missing inputs: {sorted(missing)}")
    stage.mkdir(parents=True, exist_ok=False)
    records = []
    for path in sorted(candidates):
        target = stage / path.name
        shutil.copy2(path, target)
        transformations = []
        if path.name.endswith("_hw.tcl"):
            text = target.read_text(encoding="utf-8")
            text, count = re.subn(r"PATH \S*dehazing_system_top\.v TOP_LEVEL_FILE", "PATH dehazing_system_top.v TOP_LEVEL_FILE", text)
            if count != 1:
                raise ValueError("Custom core path not found exactly once")
            target.write_text(text, encoding="utf-8")
            transformations.append("Rebase core fileset path to flat run layout")
        if target.suffix == ".qsf":
            text = target.read_text(encoding="utf-8")
            rebased = text.replace("source ../pin/", "source ").replace("-name SDC_FILE ../pin/", "-name SDC_FILE ").replace("-name QIP_FILE ../qsys/", "-name QIP_FILE ")
            if rebased != text:
                target.write_text(rebased, encoding="utf-8")
                transformations.append("Rebase pin/SDC/QIP paths to flat run layout")
        if target.suffix == ".qsys":
            ET.parse(target)
        records.append({"source": path.relative_to(ROOT).as_posix(), "staged": path.name,
                        "source_sha256": checksum(path), "staged_sha256": checksum(target),
                        "transformations": transformations})
    return records


def find_tool(root, relative, name):
    if root:
        for suffix in (".exe", ""):
            path = root / (relative + suffix)
            if path.is_file():
                return str(path.resolve())
    executable = shutil.which(name)
    if executable:
        return executable
    raise ValueError(f"Cannot find {name}; set QUARTUS_ROOTDIR to the quartus directory or pass --quartus-root")


def execute(command, stage, logfile):
    print("+ " + " ".join(command), flush=True)
    # Save complete tool output; paths and logs remain in ignored run workspace.
    with logfile.open("w", encoding="utf-8") as output:
        result = subprocess.run(command, cwd=stage, stdout=output, stderr=subprocess.STDOUT, text=True, timeout=1800)
    if result.returncode:
        raise RuntimeError(f"Tool exited {result.returncode}; inspect {logfile}")


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("action", choices=("stage", "generate", "compile"))
    parser.add_argument("--config", type=Path, default=ROOT / "hardware/de1_soc/build.json")
    parser.add_argument("--quartus-root", type=Path, default=os.environ.get("QUARTUS_ROOTDIR"))
    args = parser.parse_args()
    config = load_config(args.config)
    if args.quartus_root is not None:
        args.quartus_root = Path(args.quartus_root)
    tools = {}
    if args.action != "stage":
        tools["qsys"] = find_tool(args.quartus_root, "sopc_builder/bin/qsys-generate", "qsys-generate")
    if args.action == "compile":
        tools["quartus"] = find_tool(args.quartus_root, "bin64/quartus_sh", "quartus_sh")
    stamp = datetime.now(timezone.utc).strftime("%Y%m%dT%H%M%S") + "-" + uuid.uuid4().hex[:8]
    runroot = ROOT / "build/quartus" / config["name"]
    stage = runroot / "runs" / stamp
    record = {"design": config["name"], "action": args.action, "status": "running",
              "created_at_utc": datetime.now(timezone.utc).isoformat(),
              "run_directory": stage.relative_to(ROOT).as_posix(),
              "configuration": config, "tools": tools,
              "scope": "Generation/compile only; no simulation, CDC, timing review or board sign-off"}
    try:
        record["inputs"] = stage_inputs(config, stage)
        record["config_sha256"] = checksum(args.config)
        (stage / "run.json").write_text(json.dumps(record, indent=2) + "\n", encoding="utf-8")
        (runroot / "latest.json").write_text(json.dumps(record, indent=2) + "\n", encoding="utf-8")
        logs = stage / "logs"
        logs.mkdir()
        if args.action != "stage":
            for system in config["generation_order"]:
                command = [tools["qsys"], f"{system}.qsys", "--synthesis=VERILOG",
                           f"--output-directory={system}", "--search-path=.,$",
                           f"--family={config['family']}", f"--part={config['device']}"]
                execute(command, stage, logs / f"{system}-generate.log")
                qip = stage / system / "synthesis" / f"{system}.qip"
                if not qip.is_file():
                    raise RuntimeError(f"Expected generated QIP missing: {qip}")
                record.setdefault("generated_systems", []).append(system)
                (stage / "run.json").write_text(json.dumps(record, indent=2) + "\n", encoding="utf-8")
                (runroot / "latest.json").write_text(json.dumps(record, indent=2) + "\n", encoding="utf-8")
        if args.action == "compile":
            execute([tools["quartus"], "--flow", "compile", config["project"]], stage, logs / "quartus-compile.log")
        record["status"] = "completed"
    except KeyboardInterrupt:
        record["status"] = "interrupted"
        print("Interrupted; generated files are incomplete, see run logs.", file=sys.stderr)
    except Exception as error:
        record["status"] = "failed"
        record["error"] = str(error)
        print(str(error), file=sys.stderr)
    finally:
        if stage.exists():
            (stage / "run.json").write_text(json.dumps(record, indent=2) + "\n", encoding="utf-8")
            (runroot / "latest.json").write_text(json.dumps(record, indent=2) + "\n", encoding="utf-8")
    print(f"Run: {stage}")
    print(f"Status: {record['status']}")
    if record["status"] != "completed":
        raise SystemExit(1)


if __name__ == "__main__":
    main()
