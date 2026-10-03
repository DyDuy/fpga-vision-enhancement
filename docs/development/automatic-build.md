# Active-project workflow

## Edit one location

Persistent hardware inputs are in `hardware/de1_soc/`, not archive or generated submodules. Build configuration is `hardware/de1_soc/build.json`. HPS source is only in `software/hps/`.

For manual Quartus 18.1 use: open `hardware/de1_soc/DE1_SoC_Computer.qpf`, open parent Qsys in Platform Designer, register its directory in IP search paths and generate synthesis HDL before compilation.

## Automatic fresh run

```powershell
$env:QUARTUS_ROOTDIR = 'C:\intelFPGA_lite\18.1\quartus'
python software/python/build_fpga.py stage
python software/python/build_fpga.py generate
python software/python/build_fpga.py compile
```

`stage` snapshots current inputs. `generate` stages fresh inputs and generates VGA, Video-In, then parent. `compile` stages/regenerates first, then compiles. Every invocation creates a unique ignored run in `build/quartus/vision_1x1/runs/` with input hashes, logs and run status. `latest.json` indicates last started run, not necessarily last completed run.

GUI edits made inside a generated run do not merge back into canonical source. Save Qsys/RTL changes in hardware/de1_soc before rerunning. New IP/filesets need corresponding build inputs. The current flat staging scheme rejects filename collisions. No background watcher is installed.

Tool paths are resolved from QUARTUS_ROOTDIR/--quartus-root or PATH. Logs stay in ignored output. A tool has a 30-minute per-command timeout; a killed process may leave running status. Review status/QIP/logs rather than assuming a folder means successful generation.

## Checks

```sh
python -m pip install -r software/python/requirements.txt
python software/python/check_project.py
# Linux only:
python software/python/check_project.py --hps-syntax
```

Six Python tests cover staging/image conversion. Active files, Qsys XML, IP source path and ROM dimensions are checked. Active editable code is not frozen to historical intake hashes. Historical hash differences remain audit records rather than blockers of unrelated active-input checks; no archived modified source was overwritten to hide them.

## Current limitations

Manual FPGA compilation completed successfully on 2026-10-04 with Quartus Prime Lite 18.1.0 Build 625. Evidence: local generated [flow report](../../hardware/de1_soc/DE1_SoC_Computer.flow.rpt), lines 43–44. The earlier automatic parent-generation attempt was interrupted by the harness time limit; the manual result does not verify the automatic workflow end to end.

Timing-constraint warnings remain unresolved: the local generated [STA report](../../hardware/de1_soc/DE1_SoC_Computer.sta.rpt), lines 19032–19050, records HPS I2C/GPIO port filters that match no ports and ignored `set_false_path` constraints with empty collections. SDC exception coverage, CDC/RDC, fixed-point equivalence, reset/stall/frame integrity and ROM transmission range/atmospheric-threshold reachability still need review. Execution on the DE1-SoC board remains unverified. Successful compilation and source checks do not settle these issues. Generated reports remain local/ignored and are not included in Git.

## Archive and cleanup

Root `build/` is the single workspace for FPGA/HPS output; hardware/build has been merged into it. Retired 15x15/RGB24/Chisel sources were removed at the owner's request; [history](../history/README.md) records hashes and filtered archive status. Do not remove reports/private documents when cleaning build output.

See [build layout](build-layout.md) for HPS binaries/logs and archival snapshots. The active Quartus run layout and `latest.json` paths are retained.
