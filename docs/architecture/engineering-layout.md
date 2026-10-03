# Project ownership — one 1x1 design

| Location | Role |
|---|---|
| `hardware/de1_soc/` | only editable FPGA/SoC inputs: QPF/QSF, Qsys, RTL, SDC, ROM and build.json |
| `software/hps/` | only HPS application/header tree |
| `software/matlab/` | algorithm prototype, not validated fixed-point golden model |
| `software/python/` | supported build/image/archive/check tools and tests |
| `build/` | single ignored workspace for FPGA and HPS output |
| `hardware/archive/` | historical artifacts, not alternate source designs |
| `docs/`, `paper/`, `data/`, `ref/` | technical docs, manuscripts, input data and reference material |

The owner selected 1x1 only. Retired 15x15/RGB24/Chisel source archives and stale spatial-core generated files were removed. The former hardware/build output was merged into root build; there are not two supported workspaces. [Removal record](../history/one-build-1x1-only.json).

Edit canonical inputs, regenerate, then compile. Do not edit generated submodules as source. HPS code is not copied into hardware. Historical reports are never proof of current-design correctness. [Workflow](../development/automatic-build.md).
