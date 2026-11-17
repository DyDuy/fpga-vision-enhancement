"""Validate the vision verification contract without modifying source inputs."""
from __future__ import annotations
import argparse
import hashlib
import json
import re
from datetime import datetime, timezone
from pathlib import Path
import sys

REQUIRED = {
    "project": "hardware/de1_soc/DE1_SoC_Computer.qpf",
    "qsf": "hardware/de1_soc/DE1_SoC_Computer.qsf",
    "rtl": "hardware/de1_soc/dehazing_system_top.v",
    "qip": "hardware/qsys/Computer_System/synthesis/Computer_System.qip",
    "generated_top": "hardware/qsys/Computer_System/synthesis/Computer_System.v",
    "fixture": "hardware/verification/intake-20261004/candidate_snapshot/fixtures/input_image.hex",
    "transmission_lut": "hardware/de1_soc/transmission_lut_data.hex",
    "gamma_lut": "hardware/de1_soc/gamma_lut_data.hex",
    "filelist": "hardware/verification/rtl/filelists/dehazing_candidate.f",
}

def sha256(path: Path) -> str:
    h = hashlib.sha256()
    with path.open("rb") as stream:
        for chunk in iter(lambda: stream.read(1024 * 1024), b""):
            h.update(chunk)
    return h.hexdigest()

def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--repo-root", type=Path, default=Path(__file__).resolve().parents[3])
    ap.add_argument("--manifest-out", type=Path)
    args = ap.parse_args()
    root = args.repo_root.resolve()
    errors: list[str] = []
    files: dict[str, dict[str, object]] = {}
    for key, rel in REQUIRED.items():
        path = root / rel
        item: dict[str, object] = {"path": rel, "exists": path.is_file()}
        if path.is_file():
            item.update(size_bytes=path.stat().st_size, sha256=sha256(path))
        else:
            errors.append(f"missing {key}: {rel}")
        files[key] = item
    rtl = root / REQUIRED["rtl"]
    if rtl.is_file():
        text = rtl.read_text(encoding="utf-8", errors="replace")
        checks = {
            "top_module": bool(re.search(r"\bmodule\s+dehazing_system_top\b", text)),
            "sink_data_30": bool(re.search(r"input\s+wire\s+\[29:0\]\s+snk_data", text)),
            "source_data_30": bool(re.search(r"output\s+wire\s+\[29:0\]\s+src_data", text)),
            "sink_controls": all(re.search(rf"\b{n}\b", text) for n in ("snk_valid", "snk_ready", "snk_sop", "snk_eop")),
            "source_controls": all(re.search(rf"\b{n}\b", text) for n in ("src_valid", "src_ready", "src_sop", "src_eop")),
        }
        files["rtl"]["interface_checks"] = checks
        errors.extend(f"RTL interface check failed: {name}" for name, ok in checks.items() if not ok)
    fixture = root / REQUIRED["fixture"]
    if fixture.is_file():
        with fixture.open("r", encoding="utf-8", errors="strict") as stream:
            line_count = sum(1 for line in stream if line.strip())
        files["fixture"]["nonempty_line_count"] = line_count
        files["fixture"]["expected_line_count"] = 307200
        if line_count != 307200:
            errors.append(f"fixture line count {line_count}, expected 307200")
    qsf = root / REQUIRED["qsf"]
    if qsf.is_file():
        qsf_text = qsf.read_text(encoding="utf-8", errors="replace")
        expected = "../qsys/Computer_System/synthesis/Computer_System.qip"
        if expected not in qsf_text:
            errors.append("QSF does not reference the active Computer_System QIP")
        qip_target = root / REQUIRED["qip"]
        if qip_target.is_file() and "Computer_System.qip" not in qip_target.name:
            errors.append("active QIP target has an unexpected name")

    filelist = root / REQUIRED["filelist"]
    if filelist.is_file():
        entries = []
        for raw in filelist.read_text(encoding="utf-8", errors="replace").splitlines():
            line = raw.strip()
            if not line or line.startswith("//") or line.startswith("#"):
                continue
            entries.append(line)
        if not entries:
            errors.append("RTL file list has no source entries")
        for entry in entries:
            target = (root / entry).resolve()
            if not target.is_file() or not target.is_relative_to(root):
                errors.append(f"RTL file list entry does not resolve under repository: {entry}")
        files["filelist"]["entries"] = entries
    result = {
        "schema_version": 1,
        "created_at_utc": datetime.now(timezone.utc).isoformat(),
        "repo_root": str(root),
        "status": "passed" if not errors else "failed",
        "errors": errors,
        "files": files,
        "scope": "contract/path checks only; no simulator, synthesis, timing, or board validation",
    }
    if args.manifest_out:
        out = args.manifest_out if args.manifest_out.is_absolute() else root / args.manifest_out
        out.parent.mkdir(parents=True, exist_ok=True)
        out.write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(result, indent=2))
    return 0 if not errors else 1

if __name__ == "__main__":
    sys.exit(main())
