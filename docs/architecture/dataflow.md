# Dataflow

The intended steady-state behavior is one input pixel and one output pixel per cycle after the pipeline is full. Any stage that requires a spatial window must use line buffers sized from the kernel and image width.

## Decisions still open

- The final dehazing algorithm and window size.
- Atmospheric-light estimation: per frame, per tile, or supplied by the HPS.
- Whether to store complete frames in DDR or remain fully streaming.
- Stall behavior and sideband retention under downstream backpressure.

Each decision must be checked against the reference model and memory-throughput budget before RTL implementation.

The current `vision_1x1` design is a specific implementation snapshot, not proof that the target spatial-window architecture has been completed. Keep current RTL behavior separate from the target dataflow described above.
