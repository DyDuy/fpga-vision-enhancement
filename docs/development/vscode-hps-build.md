# Build HPS Cortex-A9 trong VS Code

## A — Kiến trúc và luồng build

```text
VS Code (Windows hoặc Remote WSL)
  -> task HPS -> Bash/Python 3 trong Ubuntu -> chụp source + ghi phiên bản
  -> ARM Linux GCC biên dịch bản chụp
  -> build/hps/linux/runs/<UTC-timestamp>-<id>/{sources,logs,bin,run.json}
  -> cập nhật build/hps/linux/bin/vga_simple_display khi thành công
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

`CC` nhận tên hoặc đường dẫn một executable compiler, không nhận chuỗi nhiều cờ. Script dừng khi compiler sai target hoặc build lỗi; không chạy binary. Cờ `-g3 -O0` giữ thông tin debug và tắt tối ưu cho các tiện ích legacy. Bash gọi helper Python 3 standard library trong WSL, không cần cài thêm Python package. Nguồn: [entrypoint, dòng 11](../../software/hps/build.sh#L11), [flags, dòng 20](../../software/hps/build_run.py#L20), [kiểm tra compiler, dòng 213](../../software/hps/build_run.py#L213).

Mỗi lần build target hợp lệ tạo run mới trong `build/hps/linux/runs/`; đường dẫn run được in ở terminal. `sources/` giữ bản chụp C/header và script build, `logs/build.log` giữ cả stdout/stderr đồng thời hiển thị trực tiếp trong VS Code, `bin/` giữ ELF của run thành công. `run.json` schema version 1 ghi thời gian UTC bắt đầu/kết thúc, target, command argv/exit code, compiler flags/path/version/target, linker version nếu truy vấn được, Git HEAD/dirty/status, SHA-256 input/output và trạng thái `running`/`succeeded`/`failed`. Nguồn: [schema, dòng 93](../../software/hps/build_run.py#L93), [log, dòng 110](../../software/hps/build_run.py#L110), [command log, dòng 115](../../software/hps/build_run.py#L115), [snapshot, dòng 174](../../software/hps/build_run.py#L174), [Git, dòng 196](../../software/hps/build_run.py#L196), [toolchain, dòng 213](../../software/hps/build_run.py#L213), [finalize, dòng 293](../../software/hps/build_run.py#L293).

Task **Ctrl+Shift+B → HPS: build all** giữ nguyên cách dùng. Thành công mới cập nhật bản tiện dụng `build/hps/linux/bin/vga_simple_display`; compile lỗi giữ nguyên binary tốt trước đó và lưu run lỗi. Không xóa các run cũ. Nguồn: [tasks.json, task HPS](../../.vscode/tasks.json), [publication, dòng 262](../../software/hps/build_run.py#L262). Toàn bộ `build/` đã được ignore. Nguồn: [.gitignore, dòng 2](../../.gitignore).

Để IntelliSense đọc đúng header Linux, nhấn **F1 → WSL: Reopen Folder in WSL**, chọn Ubuntu; cài **C/C++** vào WSL nếu VS Code yêu cầu. Nguồn: [VS Code WSL, mục From VS Code và Managing extensions](https://code.visualstudio.com/docs/remote/wsl). Cấu hình `Linux` trỏ đến ARM GCC; `Win32` không truy vấn compiler Linux, nên có thể thiếu system header khi soạn trên Windows. Nguồn: [c_cpp_properties.json, dòng 4–25](../../.vscode/c_cpp_properties.json), [C++ settings reference, mục name và compilerPath](https://code.visualstudio.com/docs/cpp/customize-cpp-settings). Task build Windows vẫn gọi WSL.

## D — Điều kiện vận hành và giới hạn

Toolchain đang dùng libc cross 2.39 như bản ghi ở B. Chưa kiểm tra ảnh Linux trên board: binary động có thể yêu cầu symbol GLIBC mới mà ảnh DE1-SoC cũ không có. Trước khi chép, kiểm tra yêu cầu binary bằng `arm-linux-gnueabihf-readelf --version-info build/hps/linux/bin/vga_simple_display` trong WSL; trên board kiểm tra `getconf GNU_LIBC_VERSION` và ABI. Nếu không khớp, dùng toolchain/sysroot của ảnh board qua `CC` (wrapper compiler có thể đặt `--sysroot`), rồi sửa cấu hình IntelliSense tương ứng. Đây là giới hạn tương thích chưa xác minh; nguồn cơ chế: [GCC Directory Options, mục --sysroot](https://gcc.gnu.org/onlinedocs/gcc/Directory-Options.html), [ld.so, mục DESCRIPTION và LD_DEBUG/versions](https://man7.org/linux/man-pages/man8/ld.so.8.html).

Build thành công chỉ chứng minh compile/link; chưa chứng minh DMA, MMIO hay VGA chạy đúng. Chỉ chạy trên DE1-SoC có bitstream, địa chỉ, bridge và quyền `/dev/mem` phù hợp. Nguồn: [HPS README, điều kiện truy cập board](../../software/hps/README.md). Task không nạp FPGA hay deploy ứng dụng.

Run là phiên bản của lần build, không tự tạo Git commit. Hash trong `run.json` xác định byte source thực tế kể cả sửa đổi chưa commit; Git dirty/status chỉ là quan sát riêng. Lưu file trước khi build và tránh sửa source trong lúc chụp vì các file được sao chép lần lượt. Log này là log biên dịch, chưa thu log chương trình chạy trên board. Compiler/sysroot không được đóng gói cùng run. Đoạn commit cuối trong WSL/Linux hoãn SIGINT/SIGTERM; publish hoàn tất thì run giữ trạng thái thành công, ngắt trước đoạn đó giữ binary cũ và ghi thất bại. JSON và ELF được publish qua các thao tác riêng, nên kill cưỡng bức có thể làm hồ sơ cuối thiếu nhất quán. Thiếu Python 3 hoặc quyền ghi `build/` cũng có thể khiến hồ sơ không tạo được. Nguồn: [snapshot, dòng 174](../../software/hps/build_run.py#L174), [Git identity, dòng 196](../../software/hps/build_run.py#L196), [commit boundary, dòng 262](../../software/hps/build_run.py#L262), [luồng build và xử lý lỗi, dòng 312](../../software/hps/build_run.py#L312).

Target `all` hiện chỉ build `vga_simple_display`. Mã nguồn `memory_benchmark.c` không còn trong cây source; binary lịch sử nếu còn trên máy được giữ lại, không thể build lại từ source hiện tại. Lệnh yêu cầu `memory_benchmark` trả lỗi thiếu source. Nguồn: [target registry, dòng 18](../../software/hps/build_run.py#L18), [target validation, dòng 62](../../software/hps/build_run.py#L62), [manifest lịch sử, bản ghi memory_benchmark](../../build/archive/restructure-20261004.json). Không đo hiệu năng phần cứng ở bước này.
