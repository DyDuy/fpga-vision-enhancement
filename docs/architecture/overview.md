# Target architecture

```mermaid
flowchart LR
    SRC[Image or video source] --> IN[Input adapter]
    IN --> PRE[Pre-processing]
    PRE --> EST[Scene and transmission estimation]
    EST --> RESTORE[Restoration and enhancement]
    RESTORE --> OUT[Output adapter]
    CTRL[HPS control and parameters] --> PRE
    CTRL --> EST
    CTRL --> RESTORE
    OUT --> SINK[DDR, VGA, or HDMI]
```

This is the target architecture, not a claim about the current implementation. The algorithm core exposes a small streaming interface; board, bus, and DDR details remain in adapters around that boundary.

## Responsibility boundaries

- `model/`: reference algorithms and numerical exploration.
- `hardware/archive/sources/rtl/chisel/`: historical proof-of-concept Chisel location; the old payload is no longer present in the active checkout.
- Create a SystemVerilog location only when a real implementation exists; empty scaffolding has been removed.
- `hardware/archive/sources/verification/`: verification around the core interface.
- `hardware/archive/sources/boards/de1_soc/`: clocks, pins, Platform Designer, and board-level top level.

The active repository currently contains a DE1-SoC implementation under `hardware/de1_soc/`. Treat archived RTL and generated Quartus output as historical or generated evidence unless an active build manifest explicitly selects them.
