# Full local Qsys generated-project snapshot

The owner requested keeping generated project folders in the research project, not just source inputs. A byte-preserving local copy now lives at:

```text
hardware/archive/qsys/luanvan_soc-current/
├── Computer_System/
├── VGA_Subsystem/
├── Video_In_Subsystem/
├── Computer_System.qsys
├── VGA_Subsystem.qsys
├── Video_In_Subsystem.qsys
├── *.sopcinfo
├── Computer_System.tcl
├── Computer_System_hw.tcl
├── DE1_SoC_Computer.{qpf,qsf,sdc,v}
├── dehazing_system_top.v
├── dehazing_system_top_hw.tcl
├── transmission_lut_data.hex
├── gamma_lut_data.hex
├── hps_fpga_addresses.h
└── vga_simple_display.c
```

All files inside the three source folders were copied, including generated HDL, synthesis/submodules, QIP, simulation support and interface/export files wherever present. Original names and relative layout are preserved; no pruning or line-ending changes applied. Companion root inputs were included to retain the parent project context.

- Total: **975 files, approximately 86.77 MiB**.
- [manifest.json](manifest.json): SHA-256, size and path of every copied file; all copies checked against source.
- Original Downloads project is unchanged.
- Entire payload is Git-ignored via `/hardware/archive/`; this record and manifest remain publishable candidates.
- This snapshot is not an archive of every other directory in LuanVan_SoC (db, datasets, personal documents etc.); it specifically preserves the three requested generated systems and companion inputs. Historical build outputs are separately archived under `hardware/archive/quartus/`.

## Build status

Generated folders can contain outputs of earlier/different parent generations. Folder presence does not establish that all HDL matches current Qsys, ROM, SDC or source. `hex_decoder.v` was not found. Missing/stale dependencies, absolute paths and timing exceptions still need review. No Quartus compile or board programming was performed.

Treat this as a preserved snapshot. For experiments, create a separate working copy under `build/`; do not silently edit the archived files or overwrite their checksums. Canonical versioned source remains in the existing RTL/board and candidate directories.

## Local completeness vs public Git

The local research project includes both tracked source candidates and ignored historical payloads. GitHub/GitLab checkout will not contain this archive by default. Do not use `git add -f` to publish vendor-generated files without checking redistribution terms and private paths. A reviewed binary/source archive may be shared separately through Releases/storage with checksum and URL.

Verification from root:

```sh
python software/python/verify_artifact_manifest.py docs/history/builds/platform/luanvan_soc-current/manifest.json
```
