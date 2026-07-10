import cv2
import numpy as np

# Đọc ảnh sương mù 640x480
img = cv2.imread(r'C:\LuanVan_SoC\anh\test14.jpg')  
img = cv2.resize(img, (640, 480))
img_rgb = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)

# Ghi ra file hex
with open(r'C:\LuanVan_SoC\Test\input_image.hex', 'w') as f:
    for row in img_rgb:
        for pixel in row:
            r, g, b = pixel

            # Nếu muốn giữ 8-bit (0–255):
            hex_val = "{:02x}{:02x}{:02x}".format(r, g, b)

            # Nếu muốn giả lập 10-bit (0–1023), scale từ 8-bit:
            # r10 = (r << 2) & 0x3FF   # dịch trái 2 bit
            # g10 = (g << 2) & 0x3FF
            # b10 = (b << 2) & 0x3FF
            # hex_val = "{:03x}{:03x}{:03x}".format(r10, g10, b10)

            f.write(hex_val + '\n')
