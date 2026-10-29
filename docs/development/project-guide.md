# FPGA Vision Enhancement project guide

This repository contains a DE1-SoC FPGA vision-enhancement study. The intended organization is one active FPGA source set, one HPS application tree, and one developer-tool directory. The current checkout requires a source-restoration step before the automated FPGA workflow can be treated as active.

## Directory layout

```text
fpga-vision-enhancement/
├── hardware/
│   ├── de1_soc/              expected active project; currently mostly ignored Quartus output
│   ├── pin/                  board pin QSF and timing SDC
│   ├── qsys/                 Platform Designer input systems
│   ├── archive/project-inputs/ preserved legacy source snapshot
│   └── verification/         imported RTL/test fixtures and simulator evidence
├── software/
│   ├── hps/                  ARM Linux application, headers, build scripts
│   ├── matlab/               algorithm prototype
│   └── python/               image tools, build/check scripts, tests
├── docs/                     engineering documentation and historical manifests
├── paper/                    manuscript and thesis records
├── data/                     input data and provenance
├── ref/                      reference notes
├── build/                    ignored FPGA/HPS working directory
└── Git / CI / editor configuration
```

The root `build/` directory is the only intended build workspace. HPS output belongs under `build/hps/linux/`; FPGA run output belongs under `build/quartus/vision_1x1/`. Historical payloads belong under `hardware/archive/` and are not alternate source designs.

## Source restoration requirement

The current checkout is missing the files expected by the active FPGA manifest: `hardware/de1_soc/build.json`, the active QPF/QSF, top-level RTL, custom IP descriptor, and active ROMs. A preserved legacy set exists under `hardware/archive/project-inputs/`, including:

```text
DE1_SoC_Computer.qpf
DE1_SoC_Computer.qsf
DE1_SoC_Computer.sdc
DE1_SoC_Computer.v
dehazing_system_top.v
dehazing_system_top_hw.tcl
gamma_lut_data.hex
transmission_lut_data.hex
```

Review the manifest and dependency closure before moving or selecting any archive content. Do not claim that the archive is the current active source merely because it contains matching filenames.

## Manual and automatic FPGA build

After restoring and reviewing the active source set, the intended Quartus 18.1 entry point is:

```powershell
$env:QUARTUS_ROOTDIR = 'C:\intelFPGA_lite\18.1\quartus'
python software/python/build_fpga.py stage
python software/python/build_fpga.py generate
python software/python/build_fpga.py compile
```

The current scripts do not silently fall back to `hardware/archive/project-inputs/`. See [automatic-build](automatic-build.md) for the source-state warning and run contract.

## Software and checks

```sh
python -m pip install -r software/python/requirements.txt
python software/python/check_project.py
# Linux syntax checks:
python software/python/check_project.py --hps-syntax
bash software/hps/build.sh all       # WSL/Linux with an ARM hard-float compiler
```

HPS applications access board MMIO through `/dev/mem`; do not execute them on an unrelated host as a runtime test. MATLAB remains a prototype, not a bit-accurate golden model.

## Status and limitations

- The design snapshot is a 30-bit RGB/1×1 transmission-LUT candidate with a declared 11-cycle pipeline; this is not a validated paper release.
- Source/tool checks cover the files currently present. They do not restore the missing active FPGA source set.
- A local manual Quartus report states successful compilation on 2026-10-04 with Quartus Prime Lite 18.1.0 Build 625. This is historical/local generated evidence, not a fresh reproducible build claim.
- Timing-constraint warnings remain open, including unmatched HPS I2C/GPIO filters and ignored false paths with empty collections. CDC/RDC, stall/reset alignment, atmospheric-light threshold reachability, and board operation remain unverified.
- Historical 15×15/RGB24/Chisel variants and generated outputs are not active source. Their provenance is retained in `docs/history/` and the intake records.

## Documentation

- [Documentation index](../README.md)
- [System anatomy](../architecture/system-anatomy.md)
- [Build workflow](automatic-build.md)
- [Repository map](../architecture/engineering-layout.md)
- [Historical sources and deduplication](../history/README.md)
- [Paper](../../paper/article/README.md), [thesis](../../paper/thesis/README.md), and [references](../../ref/README.md)

Git tracks source/configuration only after provenance, dependency, and licensing review. Historical payloads, generated output, thesis originals, signed records, and reference PDFs remain local/ignored unless a separate publication policy approves them.
