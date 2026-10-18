# Đặc tả hệ thống: CHƯA XÁC ĐỊNH

Sao chép mẫu này thành `<design-name>.md`. Điền thông tin đã xác nhận và dẫn nguồn ngay cạnh yêu cầu; giữ `CHƯA XÁC ĐỊNH` cho phần còn thiếu. Đây là mẫu thu thập yêu cầu, chưa phải cấu hình chạy hoặc thiết kế được phê duyệt.

## Chức năng và phạm vi

| Mục | Giá trị cần điền |
| --- | --- |
| Tên thiết kế / top module | CHƯA XÁC ĐỊNH |
| Công cụ sử dụng, có thể chọn nhiều | Intel HLS / Magma / Chisel-Scala / Halide-CoreIR: CHƯA XÁC ĐỊNH |
| Phần cứng mục tiêu | CHƯA XÁC ĐỊNH; có thể chọn DE1-SoC nếu phù hợp |
| Mã thiết bị / phiên bản công cụ | CHƯA XÁC ĐỊNH |
| Chức năng / thuật toán | CHƯA XÁC ĐỊNH |
| Nguồn tham chiếu thuật toán và vị trí | CHƯA XÁC ĐỊNH |
| Ngôn ngữ và thư mục mã đầu vào | CHƯA XÁC ĐỊNH |
| Đầu vào, đầu ra, phạm vi hợp lệ | CHƯA XÁC ĐỊNH |
| Các chức năng ngoài phạm vi | CHƯA XÁC ĐỊNH |

## Luồng dữ liệu và điều khiển

```text
[Đầu vào / giao tiếp: cần điền]
              |
              v
[Các khối xử lý / điều khiển: cần điền]
              |
              v
[Đầu ra / giao tiếp: cần điền]
```

| Yêu cầu | Giá trị / nguồn cần điền |
| --- | --- |
| Tên cổng, chiều, độ rộng, giao thức | CHƯA XÁC ĐỊNH |
| Clock: miền clock và tần số mục tiêu (MHz) | CHƯA XÁC ĐỊNH |
| Reset: mức tác động, đồng bộ/bất đồng bộ, hành vi | CHƯA XÁC ĐỊNH |
| Định dạng số: signed/unsigned, độ rộng bit, phần lẻ | CHƯA XÁC ĐỊNH |
| Làm tròn, bão hòa/tràn số, sai số được phép | CHƯA XÁC ĐỊNH |
| Valid/ready, backpressure, độ liên tục của dữ liệu | CHƯA XÁC ĐỊNH |
| Dữ liệu biên, dữ liệu lỗi, reset giữa giao dịch | CHƯA XÁC ĐỊNH |

## Mục tiêu và nghiệm thu

| Chỉ tiêu | Mục tiêu, đơn vị, điều kiện đo và nguồn |
| --- | --- |
| Latency (chu kỳ hoặc thời gian) | CHƯA XÁC ĐỊNH |
| Throughput (mẫu/s, pixel/s hoặc đơn vị phù hợp) | CHƯA XÁC ĐỊNH |
| Clock đạt được sau triển khai (MHz) | CHƯA XÁC ĐỊNH |
| Giới hạn tài nguyên (ALUT/LE, FF, RAM/BRAM, DSP) | CHƯA XÁC ĐỊNH |
| Công suất nếu cần (W), điều kiện đo/ước lượng | CHƯA XÁC ĐỊNH |
| Mô hình tham chiếu / vector đầu vào và phiên bản | CHƯA XÁC ĐỊNH |
| Tiêu chí so sánh đầu ra và ngưỡng sai số | CHƯA XÁC ĐỊNH |
| Kiểm thử biên, reset, backpressure và tiêu chí pass/fail | CHƯA XÁC ĐỊNH |
| Cách so sánh các công cụ trên cùng yêu cầu | CHƯA XÁC ĐỊNH |
| Kế hoạch tích hợp QSF/Qsys và cổng board/HPS | CHƯA XÁC ĐỊNH |

## Hồ sơ tái lập cần lưu khi triển khai

- Commit và trạng thái mã nguồn; checksum bản chụp đầu vào.
- Công cụ, phiên bản, môi trường, target, tùy chọn compiler và lệnh thực thi.
- Bộ kiểm chứng, seed nếu có, nguồn/phiên bản dữ liệu, điều kiện đo.
- Đường dẫn run dưới `build/hardware/generation/runs/<run-id>/`; log, trạng thái, RTL/IP và báo cáo sinh ra.
- Kết quả đo thực tế, giới hạn và run thất bại; phân biệt yêu cầu mục tiêu với số liệu đã đo.

Xem [quy ước workspace](../README.md) trước khi thêm adapter.
