# Proposed interfaces

The image-processing core should use a streaming interface at its outer boundary. Final signal names and protocol details must be fixed together with the RTL framework.

| Group | Meaning |
|---|---|
| Pixel input | Pixel data, valid/ready, and start/end-of-frame or line markers |
| Pixel output | Processed pixels and synchronized sideband signals |
| Control | Enable, start, mode, and algorithm parameters |
| Status | Busy, error, frame counter, and telemetry |
| Clock/reset | Processing clock domain and a specified synchronous reset |

Avalon-ST, Avalon-MM, DMA, and video-I/O adapters belong outside the algorithm core. This separation allows the core to be verified without requiring Platform Designer.

The interface is a target contract. It does not by itself prove that the current legacy or `vision_1x1` implementation satisfies every item, especially stall, reset, frame-boundary, and latency behavior.
