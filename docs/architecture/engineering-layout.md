# Repository ownership and current source state

| Location | Role in the intended workflow | Current checkout status |
|---|---|---|
| `hardware/de1_soc/` | Expected active Quartus project, RTL, IP descriptor, ROMs, and `build.json` | The expected source files are absent in the current checkout; the directory contains mainly ignored Quartus output. Restore/confirm this source set before using the automated build. |
| `hardware/qsys/` | Platform Designer input systems and local generated system material | Qsys input files are present and should be compared with the archived project inputs. |
| `hardware/pin/` | Pin QSF and timing SDC | Board constraint sources are present. |
| `hardware/archive/project-inputs/` | Preserved legacy companion inputs, including QPF/QSF/top-level RTL/IP Tcl/ROMs and HPS files | Historical intake snapshot; not automatically selected by the current build manifest. |
| `hardware/verification/intake-20261004/` | Imported RTL, testbench, fixtures, and simulator-state snapshot | Immutable intake evidence; not an active regression suite. |
| `software/hps/` | HPS application, headers, and cross-build scripts | Active HPS source tree. |
| `software/matlab/` | Algorithm prototype | Not a validated fixed-point golden model. |
| `software/python/` | Supported image, build/check, archive, and verification tools | Active developer tooling and tests. |
| `build/` | FPGA/HPS runs, logs, snapshots, and validation output | Single ignored workspace; not a source location. |
| `hardware/archive/` | Historical artifacts and provenance | Local/ignored payload; never an alternate active design. |
| `docs/`, `paper/`, `data/`, `ref/` | Technical documents, manuscripts, input data, and references | Versioned documentation and provenance records. |

The intended repository boundary is one 1×1 design, one HPS application tree, and one developer-tool directory. The current checkout does **not** yet satisfy that intended active-source layout because `hardware/de1_soc/build.json`, the active QPF/QSF, top-level RTL, custom IP descriptor, and active ROMs are missing. The corresponding files exist in [`hardware/archive/project-inputs/`](../../hardware/archive/project-inputs/) as a preserved intake snapshot.

Do not edit generated submodules or Quartus output as source. Restore or explicitly select a verified source set first, then run the checker and build workflow. Historical reports are not proof of current-design correctness.

See the [directory edit guide](../development/directory-architecture.md), [legacy intake](../migration/legacy-intake.md), and [automatic-build limitations](../development/automatic-build.md).
