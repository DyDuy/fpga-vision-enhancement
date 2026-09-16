# Kiến trúc dự kiến

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
    OUT --> SINK[DDR, VGA or HDMI]
```

Đây là kiến trúc mục tiêu, chưa phải implementation hiện có. Lõi thuật toán trình bày interface streaming nhỏ; các chi tiết board, bus và DDR được giữ trong adapter bên ngoài seam này.

## Phân chia trách nhiệm

- `model/`: thuật toán tham chiếu và khám phá số học.
- `rtl/chisel/`: proof-of-concept Chisel hiện có.
- `rtl/systemverilog/`: vị trí cho RTL SystemVerilog nếu được chọn.
- `verification/`: checker qua interface của lõi.
- `fpga/boards/de1_soc/`: clock, pin, Platform Designer và top-level board.
