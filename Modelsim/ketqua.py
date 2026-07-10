import cv2
import numpy as np
import os

input_path = r"C:\LuanVan_SoC\Test\output_image.hex"
output_path = r"C:\LuanVan_SoC\Test\dehazed_result.jpg"

output_pixels = []

# Kiểm tra file tồn tại
if not os.path.exists(input_path):
    print(f"Lỗi: Không tìm thấy file tại {input_path}")
else:
    with open(input_path, 'r') as f:
        for line in f:
            hex_val = line.strip()
            # Bỏ qua dòng trống hoặc dòng chứa dữ liệu không xác định 'xxxxxx'
            if len(hex_val) == 6 and all(c in '0123456789abcdefABCDEF' for c in hex_val):
                try:
                    r = int(hex_val[0:2], 16)
                    g = int(hex_val[2:4], 16)
                    b = int(hex_val[4:6], 16)
                    output_pixels.append([r, g, b])
                except ValueError:
                    continue


    # Tổng số pixel cần thiết
    total_needed = 640 * 480
    current_count = len(output_pixels)

    print(f"Đã đọc được: {current_count} pixels")

    if current_count < total_needed:
        print(f"Cảnh báo: Thiếu dữ liệu! Đang bù {total_needed - current_count} pixel đen.")
        output_pixels.extend([[0, 0, 0]] * (total_needed - current_count))
    elif current_count > total_needed:
        print(f"Cảnh báo: Thừa dữ liệu! Đang cắt bớt {current_count - total_needed} pixel thừa.")
        output_pixels = output_pixels[:total_needed]

    # Chuyển đổi và lưu ảnh
    out_img = np.array(output_pixels, dtype=np.uint8).reshape((480, 640, 3))
    
    # OpenCV mặc định dùng BGR, nên cvtColor là bắt buộc
    final_bgr = cv2.cvtColor(out_img, cv2.COLOR_RGB2BGR)
    cv2.imwrite(output_path, final_bgr)
    print(f"Đã lưu ảnh thành công tại: {output_path}")