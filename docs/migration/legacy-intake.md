# Selective intake: LuanVan_SoC

## Scope and provenance

Sources were imported from the owner's `Downloads/LuanVan_SoC` snapshot into this repository. The original directory was not modified. [legacy-manifest.json](legacy-manifest.json) maps every imported file to its destination, records SHA-256 hashes and explicit transformations. Text files use LF to keep checkout hashes portable. This intake supersedes the earlier **placeholder-only status**, not the validation gates in ADR 0002.

No existing Chisel code, user changes or Git history was removed. This is a source organization step, **not** an algorithm rewrite, hardware validation, or license clearance.

## Layout

```text
hardware/archive/sources/rtl/verilog/dehazing/             authoritative RGB30 streaming core
hardware/archive/sources/boards/de1_soc/
  top/                           DE1-SoC board wrapper
  platform/                      Computer_System and VGA_Subsystem Qsys
    ip/dehazing/                 custom component descriptor
  quartus/                       original QPF/QSF input templates
  constraints/                   pin reference; timing SDC is missing
software/hps/{src,include}/       Linux HPS utilities
software/matlab/legacy/              original MATLAB algorithm
hardware/archive/sources/experiments/baselines/legacy_*/   isolated alternative RTL snapshots
hardware/archive/sources/verification/tb/legacy_rgb24/     original RGB24 image testbench
software/python/                         portable tools and intake checks
  legacy/                        original hard-coded-path Python scripts
```

Do not recursively compile all Verilog files: baseline directories redefine the same module names with incompatible ports. `Test/main.c` and root `dehazing_system_tb.v` were misleadingly named RTL duplicates and were not selected. The generated Qsys core was byte-identical to the root core at intake, so only the root source was retained.

## Actual imported hardware path

HPS `/dev/mem` -> FPGA SDRAM -> Pixel DMA -> pixel FIFO -> RGB resampler -> RGB30 Avalon-ST dehazing -> dual-clock FIFO -> VGA 640x480.

System clock is configured at 100 MHz; VGA clock at 25 MHz. The imported inline core computes minimum RGB, 15x15 dark channel, simplified linear transmission, 15x15 box refinement, frame-adaptive atmospheric light, restoration with reciprocal LUT and 3x3 sharpening. It has no gamma stage. `SW[0]=0` selects delayed original; `SW[0]=1` selects processed pixels. Delay constants are 17957 and 18603 enabled cycles and require independent verification.

The RGB24 baseline contains gamma and has a different interface. MATLAB uses an exponential transmission and guided filter; it is not a bit-accurate golden model of RGB30 RTL.

## Reproduction and known blockers

Run from the repository root:

```sh
python software/python/check_legacy_intake.py
python software/python/prepare_quartus.py --allow-incomplete
```

The second command creates an **inspection-only** stage at `build/quartus/de1_soc/`; all generated products stay outside tracked source. It refuses to overwrite an existing stage.

Before a real FPGA build, recover and review the original `DE1_SoC_Computer.sdc` and `hex_decoder.v`. Do not fabricate timing constraints or remove references merely to obtain a green compile. Then stage with:

```sh
python software/python/prepare_quartus.py --sdc /path/to/DE1_SoC_Computer.sdc --decoder /path/to/hex_decoder.v
```

In Quartus/Qsys, use the stage as working directory, register `ip/dehazing/` and the stage in IP search paths, open `Computer_System.qsys`, resolve University Program IP and `VGA_Subsystem`, generate HDL, and confirm `Computer_System/synthesis/Computer_System.qip` exists before compiling the staged QPF. The recipe has not been exercised with Quartus here. Historical reports identify Quartus 18.1, while QPF metadata may mention a later release; do not assume interchangeability.

Remaining validation: reset/warm-up, ready/valid under stalls, LUT stall alignment, invalid input bubbles, line/frame boundaries, delay alignment, RGB ordering, SRAM/DMA stride, timing constraints and board testing. Legacy testbench does not verify RGB30 backpressure.

## Follow-up: historical output archive

A later, separate intake archived all 17 files from `LuanVan_SoC/output_files` under Git-ignored `hardware/archive/quartus/legacy-output-2026-05-02/`. Only [build record, manifest and extracted metrics](../history/builds/hardware/legacy-output-2026-05-02/README.md) are tracked candidates. This does not change the 35-file source manifest, establish source/bitstream equivalence, or import binaries into Git. The exclusions below describe the initial source intake.

## Exclusions and public hosting

Not imported: approximately 11 GB of ModelSim output, vendor-generated HDL, Qsys handoff/netlists, caches, bitstreams, raw reports, image collections, HEX frames, personal DOCX reports, third-party PDFs or backups. These remain in the original directory.

No SPDX identifier or project license was invented. Before public GitHub/GitLab push, verify ownership of imported handwritten RTL and board templates, Intel/Terasic IP redistribution terms, and any future dataset/publication assets. Add a license only after the owner chooses one for code they can license. Keep binaries in Releases or external storage with checksum, tool version and provenance; use LFS only for authorized assets that truly need versioning.

Review `git status` and `git diff` before staging: the repository already contained uncommitted changes before intake. No commit, remote change or push was performed.
