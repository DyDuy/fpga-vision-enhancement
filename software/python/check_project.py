"""Check the single active design and tooling, not archived-source immutability."""
import argparse
import json
from pathlib import Path
import re
import shutil
import subprocess
import sys
import xml.etree.ElementTree as ET

ROOT = Path(__file__).resolve().parents[2]


def check_active_design():
    config = json.loads((ROOT / "hardware/de1_soc/build.json").read_text(encoding="utf-8"))
    source = ROOT / config["source_root"]
    inputs = {}
    for directory in config["stage_directories"]:
        for path in (source / directory).iterdir():
            if path.is_file() and path.suffix.lower() in {".v", ".sv", ".qsys", ".qpf", ".qsf", ".sdc", ".tcl", ".hex", ".mif"}:
                if path.name in inputs:
                    raise ValueError(f"Duplicate active input filename: {path.name}")
                inputs[path.name] = path
    for name in config["required_inputs"]:
        if name not in inputs:
            raise ValueError(f"Missing active input: {name}")
    for name in config["generation_order"]:
        ET.parse(inputs[f"{name}.qsys"])
    descriptor = inputs["dehazing_system_top_hw.tcl"]
    match = re.search(r"PATH (\S+) TOP_LEVEL_FILE", descriptor.read_text(encoding="utf-8"))
    if not match or not (descriptor.parent / match.group(1)).is_file():
        raise ValueError("Active IP fileset path cannot be resolved")
    for name, size, bits in (("gamma_lut_data.hex", 256, 8), ("transmission_lut_data.hex", 65536, 10)):
        values = [int(token, 16) for token in inputs[name].read_text().split()]
        if len(values) != size or any(value < 0 or value >= 2**bits for value in values):
            raise ValueError(f"Invalid ROM dimensions/range: {name}")
    print("PASS: active inputs, Qsys XML, IP source path and ROM dimensions (not formula correctness)")


def run(command):
    print("+ " + " ".join(command), flush=True)
    subprocess.run(command, cwd=ROOT, check=True)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--hps-syntax", action="store_true", help="Linux GCC source syntax only")
    args = parser.parse_args()
    check_active_design()
    run([sys.executable, "-m", "unittest", "discover", "-s", "software/python/tests", "-p", "test_*.py"])
    run([sys.executable, "-m", "compileall", "-q", "software/python"])
    if args.hps_syntax:
        gcc = shutil.which("gcc")
        if gcc is None:
            parser.error("Linux-target GCC required for --hps-syntax")
        for source in ("vga_simple_display.c",):
            run([gcc, "-std=gnu11", "-Wall", "-Wextra", "-fsyntax-only", "-Isoftware/hps/include", f"software/hps/src/{source}"])
    print("PASS: selected active-project/tool checks. No HDL simulation, Quartus or board sign-off implied.")


if __name__ == "__main__":
    main()
