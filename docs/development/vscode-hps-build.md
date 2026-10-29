# HPS Cortex-A9 build in VS Code

## A — Build architecture and flow

```text
VS Code (Windows or Remote WSL)
  -> HPS task -> Bash/Python 3 in Ubuntu -> source snapshot and provenance
  -> ARM Linux GCC compiles the snapshot
  -> build/hps/linux/runs/<UTC-timestamp>-<id>/{sources,logs,bin,run.json}
  -> build/hps/linux/bin/vga_simple_display is updated after success
  -> ABI/library checks on the DE1-SoC before copying or running
```

Scope: the current HPS Linux application `vga_simple_display`. It uses `/dev/mem` and therefore requires a compatible FPGA design and bridge configuration. See the [HPS README](../../software/hps/README.md) and the [address contract](../../software/hps/include/hps_fpga_addresses.h#L5-L13).

## B — Toolchain and reference environment

The local check recorded on 2026-10-03 used `wsl.exe -d Ubuntu --exec bash -c 'id -un; cat /etc/os-release'`: user `duy_khanh`, Ubuntu 24.04.4 LTS. `command -v arm-linux-gnueabihf-gcc` returned `/usr/bin/arm-linux-gnueabihf-gcc`; GCC was 13.3.0, binutils was 2.42, and `libc6-dev-armhf-cross` was `2.39-0ubuntu8cross1`. The VS Code CLI confirmed WSL extension 0.104.3.

The packages were installed with the following command. APT returned exit code 0. The Ubuntu archive index succeeded over IPv4; the security repository and deadsnakes PPA reported DNS errors and used their previous indexes. Existing packages were not upgraded.

```powershell
wsl.exe -d Ubuntu -u root --exec env DEBIAN_FRONTEND=noninteractive apt-get -o Acquire::ForceIPv4=true --yes --no-install-recommends install gcc-arm-linux-gnueabihf binutils-arm-linux-gnueabihf libc6-dev-armhf-cross
```

The design uses a Linux hard-float compiler for the cross-build. `-mcpu=cortex-a9 -mfpu=vfpv3-d16 -mfloat-abi=hard` selects the CPU, FPU, and ABI; hard-float requires libraries built for the same ABI. See the [GCC ARM options](https://gcc.gnu.org/onlinedocs/gcc/ARM-Options.html).

## C — Configuration and build

Open the complete project directory in VS Code and press **Ctrl+Shift+B**; the default task is `HPS: build all`. Use **Terminal → Run Task** to build `vga_simple_display` alone. The task definitions are in [tasks.json](../../.vscode/tasks.json).

Equivalent PowerShell command:

```powershell
wsl.exe -d Ubuntu --cd "C:\Users\Duy Khanh\OneDrive\Desktop\Research\fpga-vision-enhancement" --exec bash software/hps/build.sh all
```

From a Linux or Remote WSL terminal at the repository root:

```bash
bash software/hps/build.sh all
bash software/hps/build.sh vga_simple_display
# Select a hard-float ARM Linux compiler compatible with the board image:
CC=/path/to/arm-linux-gnueabihf-gcc bash software/hps/build.sh all
```

`CC` accepts the name or path of one executable compiler; it does not accept a string containing multiple flags. The script stops on a wrong-target compiler or build failure and does not run the binary. The `-g3 -O0` flags retain debug information and disable optimization for the legacy utility. Bash calls the Python 3 standard library helper in WSL and does not require extra Python packages.

Every valid target creates a new run under `build/hps/linux/runs/`; the path is printed in the terminal. `sources/` contains a snapshot of C, headers, and build scripts. `logs/build.log` captures stdout and stderr while they are shown in VS Code. `bin/` contains the successful run's ELF. `run.json`, schema version 1, records UTC start/end, target, command arguments and exit code, compiler flags/path/version/target, linker version when available, Git HEAD/dirty status, input/output SHA-256, and `running`/`succeeded`/`failed` status.

The **Ctrl+Shift+B → HPS: build all** workflow is unchanged. Only a successful build updates the convenience binary `build/hps/linux/bin/vga_simple_display`; a failed compile preserves the previous good binary and stores the failed run. Older runs are not deleted. The entire `build/` tree is ignored by Git.

For correct Linux IntelliSense, use **F1 → WSL: Reopen Folder in WSL** and select Ubuntu; install the **C/C++** extension in WSL if prompted. The `Linux` configuration points to ARM GCC. `Win32` does not query the Linux compiler and may therefore lack system headers while editing on Windows. Windows build tasks still call WSL.

## D — Operating conditions and limitations

The toolchain currently uses cross libc 2.39. The board Linux image has not been checked: a dynamically linked binary may require newer GLIBC symbols than the old DE1-SoC image provides. Before copying the binary, inspect it in WSL with `arm-linux-gnueabihf-readelf --version-info build/hps/linux/bin/vga_simple_display`; on the board, inspect `getconf GNU_LIBC_VERSION` and the ABI. If they do not match, use the board image's compiler/sysroot through `CC` and update IntelliSense accordingly. See [GCC `--sysroot`](https://gcc.gnu.org/onlinedocs/gcc/Directory-Options.html) and [ld.so version diagnostics](https://man7.org/linux/man-pages/man8/ld.so.8.html).

A successful build proves only compilation and linking. It does not prove DMA, MMIO, or VGA operation. Run the program only on a DE1-SoC with a compatible bitstream, addresses, bridges, and `/dev/mem` permissions. The task does not program the FPGA or deploy the application.

A run identifies one build, not a Git commit. Hashes in `run.json` identify the actual copied source bytes, including uncommitted changes; Git dirty/status is a separate observation. Save files before building and avoid editing sources while they are being copied. The log is a compiler log, not board application runtime output. Compiler libraries and sysroot are not packaged in the run. The final publication step defers SIGINT/SIGTERM; an interruption before publication preserves the old binary and records failure. JSON and ELF publication are separate operations, so forced termination can leave incomplete final evidence. Python 3 and write access to `build/` are prerequisites.

The `all` target currently builds only `vga_simple_display`. `memory_benchmark.c` is absent from the source tree; any historical binary is not reproducible from current source. An explicit `memory_benchmark` request fails with a missing-source message. No hardware performance measurement is performed by this build step.
