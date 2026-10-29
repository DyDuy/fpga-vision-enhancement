# Roadmap

## M0 — Specification

- Finalize the image/video source, resolution, frame rate, and pixel format.
- Finalize the streaming protocol, backpressure, reset, and parameter-transfer mechanism.
- Define the quality baseline and DE1-SoC resource limits.

## M1 — Reference model

- Build a reproducible floating-point pipeline.
- Add PSNR, SSIM, and a dehazing metric appropriate for the selected dataset.
- Create a small sample-image set with clear provenance.

## M2 — Fixed-point model

- Select a Q-format and rounding/saturation rules for every stage.
- Measure stage-by-stage error against floating point.
- Generate reference vectors for RTL.

## M3 — RTL kernel

- Select the first module after the algorithm survey.
- Verify stalls, reset, frame boundaries, and overflow.
- Compare the implementation bit-for-bit with the reference model.

## M4 — SoC FPGA integration

- Integrate the accelerator with Platform Designer and the DE1-SoC adapter.
- Write the minimum HPS/host software needed to configure and transfer data.
- Report post-place-and-route timing, resource usage, and throughput.

## M5 — Research evaluation

- Compare baselines under identical conditions.
- Perform ablations for architectural contributions.
- Store configuration, commit, tool version, and logs with selected results.
