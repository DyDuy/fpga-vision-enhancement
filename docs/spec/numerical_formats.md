# Numerical specification

No official Q-format has been approved. Before calling a model or RTL implementation bit-accurate, document the following for every stage:

- signedness and the number of integer and fractional bits;
- product and accumulator widths, including division or approximation widths;
- rounding mode;
- saturation or wraparound behavior;
- the valid range of every parameter;
- maximum numerical error and the acceptable image-quality impact.

The proof-of-concept `DehazingCore` used `UInt`, modular addition, and did not represent the numerical behavior of the final dehazing algorithm.

The preserved RTL snapshot also contains fixed widths, LUTs, shifts, and clamps that need to be captured in a bit-exact reference model before they are treated as an approved numerical contract. Record scale conventions and normalization assumptions explicitly; do not infer them from signal names alone. The current active source set under `hardware/de1_soc/` is incomplete.
