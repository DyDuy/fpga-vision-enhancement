# Công cụ ảnh cho verification ModelSim

Các script hỗ trợ chuẩn bị stimulus và dựng ảnh từ đầu ra testbench; không phải launcher ModelSim hoặc scoreboard xác nhận RTL đúng.

| File | Chức năng |
|---|---|
| `chuyen640_480.py` | Resize ảnh về 640×480 bằng Pillow. |
| `Chuyen_anh_sang_hex.py` | Resize và chuyển ảnh sang HEX RGB24 bằng OpenCV. |
| `image_hex.py` | CLI encode/decode RGB24; decode kiểm tra định dạng và số pixel. |
| `ketqua.py` | Dựng ảnh từ HEX đầu ra để xem nhanh bằng OpenCV/NumPy. |

## Sử dụng

Chạy từ root repository, sau khi cài dependency trong `software/python/requirements.txt`:

```bash
python software/python/modelsim/image_hex.py encode input.jpg build/vectors/input_image.hex --width 640 --height 480
# Chạy testbench ModelSim riêng, cấu hình đúng đường dẫn đọc/ghi HEX.
python software/python/modelsim/image_hex.py decode build/vectors/output_image.hex build/results/output.png --width 640 --height 480
```

Mỗi dòng HEX là một pixel `RRGGBB`, theo thứ tự hàng từ trái sang phải, từ trên xuống dưới. Frame 640×480 cần 307200 pixel. Định dạng này phải khớp với testbench; không đồng nhất với packing RGB30 của stream phần cứng.

## Giới hạn

- Ba script legacy (`chuyen640_480.py`, `Chuyen_anh_sang_hex.py`, `ketqua.py`) vẫn giữ đường dẫn tuyệt đối cũ và thực thi thao tác khi chạy/import. Cần xem, chỉnh đường dẫn trước khi sử dụng; việc gom thư mục không thay đổi nội dung của chúng.
- `ketqua.py` bỏ qua dòng sai, bù pixel đen nếu thiếu và cắt pixel thừa: chỉ dùng xem ảnh, không dùng làm tiêu chí PASS/FAIL.
- Ưu tiên `image_hex.py decode` và PNG để phát hiện frame sai định dạng/số lượng và tránh nén mất dữ liệu.
- Các script dùng cách resize khác nhau; không mặc định đầu vào tạo ra giống từng pixel.
- ModelSim cần được chạy riêng. Các công cụ này chưa thực hiện so sánh với golden model hay kiểm tra handshake/reset/stall.
