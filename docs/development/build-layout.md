# Build output layout

## A — Output flow

Run commands from the repository root. Editable inputs stay in `hardware/` and `software/`; tools write generated output into ignored `build/`.

```text
build/
├── hps/linux/
│   ├── bin/                         latest vga_simple_display; historical files if present
│   ├── logs/                        hps-run-validation-20261004.json (local checks)
│   └── runs/<UTC-timestamp>-<id>/
│       ├── sources/software/hps/    captured C, headers and build entrypoints
│       ├── logs/build.log           live compiler/preflight stdout and stderr
│       ├── bin/                     ELF for this successful run
│       └── run.json                 hashes, Git/toolchain, commands and status
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

FPGA and HPS Python build failures now create `build/bug/{hardware,software}/<UTC-timestamp>-<uuid>/`, with `record.json`, `diagnostics.log` excerpts capped at 128 KiB per log and an editable `journal.md`; successful builds create no incident. Full run logs and source snapshots keep their original locations and references. `generation/` is available for manually importing external generation-tool errors, as are GUI/board logs; historical logs are not scanned automatically. Initialization creates all three domain directories/help without an incident or overwriting notes, and `build/bug` remains Git-ignored. Sources: [FPGA capture hook, line 150](../../software/python/build_fpga.py#L150), [HPS capture hook, line 32](../../software/hps/build_run.py#L32), [failure recorder, line 203](../../software/python/bug_journal.py#L203), [initialization, line 87](../../software/python/bug_journal.py#L87), and [operating guide](bug-logging.md).

`bin/` provides the latest successful HPS binary, while each new HPS run preserves its own source snapshot, log, metadata and successful ELF. Previous outputs and historical diagnostics are not removed. Quartus run folders keep their internal file relationships. Sources: [HPS run creation, line 83](../../software/hps/build_run.py#L83), [HPS snapshot, line 174](../../software/hps/build_run.py#L174), [HPS output publication, line 262](../../software/hps/build_run.py#L262), [FPGA input staging, line 50](../../software/python/build_fpga.py#L50), [FPGA builder workflow, line 165](../../software/python/build_fpga.py#L165), and [local restructure manifest, `files`](../../build/archive/restructure-20261004.json).

## B — Provenance and archive limits

The 2026-10-04 move records 38 files with original/new paths, byte sizes and SHA-256 before/after; all 38 matched immediately after the move. This checks file preservation. It does not verify a fresh build or hardware operation. Source: [local manifest, `expected_file_count`, `preserved_file_count` and `files`](../../build/archive/restructure-20261004.json).

The candidate folder is an inert input snapshot. Its original QSF was preserved without rewriting paths: `POWER_INPUT_FILE_NAME` at line 976 references `../../../../LuanVan_SoC/Test/power_analysis.vcd`, and `QIP_FILE` at line 1003 references a generated `Computer_System/synthesis/Computer_System.qip`. Relative external references can change meaning after relocation, and the snapshot is not a ready-to-build project. Source: [archived QSF, lines 976 and 1003](../../build/archive/quartus/input-snapshots/paper_candidate_1x1/DE1_SoC_Computer.qsf). Use the [active build workflow](automatic-build.md) for current inputs.

## C — Commands and consumers

```bash
bash software/hps/build.sh all
# Compiler override, if required by the target Linux image:
CC=/path/to/arm-linux-gnueabihf-gcc bash software/hps/build.sh all
```

Current HPS builds produce `build/hps/linux/bin/vga_simple_display`. `all` uses the explicit target registry for this application. `memory_benchmark.c` is absent; any historical binary, if present locally, cannot be reproduced from current source and is preserved. An explicit `memory_benchmark` request fails with a missing-source message, and VS Code offers only current build targets. Sources: [HPS target registry, line 18](../../software/hps/build_run.py#L18), [HPS target validation, line 62](../../software/hps/build_run.py#L62), [VS Code tasks, HPS task arguments](../../.vscode/tasks.json), [historical manifest, memory_benchmark file record](../../build/archive/restructure-20261004.json).

The same commands now create a distinct HPS run, including failed attempts for accepted targets. `run.json` schema version 1 records UTC start/end, `running`/`succeeded`/`failed`, compiler flags and commands/exit codes, input/output SHA-256, Git HEAD/dirty status and toolchain versions. Compilation uses frozen `sources/` inputs; a failed compile cannot replace the last good convenience binary. Sources: [run schema, line 93](../../software/hps/build_run.py#L93), [snapshot, line 174](../../software/hps/build_run.py#L174), [Git provenance, line 196](../../software/hps/build_run.py#L196), [toolchain provenance, line 213](../../software/hps/build_run.py#L213), [build publication, line 262](../../software/hps/build_run.py#L262), [finalization, line 293](../../software/hps/build_run.py#L293).

FPGA commands and the `build/quartus/<name>/runs/` contract retain their existing paths; `latest.json` indicates the last started run, which may be incomplete. Source: [automatic workflow, Automatic fresh run](automatic-build.md#automatic-fresh-run).

## D — Retention and operating limits

Keep archived reports, bitstreams and input snapshots with their manifest. There is no automatic cleanup policy. Review and back up required evidence before deleting old runs or archives; do not clean a working Quartus run. Source for archive provenance: [manifest, `notes` and `files`](../../build/archive/restructure-20261004.json). Current HPS run-logging validation is recorded separately in [local validation evidence, `assertions` and `checks`](../../build/hps/linux/logs/hps-run-validation-20261004.json), including captured inputs, ARM ELF, failure handling and deferred interruption. This local record covers build behavior; its `mmio_application_executed` value is false and does not establish board operation.

HPS builds compile/link only; board Linux ABI, bridges, MMIO and FPGA compatibility still require target validation. Source: [HPS operating limits](vscode-hps-build.md#d--điều-kiện-vận-hành-và-giới-hạn).

HPS run IDs are build versions, not Git commits. Git status is observed separately from the individual file copies; save files and avoid concurrent source edits while staging. Compiler libraries/sysroot and host OS are not copied. The run log records build diagnostics, not board application runtime. Python 3 in WSL/Linux and a writable `build/` are prerequisites. The final publication section defers SIGINT/SIGTERM and keeps a committed run successful; precommit interruption preserves the previous binary. JSON and ELF publication are separate operations, so forced termination can prevent consistent final evidence. Sources: [HPS provenance and operating limits](../../software/hps/README.md#build-versions-and-logs), [commit boundary, line 262](../../software/hps/build_run.py#L262), [helper control flow, line 312](../../software/hps/build_run.py#L312).
