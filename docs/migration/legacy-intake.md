# Legacy source intake and provenance

## Scope and current status

The repository contains two related historical records:

1. `docs/migration/legacy-manifest.json` records an earlier selective intake from the owner's `Downloads/LuanVan_SoC` snapshot. Its destinations under `hardware/archive/sources/` are historical manifest entries; those files are not present in the current checkout and must not be treated as current paths.
2. `hardware/archive/project-inputs/` contains the currently preserved companion-input snapshot used for the `vision_1x1` design review. It includes the QPF/QSF/SDC, board wrapper, candidate enhancement RTL and IP Tcl, LUT files, and HPS address header/application input.

The current active-source directory `hardware/de1_soc/` is incomplete: `build.json`, the active QPF/QSF, top-level RTL, custom IP descriptor, and active ROMs are absent. No archive file is silently substituted by the build scripts. This intake record is provenance, not a promotion of archive content to active source.

## Preserved project-input snapshot

```text
hardware/archive/project-inputs/
├── DE1_SoC_Computer.qpf
├── DE1_SoC_Computer.qsf
├── DE1_SoC_Computer.sdc
├── DE1_SoC_Computer.v
├── dehazing_system_top.v
├── dehazing_system_top_hw.tcl
├── gamma_lut_data.hex
├── hps_fpga_addresses.h
├── transmission_lut_data.hex
└── vga_simple_display.c
```

The actual path is `hardware/archive/project-inputs/dehazing_system_top.v`.

Related Platform Designer inputs are currently under `hardware/qsys/`, with board constraints under `hardware/pin/`. Their relationship to the archive snapshot must be checked before a clean Quartus build is claimed.

## Observed design snapshot

The preserved RTL is a 30-bit RGB Avalon-ST, 1×1 per-pixel candidate. The reviewed notes record RGB extrema, a 65,536-entry × 10-bit transmission LUT, transmission refinement/clamping, restoration, gamma lookup, and a declared 11-cycle nominal pipeline. These are observations of the preserved snapshot, not independent validation of the intended algorithm.

The related HPS/display path uses a 640×480 image and the memory-map constants recorded in `software/hps/include/hps_fpga_addresses.h`. The Qsys files include VGA and Video-In subsystems, but the presence of those files does not establish continuous camera-to-display operation.

## Reproduction status

The current Python build flow expects `hardware/de1_soc/build.json` and does not use this archive as an implicit fallback. Do not run a real compile until the intended active source set, dependency closure, external IP, and tool versions have been restored and reviewed.

The preserved Quartus output under `hardware/archive/quartus/` is historical evidence. It does not establish source/bitstream equivalence, current timing closure, or board validation. The local generated reports record an earlier manual compilation, while the current source checkout remains incomplete.

## Validation and licensing gates

Before promoting any file from the archive to active source:

- compare hashes and record the selected provenance;
- inspect QSF/QPF paths, Qsys/IP dependencies, ROM generators, and external files;
- review clock/reset, SDC exceptions, data widths, latency, and memory-map compatibility;
- run source checks, simulation, generation, synthesis, timing review, and board tests as separate evidence layers; and
- review ownership and redistribution terms for handwritten RTL, Intel/Terasic IP, datasets, and reports.

No commit, remote change, or push is implied by this document. Review `git status` and `git diff` before staging.
