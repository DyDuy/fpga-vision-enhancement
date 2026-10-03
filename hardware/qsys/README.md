# Qsys platforms

```text
hardware/qsys/
├── Computer_System.qsys
├── VGA_Subsystem.qsys
├── Video_In_Subsystem.qsys
├── Computer_System/             retained generated HDL
├── VGA_Subsystem/                retained generated HDL
├── Video_In_Subsystem/           retained generated HDL
└── *.sopcinfo                   retained generated metadata
```

There is no extra `luanvan_soc-current` folder. The three editable Qsys files are here; generated folders were moved here without copying their bytes and are Git-ignored. Their archived companion inputs are in hardware/archive/project-inputs, not another edit location.

Manual Platform Designer: open the Qsys here and include this directory plus `../de1_soc/` in IP search paths, retaining Quartus defaults. The custom core descriptor and RTL live in de1_soc. Generate before compiling the parent QPF; it references `../qsys/Computer_System/synthesis/Computer_System.qip`.

Retained generated output is a historical 1x1 snapshot, not proof of freshness after a source edit. Edit Qsys/RTL inputs and regenerate, never edit submodules as canonical source. The automated build stages de1_soc/pin/qsys inputs into a new root-build run and generates all three systems there.

The prior snapshot manifest remains a checksum record, with moved paths and filtered obsolete 15x15 files explicitly documented. Standalone generation and raw archive preservation do not establish full compile/CDC/timing or board correctness.
