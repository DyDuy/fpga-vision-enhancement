# Build C trên PC, đưa sang DE1-SoC và chạy từ terminal

## A. Luồng sử dụng

Workflow dành cho ứng dụng C hiện có `vga_simple_display`. Trong VSCode, **Ctrl+Shift+B** chọn task mới **DE1: build validated for Linaro**. Visual Studio có thể mở thư mục dự án rồi dùng terminal PowerShell với cùng lệnh bên dưới. Các task HPS cũ vẫn gọi builder trực tiếp; lệnh `de1` bổ sung SDK và kiểm tra ELF. Nguồn: [tasks.json](../../.vscode/tasks.json), các task `DE1:`; [de1.py](de1.py), `build_checked`.

~~~text
VSCode / Visual Studio (PC)
        |
        v
Ubuntu WSL: cross GCC + SDK Linaro lưu trên PC
        |
        v
BuildRun lưu mã nguồn + ELF -> kiểm tra ARMhf / GLIBC / thư viện
        |
        v
SSH + SCP -> ~/de1-releases/<UTC-id> mới -> kiểm tra SHA256
        |
        +--> chỉ lưu release
        +--> chạy trên board khi có --run và ảnh hợp lệ
~~~

SDK mặc định là `~/.local/share/de1-sdk/linaro-12.11-armhf` trong **Ubuntu WSL**. Snapshot SDK đã đối chiếu thành công 3.708 file thường; còn 571 symlink sau 8 loại trừ chính xác và 19 chuyển đổi đường dẫn trong SDK local. Nguồn SD chỉ được đọc; xem [hồ sơ SDK, dòng 30–31](<C:/Users/Duy Khanh/Documents/ChatGPT/thẻ SD/evidence/de1-sdk-snapshot.txt:30>). Không cần cắm thẻ SD để build từ bản SDK này. Có thể đổi bằng biến môi trường WSL `DE1_SDK`. Mỗi lần chạy kiểm tra nội dung theo `SDK_MANIFEST.sha256`, symlink theo `SDK_SYMLINKS.tsv` và lưu các bản ghi cùng workflow; bản gốc trước khi chuyển symlink được giữ trong `SDK_SYMLINKS_ORIGINAL.tsv` khi có. Nguồn/cách sao chép và lý do loại symlink nằm trong `SDK_INFO.txt` cùng `SDK_EXCLUDED_SYMLINKS.tsv` của SDK; logic kiểm tra lúc build tại [de1.py](de1.py), `verify_sdk`.

## B. Nền tảng và giới hạn

Compiler chạy trên PC; header C, CRT và thư viện liên kết lấy từ SDK cũ. [legacy-cc.sh](legacy-cc.sh) dùng `--sysroot`, `-nostdinc`, `-isystem` và `-B` đến thư mục CRT; không trỏ `-B` đến thư mục chứa `cc1` ARM. Ý nghĩa: [GCC, “Options for Directory Search”, các mục `-nostdinc`, `-B`, `--sysroot`](https://gcc.gnu.org/onlinedocs/gcc/Directory-Options.html).

Kiểm tra tĩnh yêu cầu ELF32 ARM, ABI truyền tham số VFP, loader ARMhf của SDK, yêu cầu GLIBC không vượt 2.15 và toàn bộ tên thư viện `NEEDED` tìm thấy trong SDK. Đây là điều kiện chặn lỗi ABI phổ biến; chưa chứng minh chương trình hoạt động với kernel, thanh ghi và bitstream thực tế. Không chạy ứng dụng phần cứng trong WSL hoặc QEMU. Nguồn: [de1.py](de1.py), `check_elf`; [vga_simple_display.c](src/vga_simple_display.c), `main`.

Phạm vi hiện tại là **C**; chưa thiết lập cross G++ cho C++. Workflow gọi builder hiện có và giữ nguyên cờ Cortex-A9/VFPv3-D16/hard-float, C và RTL. Địa chỉ/stride lấy từ [hps_fpga_addresses.h](include/hps_fpga_addresses.h) và [vga_simple_display.c](src/vga_simple_display.c), vòng ghi pixel với stride 1024.

Để mở VSCode trong WSL, vào thư mục dự án bằng terminal Ubuntu rồi gõ `code .`; xem [VSCode, “Run VS Code in WSL”](https://code.visualstudio.com/docs/cpp/config-wsl#_run-vs-code-in-wsl). Build dùng task riêng của dự án. Không cần cài VSCode Server lên Linux cũ của DE1; hướng dẫn này chưa cấu hình IntelliSense hoặc debugger từ xa.

## C. Cấu hình và lệnh

Từ **thư mục gốc dự án**, dùng VSCode hoặc terminal PowerShell của Visual Studio:

~~~powershell
# Build và kiểm tra ELF của đúng run vừa tạo
.\software\hps\de1.ps1 build

# Chỉ kiểm tra lại build/hps/linux/bin/vga_simple_display
.\software\hps\de1.ps1 check

# Một lần; sau đó sửa JSON bằng editor
Copy-Item software/hps/de1.config.example.json software/hps/de1.local.json
~~~

Điền `host`, `user`, `port` bằng thông tin thật của board. `host` nhận SSH alias, DNS hoặc IPv4; nếu alias WSL đã khai báo User, có thể để `user` trống. `port` là số nguyên 1–65535. Không hỗ trợ chuỗi lệnh hoặc IPv6 trong trường host. File local được Git bỏ qua. Chưa có endpoint thì `push` dừng ngay, không build hoặc thử SSH. Nguồn: [de1.config.example.json](de1.config.example.json); [de1.py](de1.py), `read_config`, `main`; [.gitignore](../../.gitignore).

SSH/scp chạy trong **Ubuntu WSL**, nên alias, key và known_hosts dùng `~/.ssh` của Ubuntu, không tự lấy cấu hình Windows. Trước lần push đầu, tự kết nối SSH từ terminal Ubuntu đến endpoint thật và kiểm chứng fingerprint board qua kênh đáng tin. Workflow giữ `StrictHostKeyChecking=yes`, không tự nhận host key mới; xem [OpenSSH, ssh_config(5), mục “StrictHostKeyChecking”](https://man.openbsd.org/ssh_config.5#StrictHostKeyChecking). Nếu server cũ không thương lượng được thuật toán, xử lý riêng cho alias sau khi xem lỗi, không bật thuật toán cũ toàn cục.

~~~powershell
# Build + kiểm tra + upload vào release mới, chưa chạy
.\software\hps\de1.ps1 push

# Build + upload + kiểm tra hash + chạy với ảnh hợp lệ
.\software\hps\de1.ps1 push --run 'C:\duong dan co dau\input_image.hex'

# Đường dẫn tương đối tính từ gốc dự án
.\software\hps\de1.ps1 push --run 'data/input_image.hex'
~~~

Trong Ubuntu WSL:

~~~bash
bash software/hps/de1.sh build
bash software/hps/de1.sh check
bash software/hps/de1.sh push
bash software/hps/de1.sh push --run '/mnt/c/duong dan co dau/input_image.hex'
~~~

PowerShell launcher chuyển đường dẫn Windows tuyệt đối của ảnh/ELF bằng `wslpath`; đường dẫn tương đối luôn tính từ gốc dự án, kể cả khi gọi launcher từ thư mục khác. Đặt đường dẫn có khoảng trắng trong dấu nháy. VSCode có thêm task **DE1: push new release** và **DE1: push and run RGB24 image**; task thứ hai hỏi đường dẫn ảnh. Nguồn: [de1.ps1](de1.ps1); [de1.sh](de1.sh); [tasks.json](../../.vscode/tasks.json), input `de1Rgb24Input`.

Ảnh là text ASCII gồm đúng **307200 token hex RGB24** cho ảnh 640×480; mỗi token 0–FFFFFF, có thể có tiền tố 0x; file không quá 8 MiB. Wrapper đóng băng bản sao và kiểm tra trước khi build/kết nối. Đây không phải PNG/JPEG. Nguồn định dạng: [vga_simple_display.c](src/vga_simple_display.c), vòng `fscanf("%x", ...)`; ràng buộc wrapper: [de1.py](de1.py), `validate_image`, `main`.

Mỗi push tạo release mới dưới home tài khoản SSH. Truyền file dùng `scp -O` để chọn SCP cũ; xem [OpenSSH, scp(1), mục “-O” và “CAVEATS”](https://man.openbsd.org/scp.1#O). Chỉ sau khi `sha256sum -c SHA256SUMS` trên board thành công mới chạy. Tên file phía board cố định, không chèn đường dẫn ảnh người dùng vào shell từ xa. Nguồn: [de1.py](de1.py), `deploy`.

## D. Vận hành và truy vết

Ứng dụng mở `/dev/mem`, ghi framebuffer, cấu hình DMA và giữ tiến trình trong vòng lặp vô hạn. Chỉ dùng `--run` khi bitstream/bridge khớp [hps_fpga_addresses.h](include/hps_fpga_addresses.h) và tài khoản được phép truy cập /dev/mem. Workflow không gọi sudo. Dùng Ctrl+C để ngắt phiên chạy; nếu SSH rớt, kiểm tra tiến trình trên board trước khi chạy lại. Chưa có board nên chưa xác minh ảnh VGA hoặc hành vi khi mất kết nối. Nguồn: [vga_simple_display.c](src/vga_simple_display.c), `open`, các vùng `mmap`, cấu hình pixel DMA và `while(1)`; [de1.py](de1.py), `deploy`.

Terminal in `DE1 workflow: ...`. Trong `build/hps/remote/runs/<UTC-id>/`:

- `workflow.json` lưu lệnh, exit code, hash helper/SDK/ELF và đường dẫn BuildRun.
- Snapshot helper/manifest SDK và log từng bước: `build.log`, `check-*.log`, `upload.log`, `remote-verify.log`, `run.log` khi bước đó thực sự chạy.
- `release/` chứa ELF, ảnh đã đóng băng nếu có, `release.json`, `SHA256SUMS`.

Builder cũ vẫn lưu mã nguồn snapshot và nhật ký tại `build/hps/linux/runs/`; workflow chọn ELF đúng run đó, đối chiếu hash trước upload. Stdout/stderr hiển thị đồng thời gộp vào log; lỗi build, SCP, hash hoặc run trả exit code khác 0. Nguồn: [de1.py](de1.py), `Session`, `build_checked`, `deploy`; [build_run.py](build_run.py), `BuildRun`.

Kiểm tra offline: `python3 -m unittest discover -s software/hps -p test_de1.py` trong WSL; các fixture tại [test_de1.py](test_de1.py) không kết nối board. Build và check bằng PowerShell đã PASS exit 0 với `vga_simple_display`; xem [log, dòng 6 và 8](<C:/Users/Duy Khanh/Documents/ChatGPT/thẻ SD/evidence/de1-remote-workflow-tests.txt:6>). Chương trình C/stdio nhỏ PASS trên QEMU Cortex-A9 ([log, dòng 9](<C:/Users/Duy Khanh/Documents/ChatGPT/thẻ SD/evidence/de1-remote-workflow-tests.txt:9>)); mock và smoke này không chứng minh chạy phần cứng. Chưa có endpoint nên chưa push/run thật. SDK PASS không chứng nhận toàn thẻ: đã có lỗi metadata ext4 ngoài các cây SDK và chưa sửa filesystem ([hồ sơ SDK, dòng 33](<C:/Users/Duy Khanh/Documents/ChatGPT/thẻ SD/evidence/de1-sdk-snapshot.txt:33>)).

