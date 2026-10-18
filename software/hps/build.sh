#!/usr/bin/env bash
# Cross-build only: the legacy apps access board MMIO and must never run here.
set -euo pipefail

repo_root="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/../.." && pwd)"
cd -- "$repo_root"

# Python standard library keeps JSON escaping, byte hashes and failure records
# reliable even when repository/compiler paths contain spaces. Forward every
# argument so rejected requests can also be retained by the failure journal.
exec python3 software/hps/build_run.py "$@"
