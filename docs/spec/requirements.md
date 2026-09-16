# Yêu cầu ban đầu

## Mục tiêu

Xử lý ảnh/video bị suy giảm bởi sương hoặc khói trên SoC FPGA với luồng pixel liên tục. Hệ thống phải tách lõi xử lý khỏi adapter board và phần mềm điều khiển.

## Yêu cầu cần chốt trước RTL chức năng

- Nguồn dữ liệu: SD card, DDR/HPS hoặc video capture.
- Đích hiển thị: frame buffer, VGA hoặc HDMI.
- Độ phân giải, frame rate và pixel format.
- Clock mục tiêu, giới hạn DSP/BRAM/logic và ngân sách DDR bandwidth.
- Thước đo chất lượng ảnh và dataset đánh giá.
- Độ trễ cho phép và hành vi khi downstream backpressure.

## Tiêu chí theo mốc

- Model: chạy tái lập và báo chỉ số chất lượng.
- Fixed-point: nêu rõ sai số và overflow so với floating-point.
- RTL: khớp vector chuẩn, xử lý reset/stall/frame boundary.
- FPGA: timing đạt, báo tài nguyên, thông lượng và điều kiện đo.

Chưa gán giá trị giả cho các yêu cầu chưa được đo hoặc chưa được quyết định.
