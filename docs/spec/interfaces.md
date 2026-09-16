# Interface dự kiến

Lõi xử lý ảnh dùng một interface streaming ở seam ngoài cùng. Tên tín hiệu cuối cùng sẽ được chốt cùng framework RTL.

| Nhóm | Ý nghĩa |
|---|---|
| Pixel input | Dữ liệu pixel, valid/ready, start/end of frame hoặc line |
| Pixel output | Pixel đã xử lý và sideband đồng bộ |
| Control | Enable, start, mode và tham số thuật toán |
| Status | Busy, error, frame counter và telemetry |
| Clock/reset | Clock miền xử lý và reset đồng bộ được đặc tả |

Các adapter Avalon-ST, Avalon-MM, DMA hoặc video I/O nằm ngoài lõi thuật toán. Điều này cho phép kiểm tra lõi mà không cần Platform Designer.
