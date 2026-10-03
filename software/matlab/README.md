# Reference model

`matlab/legacy/Thuat_toan.m` is an imported algorithm prototype with 15×15 dark channel, guided filtering, sharpening and interactive gamma. It is not a bit-accurate golden model of the RGB30 RTL or the paper 1×1 core.

A validated model must explicitly specify floating/fixed-point scales, LUT addressing, black-pixel convention, rounding, saturation and temporal atmospheric-light state. Add separate golden-vector generation only with executable tests and a selected implementation contract. No such validated golden model is currently claimed.
