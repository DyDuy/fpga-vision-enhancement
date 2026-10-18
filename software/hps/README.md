# HPS Linux utilities (legacy intake)

Sources preserve legacy behavior. `vga_simple_display` maps SDRAM through the heavyweight bridge and Pixel DMA registers through the lightweight bridge. Requires DE1-SoC Linux, matching FPGA configuration, enabled bridges and permission to access `/dev/mem`; never run on an unrelated host.

```sh
bash software/hps/build.sh all
# Latest successful binary: build/hps/linux/bin/vga_simple_display
# Per-build evidence: build/hps/linux/runs/<UTC-timestamp>-<id>/
# On target only:
sudo ./vga_simple_display input_image.hex
```

Use an appropriate ARM Linux cross-compiler for cross builds. The viewer expects 307200 RGB24 hexadecimal tokens and stores 32-bit words with stride 1024. Its input validation and resource handling remain legacy behavior (including an infinite sleep loop); inspect before production use.

## Build versions and logs

The existing Bash interface now calls a Python 3 standard-library helper; no extra Python packages are required. Save edited C/header files before building. Each accepted target creates a new ignored `build/hps/linux/runs/<UTC-timestamp>-<id>/` and prints its path in the terminal. Existing runs are retained. Sources: [entrypoint, line 11](build.sh#L11), [run creation and schema, line 83](build_run.py#L83).

```text
runs/<UTC-timestamp>-<id>/
├── sources/software/hps/    captured .c/.h inputs and build entrypoints
├── logs/build.log           compiler/preflight stdout and stderr
├── bin/vga_simple_display  output belonging to this successful run
└── run.json                input/output SHA-256, commands and provenance
```

Compilation reads only the captured HPS inputs under `sources/`, with the same Cortex-A9 hard-float flags. `run.json` schema version 1 records UTC start/end, requested target, compiler path/version/target, linker version when available, command argument arrays and exit codes, input paths/hashes, successful output hash and final `succeeded`/`failed` status. Compiler output is also shown live in the task terminal. Sources: [flags, line 20](build_run.py#L20), [schema, line 93](build_run.py#L93), [logging, line 110](build_run.py#L110), [snapshot, line 174](build_run.py#L174), [toolchain, line 213](build_run.py#L213), [compile, line 245](build_run.py#L245), [final status, line 293](build_run.py#L293).

A build run identifies a particular captured input set; it does not create a Git commit. Git HEAD and the observed repository dirty/status state are recorded, or Git availability is explicitly reported. Use `inputs` and `input_set_sha256` to identify the actual source bytes, especially for uncommitted changes. Files are copied individually, so avoid editing source while a build starts; Git status is a provenance observation, not an atomic repository snapshot. Sources: [input identity, line 174](build_run.py#L174), [Git identity, line 196](build_run.py#L196).

Valid-target preflight/compiler failures retain their run and log with a nonzero exit code; a failed attempt leaves the previous `build/hps/linux/bin/vga_simple_display` unchanged. After compilation, the helper stages a convenience copy and finishes fallible metadata/log writes before atomically publishing it. SIGINT/SIGTERM are deferred inside this short WSL/Linux commit section; when publication completes the run remains successful, including a deferred interruption. An interruption before that section records failure. If publication fails, the helper restores a failed record and keeps the previous convenience binary. JSON and ELF publication are separate filesystem operations; forced termination such as `SIGKILL` can interrupt them and prevent consistent final evidence. Unavailable Python or an unwritable output directory can also prevent records. Sources: [compile/archive, line 245](build_run.py#L245), [commit boundary, line 262](build_run.py#L262), [failure finalization, line 293](build_run.py#L293), [signal handling, line 312](build_run.py#L312).

These are compile/link logs. The helper never runs or deploys the `/dev/mem` application, and does not collect runtime logs from the DE1-SoC. Source: [build control flow, line 312](build_run.py#L312).

`all` builds only `vga_simple_display`. `memory_benchmark.c` is absent from current source; any historical binary, if present locally, is preserved and cannot be reproduced from this source tree. Explicitly requesting `memory_benchmark` returns an unsupported/missing-source error. Sources: [target registry, line 18](build_run.py#L18), [target validation, line 62](build_run.py#L62), [historical move manifest, memory_benchmark file record](../../build/archive/restructure-20261004.json).

## Failure journal

An unsuccessful HPS invocation also creates a local incident under `build/bug/software/<UTC-timestamp>-<id>/`. This includes rejected arguments (exit 2), missing/invalid compilers, compile failures, interruptions before an accepted commit, and run initialization/finalization errors. An accepted successful publication creates no incident. The original build exit code is preserved, including a negative command signal code in JSON; the shell receives its conventional `128 + signal` code. Sources: [validation, line 62](build_run.py#L62), [failure recorder, line 32](build_run.py#L32), [failure control flow, line 312](build_run.py#L312).

Each incident has `record.json` (failure phase/code, command, run metadata and evidence references), `diagnostics.log` (bounded text excerpts), and `journal.md` for hypotheses, confirmed cause, corrective edits and verification. The existing run, log and source snapshots remain in their original directories; the journal references the full build log and does not copy binaries or waveform data. Journaling is best effort: an unavailable helper, unwritable destination or forced termination can prevent an incident. A recorder error prints a warning and does not change the original build result; metadata supplied to the journal explicitly describes failure even if finalizing `run.json` failed. Sources: [HPS recorder, line 32](build_run.py#L32), [shared journal schema and files, line 203](../python/bug_journal.py#L203), [bounded log capture, line 101](../python/bug_journal.py#L101).

This integration covers this HPS build entrypoint. Quartus GUI failures, manual compiler invocations, generator commands and runtime failures on the DE1-SoC require manual log import unless their entrypoints are separately integrated. Keep full board logs as evidence and record board/FPGA configuration when filling in the journal. See [manual import and workflow](../../docs/development/bug-logging.md). Sources: [HPS control flow, line 312](build_run.py#L312), [shared journal manual CLI, line 264](../python/bug_journal.py#L264).

The address contract is in `include/hps_fpga_addresses.h`. A host syntax check does not validate memory mapping or DMA operation.
