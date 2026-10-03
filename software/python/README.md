# Python developer tools

Run from repository root; scripts resolve it relative to their location.

| Tool | Purpose |
|---|---|
| `build_fpga.py` | Stage latest `hardware/de1_soc/`, generate all three Qsys, optionally compile |
| `check_project.py` | Validate active inputs/XML/ROMs and run `tests/`; optional Linux C syntax |
| `image_hex.py` | Strict portable RGB24 encode/decode |
| `archive_quartus_outputs.py` | Archive selected outputs locally and create tracked checksum/metrics records |
| `verify_artifact_manifest.py` | Check local archive sizes/SHA-256 |
| `tests/` | Executable staging and image-conversion tests |

Install `requirements.txt`. Build configuration is `hardware/de1_soc/build.json`. Generated files are not placed in this directory. Retired preparation/intake checker scripts are historical only and were moved to `hardware/archive/sources/tooling/`; they are not current entry points.

Historical integrity is recorded separately from active-source CI; editable active source is not frozen to an initial intake checksum. Passing these checks is not HDL simulation, synthesis or board sign-off.
