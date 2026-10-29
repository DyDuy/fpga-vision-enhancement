# Historical Quartus build — legacy-output-2026-05-02

## Source and status

This archive came from `LuanVan_SoC/output_files` and was supplied by the project owner. The ID is based on the **2026-05-02 build date recorded in the reports**, not the archive date or a source commit.

- 17 files, 29,975,654 bytes (28.59 MiB), copied byte-for-byte and checked with SHA-256.
- Local payload: `hardware/archive/quartus/legacy-output-2026-05-02/` (Git-ignored).
- [manifest.json](manifest.json): file locations, sizes, and checksums; archive time is recorded in `archived_at_utc`.
- [metrics.json](metrics.json): extracted fitter summary and 24 timing-summary entries.
- Source commit: **unknown**. Do not claim that the bitstream matches tracked RTL.
- This is a historical build; Quartus was not rerun and the board was not programmed during artifact organization.

## File classification

| Archive path | Contents | Files |
|---|---|---:|
| `bitstreams/` | `DE1_SoC_Computer.sof` | 1 |
| `reports/` | asm/eda/fit/flow/map/sta `.rpt`, fit/map `.smsg`, and fit/map/sta `.summary` | 11 |
| `programming/` | Original `.cdf` | 1 |
| `metadata/` | `.done`, `.jdi`, `.pin`, and `.sld` | 4 |

This source directory contains no `.rbf`. The `output_file.rbf` at the legacy root came from another source and was not merged into this snapshot.

## Results recorded in the reports

| Metric | Value |
|---|---|
| Flow status | Successful — Sat May 02 01:01:20 2026 |
| Fitter status | Successful — Sat May 02 01:00:17 2026 |
| Compilation tool | Quartus Prime 18.1.0 Build 625, Lite Edition |
| Revision / top level | `DE1_SoC_Computer` |
| Family / device | Cyclone V / `5CSEMA5F31C6` |
| ALM | 3308 / 32070 — 10% |
| Registers, post-fit | 4245 |
| Pins | 326 / 457 — 71% |
| Block-memory bits | 1418810 / 4065280 — 35% |
| RAM blocks | 182 / 397 — 46% |
| DSP blocks | 13 / 87 — 15% |
| PLL / DLL | 2 / 6; 1 / 4 |

Analysis & Synthesis reports 4281 registers, while the post-fit report reports 4245. This document uses the post-fit value and does not mix the two stages.

### Timing summary

| Corner | Setup slack (ns) | Hold slack (ns) |
|---|---:|---:|
| Slow 1100 mV, 85 °C | +1.730 | +0.143 |
| Slow 1100 mV, 0 °C | +1.727 | +0.162 |
| Fast 1100 mV, 85 °C | +2.110 | +0.084 |
| Fast 1100 mV, 0 °C | +2.110 | +0.077 |

The summary rows refer to the HPS DDR3 PHY clock `afi_clk_write_clk`. TNS is reported as 0. The summary also contains recovery/removal and minimum-pulse-width entries; the complete DDR report is required for a full timing assessment.

Do not infer Fmax, core latency, constraint coverage, CDC correctness, or camera frame rate from this table. “Flow Successful” and these slack values do not replace independent timing sign-off for the complete system.

## Three provenance groups

| Source | ALM | Memory bits | DSP |
|---|---:|---:|---:|
| This `output_files` snapshot, 2026-05-02 | 3308 | 1418810 | 13 |
| Legacy-root report, 2026-05-11, observed during intake | 3928 | 2215198 | 7 |
| Paper Table 2 | 6279 | 1113243 | 8 |

These three groups have different provenance. This snapshot is not direct evidence for the paper’s Table 2 or for the imported RGB30 source. See the [paper review](../../../../../paper/article/implementation-review.md) and [source intake](../../../../migration/legacy-intake.md).

## CDF and bitstream use

The retained CDF contains Quartus **23.1std** metadata, which differs from the **18.1** compilation tool in the reports. It may have been edited by a different Programmer version; the time relationship is unknown. The CDF references `C:/LuanVan_SoC/output_files/`, not the current repository path.

Before using Programmer, verify the device/board, artifact rights, and source version. Create a local chain that points to the archived `.sof` rather than modifying the hashed payload. The `.sof` is an SRAM-configuration artifact, not an `.rbf` for the Linux FPGA manager. Do not claim equivalence between formats without a conversion recipe.

## Local archive verification

From the repository root:

```sh
python software/python/verify_artifact_manifest.py docs/history/builds/hardware/legacy-output-2026-05-02/manifest.json
```

A clean checkout contains only the record and manifest, not the payload. To restore the payload, copy it from the correct source with matching checksums or download it from a Release/object store when a URL is added. Do not delete the original Downloads source after this step.

## Publication policy

Track the README, manifest, and metrics. Do not track the bitstream, raw reports, or raw metadata. Before public release, review Intel/IP terms and machine information in reports and the CDF. No public download URL, tag, or linked release currently exists.
