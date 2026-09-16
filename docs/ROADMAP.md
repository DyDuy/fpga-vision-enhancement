# Roadmap

## M0 — Đặc tả

- Chốt nguồn ảnh/video, độ phân giải, frame rate và định dạng pixel.
- Chốt giao tiếp streaming, backpressure, reset và cách truyền tham số.
- Xác định baseline chất lượng và giới hạn tài nguyên DE1-SoC.

## M1 — Mô hình tham chiếu

- Xây pipeline floating-point có thể tái lập.
- Thêm chỉ số PSNR, SSIM và chỉ số khử sương phù hợp với dataset.
- Tạo bộ ảnh mẫu nhỏ có nguồn gốc rõ ràng.

## M2 — Mô hình fixed-point

- Chọn Q-format cho từng khâu và quy tắc rounding/saturation.
- Đo sai số từng khâu so với floating-point.
- Sinh vector chuẩn cho RTL.

## M3 — RTL kernel

- Chốt module đầu tiên sau khảo sát thuật toán.
- Kiểm chứng stall, reset, frame boundary và overflow.
- Đối chiếu bit-accurate với model.

## M4 — SoC FPGA

- Ghép accelerator với Platform Designer và adapter DE1-SoC.
- Viết phần mềm HPS/host tối thiểu để cấu hình và truyền dữ liệu.
- Báo cáo timing sau place-and-route, tài nguyên và thông lượng.

## M5 — Nghiên cứu

- So sánh baseline dưới cùng điều kiện.
- Thực hiện ablation cho đóng góp kiến trúc.
- Lưu cấu hình, commit, tool version và log cùng kết quả chọn lọc.
