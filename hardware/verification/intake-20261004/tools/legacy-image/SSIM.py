import cv2
import numpy as np
from skimage.metrics import structural_similarity as ssim
from skimage.metrics import peak_signal_noise_ratio as psnr

def evaluate_image_quality(original_path, processed_path):
    # Đọc ảnh
    # Đảm bảo đường dẫn chính xác
    img_original = cv2.imread(original_path)
    img_processed = cv2.imread(processed_path)

    if img_original is None or img_processed is None:
        print("Lỗi: Không tìm thấy ảnh. Vui lòng kiểm tra lại đường dẫn.")
        return

    # Chuyển đổi sang ảnh xám (Grayscale) để tính SSIM
    gray_original = cv2.cvtColor(img_original, cv2.COLOR_BGR2GRAY)
    gray_processed = cv2.cvtColor(img_processed, cv2.COLOR_BGR2GRAY)

    # Tính PSNR
    psnr_value = psnr(img_original, img_processed)

    # Tính SSIM
    ssim_value = ssim(gray_original, gray_processed)

    print(f"Kết quả đánh giá:")
    print(f"- PSNR: {psnr_value:.4f} dB")
    print(f"- SSIM: {ssim_value:.4f}")

# --- CẤU HÌNH ĐƯỜNG DẪN ---
# Bạn hãy thay thế các đường dẫn dưới đây bằng file ảnh thực tế của bạn
path_to_original = r"C:\LuanVan_SoC\anh\test24.jpg"
path_to_processed = r"C:\LuanVan_SoC\Test\dehazed_result.jpg"

# Gọi hàm thực hiện
if __name__ == "__main__":
    evaluate_image_quality(path_to_original, path_to_processed)