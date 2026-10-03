# Re-intake review: current LuanVan_SoC snapshot

## Why this is a separate snapshot

The owner-supplied Downloads directory changed since the initial intake. Current core, board wrapper, QSF, Computer_System/VGA Qsys, IP descriptor and viewer differ from original hashes. Some old Test/MATLAB/benchmark sources no longer exist there. Existing imported sources are preserved rather than overwritten.

New candidate inputs live under [`hardware/archive/sources/experiments/baselines/paper_candidate_1x1/`](../history/README.md). [Current manifest](../migration/current-snapshot-manifest.json) records 13 files and compares every original manifest source against the current directory. The candidate is not yet promoted to the active core.

## Code observations

- RGB30 Avalon-ST ports and original/processed bypass.
- Feature extraction computes Cmax/Cmin; `dark_channel_1x1` is a registered feature stage, not spatial filtering.
- Transmission ROM address is `{Cmax,Cmin}`, 65536 entries, two read/pipeline stages.
- Refinement is transmission scaling/clamp (`STRENGTH=256`, `T_FLOOR=102`), not a spatial guided/box filter.
- Restoration has four registered stages; gamma has two; constants declare `UD_DELAY=5`, `TOTAL_DELAY=11`.
- Atmospheric light threshold is 220, startup value 220, smoothing `(15*A+max)/16` conditional on `max > 50`.
- Gamma and transmission data are loaded from external HEX files. No generator/model proving exact intended formula was located.
- Gamma HEX: 256 entries, all fit 8 bits, range 0–255.
- Transmission HEX: 65536 entries, all fit 10 bits, range 376–1023 across the complete ROM. Structural size/range checks are not formula verification.

**Important:** with STRENGTH=256 and this ROM range, steady-state transmission values cannot fall below the atmospheric update threshold 220. Thus the selected max-in-frame estimator may have no qualifying pixel. Startup/invalid behavior and atmospheric-light adaptation require simulation; do not claim the supplied ROM proves adaptation.

`common_delay_line` accepts `i_v` but does not use it; memory is not cleared on reset. Gamma/reciprocal ROMs run every clock even when the main pipeline is stalled. These warrant reset/warm-up and backpressure alignment tests. Declared latency is not independently measured.

## Platform and constraints

Current Computer_System adds an enabled Video_In_Subsystem; its Qsys includes decoder, chroma resampler, clipper, scaler, RGB resampler, CSC and DMA. Presence in Qsys is not a continuous-camera demonstration.

SDC is now present for this candidate, but absent in the original snapshot. It includes physical 50 MHz clocks, PLL derivation, hierarchy-specific generated-clock pins, `set_clock_groups -exclusive` and broad HPS false paths. Review hierarchy resolution, clock relationships, IO delays and exception coverage before timing sign-off. Do not copy it into the older baseline as if known compatible.

`hex_decoder.v` is still missing, referenced by QSF. Edge_Detection_Subsystem has generated interface files but no standalone source Qsys found in the root inventory; do not infer complete dependency closure from generated stubs.

## Reports: closer to paper, but mixed provenance

Root fitter summary is dated July 28, 2026 and reports 6279 ALM, 4875 registers, 1113243 memory bits, 144 RAM blocks and 8 DSP: these numbers match paper Table 2. This is a useful lead, not source/bitstream equivalence proof.

Root power summary is dated July 10, 2026, reports 824.12 mW, and confidence **Low: user provided insufficient toggle rate data**. Since dates differ, the claim that power and July 28 fit belong to the same fit remains unverified.

All 24 selected root report/bitstream/metadata files are preserved byte-for-byte in a separate ignored archive, [`legacy-root-mixed-2026-07-28`](../history/builds/hardware/legacy-root-mixed-2026-07-28/README.md). This does not mix with the May 2 output_files archive. Multiple RBFs are preserved but their source/conversion versions are unknown.

## Research next steps

1. Validate LUT formula, normalization, rounding and black/invalid address behavior; recover generators.
2. Test atmospheric update reachability and intended threshold using valid ROM addresses.
3. Add fixed-point model and independent pixel/latency/packet checks.
4. Exercise stalls, invalid bubbles, reset and frame cuts.
5. Recover decoder; review supplied SDC; regenerate Qsys with recorded vendor/IP versions.
6. Link a clean compile to exact sources, ROM hashes and constraints; obtain corresponding timing/power reports.
7. Verify video input on board separately from still-image display.

No original files were modified, no generated vendor HDL was promoted to source, and no new performance or quality measurement is claimed.
