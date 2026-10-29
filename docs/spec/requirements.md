# Initial requirements

## Goal

Process images or video degraded by haze or smoke on a SoC FPGA using a continuous pixel stream. The system must separate the processing core from the board adapter and control software.

## Requirements to close before functional RTL

- Data source: SD card, DDR/HPS, or video capture.
- Display target: frame buffer, VGA, or HDMI.
- Resolution, frame rate, and pixel format.
- Target clock, DSP/BRAM/logic limits, and DDR bandwidth budget.
- Image-quality metrics and evaluation dataset.
- Permitted latency and behavior under downstream backpressure.

## Milestone criteria

- Model: reproducible execution with reported quality metrics.
- Fixed point: numerical error and overflow relative to floating point are documented.
- RTL: matches reference vectors and handles reset, stalls, and frame boundaries.
- FPGA: timing closes and the report includes resources, throughput, and measurement conditions.

Do not invent values for requirements that have not been measured or decided.
