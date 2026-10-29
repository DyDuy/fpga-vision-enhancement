# FPGA Vision Enhancement project audit

**Review date:** 2026-10-04
**Git reference:** `main`, `5e287f1821ffd83656033a32633448babdc4a698`

This is a source-tree, repository-organization, and available-build-evidence review. It is not board validation. The limits are also recorded in the [project guide](project-guide.md) and [verification plan](verification.md).

## Executive conclusion

The separation of `hardware/`, `software/`, `docs/`, `paper/`, `ref/`, and `build/` is appropriate for an FPGA SoC research prototype. Keep the structure, but close the numerical contract, dataflow contract, RTL verification, pin/timing review, and clean-build provenance before making performance or product claims.

The preserved design snapshot is `vision_1x1` for Cyclone V `5CSEMA5F31C6`. The HPS target is the Linux application `vga_simple_display`, not bare-metal Cortex-M firmware. The preserved enhancement RTL is a 1×1 pixel path: it extracts RGB channels, computes per-pixel extrema, uses a transmission LUT, refines/clamps transmission, restores RGB, and applies gamma. The current checkout does not contain the expected active FPGA manifest and source set under `hardware/de1_soc/`; this snapshot is not evidence of a 15×15 spatial-window implementation.

## 1. Architecture and repository organization

### 1.1 Current image paths

The Qsys design contains a Video-In path and a separate HPS-to-VGA path. Video-In DMA writes on-chip SRAM at `0x08000000`. The HPS application writes a frame buffer to SDRAM; VGA Pixel DMA reads SDRAM; the resampler produces RGB30; the enhancement core sits in the Avalon-ST path before the output-side FIFO and VGA controller.

The current Qsys sources do not show a direct Video-In-to-enhancement connection. Continuous camera enhancement therefore needs a defined buffer-transfer policy or a revised connection. The presence of Video-In IP is not proof of camera-to-display operation.

### 1.2 Source ownership

| Area | Current responsibility | Review result |
|---|---|---|
| `hardware/de1_soc/` | Quartus project, board wrapper, enhancement RTL, IP Tcl, ROMs, build manifest | Clear active boundary, but local reports are mixed with source. |
| `hardware/pin/` | Pin and timing inputs | Correct separation; warnings still need disposition. |
| `hardware/qsys/` | Qsys sources and generated trees | Keep `.qsys` as source; regenerate output. |
| `software/hps/` | ARM Linux application, address header, cross-build | Target and toolchain are explicit. |
| `software/python/` | Staging, checking, image conversion, archive, and tests | Appropriate shared project tooling. |
| `software/matlab/` | Historical algorithm prototype | Not automatically a fixed-point golden model. |
| `build/` and archives | Run output, snapshots, reports, and local evidence | Must remain separate from canonical sources. |

A remaining documentation risk is that GUI-generated reports may sit beside `hardware/de1_soc/` while automated output is intended under `build/quartus/`. Do not delete reports solely for layout consistency; use a future run policy that records their source/configuration and output location.

## 2. High-priority technical findings

### P0.1 — Atmospheric-light candidate condition is incompatible with the current transmission ROM

The preserved transmission ROM contains 65,536 10-bit values. The observed minimum is 376 (`0x178`) and the maximum is 1,023 (`0x3ff`). The snapshot RTL uses `STRENGTH=256` and `T_FLOOR=102`; refinement multiplies and takes bits `[17:8]`, then clamps at the floor. For a valid ROM value `x`, the recorded operations imply:

$$
 t_{ref}=\max\left(102,\left\lfloor\frac{256x}{256}\right\rfloor\right)=x,
 \qquad 376\leq t_{ref}\leq1023.
$$

The estimator accepts a candidate only when `i_t < 220`. Since every refined value is at least 376, no current ROM entry satisfies the candidate condition. This is a source-level numerical deduction, not a measured waveform result.

Before changing the threshold, define the transmission scale, candidate range, per-frame atmospheric-light policy, and expected response on reference vectors. Then update the ROM generator/reference model and RTL together. Do not choose a new constant merely to make the condition reachable.

### P0.2 — HPS HEX parsing does not validate each pixel token

The current loop uses `fscanf(..., "%x", &hex_val) != EOF` and advances the image position. A conversion failure can return 0 rather than EOF, so an invalid token may be treated as data or leave the previous/uninitialized value in use. A short file can also be reported as successfully loaded after the remaining buffer was cleared to zero.

Refactor parsing into a host-testable function that requires one valid token per pixel, checks the RGB range, defines the policy for extra/missing/invalid tokens, and returns an error before DMA activation. Handle each mapping cleanup path independently and use a consistent nonzero error status.

### P1.3 — Memory and pixel contracts are duplicated

The HPS header declares `SCREEN_WIDTH=640`, `SCREEN_HEIGHT=480`, and `DMA_STRIDE=1024`, while the C application also uses literal dimensions and expressions such as `(y << 10) + x`. The stride must not be changed to 640 simply because the visible width is 640; it matches the current X/Y address layout and requires comparison with generated DMA logic.

Centralize width, height, packing, stride, buffer ranges, bridge bases, DMA offsets, swap policy, and cache/coherency assumptions. The new `configs/memory_map.yaml` and `configs/fpga_design.yaml` are reference snapshots only until validation/generation is integrated.

### P1.4 — Latency, stalls, bubbles, and reset are not verified

The RTL declares an 11-cycle nominal pipeline delay (`5+4+2`). This is not a measured end-to-end latency under stalls. Valid, sideband, and output timing need a scoreboard with randomized bubbles/backpressure and reset between frames. Required checks include stable output during stall, no loss/duplication, correct SOP/EOP alignment, no false valid during warm-up, and correct bypass behavior.

### P1.5 — Compile success is not timing or board sign-off

A local manual report states **Successful**, Quartus Prime Lite **18.1.0 Build 625**, target `5CSEMA5F31C6`. The report contains unresolved or unmatched HPS I2C/GPIO filters and ignored false paths with empty collections. The fitter also reports critical warnings involving pin assignment, including HPS DDR3-related assignments.

Review each warning by endpoint, clock, hierarchy, intended behavior, and source constraint. Do not edit generated SDC blindly or add broad false paths just to remove warnings. Board bring-up is a separate step after pin and constraint review.

### P1.6 — Build reproducibility has useful foundations but incomplete closure

`build_fpga.py` validates inputs, rejects flat-layout name collisions, hashes staged files, rewrites paths, and records run IDs and logs. The HPS builder snapshots source, records compiler/toolchain data, and publishes a convenience binary only after success.

Remaining closure work includes tool/IP version, Git SHA/dirty state, optional QSF inputs such as VCD/SignalTap files, profile-specific dependencies, and a clean-checkout generation/compile test. Do not rely on generated HDL left by a previous GUI run.

### P2.1 — Some documentation describes different project states

The public README may still describe a 15×15 design, while the preserved snapshot uses `vision_1x1`. Historical snapshot review, memory-map, and numerical-format documents must clearly label target concepts, imported snapshots, and active implementation facts. The expected active manifest is currently absent under `hardware/de1_soc/`; do not rewrite historical hashes to make them appear current.

## 3. Local report values and provenance

The following resource values were observed in a local manual report, not generated by this audit and not tied here to a fresh source hash:

| Resource | Local report value |
|---|---:|
| ALM | 6,279 / 32,070 |
| Registers | 4,875 |
| Block-memory bits | 1,113,243 / 4,065,280 |
| RAM blocks | 144 / 397 |
| DSP blocks | 8 / 87 |
| PLLs | 2 / 6 |

The STA summary includes setup slack **1.727 ns** and hold slack **0.077 ns** for the reported `afi_clk_write_clk` entries at the listed corners. These values do not establish full constraint coverage or timing closure for the complete design.

Keep the following provenance groups separate:

| Source | ALM | Memory bits | DSP |
|---|---:|---:|---:|
| Historical `output_files` snapshot, 2026-05-02 | 3,308 | 1,418,810 | 13 |
| Legacy-root report, 2026-05-11 | 3,928 | 2,215,198 | 7 |
| Paper Table 2 | 6,279 | 1,113,243 | 8 |

These are not interchangeable results. A historical bitstream does not prove the current RTL, and paper values do not become current results without source/configuration provenance.

## 4. Recommended work packages

| Priority | Work package | Acceptance evidence |
|---|---|---|
| P0.1 | Numerical contract and atmospheric-light behavior | Versioned LUT/reference generator, defined scale/rounding/clamp rules, vectors with and without candidates, reset/default behavior. |
| P0.2 | HPS parser and buffer lifecycle | Host tests for malformed/short/long input, mapping failures, bounds, and cleanup; no false success or DMA activation. |
| P1.1 | RTL scoreboard | Bit-accurate comparison with deterministic seeds; stall/bubble/SOP/EOP/reset/bypass coverage; measured latency. |
| P1.2 | Pin, STA, CDC, and RDC review | Disposition for every critical warning and unconstrained path; matching exceptions; rerun report. |
| P1.3 | Clean-checkout build | No undeclared external/generated dependency; run manifest with Git/tool versions, hashes, reports, and bitstream provenance. |
| P1.4 | Board and video path | Known bitstream, correct color/stride/buffer swap, captured images/logs, and a demonstrated Video-In-to-output path if required. |
| P2.1 | Single active-state guide | New developer can identify current top level, memory map, flow, tool version, and test status without confusing history with active source. |
| P2.2 | Benchmark evidence | Baselines, ablations, quality/latency/resource/power method, configuration, seed, source commit, and selected results. |

## 5. Verification status

The available Python checker/tests and HPS cross-build establish tooling and source-compilation behavior. They do not establish RTL simulation, parser correctness, timing sign-off, camera frame rate, image quality, or board operation.

Recommended execution order:

1. Freeze stream, memory, clock/reset, and numerical contracts.
2. Add a bit-accurate model and reference-vector generator.
3. Add RTL scoreboard and randomized backpressure/reset tests.
4. Test the HPS parser and buffer lifecycle on the host.
5. Reconcile Qsys, header, generated DMA, and bitstream addresses.
6. Disposition pin/timing/CDC/RDC warnings.
7. Rebuild from a clean checkout and retain a complete run record.
8. Perform board bring-up with a known bitstream and capture evidence.
9. Report performance only from reproducible, provenance-linked measurements.

This audit is a documentation and review record. It does not modify RTL, constraints, README claims, or Git history.
