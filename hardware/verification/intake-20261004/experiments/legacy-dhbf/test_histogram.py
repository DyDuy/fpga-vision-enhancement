import cv2
import numpy as np
import time
import os
import matplotlib.pyplot as plt

def o1_bilateral_filter_single_channel(img, guidance, delta, radius):
    """
    Triển khai O(1) Bilateral Filter cho một kênh đơn lẻ.
    """
    h, w = img.shape
    window_size = 2 * radius + 1
    
    # Range kernel weights
    i_vals = np.arange(256).reshape(256, 1)
    l_vals = np.arange(256).reshape(1, 256)
    beta = np.exp(-((i_vals - l_vals)**2) / (delta**2))
    
    numerator = np.zeros((h, w), dtype=np.float32)
    denominator = np.zeros((h, w), dtype=np.float32)
    
    for l in range(256):
        mask = (guidance == l).astype(np.float32)
        hx_l = cv2.boxFilter(mask, -1, (window_size, window_size), normalize=False)
        weight_map = beta[img, l]
        numerator += weight_map * hx_l * l
        denominator += weight_map * hx_l
        
    result = numerator / (denominator + 1e-6)
    return np.clip(result, 0, 255).astype(np.uint8)

def dhbf_color_processing(img_color, delta, radius, guidance_img=None):
    """
    Xử lý DHBF cho ảnh màu bằng cách lọc từng kênh R, G, B song song.
    """
    b, g, r = cv2.split(img_color)
    
    if guidance_img is None:
        # Stage 1: Tự dẫn đường
        gb, gg, gr = b, g, r
    else:
        # Stage 2: Dùng ảnh dẫn đường từ Stage 1
        gb, gg, gr = cv2.split(guidance_img)
    
    print(f"   - Đang xử lý kênh Blue...")
    rb = o1_bilateral_filter_single_channel(b, gb, delta, radius)
    print(f"   - Đang xử lý kênh Green...")
    rg = o1_bilateral_filter_single_channel(g, gg, delta, radius)
    print(f"   - Đang xử lý kênh Red...")
    rr = o1_bilateral_filter_single_channel(r, gr, delta, radius)
    
    return cv2.merge([rb, rg, rr])

def process_dehazing():
    # --- THIẾT LẬP ĐƯỜNG DẪN ---
    input_file = r"C:\LuanVan_SoC\Test\dehazed_result.jpg"
    output_dir = os.path.dirname(input_file)
    output_file = os.path.join(output_dir, "dehazed_final_color_dhbf.png")

    # 1. Kiểm tra và đọc ảnh đầu vào (MÀU)
    if not os.path.exists(input_file):
        print(f"Lỗi: Không tìm thấy ảnh màu tại {input_file}")
        return

    img = cv2.imread(input_file) # Đọc ảnh màu (BGR)
    if img is None:
        print(f"Lỗi: Không thể đọc định dạng ảnh tại {input_file}")
        return

    print(f"--- Đang xử lý ẢNH MÀU: {input_file} ---")
    start_time = time.time()
    
    # 2. Thực hiện thuật toán DHBF 2 Giai đoạn (Màu)
    radius = 15
    
    print(">>> Giai đoạn 1: Tạo Guidance Image (Màu)...")
    guidance = dhbf_color_processing(img, delta=45, radius=radius)
    
    print(">>> Giai đoạn 2: Lọc chi tiết giữ cạnh (Màu)...")
    result = dhbf_color_processing(img, delta=15, radius=radius, guidance_img=guidance)
    
    duration = time.time() - start_time
    print(f"Xử lý MÀU hoàn tất trong: {duration:.4f} giây")

    # 3. Lưu kết quả
    cv2.imwrite(output_file, result)
    print(f"Kết quả MÀU đã lưu tại: {output_file}")

    # 4. So sánh
    img_rgb = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
    res_rgb = cv2.cvtColor(result, cv2.COLOR_BGR2RGB)
    
    plt.figure(figsize=(12, 6))
    plt.subplot(1, 2, 1); plt.title("Original Color Input"); plt.imshow(img_rgb)
    plt.subplot(1, 2, 2); plt.title("DHBF Color Output"); plt.imshow(res_rgb)
    plt.tight_layout()
    plt.savefig(os.path.join(output_dir, "color_comparison.png"))
    print("Biểu đồ so sánh đã lưu.")

if __name__ == "__main__":
    process_dehazing()
