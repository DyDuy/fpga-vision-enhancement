"""Archive Quartus outputs byte-for-byte; track only manifest and extracted metrics."""
import argparse
from datetime import datetime, timezone
import hashlib
import json
from pathlib import Path
import re
import shutil

ROOT = Path(__file__).resolve().parents[2]


def sha256(path):
    digest = hashlib.sha256()
    with path.open("rb") as stream:
        for chunk in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(chunk)
    return digest.hexdigest()


def category(path):
    if path.suffix.lower() in {".sof", ".pof", ".rbf", ".jic"}:
        return "bitstreams"
    if path.suffix.lower() == ".cdf":
        return "programming"
    if path.suffix.lower() in {".rpt", ".summary", ".smsg"}:
        return "reports"
    return "metadata"


def extract_metrics(source):
    fit_files = list(source.glob("*.fit.summary"))
    timing_files = list(source.glob("*.sta.summary"))
    result = {"scope": "Historical report extraction, not a new build or board validation"}
    if len(fit_files) == 1:
        result["fit_source"] = fit_files[0].name
        result["fit_summary"] = {}
        for line in fit_files[0].read_text(encoding="utf-8", errors="replace").splitlines():
            if " : " in line:
                key, value = line.split(" : ", 1)
                result["fit_summary"][key.strip()] = value.strip()
    if len(timing_files) == 1:
        result["timing_source"] = timing_files[0].name
        text = timing_files[0].read_text(encoding="utf-8", errors="replace")
        result["timing_entries"] = [
            {"type": match[0].strip(), "slack_ns": float(match[1]), "tns_ns": float(match[2])}
            for match in re.findall(r"Type\s*:\s*([^\n]+)\nSlack\s*:\s*([-\d.]+)\nTNS\s*:\s*([-\d.]+)", text)
        ]
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("source", type=Path, help="Existing Quartus output_files directory")
    parser.add_argument("--build-id", required=True, help="Unique historical build identifier")
    args = parser.parse_args()
    if not re.fullmatch(r"[a-zA-Z0-9][a-zA-Z0-9_-]*", args.build_id):
        parser.error("build-id must contain only letters, digits, underscores and hyphens")
    if not args.source.is_dir():
        parser.error(f"Not a directory: {args.source}")
    files = sorted(path for path in args.source.rglob("*") if path.is_file())
    if not files:
        parser.error("Source directory contains no files")
    archive = ROOT / "hardware/archive/quartus" / args.build_id
    evidence = ROOT / "docs/history/builds/hardware" / args.build_id
    if archive.exists() or evidence.exists():
        parser.error("Build ID already exists; existing snapshots will not be overwritten")
    archive.mkdir(parents=True)
    evidence.mkdir(parents=True)
    entries = []
    for original in files:
        relative = original.relative_to(args.source)
        target = archive / category(original) / relative
        target.parent.mkdir(parents=True, exist_ok=True)
        shutil.copy2(original, target)
        checksum = sha256(original)
        if sha256(target) != checksum:
            raise RuntimeError(f"Copy checksum mismatch: {relative}")
        entries.append({
            "source_relative_path": relative.as_posix(),
            "archive_relative_path": target.relative_to(ROOT).as_posix(),
            "category": category(original),
            "bytes": original.stat().st_size,
            "sha256": checksum,
        })
    manifest = {
        "build_id": args.build_id,
        "archived_at_utc": datetime.now(timezone.utc).isoformat(),
        "source_snapshot": f"{args.source.parent.name}/{args.source.name}",
        "source_commit": None,
        "source_commit_status": "Unknown; no source/bitstream equivalence established",
        "archive_root": archive.relative_to(ROOT).as_posix(),
        "artifact_policy": "Local Git-ignored archive; manifest and metrics are tracked candidates",
        "public_download_url": None,
        "redistribution_status": "Not reviewed; check applicable Intel/IP terms before publishing binaries",
        "copy_transformations": "None; all payload files preserved byte-for-byte",
        "file_count": len(entries),
        "total_bytes": sum(entry["bytes"] for entry in entries),
        "files": entries,
    }
    for name, value in (("manifest.json", manifest), ("metrics.json", extract_metrics(args.source))):
        (evidence / name).write_text(json.dumps(value, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(f"Archived {len(entries)} files ({manifest['total_bytes']} bytes) to {archive}")
    print(f"Manifest and extracted historical metrics: {evidence}")
    print("No source changes, bitstream loading, Git staging or push performed.")


if __name__ == "__main__":
    main()
