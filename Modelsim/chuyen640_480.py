from PIL import Image

def resize_image_pil(input_path, output_path):
    try:
        # Mở ảnh từ đường dẫn
        img = Image.open(input_path)
        
        # Thay đổi kích thước về 640x480
        # Sử dụng Image.Resampling.LANCZOS để giữ độ sắc nét tốt nhất khi thu nhỏ
        img_resized = img.resize((640, 480), Image.Resampling.LANCZOS)
        
        # Lưu ảnh đã resize
        img_resized.save(output_path)
        print(f"Thành công! Ảnh đã được lưu tại: {output_path}")
    except Exception as e:
        print(f"Có lỗi xảy ra: {e}")

# Sử dụng thực tế với ảnh bạn đã gửi
resize_image_pil(r"C:\LuanVan_SoC\Data\1020_10_0.85551.png", r"C:\LuanVan_SoC\anh\test27.jpg")