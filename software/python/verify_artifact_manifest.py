"""Verify the size and SHA-256 of every payload in a local artifact manifest."""
import argparse
import json
from pathlib import Path

from archive_quartus_outputs import ROOT, sha256


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("manifest", type=Path)
    args = parser.parse_args()
    manifest = json.loads(args.manifest.read_text(encoding="utf-8"))
    errors = []
    total = 0
    for entry in manifest["files"]:
        path = (ROOT / entry["archive_relative_path"]).resolve()
        if not path.is_relative_to(ROOT.resolve()):
            errors.append("Manifest path escapes repository")
            continue
        if not path.is_file():
            errors.append(f"Missing local payload: {entry['archive_relative_path']}")
            continue
        size = path.stat().st_size
        total += size
        if size != entry["bytes"] or sha256(path) != entry["sha256"]:
            errors.append(f"Checksum/size mismatch: {entry['archive_relative_path']}")
    if manifest["file_count"] != len(manifest["files"]) or total != manifest["total_bytes"]:
        errors.append("Manifest count or total bytes mismatch")
    if errors:
        raise SystemExit("\n".join(errors))
    print(f"PASS: {manifest['file_count']} artifact files, {total} bytes; all SHA-256 hashes match")
    print("Checksum verification does not establish hardware compatibility or source equivalence.")


if __name__ == "__main__":
    main()
