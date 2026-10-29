# Hardware — 1×1 design scope

```text
hardware/
├── de1_soc/    expected active Quartus project; current directory is mostly ignored output
├── pin/        board pin assignments and timing SDC
├── qsys/       Platform Designer input systems and local generated system material
├── generation/ design-contract and tool-input workspace
├── archive/    historical reports, binaries, and preserved project-input records
└── verification/ imported RTL, fixtures, and simulator-state evidence
```

See the [generation workspace](generation/README.md) for tool inputs and the planned generation workflow. The preserved candidate project-input snapshot is under `archive/project-inputs/`; it is not silently selected by the current build scripts.

The expected active project entry point is `de1_soc/DE1_SoC_Computer.qpf`, but that file is absent from the current checkout. The preserved historical counterpart is `archive/project-inputs/DE1_SoC_Computer.qpf`. Before opening or compiling it, review the QSF/Qsys paths, external IP, ROMs, timing constraints, and source provenance.

HPS source is under `../software/hps/`. Historical 15×15 and other variants are not active source. Historical reports are not proof of current-source correctness. See [pin](pin/README.md), [Qsys](qsys/README.md), and the [build workflow](../docs/development/automatic-build.md).

When `software/python/build_fpga.py stage|generate|compile` is run, configuration, tool, staging, Qsys/Quartus, timeout, or interruption failures are recorded under `build/bug/hardware/<incident-id>/`. Each incident may contain `record.json`, `diagnostics.log`, and `journal.md`. Full logs remain in the originating run. Quartus GUI use, direct tool invocation, and board runs require manual log entry; see [bug logging](../docs/development/bug-logging.md).
