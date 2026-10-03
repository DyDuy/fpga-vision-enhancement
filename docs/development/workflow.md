# FPGA/SoC development and release workflow

## Environment

| Workflow | Environment | Limits |
|---|---|---|
| Portable source/tool checks | Python 3.12+; `software/python/requirements.txt` | no HDL correctness claim |
| HPS syntax/build | Linux GCC or ARM Linux cross toolchain | Windows native GCC lacks `sys/mman.h`; host syntax is not target execution |
| DE1-SoC build | Quartus Prime Lite 18.1.0 Build 625; generated University Program IP | manual compilation successful; automatic clean-checkout reproduction and constraint review remain open |

The manual compilation result and compiler version are recorded in the local generated [flow report](../../hardware/de1_soc/DE1_SoC_Computer.flow.rpt), lines 43–44. This is evidence for that run, not an end-to-end automatic-build validation. Chisel/RGB24 source variants were retired; their earlier checks are historical records, not active workflows. No universal toolchain lock is asserted: pin vendor/IP versions once a clean build is demonstrated.

## Standard local commands

From repository root, using PowerShell or a shell:

```sh
python -m pip install -r software/python/requirements.txt
python software/python/check_project.py
# Linux only (or appropriate Linux-target environment):
python software/python/check_project.py --hps-syntax
```

GNU Make is optional: `make check` and `make check-linux` call the same entry point. CI covers source/tool checks; the GitHub job invokes `--hps-syntax` ([configuration](../../.github/workflows/source-checks.yml), line 14). These checks do not simulate RTL or run Quartus.

```powershell
$env:QUARTUS_ROOTDIR = 'C:\intelFPGA_lite\18.1\quartus'
python software/python/build_fpga.py stage
python software/python/build_fpga.py generate
python software/python/build_fpga.py compile
```

Each command snapshots current inputs into a fresh ignored run under root `build/quartus/vision_1x1/runs/`. `generate` generates the component systems and parent; `compile` regenerates before compiling. See [the active workflow](automatic-build.md). Local generated reports and archives are excluded from Git.

Clean-checkout reproducibility also requires review of the external power-analysis VCD and `stp2.stp` assignments in [the active QSF](../../hardware/de1_soc/DE1_SoC_Computer.qsf), lines 220, 223 and 249. Supply the intended diagnostic inputs or explicitly adjust those assignments before making a reproducibility claim. The successful manual build alone does not resolve these dependencies.

## Change protocol

1. Identify active implementation, interface contract and baseline before editing.
2. Record intended behavior and affected requirements; distinguish refactor from algorithm change.
3. Use only the selected file list for HDL builds; never glob historical baselines into active synthesis.
4. Preserve original source hashes. For intentional changes to intake files, document transformations and update destination hashes in manifest.
5. Add independent tests before claiming behavior. Numeric changes need quantization/rounding/overflow tests; stream changes need reset/stall/frame tests.
6. Keep generated outputs under `build/`. Review `git diff --check`, `git diff`, and `git status` before staging.
7. Link successful build evidence to exact source commit, parameters, constraints, tool/IP versions and artifact checksum.

## Verification gates

| Gate | Required evidence | Current state |
|---|---|---|
| Source/tool hygiene | manifests, XML/source paths, conversion tests, no unwanted payloads | local selected checks pass |
| Protocol and arithmetic | golden model/LUT, reset/stall/frame tests, pixel equivalence | open |
| Platform closure | resolved IP, generated Qsys, reproducible clean-checkout build | manual compilation completed; automatic reproduction open |
| Timing/CDC | full constraints coverage, per-domain timing, CDC/RDC review | open; unmatched HPS filters and ignored false paths in local [STA report](../../hardware/de1_soc/DE1_SoC_Computer.sta.rpt), lines 19032–19050 |
| On-board validation | device/config/clock logs, sustained transfer, measured performance | not reproduced |
| Publication/release | rights, no private files, accurate claim-to-evidence mapping | review required |

## Release checklist

- [ ] Select and document a project license for code the owner can license; review vendor terms separately.
- [ ] Resolve diagnostic input dependencies and identify source version for any binary release.
- [ ] Do not release signed licenses, signatures, private administrative records or unreviewed dataset/manuscript assets.
- [ ] Confirm no `hardware/archive/`, `build/`, cache or secrets are staged.
- [ ] Publish binaries only after compatibility/right checks; use Releases/object storage and record checksums/URLs.
- [ ] Record commit/tag and distinguish historical report, simulated result and physical measurement.
- [ ] Map any paper claim to the actual 1x1 implementation; do not label 15x15 legacy as the paper release.

No commit, push, toolchain install, source functional rewrite or bitstream programming is implied by repository restructuring.
