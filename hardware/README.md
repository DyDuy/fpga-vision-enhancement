# Hardware — 1x1 only

```text
hardware/
├── de1_soc/    QPF/QSF, board/core RTL, IP descriptor, ROM and build.json
├── pin/        editable physical assignments and timing SDC
├── qsys/       3 editable Qsys plus generated system folders (ignored)
└── archive/    historical report/binary and companion-input records, not active source
```

Open `de1_soc/DE1_SoC_Computer.qpf` in Quartus. QSF references pin and Qsys paths relatively; build automation collects all three input directories into a fresh flat root-build run and rebases paths. There is only root `build/`, not hardware/build.

HPS source is only in software/hps. 15x15 source was removed. Historical files are not proof of current-source correctness. See [pin](pin/README.md), [Qsys](qsys/README.md) and [workflow](../docs/development/automatic-build.md).
