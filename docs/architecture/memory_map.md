# Memory architecture

The memory and register map must be treated as a contract shared by Qsys/Platform Designer, the FPGA top level, and HPS software. The current values are implementation evidence copied from the HPS header and Qsys sources; they have not been validated against a newly generated system or a board bitstream.

## Ownership rules

- A line buffer belongs to the processing core when it is needed for a local window.
- Frame buffers and DMA belong to the SoC/board adapter.
- Control and status registers should have one machine-readable source once the register map is stable.
- Do not maintain independently hand-edited C headers and RTL packages.

For the current HPS-facing addresses, see [`software/hps/include/hps_fpga_addresses.h`](../../software/hps/include/hps_fpga_addresses.h) and the centralized reference snapshot [`configs/memory_map.yaml`](../../configs/memory_map.yaml). The YAML file is documentation only until a validator or generator consumes it.

Before sign-off, compare the YAML/header values with generated Qsys addresses, buffer dimensions, stride, bridge configuration, and the bitstream used on the board.
