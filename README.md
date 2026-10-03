# FPGA Vision Enhancement

DE1-SoC vision-enhancement project. There is **one editable FPGA project**, one HPS application tree and one developer-tool directory. Older research versions and generated outputs are archival, not parallel edit locations.

## Directory layout

```text
fpga-vision-enhancement/
├── hardware/
│   ├── de1_soc/              ACTIVE Quartus project, RTL, IP descriptor and ROM
│   ├── pin/                  pin QSF and timing SDC
│   ├── qsys/                 3 Qsys inputs + generated system folders
│   └── archive/              historical reports/generated 1x1 snapshot — ignored
├── software/
│   ├── hps/                  ARM Linux apps, headers, build.sh
│   ├── matlab/               MATLAB algorithm prototype
│   └── python/               image tools, build/check scripts, tests/
├── docs/                     engineering docs and historical manifests
├── paper/
│   ├── article/              manuscript Markdown and review
│   └── thesis/               EN/VI thesis records; original files in ignored local/
├── data/                     input data and provenance
├── ref/                      reference notes; PDF library in ignored local/
├── build/                    ONLY build directory; FPGA/HPS output — ignored
├── README.md
├── CONTRIBUTING.md
├── CHANGELOG.md
├── Makefile
└── Git / CI / editor configuration
```

There is one build directory: root `build/`. FPGA and HPS tools both write there. The former hardware/build runs were merged without closing the user’s Quartus process.

HPS binaries now use `build/hps/linux/bin/`; existing validation logs use `build/hps/linux/logs/`. Active Quartus runs remain in `build/quartus/vision_1x1/`, while old snapshots and output dumps are grouped under `build/archive/quartus/`. See [build layout and retention](docs/development/build-layout.md).

## Open manually in Quartus 18.1

**File → Open Project →**

```text
hardware/de1_soc/DE1_SoC_Computer.qpf
```

Edit RTL in hardware/de1_soc, Qsys in hardware/qsys, and pin/timing inputs in hardware/pin. In Platform Designer add hardware/qsys and hardware/de1_soc to IP search paths, retaining vendor defaults; regenerate HDL before compiling. Generated submodules are not canonical source.

## Automatic update and build

```powershell
$env:QUARTUS_ROOTDIR = 'C:\intelFPGA_lite\18.1\quartus'
python software/python/build_fpga.py stage
python software/python/build_fpga.py generate
python software/python/build_fpga.py compile
```

Configuration: `hardware/de1_soc/build.json`. Every command snapshots the **latest active inputs** to a unique run under `build/quartus/vision_1x1/runs/`. `generate` builds VGA, Video-In, then Computer_System; `compile` regenerates first, then invokes Quartus. Logs, input hashes and status are saved. It never reuses an old generated design or silently merges GUI working-run edits into source.

## Software and checks

```sh
python -m pip install -r software/python/requirements.txt
python software/python/check_project.py
# Linux syntax checks as well:
python software/python/check_project.py --hps-syntax

python software/python/image_hex.py encode input.jpg build/vectors/input_image.hex
python software/python/image_hex.py decode build/vectors/output_image.hex build/results/output.png

# WSL/Linux, ARM Linux hard-float compiler required:
bash software/hps/build.sh all
```

GNU Make shortcuts: `make check`, `make fpga-generate`, `make fpga-build`, `make hps-build`. Image decode rejects unknown pixels and incomplete frames. HPS apps access board MMIO: do not execute on an unrelated host.

## Status and limitations

- Active design: RGB30 1x1 transmission LUT candidate, declared 11-cycle pipeline; not a validated paper release.
- Six Python checks pass for staging/image conversion; active dependencies, Qsys XML, component path and ROM dimensions are checked.
- The manual FPGA compilation completed successfully on 2026-10-04 with Quartus Prime Lite 18.1.0 Build 625. Evidence: local generated [flow report](hardware/de1_soc/DE1_SoC_Computer.flow.rpt), lines 43–44. This does not verify the automatic build workflow or execution on the DE1-SoC board.
- Timing-constraint review remains pending: the local generated [STA report](hardware/de1_soc/DE1_SoC_Computer.sta.rpt), lines 19032–19050, records unmatched HPS I2C/GPIO port filters and ignored `set_false_path` constraints with empty collections. SDC exception coverage, CDC/RDC, stall/reset alignment and the atmospheric-light threshold/ROM range still require independent validation; on-board operation is unverified.
- MATLAB is a legacy prototype, not a bit-accurate golden model.
- Per owner request, retired 15x15/RGB24/Chisel source variants and stale 15x15 generated cores have now been removed. Only the active 1x1 source remains. Removal is recorded in docs/history/one-build-1x1-only.json; historical reports are not active source.

## Documentation

- [Documentation index](docs/README.md)
- [Build workflow](docs/development/automatic-build.md)
- [Repository map](docs/architecture/engineering-layout.md)
- [Historical sources and deduplication](docs/history/README.md)
- [Paper](paper/article/README.md), [thesis](paper/thesis/README.md), [references](ref/README.md)

Git tracks active source/configuration, software/tools/tests, documentation and small manifests. Historical payloads, generated output, thesis originals, signed records and reference PDFs are local/ignored. Review rights and select a license before public release; no vendor or manuscript license is invented.
