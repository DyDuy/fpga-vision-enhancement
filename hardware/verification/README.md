# Hardware verification

## A. Tổ chức và luồng sử dụng

Thư mục này tiếp nhận bộ thử nghiệm cũ từ `C:\LuanVan_SoC\Test` dưới dạng bản sao có nguồn gốc, tách mã ứng viên, dữ liệu đầu vào và đầu ra cũ. Đợt `intake-20261004` đã sao chép **74 file, 40.417.063 byte**; danh sách đường dẫn và SHA256 từng file nằm trong [manifest.json, mục `inventory` dòng 8 và `files` dòng 63](intake-20261004/manifest.json). Bản gốc được giữ tại vị trí cũ; phạm vi kiểm tra tính toàn vẹn được ghi ở [`original_preservation`, dòng 16](intake-20261004/manifest.json).

```text
hardware/verification/
├── README.md
├── intake-20261004/
│   ├── manifest.json
│   ├── candidate_snapshot/
│   │   ├── sim/                 testbench ứng viên từ Test
│   │   ├── rtl/                 RTL và khai báo IP ứng viên từ Test
│   │   └── fixtures/            input_image.hex và hai ROM HEX gốc
│   ├── legacy/15x15/rtl/        biến thể RTL 15×15 và bản .bak
│   ├── legacy/backup/           các bản sao lưu khác
│   ├── tools/legacy-image/      script chuyển ảnh/HEX và SSIM cũ
│   ├── experiments/legacy-dhbf/ script thí nghiệm ảnh cũ
│   ├── results/legacy/          ảnh và output_image.hex đã có từ Test
│   └── archive/
│       ├── simulator-projects/  ba file ModelSim .mpf
│       ├── simulator-state/     transcript, waveform và thư viện work/
│       └── unrelated/           d.py, testAI chưa tích hợp
└── runs/                       workspace cho các run tương lai, Git ignore
```

`runs/` là quy ước cho bước tích hợp sau, chưa có launcher hoặc run mô phỏng được xác thực. Cách phân nhóm từng file có thể kiểm chứng tại [`manifest.json`, mục `files`, dòng 63](intake-20261004/manifest.json).

## B. Nguồn thiết kế và ranh giới phiên bản

Thiết kế Quartus hiện hành tiếp tục sử dụng `hardware/de1_soc`, `hardware/pin` và `hardware/qsys`; cấu hình staging hiện chỉ liệt kê ba thư mục đó trong [build.json, `stage_directories`, dòng 7](../de1_soc/build.json). Intake này không thay RTL/LUT của thiết kế hiện hành.

RTL, ROM gamma và ROM transmission từ Test có SHA256 khác các file cùng tên tại `hardware/de1_soc`; phép so sánh byte được ghi tại [`canonical_comparisons`, dòng 24](intake-20261004/manifest.json). Khác hash không chứng minh khác chức năng. `candidate_snapshot` giữ nguyên bộ Test để đối chiếu riêng, chưa được xem là regression test của thiết kế hiện hành.

File legacy có tên `dehazing_system_tb.v` thực tế khai báo `module dehazing_system_top` và chứa khối 15×15; xem [legacy RTL, dòng 9 và 34](intake-20261004/legacy/15x15/rtl/dehazing_system_tb.v). RTL ứng viên cũng khai báo cùng tên module tại [candidate RTL, dòng 3](intake-20261004/candidate_snapshot/rtl/dehazing_system_top.v). Khi tích hợp mô phỏng, chọn một biến thể DUT cụ thể; compile tất cả `.v` có thể gây trùng module.

## C. Dữ liệu bất biến và workspace mô phỏng

Các file nhập được sao chép nguyên byte, giữ nguyên tên, phần mở rộng và nội dung script. Quy tắc hẹp `-text -eol` cho intake trong [.gitattributes, dòng 22](../../.gitattributes) giữ line ending và checksum qua Git, không chuẩn hóa các snapshot đã nhập. Trong đợt tổ chức này, **không chạy mã nhập, không mô phỏng và không compile FPGA**; xem [`validation_scope`, dòng 62](intake-20261004/manifest.json).

Testbench đọc `input_image.hex` và ghi `output_image.hex` bằng tên tương đối ở [dòng 38–39](intake-20261004/candidate_snapshot/sim/dehazing_system_testbench.v). Candidate RTL đọc hai ROM bằng `$readmemh` tại [dòng 182 và 308](intake-20261004/candidate_snapshot/rtl/dehazing_system_top.v). Vì vậy, bước tích hợp tương lai phải:

1. Tạo workspace riêng trong `hardware/verification/runs/<run-id>/`.
2. Sao chép ba fixture đầu vào từ `candidate_snapshot/fixtures/` vào workspace đó.
3. Chọn đúng candidate RTL và testbench; chạy simulator với thư mục làm việc là workspace, lưu mọi đầu ra/log ở đó.
4. Giữ fixture và `results/legacy/` nguyên trạng; không chạy simulator trong thư mục fixture hoặc dùng output cũ làm golden reference khi chưa kiểm chứng.

Đây là yêu cầu bố trí dữ liệu cho lần tích hợp sau, chưa phải hướng dẫn lệnh simulator đã kiểm nghiệm.

## D. Giới hạn, lưu trữ và Git

- Testbench có thông báo delay `1943` tại [dòng 36 và 68](intake-20261004/candidate_snapshot/sim/dehazing_system_testbench.v), nhưng chờ `1291` chu kỳ tại dòng 69; RTL ứng viên ghi `TOTAL_DELAY = 11` tại [dòng 38](intake-20261004/candidate_snapshot/rtl/dehazing_system_top.v). Testbench hiện thu ảnh, chưa có scoreboard/assertion kiểm chứng kết quả; xem toàn bộ [testbench, dòng 1–92](intake-20261004/candidate_snapshot/sim/dehazing_system_testbench.v). Cần rà soát trước khi dùng để kết luận tính đúng của pipeline.
- Python giữ các đường dẫn tuyệt đối cũ: generator tham chiếu `test36.jpg` ở [Chuyen_anh_sang_hex.py, dòng 5](intake-20261004/tools/legacy-image/Chuyen_anh_sang_hex.py), SSIM tham chiếu `test24.jpg` ở [SSIM.py, dòng 32–33](intake-20261004/tools/legacy-image/SSIM.py). Các ảnh gốc này không có trong inventory nhập; đối chiếu [`files`, dòng 63](intake-20261004/manifest.json). Chưa đủ provenance để khẳng định ảnh/HEX kết quả là ground truth hoặc công bố metrics từ bộ này. Script cần điều chỉnh đường dẫn trong bản làm việc riêng khi tích hợp.
- Các `.mpf` vẫn trỏ `C:/LuanVan_SoC/Test/...`; ví dụ [dehazing_system_tb.mpf, dòng 414–422](intake-20261004/archive/simulator-projects/dehazing_system_tb.mpf). Chúng được giữ làm lịch sử, chưa được chuyển thành project chạy từ đường dẫn mới.
- `power_analysis.vcd` **34.308.594.715 byte** không sao chép hoặc hash; vẫn ở `C:\LuanVan_SoC\Test\power_analysis.vcd`. Manifest ghi đường dẫn, kích thước, mốc sửa đổi và giới hạn chỉ kiểm tra metadata tại [`excluded_files`, dòng 50](intake-20261004/manifest.json). Điều này tránh nhân đôi waveform lớn trong repo; file gốc vẫn được giữ.
- Source ứng viên, fixture đầu vào, script nghiên cứu, manifest và README được phép đưa vào Git. Đầu ra lịch sử, archive, backup và run mới được ignore bằng các quy tắc riêng trong [.gitignore, mục `Verification intake`](../../.gitignore); các quy tắc `.bak`, `.mpf`, `.wlf`, `work/` hiện có vẫn áp dụng. Việc tổ chức chưa tạo commit hoặc push.

SHA256 chỉ kiểm chứng bản sao bằng dữ liệu đầu vào của intake, không thay thế xác thực thuật toán, giao thức stream, timing hoặc hoạt động board. Giới hạn này được ghi tại [`validation_scope`, dòng 62](intake-20261004/manifest.json).
