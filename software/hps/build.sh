#!/usr/bin/env bash
# Cross-build only: the legacy apps access board MMIO and must never run here.
set -euo pipefail

repo_root="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/../.." && pwd)"
cd -- "$repo_root"

if (( $# > 1 )); then
    printf 'Usage: bash software/hps/build.sh [all|vga_simple_display]\n' >&2
    exit 2
fi

case "${1:-all}" in
    all) apps=(vga_simple_display) ;;
    vga_simple_display) apps=("$1") ;;
    memory_benchmark)
        printf 'Unsupported app: memory_benchmark source software/hps/src/memory_benchmark.c is absent; retained binary is historical.\n' >&2
        exit 2
        ;;
    *)
        printf 'Unknown app: %s\n' "$1" >&2
        exit 2
        ;;
esac

compiler="${CC:-arm-linux-gnueabihf-gcc}"
if ! command -v "$compiler" >/dev/null 2>&1; then
    printf 'ARM Linux compiler not found: %s\n' "$compiler" >&2
    printf 'Install gcc-arm-linux-gnueabihf and libc6-dev-armhf-cross in WSL Ubuntu.\n' >&2
    exit 1
fi

# Reject a host or bare-metal compiler before creating misleading ARM artifacts.
case "$("$compiler" -dumpmachine)" in
    arm*-linux-gnueabihf) ;;
    *)
        printf 'CC must be an ARM Linux hard-float compiler, got: %s\n' "$compiler" >&2
        exit 1
        ;;
esac

mkdir -p build/hps/linux/bin
# Keep optimization disabled for these legacy utilities; no benchmark claim is
# made by this build. Hard-float must match the target Linux libraries.
flags=(-std=gnu11 -Wall -Wextra -g3 -O0 -mcpu=cortex-a9
       -mfpu=vfpv3-d16 -mfloat-abi=hard -Isoftware/hps/include)

for app in "${apps[@]}"; do
    printf 'Building %s with %s\n' "$app" "$compiler"
    "$compiler" "${flags[@]}" "software/hps/src/$app.c" -o "build/hps/linux/bin/$app"
    printf 'Built %s/build/hps/linux/bin/%s\n' "$repo_root" "$app"
done
