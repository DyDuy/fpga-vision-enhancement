# Python developer tools

Run commands from the repository root. Build and check tools resolve the repository relative to their location; legacy ModelSim helpers may still contain local absolute paths.

| Tool | Purpose |
|---|---|
| `build_fpga.py` | Stage the expected active FPGA inputs, generate the Qsys systems, and optionally compile |
| `check_project.py` | Validate the source/configuration files that are present and run the Python tests; optionally run Linux C syntax checks |
| [`modelsim/`](modelsim/README.md) | Image preparation and HEX conversion helpers for ModelSim verification |
| `archive_quartus_outputs.py` | Archive selected outputs locally and create checksum/metrics records |
| `verify_artifact_manifest.py` | Check local archive sizes and SHA-256 values |
| `tests/` | Executable staging and image-conversion tests |

Install `requirements.txt` before running the tools. The build flow expects `hardware/de1_soc/build.json`; that manifest and the expected active QPF/QSF, RTL, IP descriptor, and ROM files are currently absent from the checkout. A preserved candidate snapshot exists under `hardware/archive/project-inputs/`, but the tooling does not silently use it as a fallback. Generated files are not placed in this directory.

Historical integrity is recorded separately from source checks. Passing these checks is not HDL simulation, synthesis, timing closure, or board sign-off.
