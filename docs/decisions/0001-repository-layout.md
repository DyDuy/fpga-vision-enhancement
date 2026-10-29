# ADR 0001: Separate the processing core from the board adapter

## Status

Accepted — 2026-09-16.

## Decision

The image-processing core exposes a streaming interface independent of the DE1-SoC. Avalon, HPS, DDR, camera, and display integration are implemented by adapters under the hardware/board boundary.

## Rationale

This seam allows the model and checker to verify the core, supports reuse on another board, and isolates SoC integration failures from algorithm failures.
