"""Fresh-source FPGA runs: stage -> Qsys generation -> optional Quartus compile.

Each invocation creates a unique ignored run. Never reuses generated HDL or deletes
source/history. Set QUARTUS_ROOTDIR or pass --quartus-root for vendor tools.
"""
import argparse
from datetime import datetime, timezone
import hashlib
import importlib.util
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

# Resolve the sibling by its file so direct CLI use and filepath-loaded tests
# share the same recorder without depending on the caller's import search path.
_JOURNAL_SPEC = importlib.util.spec_from_file_location(
    "_fpga_bug_journal", Path(__file__).with_name("bug_journal.py"))
_JOURNAL = importlib.util.module_from_spec(_JOURNAL_SPEC)
_JOURNAL_SPEC.loader.exec_module(_JOURNAL)
record_failure = _JOURNAL.record_failure


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


def stage_inputs(config, stage, record=None):
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
    if record is not None:
        # Only this invocation's directory may receive run metadata. A rejected
        # existing directory must retain its original evidence unchanged.
        record["stage_created"] = True
        record["inputs"] = records
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


class ToolFailure(RuntimeError):
    def __init__(self, returncode, logfile):
        super().__init__(f"Tool exited {returncode}; inspect {logfile}")
        self.returncode = returncode


def execute(command, stage, logfile, record=None):
    print("+ " + " ".join(command), flush=True)
    tool_run = {"argv": command, "started_at_utc": datetime.now(timezone.utc).isoformat(),
                "log": str(logfile), "status": "running", "returncode": None}
    if record is not None:
        record.setdefault("commands", []).append(tool_run)
    # Save complete tool output; paths and logs remain in ignored run workspace.
    try:
        with logfile.open("w", encoding="utf-8") as output:
            result = subprocess.run(command, cwd=stage, stdout=output, stderr=subprocess.STDOUT, text=True, timeout=1800)
        tool_run["returncode"] = result.returncode
        tool_run["status"] = "failed" if result.returncode else "completed"
        if result.returncode:
            raise ToolFailure(result.returncode, logfile)
    except subprocess.TimeoutExpired as error:
        tool_run.update(status="timed_out", timeout_seconds=error.timeout, error=str(error))
        raise
    except KeyboardInterrupt:
        tool_run["status"] = "interrupted"
        raise
    except Exception as error:
        tool_run.update(status="failed", error=str(error))
        raise
    finally:
        tool_run["finished_at_utc"] = datetime.now(timezone.utc).isoformat()


def write_metadata(record, stage, runroot):
    payload = json.dumps(record, indent=2) + "\n"
    (stage / "run.json").write_text(payload, encoding="utf-8")
    (runroot / "latest.json").write_text(payload, encoding="utf-8")


def capture_failure(record, stage):
    """Best effort only: journal failures cannot change the build's outcome."""
    try:
        logs = sorted((stage / "logs").glob("*.log")) if record.get("stage_created") else []
        commands = record.get("commands", [])
        incident = record_failure(
            ROOT, "hardware", message=record["error"],
            exit_code=record["failure_exit_code"], phase=record["phase"],
            run_directory=stage, record=record, logs=logs,
            command=commands[-1]["argv"] if commands else record["invocation"])
        print(f"Bug journal: {incident}")
    except (Exception, KeyboardInterrupt) as error:
        print(f"Warning: could not save hardware bug journal: {error}", file=sys.stderr)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("action", choices=("stage", "generate", "compile"))
    parser.add_argument("--config", type=Path, default=ROOT / "hardware/de1_soc/build.json")
    parser.add_argument("--quartus-root", type=Path, default=os.environ.get("QUARTUS_ROOTDIR"))
    args = parser.parse_args()
    stage = runroot = None
    record = {"action": args.action, "status": "running", "phase": "configuration",
              "created_at_utc": datetime.now(timezone.utc).isoformat(),
              "config_path": str(args.config), "invocation": list(sys.argv),
              "cli_exit_code": 1, "stage_created": False,
              "scope": "Generation/compile only; no simulation, CDC, timing review or board sign-off"}
    try:
        record["config_sha256"] = checksum(args.config)
        config = load_config(args.config)
        record.update(design=config["name"], configuration=config)
        record["phase"] = "tool_discovery"
        if args.quartus_root is not None:
            args.quartus_root = Path(args.quartus_root)
        record["quartus_root"] = str(args.quartus_root) if args.quartus_root is not None else None
        tools = record["tools"] = {}
        if args.action != "stage":
            tools["qsys"] = find_tool(args.quartus_root, "sopc_builder/bin/qsys-generate", "qsys-generate")
        if args.action == "compile":
            tools["quartus"] = find_tool(args.quartus_root, "bin64/quartus_sh", "quartus_sh")
        stamp = datetime.now(timezone.utc).strftime("%Y%m%dT%H%M%S") + "-" + uuid.uuid4().hex[:8]
        runroot = ROOT / "build/quartus" / config["name"]
        stage = runroot / "runs" / stamp
        record["run_directory"] = stage.relative_to(ROOT).as_posix()
        record["phase"] = "staging"
        record["inputs"] = stage_inputs(config, stage, record)
        record["phase"] = "metadata"
        write_metadata(record, stage, runroot)
        logs = stage / "logs"
        logs.mkdir()
        if args.action != "stage":
            for system in config["generation_order"]:
                record["phase"] = f"generate:{system}"
                command = [tools["qsys"], f"{system}.qsys", "--synthesis=VERILOG",
                           f"--output-directory={system}", "--search-path=.,$",
                           f"--family={config['family']}", f"--part={config['device']}"]
                execute(command, stage, logs / f"{system}-generate.log", record)
                qip = stage / system / "synthesis" / f"{system}.qip"
                if not qip.is_file():
                    raise RuntimeError(f"Expected generated QIP missing: {qip}")
                record.setdefault("generated_systems", []).append(system)
                write_metadata(record, stage, runroot)
        if args.action == "compile":
            record["phase"] = "compile"
            execute([tools["quartus"], "--flow", "compile", config["project"]], stage, logs / "quartus-compile.log", record)
        record["status"] = "completed"
        record["cli_exit_code"] = 0
    except KeyboardInterrupt:
        record["status"] = "interrupted"
        record["error"] = "Interrupted; generated files are incomplete, see run logs if available."
        record["failure_exit_code"] = 130
        print(record["error"], file=sys.stderr)
    except Exception as error:
        record["status"] = "failed"
        record["error"] = str(error)
        record["failure_exit_code"] = error.returncode if isinstance(error, ToolFailure) else 1
        print(str(error), file=sys.stderr)
    finally:
        record["finished_at_utc"] = datetime.now(timezone.utc).isoformat()
        if record["stage_created"]:
            try:
                write_metadata(record, stage, runroot)
            except (Exception, KeyboardInterrupt) as error:
                # Preserve the primary tool/configuration error even when disk
                # failure also prevents updating run.json or latest.json.
                record.setdefault("metadata_errors", []).append(str(error))
                print(f"Warning: could not finalize run metadata: {error}", file=sys.stderr)
                if record["status"] == "completed":
                    interrupted = isinstance(error, KeyboardInterrupt)
                    record.update(status="interrupted" if interrupted else "failed",
                                  phase="finalization", error=str(error) or "Interrupted while finalizing run metadata",
                                  failure_exit_code=130 if interrupted else 1, cli_exit_code=1)
        if record["status"] != "completed":
            capture_failure(record, stage)
    if record["stage_created"]:
        print(f"Run: {stage}")
    print(f"Status: {record['status']}")
    if record["status"] != "completed":
        raise SystemExit(1)


if __name__ == "__main__":
    main()
