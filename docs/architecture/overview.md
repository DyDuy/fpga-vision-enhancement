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
- `hardware/archive/sources/rtl/chisel/`: proof-of-concept Chisel hiện có.
- Chỉ tạo vị trí SystemVerilog khi có implementation thực; scaffold rỗng đã được dọn.
- `hardware/archive/sources/verification/`: checker qua interface của lõi.
- `hardware/archive/sources/boards/de1_soc/`: clock, pin, Platform Designer và top-level board.
