# DE1-SoC

Chưa có project Quartus hoặc bitstream. Khi triển khai, tách:

- `constraints/`: pin, clock và timing constraint;
- `platform/`: HPS, interconnect, DMA và generated system;
- `top/`: board top và adapter video;
- `scripts/`: lệnh tạo/build có thể tái lập.

Không commit database build hoặc file output tự sinh.
