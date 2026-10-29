# Verification plan

## Current executable checks

From the repository root:

```sh
python -m pip install -r software/python/requirements.txt
python software/python/check_project.py
# Linux GCC source syntax; also used by the GitHub source-check job:
python software/python/check_project.py --hps-syntax
```

The entry point checks active inputs, Qsys XML, IP source paths, and ROM dimensions, then runs Python tooling tests and byte-compilation. The Linux option checks the current `vga_simple_display.c` source with GCC and must fail if the expected source is missing. It does not execute board MMIO code or establish target compatibility. Sources: [check_project.py](../../software/python/check_project.py), lines 15–37 and 45–58; [GitHub CI](../../.github/workflows/source-checks.yml), line 14.

For staging, generation, and FPGA compilation use `python software/python/build_fpga.py stage`, `generate`, or `compile`; see [the active build workflow](automatic-build.md). Generated output belongs under the root `build/` directory.

A manual Quartus compilation completed on 2026-10-04 with Quartus Prime Lite 18.1.0 Build 625; see the local generated [flow report](../../hardware/de1_soc/DE1_SoC_Computer.flow.rpt), lines 43–44. Timing-constraint warnings remain: unmatched HPS I2C/GPIO port filters and ignored false paths with empty collections in the local generated [STA report](../../hardware/de1_soc/DE1_SoC_Computer.sta.rpt), lines 19032–19050. Clean-checkout reproduction and board execution remain unverified; these local reports are excluded from Git.

## Historical intake evidence

Earlier intake checks, including Chisel/RGB24 records and missing-dependency observations, describe imported snapshots. Their retired checker/source paths are not runnable commands for the current tree. Keep their provenance separate from active-build evidence; see the [intake guide](../migration/legacy-intake.md) and [history index](../history/README.md). Manifest source hashes describe the original snapshot, while destination hashes describe the normalized intake baseline; preserve original hashes when documenting later transformations.

## Algorithm and hardware validation

| Requirement | Test | Evidence | Status |
|---|---|---|---|
| Reference model matches the dehazing baseline | Not available | Not available | Planned |
| RTL matches the fixed-point model | Not available | Not available | Planned |
| Reset, stalls, and frame boundaries | Not available | Not available | Planned |
| DE1-SoC timing and throughput | Not available | Not available | Planned |

Passing source checks does not establish bit-accurate RTL, timing closure, end-to-end video operation, or board validation.
