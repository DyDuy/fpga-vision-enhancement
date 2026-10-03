# Build output layout

## A — Output flow

Run commands from the repository root. Editable inputs stay in `hardware/` and `software/`; tools write generated output into ignored `build/`.

```text
build/
├── hps/linux/
│   ├── bin/                         vga_simple_display, memory_benchmark
│   └── logs/                        existing validation.txt
├── quartus/vision_1x1/
│   ├── runs/<run-id>/               active staged inputs, generated files and logs
│   └── latest.json                  last started run
├── archive/
│   ├── quartus/
│   │   ├── input-snapshots/paper_candidate_1x1/
│   │   └── legacy-artifacts/intake-root-artifacts-2026-07-28/
│   └── restructure-20261004.json     local move/hash manifest
└── software/                        empty former output directory
```

`bin/` contains build products, including the retained historical `memory_benchmark` binary; `logs/` keeps existing diagnostic records. Quartus run folders keep their internal file relationships. Sources: [HPS build script, output loop](../../software/hps/build.sh), [FPGA builder, lines 121–160](../../software/python/build_fpga.py), and [local restructure manifest, `files`](../../build/archive/restructure-20261004.json).

## B — Provenance and archive limits

The 2026-10-04 move records 38 files with original/new paths, byte sizes and SHA-256 before/after; all 38 matched immediately after the move. This checks file preservation. It does not verify a fresh build or hardware operation. Source: [local manifest, `expected_file_count`, `preserved_file_count` and `files`](../../build/archive/restructure-20261004.json).

The candidate folder is an inert input snapshot. Its original QSF was preserved without rewriting paths: `POWER_INPUT_FILE_NAME` at line 976 references `../../../../LuanVan_SoC/Test/power_analysis.vcd`, and `QIP_FILE` at line 1003 references a generated `Computer_System/synthesis/Computer_System.qip`. Relative external references can change meaning after relocation, and the snapshot is not a ready-to-build project. Source: [archived QSF, lines 976 and 1003](../../build/archive/quartus/input-snapshots/paper_candidate_1x1/DE1_SoC_Computer.qsf). Use the [active build workflow](automatic-build.md) for current inputs.

## C — Commands and consumers

```bash
bash software/hps/build.sh all
# Compiler override, if required by the target Linux image:
CC=/path/to/arm-linux-gnueabihf-gcc bash software/hps/build.sh all
```

Current HPS builds produce `build/hps/linux/bin/vga_simple_display`. `all` uses the explicit target registry for this application. `memory_benchmark.c` is absent; the moved binary is historical and cannot be reproduced from current source. An explicit `memory_benchmark` request fails with a missing-source message, and VS Code offers only current build targets. Sources: [build script, target registry](../../software/hps/build.sh), [VS Code tasks, HPS task arguments](../../.vscode/tasks.json), [manifest, memory_benchmark file record](../../build/archive/restructure-20261004.json).

FPGA commands and the `build/quartus/<name>/runs/` contract retain their existing paths; `latest.json` indicates the last started run, which may be incomplete. Source: [automatic workflow, Automatic fresh run](automatic-build.md#automatic-fresh-run).

## D — Retention and operating limits

Keep archived reports, bitstreams and input snapshots with their manifest. There is no automatic cleanup policy. Review and back up required evidence before deleting old runs or archives; do not clean a working Quartus run. The moved `validation.txt` is a historical log whose embedded paths were retained, not a new validation result. Sources: [manifest, `notes` and `files`](../../build/archive/restructure-20261004.json), [existing validation log](../../build/hps/linux/logs/validation.txt).

HPS builds compile/link only; board Linux ABI, bridges, MMIO and FPGA compatibility still require target validation. Source: [HPS operating limits](vscode-hps-build.md#d--điều-kiện-vận-hành-và-giới-hạn).
