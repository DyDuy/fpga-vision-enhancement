# Thông số FPGA tham chiếu

- `fpga_design.yaml`: thông số thiết kế thu thập từ RTL archive, Qsys và HPS.
- `memory_map.yaml`: địa chỉ trong header HPS, chưa xác minh với bitstream/board.
- `synthesis_results.example.json`: mẫu kết quả cho một lần chạy Quartus, không phải kết quả đo.

**Đây là tài liệu mô tả, không phải cấu hình điều khiển build hay Verilog.** Thay đổi YAML không thay đổi độ phân giải, bit width, clock, LUT hoặc phần cứng. Những file này chưa được build script, Quartus, Qsys hay RTL đọc; cũng chưa có validator hoặc trình nhập báo cáo tự động. Không dùng làm nguồn sự thật duy nhất cho việc nạp board.

RTL trong `hardware/archive/project-inputs/` là bản lưu trữ. Các file source active được tài liệu mô tả tại `hardware/de1_soc/` hiện không có trong checkout; thư mục local có thể vẫn chứa output bị Git bỏ qua. Không mặc định khôi phục hoặc coi output đó tương ứng với RTL archive. Script `software/python/build_fpga.py` vẫn kỳ vọng `hardware/de1_soc/build.json`, không đọc các file ở đây.

Khi thay đổi source thực tế, đối chiếu lại YAML với RTL, IP descriptor, Qsys, HPS và các báo cáo của **cùng một** build. Ghi nguồn, hash/commit, phiên bản tool, điều kiện timing và đường dẫn report. Lưu output tự sinh dưới `build/` (Git bỏ qua); chỉ lưu số liệu đã kiểm tra nếu cần công bố. Không ghi đè template bằng kết quả lịch sử hoặc coi build thành công là timing sign-off.

## Lưu ý số học

Transmission là giá trị không dấu 10-bit; chưa khẳng định chính xác hệ số chuẩn hóa chỉ từ độ rộng. Mã nhân `STRENGTH` dùng 8 bit phần lẻ, lấy `[17:8]`, sau đó clamp ở 102. Phép phục hồi dùng LUT nghịch đảo và dịch phải số học 10 bit. Các chi tiết này cần được kiểm chứng bit-exact với LUT và mô phỏng, đặc biệt khi đổi tham số. Quy ước Q-format có thể khác nhau; ưu tiên width, signedness, biểu thức và hệ số scale cụ thể.

Các clock là cấu hình Qsys, không phải kết quả timing thực đo. `11` là độ trễ được khai báo trong RTL archive theo chu kỳ được enable, chưa chứng minh đúng trong mọi điều kiện stall/reset/frame.
