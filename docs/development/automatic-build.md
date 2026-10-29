# FPGA build workflow and current limitations

## Source selection

The automation expects persistent FPGA inputs under `hardware/de1_soc/`, board constraints under `hardware/pin/`, and Qsys inputs under `hardware/qsys/`. The expected manifest is `hardware/de1_soc/build.json`.

**Current checkout warning:** `hardware/de1_soc/build.json`, the active QPF/QSF, top-level RTL, custom IP descriptor, and active ROM files are not present in the current tree. `hardware/de1_soc/` contains primarily ignored Quartus output. A preserved legacy source set exists under `hardware/archive/project-inputs/`, but the current script does not silently substitute archive files for missing active inputs. Restore and review the intended active source set before treating the commands below as a build procedure.

The current Qsys input files and pin/SDC sources also require comparison with the archived project inputs. Do not copy files merely to make the checker pass; record provenance and confirm that the selected source set is the intended design.

## Intended automatic run

After the active source set and dependencies are restored:

```powershell
$env:QUARTUS_ROOTDIR = 'C:\intelFPGA_lite\18.1\quartus'
python software/python/build_fpga.py stage
python software/python/build_fpga.py generate
python software/python/build_fpga.py compile
```

`stage` snapshots current inputs. `generate` stages fresh inputs and generates the VGA subsystem, Video-In subsystem, and parent system. `compile` stages and regenerates before invoking Quartus. Each invocation creates a unique ignored run under `build/quartus/vision_1x1/runs/` with input hashes, logs, and run status. `latest.json` identifies the last started run, not necessarily the last completed run.

GUI edits made inside a generated run do not merge back into canonical source. Save Qsys, RTL, pin, and constraint changes in their selected source locations before starting another run. New IP/filesets need corresponding manifest entries. The flat staging scheme rejects filename collisions. No background watcher is installed.

Tool paths are resolved from `QUARTUS_ROOTDIR`, `--quartus-root`, or `PATH`. A tool command has a 30-minute timeout. An interrupted process may leave a run marked as running; inspect the status, QIP, and logs rather than inferring success from directory existence.

## Checks

```sh
python -m pip install -r software/python/requirements.txt
python software/python/check_project.py
# Linux only:
python software/python/check_project.py --hps-syntax
```

The checker is intended to validate the active source set, Qsys XML, IP source paths, and ROM dimensions. In the current checkout it stops with `FileNotFoundError` because `hardware/de1_soc/build.json` is missing. It does not restore missing sources and does not prove RTL correctness, timing closure, or board operation.

## Current evidence and limitations

A manual FPGA compilation completed on 2026-10-04 with Quartus Prime Lite 18.1.0 Build 625; see the local generated [flow report](../../hardware/de1_soc/DE1_SoC_Computer.flow.rpt), lines 43–44. The local report is generated output and is not tied here to a fresh, complete source checkout.

The earlier automatic parent-generation attempt was interrupted by the harness time limit. Timing-constraint warnings remain unresolved: the local generated [STA report](../../hardware/de1_soc/DE1_SoC_Computer.sta.rpt), lines 19032–19050, records HPS I2C/GPIO filters that match no ports and ignored `set_false_path` constraints with empty collections. SDC exception coverage, CDC/RDC, fixed-point equivalence, reset/stall/frame integrity, and ROM transmission-range/threshold reachability remain open. Execution on the DE1-SoC board is unverified.

Successful compilation and source checks do not settle these issues. Generated reports remain local/ignored and are not current source inputs.

## Archive and cleanup

Root `build/` is the single workspace for new FPGA/HPS output. Historical input snapshots and reports remain under `hardware/archive/` and `docs/history/`. Do not remove reports or private documents merely because they are ignored. See [build layout](build-layout.md), [artifact policy](../history/artifact-policy.md), and [legacy intake](../migration/legacy-intake.md).
