# Không gian sinh hệ thống phần cứng

`hardware/generation/` chứa đặc tả hệ thống và các đầu vào có thể chỉnh sửa cho Intel HLS, Magma, Chisel/Scala và Halide/CoreIR. Bộ công cụ tiếp tục nằm tại `C:\Users\Duy Khanh\OneDrive\Desktop\Research\tools`; thư mục này giữ đầu vào riêng của dự án.

## A — Kiến trúc và luồng làm việc

Luồng dự kiến sau khi chọn công cụ và hoàn thiện đặc tả:

```text
specs/ + src/<tool>/ + configs/
                  |
                  v
scripts/ (adapter sẽ được bổ sung theo công cụ)
                  |
                  v
C:/Users/Duy Khanh/OneDrive/Desktop/Research/tools/<tool>
                  |
                  v
build/hardware/generation/runs/<run-id>/
    inputs/ -> rtl/ + reports/ + logs/ + run.json
                  |
                  v
Kiểm chứng -> xem xét RTL/IP -> tích hợp QSF/Qsys -> build Quartus
```

`inputs/`, `rtl/`, `reports/`, `logs/` và `run.json` là quy ước cho adapter tương lai. Chưa có adapter, thiết kế mới hoặc run được tạo trong bước chuẩn bị thư mục này.

## B — Công cụ và nguồn đối chiếu

Các liên kết dưới đây trỏ đến tài liệu đang có trên máy. Thông tin hoạt động trong tài liệu là kết quả đã được ghi nhận trước đó; bước chuẩn bị workspace này chỉ đọc tài liệu, chưa chạy lại các công cụ.

| Công cụ | Đầu vào của dự án | Bộ công cụ ngoài repo và vị trí kiểm chứng |
| --- | --- | --- |
| Intel HLS | `src/intel_hls/` | `tools/hls-tool/`: hướng dẫn sinh RTL/report tại [README, dòng 18–19](<C:/Users/Duy Khanh/OneDrive/Desktop/Research/tools/hls-tool/README.md:18>); trạng thái trước đó và giới hạn mô phỏng HDL tại [dòng 45–51](<C:/Users/Duy Khanh/OneDrive/Desktop/Research/tools/hls-tool/README.md:45>). |
| Magma | `src/magma/` | `tools/magma/`: mô tả Python HDL và đầu ra CoreIR/Verilog tại [README, dòng 1–3](<C:/Users/Duy Khanh/OneDrive/Desktop/Research/tools/magma/README.md:1>). |
| Chisel/Scala | `src/chisel/` | `tools/scala/`: môi trường Scala/Chisel/sbt tại [README, dòng 1–3](<C:/Users/Duy Khanh/OneDrive/Desktop/Research/tools/scala/README.md:1>); đường dẫn RTL của mẫu cũ tại [dòng 15–19](<C:/Users/Duy Khanh/OneDrive/Desktop/Research/tools/scala/README.md:15>). |
| Halide/CoreIR | `src/halide/` | `tools/Halide/hardware/`: luồng CoreIR JSON → Verilog và giới hạn compiler Stanford tại [README, dòng 18–24](<C:/Users/Duy Khanh/OneDrive/Desktop/Research/tools/Halide/hardware/README.md:18>); script hiện có gọi CoreIR qua WSL tại [generate-verilog.ps1, dòng 39–50](<C:/Users/Duy Khanh/OneDrive/Desktop/Research/tools/Halide/hardware/scripts/generate-verilog.ps1:39>). |

Thư mục `src/halide/` có thể giữ đầu vào CoreIR JSON. Với mã Halide cấp cao, cần xác nhận compiler và các phụ thuộc hoạt động trước khi viết adapter; README công cụ chưa ghi nhận compiler Stanford đầy đủ đã được build. [Nguồn: README Halide, dòng 24](<C:/Users/Duy Khanh/OneDrive/Desktop/Research/tools/Halide/hardware/README.md:24>).

## C — Tổ chức đầu vào

```text
hardware/generation/
  README.md
  specs/
    system-template.md
  src/
    intel_hls/
    magma/
    chisel/
    halide/
  configs/
  scripts/
```

- `specs/`: đặc tả đầu vào/đầu ra, giao tiếp, clock/reset, độ rộng số và tiêu chí nghiệm thu. Sao chép [system-template.md](specs/system-template.md) thành đặc tả có tên thiết kế.
- `src/<tool>/`: mã và dữ liệu đầu vào do người phát triển quản lý. Khi dùng nhiều công cụ, giữ cùng đặc tả giao tiếp và bộ kiểm chứng để đối chiếu kết quả.
- `configs/`: khi triển khai, đặt cấu hình theo tên công cụ/thiết kế; ghi top module, target, tùy chọn compiler, đường dẫn môi trường và phiên bản đã xác minh. Hiện chưa có cấu hình chạy.
- `scripts/`: khi triển khai, đặt adapter theo tên công cụ; adapter phải đưa mọi đầu ra vào thư mục run ở root `build/` và trả mã lỗi rõ ràng. Hiện chưa có lệnh sinh hệ thống cho dự án.

Các `.gitkeep` chỉ giữ thư mục trống trong Git. Đầu vào được quản lý trong Git; đầu ra sinh tự động đặt dưới root `build/`, đã được bỏ qua tại [.gitignore, dòng 2](../../.gitignore:2).

## D — Vận hành, kiểm chứng và tích hợp

1. Điền đặc tả: chức năng mong muốn, công cụ, cổng/giao tiếp, clock/reset, định dạng số, mục tiêu đo và điều kiện chấp nhận. Ô chưa rõ để `CHƯA XÁC ĐỊNH`, chưa coi là giả định thiết kế.
2. Chuẩn bị mã đầu vào trong `src/<tool>/`, rồi viết cấu hình và adapter cho công cụ được chọn. Có thể triển khai Intel HLS, Magma và Chisel song song; Halide/CoreIR có vùng đầu vào riêng.
3. Mỗi lần sinh hệ thống dùng `build/hardware/generation/runs/<run-id>/` mới. Quy ước `run-id`: thời gian UTC và mã phân biệt, ví dụ `YYYYMMDDTHHMMSSZ-<id>`. Lưu bản chụp đầu vào, checksum, phiên bản công cụ, lệnh/tùy chọn, log, trạng thái và đầu ra vào run; giữ cả run thất bại. Chưa có adapter thực thi quy ước này.
4. Kiểm chứng RTL/IP theo đặc tả trước khi tích hợp. Ghi số liệu đo, đơn vị, điều kiện đo và nguồn báo cáo; chưa có số liệu tài nguyên hoặc hiệu năng cho workspace mới.
5. Sau khi xem xét đầu ra, chọn phiên bản RTL/IP cần dùng và đăng ký nguồn/IP trong QSF/Qsys tương ứng. Build Quartus hiện chỉ gom `de1_soc`, `pin`, `qsys`; thêm thư mục này không tự đưa nó vào thiết kế đang build. [Nguồn: hardware/de1_soc/build.json, dòng 7–11](../de1_soc/build.json:7).

Nếu cần thay đổi cách gom nguồn của build Quartus, thực hiện thành bước tích hợp riêng sau khi có thiết kế và adapter đã kiểm chứng. Không chỉnh sửa trực tiếp đầu ra của run để thay đặc tả; thay mã/cấu hình đầu vào và sinh run mới.
