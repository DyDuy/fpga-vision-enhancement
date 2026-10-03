# Build HPS Cortex-A9 trong VS Code

## A — Kiến trúc và luồng build

```text
VS Code (Windows hoặc Remote WSL)
  -> task HPS -> Bash trong Ubuntu -> ARM Linux GCC
  -> build/hps/linux/bin/vga_simple_display
  -> kiểm tra ABI/thư viện trên DE1-SoC trước khi chép/chạy
```

Phạm vi: ứng dụng Linux `vga_simple_display` hiện có của HPS; ứng dụng dùng `/dev/mem`, cần FPGA và bridge phù hợp. Nguồn: [HPS README, phần mô tả và lệnh build](../../software/hps/README.md), [hợp đồng địa chỉ, dòng 5–13](../../software/hps/include/hps_fpga_addresses.h).

## B — Toolchain và nguồn tham chiếu

Bản ghi kiểm tra tại máy ngày 2026-10-03: `wsl.exe -d Ubuntu --exec bash -c 'id -un; cat /etc/os-release'` cho user `duy_khanh`, Ubuntu 24.04.4 LTS. `command -v arm-linux-gnueabihf-gcc` cho `/usr/bin/arm-linux-gnueabihf-gcc`; `--version` cho GCC 13.3.0; `arm-linux-gnueabihf-ld --version` cho binutils 2.42. `dpkg-query -W libc6-dev-armhf-cross` cho `2.39-0ubuntu8cross1`. CLI VS Code xác nhận cài WSL extension `0.104.3`.

Đã cài bằng lệnh dưới đây; apt trả exit 0. Cập nhật index bằng IPv4 thành công với kho archive Ubuntu; kho security và PPA deadsnakes báo lỗi DNS và dùng index cũ. Không nâng cấp các gói sẵn có.

```powershell
wsl.exe -d Ubuntu -u root --exec env DEBIAN_FRONTEND=noninteractive apt-get -o Acquire::ForceIPv4=true --yes --no-install-recommends install gcc-arm-linux-gnueabihf binutils-arm-linux-gnueabihf libc6-dev-armhf-cross
```

Thiết kế dùng compiler Linux hard-float theo yêu cầu cross build trong [HPS README, yêu cầu cross-compiler](../../software/hps/README.md). Các cờ `-mcpu=cortex-a9 -mfpu=vfpv3-d16 -mfloat-abi=hard` chỉ định CPU, FPU và ABI; hard-float cần thư viện cùng ABI. Nguồn: [GCC ARM Options, mục -mcpu, -mfpu, -mfloat-abi](https://gcc.gnu.org/onlinedocs/gcc/ARM-Options.html).

## C — Cấu hình và cách build

Mở toàn bộ thư mục dự án trong VS Code, lưu mã, nhấn **Ctrl+Shift+B**: task mặc định `HPS: build all`. Chọn **Terminal → Run Task** để build riêng `vga_simple_display`. Cấu hình: [tasks.json](../../.vscode/tasks.json). Nguồn cơ chế: [VS Code Tasks, mục Custom tasks và Operating system specific properties](https://code.visualstudio.com/docs/debugtest/tasks).

Lệnh tương đương trong PowerShell:

```powershell
wsl.exe -d Ubuntu --cd "C:\Users\Duy Khanh\OneDrive\Desktop\Research\fpga-vision-enhancement" --exec bash software/hps/build.sh all
```

Trong terminal Linux/Remote WSL tại thư mục dự án:

```bash
bash software/hps/build.sh all
bash software/hps/build.sh vga_simple_display
# Đổi sang compiler ARM Linux hard-float phù hợp ảnh Linux của board:
CC=/path/to/arm-linux-gnueabihf-gcc bash software/hps/build.sh all
```

`CC` nhận tên hoặc đường dẫn một executable compiler, không nhận chuỗi nhiều cờ. Script dừng khi compiler sai target hoặc build lỗi; không chạy binary. Cờ `-g3 -O0` giữ thông tin debug và tắt tối ưu cho các tiện ích legacy. Nguồn: [build.sh, kiểm tra compiler và vòng lặp build](../../software/hps/build.sh). Kết quả lưu vào `build/hps/linux/bin/vga_simple_display`; thư mục `build/` đã được ignore. Nguồn: [script, thư mục và đường dẫn đầu ra](../../software/hps/build.sh), [.gitignore, dòng 2](../../.gitignore).

Để IntelliSense đọc đúng header Linux, nhấn **F1 → WSL: Reopen Folder in WSL**, chọn Ubuntu; cài **C/C++** vào WSL nếu VS Code yêu cầu. Nguồn: [VS Code WSL, mục From VS Code và Managing extensions](https://code.visualstudio.com/docs/remote/wsl). Cấu hình `Linux` trỏ đến ARM GCC; `Win32` không truy vấn compiler Linux, nên có thể thiếu system header khi soạn trên Windows. Nguồn: [c_cpp_properties.json, dòng 4–25](../../.vscode/c_cpp_properties.json), [C++ settings reference, mục name và compilerPath](https://code.visualstudio.com/docs/cpp/customize-cpp-settings). Task build Windows vẫn gọi WSL.

## D — Điều kiện vận hành và giới hạn

Toolchain đang dùng libc cross 2.39 như bản ghi ở B. Chưa kiểm tra ảnh Linux trên board: binary động có thể yêu cầu symbol GLIBC mới mà ảnh DE1-SoC cũ không có. Trước khi chép, kiểm tra yêu cầu binary bằng `arm-linux-gnueabihf-readelf --version-info build/hps/linux/bin/vga_simple_display` trong WSL; trên board kiểm tra `getconf GNU_LIBC_VERSION` và ABI. Nếu không khớp, dùng toolchain/sysroot của ảnh board qua `CC` (wrapper compiler có thể đặt `--sysroot`), rồi sửa cấu hình IntelliSense tương ứng. Đây là giới hạn tương thích chưa xác minh; nguồn cơ chế: [GCC Directory Options, mục --sysroot](https://gcc.gnu.org/onlinedocs/gcc/Directory-Options.html), [ld.so, mục DESCRIPTION và LD_DEBUG/versions](https://man7.org/linux/man-pages/man8/ld.so.8.html).

Build thành công chỉ chứng minh compile/link; chưa chứng minh DMA, MMIO hay VGA chạy đúng. Chỉ chạy trên DE1-SoC có bitstream, địa chỉ, bridge và quyền `/dev/mem` phù hợp. Nguồn: [HPS README, điều kiện truy cập board](../../software/hps/README.md). Task không nạp FPGA hay deploy ứng dụng.

Target `all` hiện chỉ build `vga_simple_display`. Mã nguồn `memory_benchmark.c` không còn trong cây source; binary đã chuyển sang `build/hps/linux/bin/memory_benchmark` là đầu ra lịch sử được giữ lại, không thể build lại từ source hiện tại. Lệnh yêu cầu `memory_benchmark` trả lỗi thiếu source. Nguồn: [build.sh, target registry](../../software/hps/build.sh), [manifest, bản ghi memory_benchmark](../../build/archive/restructure-20261004.json). Không đo hiệu năng phần cứng ở bước này.
