# Current design-snapshot review

## Scope and provenance

This review describes the preserved 1×1 candidate snapshot, not a verified active FPGA source tree. The principal preserved RTL is [`hardware/archive/project-inputs/dehazing_system_top.v`](../../hardware/archive/project-inputs/dehazing_system_top.v), SHA-256 `a548877b56ab24ad115238628b1560fdc658df33fdbb801ad8589de19400dbc3`.

The current checkout has Qsys inputs under `hardware/qsys/`, pin/timing inputs under `hardware/pin/`, and generated Quartus output under `hardware/de1_soc/`. The expected active manifest and source closure under `hardware/de1_soc/` are missing. Do not infer active-source status from matching filenames in the archive.

## Code observations

- RGB30 Avalon-ST ports and an original/processed bypass are present in the preserved candidate.
- Feature extraction computes per-pixel channel extrema; `dark_channel_1x1` is a registered feature stage, not spatial filtering.
- The transmission ROM address is `{Cmax,Cmin}` with 65,536 entries and 10-bit values.
- Refinement is transmission scaling/clamping (`STRENGTH=256`, `T_FLOOR=102`), not a spatial guided or box filter.
- Restoration contains registered stages; gamma uses channel lookup tables. Constants declare `UD_DELAY=5` and `TOTAL_DELAY=11`.
- Gamma and transmission data are loaded from external HEX files. No generator or model proving the exact intended formula was located.
- The gamma table contains 256 8-bit entries. The transmission table contains 65,536 10-bit entries with observed values from 376 to 1,023. Structural size/range checks are not formula verification.

With `STRENGTH=256` and this ROM range, steady-state transmission values cannot fall below the atmospheric-update threshold 220. The selected maximum estimator may therefore have no qualifying pixel. Startup, invalid-data, and adaptation behavior require simulation; the supplied ROM does not by itself prove atmospheric-light adaptation.

`common_delay_line` accepts `i_v` but does not use it; memory is not cleared on reset. Gamma/transmission ROMs run every clock even when the main pipeline is stalled. These observations require reset, warm-up, and backpressure-alignment tests. Declared latency is not independently measured.

## Platform and constraints

`hardware/qsys/Computer_System.qsys` includes the HPS/SDRAM path and a Video-In subsystem; related Qsys inputs include the VGA subsystem. Their presence is not a continuous-camera demonstration.

The preserved project-input snapshot includes `DE1_SoC_Computer.sdc`, but the current active QSF and manifest are absent from `hardware/de1_soc/`. Review hierarchy resolution, clock relationships, I/O delays, and exception coverage before timing sign-off. Do not copy the archived SDC into an active project without checking compatibility.

## Reports and evidence boundaries

Historical Quartus reports and bitstreams under `hardware/archive/quartus/` are retained with provenance. Resource, power, and timing values from those reports or from the paper remain historical evidence unless tied to exact current sources, constraints, tool versions, and a reproducible run.

No source/bitstream equivalence, timing closure, fixed-point equivalence, or board operation is established by this review.

## Research next steps

1. Recover or validate the LUT formula, normalization, rounding, and invalid-address behavior.
2. Test atmospheric-light reachability against valid ROM addresses.
3. Add a fixed-point model and independent pixel, latency, and packet checks.
4. Exercise stalls, invalid bubbles, reset, and frame boundaries.
5. Reconcile the archived QSF/SDC, Qsys files, custom IP, and external dependencies.
6. Link any clean compile to exact sources, ROM hashes, constraints, tool versions, and reports.
7. Verify video input on the board separately from still-image display.

No original files were modified by this review, and no new performance or quality measurement is claimed.
