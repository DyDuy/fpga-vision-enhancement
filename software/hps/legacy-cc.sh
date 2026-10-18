#!/usr/bin/env bash
# Native x86 cross-compiler programs; headers, target CRT and runtime from SDK.
set -euo pipefail
sdk="${DE1_SDK:-$HOME/.local/share/de1-sdk/linaro-12.11-armhf}"
if [[ ! -f "$sdk/SDK_MANIFEST.sha256" || ! -d "$sdk/usr/include" ]]; then
    printf 'Legacy SDK missing: %s; see software/hps/README_REMOTE.md\n' "$sdk" >&2
    exit 2
fi
compiler="$(command -v arm-linux-gnueabihf-gcc)" || {
    printf 'Missing host arm-linux-gnueabihf-gcc; no compiler installed by this wrapper.\n' >&2
    exit 2
}
internal_include="$("$compiler" -print-file-name=include)"
[[ -d "$internal_include" ]] || { printf 'Compiler internal include directory missing.\n' >&2; exit 2; }
# Do not -B the SDK's GCC directory: its cc1 is an ARM executable.
exec "$compiler" --sysroot="$sdk" -B"$sdk/usr/lib/arm-linux-gnueabihf/" \
    -nostdinc -isystem "$internal_include" \
    -isystem "$sdk/usr/include/arm-linux-gnueabihf" -isystem "$sdk/usr/include" \
    -U_TIME_BITS -no-pie \
    "-Wl,-rpath-link,$sdk/lib/arm-linux-gnueabihf" \
    "-Wl,-rpath-link,$sdk/usr/lib/arm-linux-gnueabihf" "$@"

