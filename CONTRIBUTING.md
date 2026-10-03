# Development rules

1. Edit hardware only in `hardware/de1_soc/`, HPS only in `software/hps/`, algorithm prototypes in `software/matlab/`, and tools/tests in `software/python/`.
2. Do not create another editable copy of an existing IP/platform. Use Git history/branches for active variants; local older snapshots belong in archive.
3. Never edit generated submodules as the canonical IP or recursively include archived HDL in synthesis.
4. Interface/parameter changes require matching Qsys descriptor, wrapper/software contract and independent tests.
5. Run `python software/python/check_project.py`; Linux can add `--hps-syntax`. CI success is not RTL/timing/board sign-off.
6. Keep generated output in root `build/`. Archive chosen evidence with configuration/source identity/checksum; do not attribute old reports to current code.
7. Exact duplicates may be removed only after byte/hash comparison and recording a canonical path. Nonidentical historical user code must not be silently destroyed.
8. Review Git status/diff before committing. Keep archive, signed records, thesis originals and reference PDFs private until redistribution rights are confirmed.

No project license has been selected. No automatic commit/push or board programming is implied by a build/tool check.
