# Repository layout and intake boundaries

> **Complete leaf-directory table:** see the [edit guide and directory map](../development/directory-architecture.md), the [full CSV inventory](../development/directory-inventory.csv), and the [snapshot metadata and scope](../development/directory-inventory-metadata.json). The current guide distinguishes active source, placeholders, generated output, snapshots, and retained logs; this document preserves the architectural decision context.

> **Intake status:** historical manifests record selective imports from the `LuanVan_SoC` Downloads snapshot. The currently preserved companion inputs are under `hardware/archive/project-inputs/`; older `hardware/archive/sources/` destinations in the manifest are unavailable in this checkout. The layout, missing dependencies, and validation gates are described in [legacy intake](../migration/legacy-intake.md). The build, verification, and license gates remain open.

This document distinguishes **observed** from **target** state. It does not treat scaffolding as implementation or a build report as build proof. Use the [requirements](../spec/requirements.md), [roadmap](../ROADMAP.md), [ADR 0001](../decisions/0001-repository-layout.md), and [ADR 0002](../decisions/0002-legacy-quartus-intake.md) as decision anchors.

## A. Layout, modules, and dataflow

| Location | Observed state | Intended responsibility / boundary |
|---|---|---|
| [`docs/`](..) | Specifications, target architecture, development guides, provenance, and research notes | Record interfaces, decisions, evidence, and references before closing the algorithm. |
| [`software/matlab/`](../../software/matlab/README.md) | Historical model location; not a verified dehazing model | Floating-point model, fixed-point model, vector generation, and error measurement. |
| `hardware/archive/` | Historical inputs and Quartus payloads | Preserve provenance; never use the archive as an active edit location. |
| `hardware/verification/` | Imported fixtures and test snapshots | Preserve immutable intake; create active regression tests separately. |
| `hardware/de1_soc/` | Expected active Quartus/project, RTL, IP descriptor, ROMs, and build manifest; source set currently incomplete | Own the current board/core implementation after restoration and review. |
| `hardware/qsys/` and `hardware/pin/` | Platform Designer sources and board constraints | Own interconnect, clocks, exported ports, pin assignments, and timing constraints. |
| `software/hps/` | HPS Linux source and cross-build | Own board-side control and frame-buffer/DMA access. |
| `software/python/` | Staging, checking, conversion, archiving, and tests | Own reproducible developer tooling, not the RTL algorithm. |
| `build/` | Generated runs, logs, snapshots, validation sandboxes, and retained evidence | Never use as canonical source; preserve selected evidence with provenance. |

Target flow:

```text
image/video source -> input adapter -> pixel stream -> preprocessing
  -> estimation -> restoration -> pixel stream -> output adapter -> sink
HPS/host configuration ---------------------------> control/parameters
reference model -> golden vectors -> checker <------ RTL observations
```

The processing core owns pixel transformation. Adapters own camera/display, HPS, DDR, DMA, and bus integration. The target interface includes pixel data, valid/ready, frame/line markers, control/status, and clock/reset; exact signal names, reset semantics, stall behavior, and timing remain to be closed.

## B. Decision basis and source policy

Algorithm choice, window/line-buffer behavior, atmospheric-light estimation, and DDR policy remain open until checked with a model and memory-throughput measurements. Keep board integration separate from the core so each can be tested independently.

Track in Git when provenance, licensing, and dependency closure are known:

- specifications and decisions;
- project-owned model/RTL and tests;
- small reference vectors with provenance;
- pin/timing configuration and build recipes after their dependencies are verified.

Do not track caches, generated netlists, raw reports, bitstreams, private datasets, or credentials. Large datasets/artifacts should have a URI, checksum, license, version, and retrieval script. The current repository does not claim a reproducible Quartus build until tool/IP versions, external inputs, and clean-checkout closure are demonstrated.

## C. Integration stages and gates

1. **Read-only inventory:** preserve the legacy source outside the active tree, create a manifest and hashes, classify handwritten/generated/vendor content, and review licensing. Do not copy guessed dependencies.
2. **Contract closure:** define pixel format, clock/reset, sideband, stall, control addresses, image source, and sink. Review the model and checker independently of the board.
3. **Selective intake:** move only verified sources into the active board area after manifest and dependency closure. Record IP/tool versions, licenses, and regeneration recipes; keep generated output outside Git.
4. **Measured integration:** run regression, timing, resource, throughput, and board tests with their measurement conditions, including failures. Do not claim reproducibility or performance without logs and checked artifacts.

## D. Current limitations

The intended active source and archived source are not interchangeable. Historical reports can describe a different RTL, Qsys generation, tool version, or source commit. The current centralized configuration files are reference documentation until validators or generators consume them. The memory map and clock values must be reconciled with generated Qsys and the exact bitstream used for a board run. The current active manifest and source closure are not yet present under `hardware/de1_soc/`.
