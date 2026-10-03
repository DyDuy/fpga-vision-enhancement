# Active 1x1 Quartus project

Open `DE1_SoC_Computer.qpf` manually in Quartus 18.1. This directory contains the board/core RTL, core IP descriptor, ROM data, QPF/QSF and build.json.

- Platform inputs/generated HDL: [`../qsys/`](../qsys/README.md).
- Physical pin assignments and timing: [`../pin/`](../pin/README.md).
- HPS apps: `software/hps/` at repository root.

The project QSF includes `../pin/de1_soc_pins.qsf`, references `../pin/DE1_SoC_Computer.sdc` and uses generated `../qsys/Computer_System/synthesis/Computer_System.qip`. Add qsys and de1_soc to Platform Designer search paths and regenerate before compiling; generated output may be older than source changes.

Automatic build from repository root:

```powershell
$env:QUARTUS_ROOTDIR = 'C:\intelFPGA_lite\18.1\quartus'
python software/python/build_fpga.py generate
python software/python/build_fpga.py compile
```

Both commands stage fresh inputs from de1_soc/pin/qsys through build.json; per-run relative paths are rebased to the flat workspace under root build/. Only 1x1 source is maintained. Full parent generation/compile, timing/CDC and protocol/ROM validation remain open.
