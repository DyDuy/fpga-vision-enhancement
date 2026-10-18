import cv2
import numpy as np
import os

def calculate_detailed_metrics(img_original, img_processed, edge_threshold=0.05):
    """
    Tinh toan chi tiet cac thong so blind assessment (Hautiere et al. [14])
    de so sanh anh goc (O) va anh da xu ly (P).
    """
    # 0. DONG BO KICH THUOC: bat buoc phai cung shape truoc khi so sanh
    #    tung pixel (mask_o & mask_p, mag_p[valid_pixels]...). Anh goc (vd
    #    tu dataset/webcam) va anh xuat tu VGA (thuong co dinh 640x480) rat
    #    de khac kich thuoc nhau -> neu khong resize, ket qua se sai lech
    #    am tham hoac gay loi runtime.
    if img_original.shape[:2] != img_processed.shape[:2]:
        h, w = img_processed.shape[:2]
        img_original = cv2.resize(img_original, (w, h), interpolation=cv2.INTER_AREA)
        print(f"[Canh bao] Anh goc va anh xu ly khac kich thuoc -> da resize "
              f"anh goc ve {w}x{h} de khop voi anh xu ly.")

    # 1. Chuyen sang anh xam va chuan hoa ve [0, 1]
    def to_gray_float(img):
        if len(img.shape) == 3:
            return cv2.cvtColor(img, cv2.COLOR_BGR2GRAY).astype(np.float32) / 255.0
        return img.astype(np.float32) / 255.0

    gray_o = to_gray_float(img_original)
    gray_p = to_gray_float(img_processed)

    # 2. Tinh Gradient (Do tuong phan cuc bo)
    def get_gradient_mag(gray_img):
        gx = cv2.Sobel(gray_img, cv2.CV_32F, 1, 0, ksize=3)
        gy = cv2.Sobel(gray_img, cv2.CV_32F, 0, 1, ksize=3)
        return np.sqrt(gx**2 + gy**2)

    mag_o = get_gradient_mag(gray_o)
    mag_p = get_gradient_mag(gray_p)

    # 3. Thong ke Canh (Visible Edges)
    mask_o = mag_o > edge_threshold
    mask_p = mag_p > edge_threshold
    n_o = np.sum(mask_o)
    n_p = np.sum(mask_p)

    # 4. Thong ke Bao hoa (Saturation) - chi bao cao cho anh xu ly (P) theo
    #    dung dinh nghia cua Hautiere (do luong mat chi tiet do qua/thieu
    #    sang khi tang cuong), nhung van tinh ca O de tham khao doi chieu.
    def get_saturation(gray_img):
        black = np.sum(gray_img <= 0.01)
        white = np.sum(gray_img >= 0.99)
        return (black + white) / float(gray_img.size)

    sigma_o = get_saturation(gray_o)
    sigma_p = get_saturation(gray_p)

    # 5. Tinh cac chi so Hautiere (So sanh)
    # e: Ty le tang truong canh moi
    e = (n_p - n_o) / float(n_o) if n_o > 0 else 0

    # r: Ty le tang cuong do tuong phan trung binh, CHI tinh tren giao cua
    #    2 tap canh nhin thay Omega_r giao Omega_O (dung dinh nghia goc [14]).
    #    SUA LOI: truoc day dung (mag_o > 0.001) qua long, gay khuech dai
    #    gia tao khi mau so (mag_o) rat nho nhung chua du la "canh".
    valid_pixels = mask_p & mask_o
    if np.sum(valid_pixels) > 0:
        r_map = mag_p[valid_pixels] / mag_o[valid_pixels]
        r = np.exp(np.mean(np.log(r_map)))
    else:
        r = 0

    avg_mag_o = np.mean(mag_o)
    avg_mag_p = np.mean(mag_p)

    return {
        "original": {"n_edges": n_o, "sigma": sigma_o, "avg_contrast": avg_mag_o},
        "processed": {"n_edges": n_p, "sigma": sigma_p, "avg_contrast": avg_mag_p},
        "hautiere": {"e": e, "r": r, "n_common_edges": int(np.sum(valid_pixels))}
    }

def main():
    # --- DUONG DAN FILE ---
    path_original = r"C:\Users\Duy Khanh\Downloads\Data\Scene 2\Scene_2.jpg"
    path_processed = r"C:\Users\Duy Khanh\Downloads\Data\Scene 2\Scene_2_P.jpg"

    if not os.path.exists(path_original) or not os.path.exists(path_processed):
        print("Loi: Khong tim thay file anh. Vui long kiem tra lai duong dan.")
        return

    img_o = cv2.imread(path_original)
    img_p = cv2.imread(path_processed)

    results = calculate_detailed_metrics(img_o, img_p)

    o = results["original"]
    p = results["processed"]
    h = results["hautiere"]

    print("="*50)
    print(f"{'THONG SO DANH GIA CHAT LUONG HINH ANH':^50}")
    print("="*50)

    print(f"{'Tieu chi':<25} | {'Anh Goc (O)':<10} | {'Anh Xu ly (P)':<10}")
    print("-" * 50)
    print(f"{'So luong canh nhin thay':<25} | {o['n_edges']:<10.0f} | {p['n_edges']:<10.0f}")
    print(f"{'Do bao hoa (Saturation)':<25} | {o['sigma']*100:<9.2f}% | {p['sigma']*100:<9.2f}%")
    print(f"{'Do tuong phan trung binh':<25} | {o['avg_contrast']:<10.4f} | {p['avg_contrast']:<10.4f}")

    print("\n" + "="*50)
    print(f"{'KET QUA THEO MO HINH HAUTIERE (P vs O)':^50}")
    print("="*50)
    print(f"So canh chung (Omega_r giao Omega_O): {h['n_common_edges']}")
    print(f"1. Chi so e (Ty le canh moi):      {h['e']:.4f}")
    print(f"   => Khoi phuc them {h['e']*100:.2f}% chi tiet canh.")

    print(f"\n2. Chi so r (Do tang tuong phan):  {h['r']:.4f}")
    print(f"   => Do tuong phan bien tang gap {h['r']:.2f} lan.")

    print(f"\n3. Chi so sigma (Do bao hoa moi):  {p['sigma']*100:.2f}%")
    print(f"   (Nguong an toan cua bai bao la < 1%)")
    print("="*50)

if __name__ == "__main__":
    main()
