# HPS Linux utilities (legacy intake)

Sources preserve legacy behavior. `vga_simple_display` maps SDRAM through the heavyweight bridge and Pixel DMA registers through the lightweight bridge. Requires DE1-SoC Linux, matching FPGA configuration, enabled bridges and permission to access `/dev/mem`; never run on an unrelated host.

```sh
bash software/hps/build.sh all
# Output: build/hps/linux/bin/vga_simple_display
# On target only:
sudo ./vga_simple_display input_image.hex
```

Use an appropriate ARM Linux cross-compiler for cross builds. The viewer expects 307200 RGB24 hexadecimal tokens and stores 32-bit words with stride 1024. Its input validation and resource handling remain legacy behavior (including an infinite sleep loop); inspect before production use.

`all` builds only `vga_simple_display`. `memory_benchmark.c` is absent from current source; its binary in `build/hps/linux/bin/` is retained historical output and cannot be reproduced from this source tree. Explicitly requesting `memory_benchmark` returns an unsupported/missing-source error. Sources: [build target registry](build.sh), [move manifest, memory_benchmark file record](../../build/archive/restructure-20261004.json).

The address contract is in `include/hps_fpga_addresses.h`. A host syntax check does not validate memory mapping or DMA operation.
