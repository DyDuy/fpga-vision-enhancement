# FPGA Vision Enhancement

Nghiên cứu kiến trúc xử lý ảnh tăng cường chất lượng trên SoC FPGA, bắt đầu với khử sương/khói theo luồng pixel và hướng tới xử lý video thời gian thực trên Terasic DE1-SoC.

## Trạng thái

- Có một proof-of-concept Chisel tên `DehazingCore`, hiện chỉ cộng 5 theo modulo rồi trễ một số chu kỳ. Ba test của lõi minh họa được giữ lại.
- Chưa có mô hình DCP hoàn chỉnh, RTL khử sương, project Quartus, bitstream hoặc số đo trên board.
- Các thư mục còn lại xác định nơi đặt mã và bằng chứng khi chúng thực sự tồn tại.

## Luồng phát triển

1. Chốt yêu cầu và định dạng pixel trong `docs/spec/`.
2. Xây mô hình floating-point rồi fixed-point trong `model/`.
3. Thay proof-of-concept bằng các module streaming có interface được đặc tả.
4. Đối chiếu model–RTL bằng vector chuẩn trong `verification/`.
5. Tích hợp DE1-SoC trong `fpga/`, sau đó đo chất lượng ảnh, độ trễ, thông lượng, tài nguyên và công suất.

## Lệnh Chisel hiện có

Yêu cầu JDK và sbt:

```powershell
cd rtl/chisel
sbt test
sbt "runMain vision.DehazingGen generated"
```

Output sinh tự động nằm trong `build/`, `rtl/chisel/target/`, `rtl/chisel/generated/` và không đưa vào Git.

## Bản đồ

- `docs/`: đặc tả, kiến trúc, quyết định và ghi chú nghiên cứu.
- `model/`: mô hình tham chiếu và mô hình số học.
- `rtl/`: implementation tổng hợp được; Chisel hiện nằm tại `rtl/chisel/`.
- `verification/`: test plan, checker và vector chuẩn.
- `fpga/`: adapter board, constraint và project công cụ.
- `software/`, `host/`: phần mềm HPS và công cụ PC.
- `experiments/`: cấu hình baseline, sweep và phân tích.
- `results/`: kết quả chọn lọc có nguồn gốc; output thô đi vào `build/`.
- `publication/`: bản thảo, hình và tài liệu tham khảo.

Xem [kiến trúc](docs/architecture/overview.md), [đặc tả ban đầu](docs/spec/requirements.md) và [kế hoạch](docs/ROADMAP.md).
