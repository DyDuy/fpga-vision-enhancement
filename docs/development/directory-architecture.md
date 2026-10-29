# Directory architecture and edit guide

Read this guide to determine **where code belongs, what tools generate, and which evidence must be retained**. The complete leaf-directory inventory is in [directory-inventory.csv](directory-inventory.csv), with scope and counting rules in [directory-inventory-metadata.json](directory-inventory-metadata.json). The inventory is read-only: it records names and file metadata and does not run tools or verify the algorithm or board.

This guide describes the observed repository and distinguishes **current**, **generated**, **historical**, **planned**, and **validation** areas. A scaffold is not an implementation, and a report is not proof of a reproducible build.

## 1. Quick edit map

All paths below are relative to the repository root.

| Change you want to make | Canonical source | Required follow-up |
|---|---|---|
| Open the intended Quartus project | Expected path: `hardware/de1_soc/DE1_SoC_Computer.qpf` | The file is absent in the current checkout; the preserved historical counterpart is under `hardware/archive/project-inputs/`. Do not open generated output as canonical source. |
| Change intended project settings, top level, source/QIP/SDC lists | Expected path: `hardware/de1_soc/DE1_SoC_Computer.qsf` | The active file is absent; review the archived QSF and dependency closure before restoring it. |
| Change HPS, bridges, memory, subsystems, or custom IP connections | `hardware/qsys/Computer_System.qsys` | Save Qsys, regenerate, compile, and compare changed addresses with the HPS header. |
| Change VGA DMA, FIFO, resampler, or display control | `hardware/qsys/VGA_Subsystem.qsys` | Regenerate the subsystem and parent system; update format/stride software if needed. |
| Change video input configuration | `hardware/qsys/Video_In_Subsystem.qsys` | Regenerate and review buffer ownership and connections. |
| Change the enhancement pipeline | Expected path: `hardware/de1_soc/dehazing_system_top.v` | The active file is absent; the preserved candidate is under `hardware/archive/project-inputs/`. Simulate selected RTL/LUTs before promotion. |
| Change the custom-IP descriptor | Expected path: `hardware/de1_soc/dehazing_system_top_hw.tcl` | The active file is absent; review the archived descriptor and external IP closure before restoring it. |
| Change board-level ports | Expected path: `hardware/de1_soc/DE1_SoC_Computer.v` | The active wrapper is absent; compare the archived wrapper with Qsys exports and pin assignments before promotion. |
| Change pins or I/O standards | `hardware/pin/de1_soc_pins.qsf` | Re-run fitter and compare with the board schematic/documentation. |
| Change clocks or timing exceptions | `hardware/pin/DE1_SoC_Computer.sdc` | Run TimeQuest, review unconstrained paths and unmatched exceptions, and never hide warnings with broad false paths. |
| Change active LUT contents | Expected paths under `hardware/de1_soc/` | Active LUT files are absent; the preserved candidate files are under `hardware/archive/project-inputs/`. Check width/depth, generator provenance, checksum, simulation, and compilation before promotion. |
| Change staged inputs or Qsys generation order | Expected path: `hardware/de1_soc/build.json` | Restore and review the manifest first; it is absent from the current checkout, and a new directory is not included automatically. |
| Change stage/generate/compile behavior | `software/python/build_fpga.py` | Run tooling tests and the project checker; do not put RTL algorithm changes here. |
| Change HPS image loading, buffers, or DMA access | `software/hps/src/vga_simple_display.c` | Cross-build and deploy only with a matching memory map, bitstream, and board test. |
| Change HPS addresses, dimensions, or stride | `software/hps/include/hps_fpga_addresses.h` | Compare with Qsys and C usage; do not change the header instead of fixing hardware configuration. |
| Prepare image/HEX data or ModelSim output | `software/python/modelsim/` | Follow that directory's README and keep generated output outside source fixtures. |
| Inspect imported verification material | `hardware/verification/intake-20261004/` | Preserve the snapshot; create a separate working test when integrating it. It is not automatically an active regression. |
| Add HLS/Chisel/Magma/Halide generation | `hardware/generation/` | This is a preparation workspace; no active adapter currently consumes it. |

## 2. Source, generated output, and evidence

### Canonical source

1. `.qsys` files directly under `hardware/qsys/`.
2. RTL, IP descriptors, and active ROMs under `hardware/de1_soc/`.
3. Pin and SDC sources under `hardware/pin/`.
4. HPS C source and headers under `software/hps/`.
5. Python build/check tools and tests under `software/python/`.
6. Specifications and evidence under `docs/`.

### Generated output

Do not edit these as long-term sources:

- `hardware/qsys/<system>/synthesis/`, `simulation/`, `submodules/`, `.qip`, `.sopcinfo`, generated SDC, and generated handoff files;
- Quartus databases, incremental databases, reports, and bitstreams;
- `build/quartus/` and `build/hps/` run snapshots;
- Python bytecode caches and temporary validation sandboxes.

If a generated file needs to change, locate the Qsys, IP Tcl, RTL, pin, SDC, or build manifest that produced it. A generated copy of `dehazing_system_top.v` is not the place to fix the IP.

### Historical and validation evidence

`hardware/archive/`, `hardware/verification/intake-20261004/`, `docs/history/`, and `build/verification/` are evidence or snapshots. Preserve their checksums and provenance. Do not use them as active sources, and do not delete them merely because Git ignores the payload.

## 3. Current ownership boundaries

| Area | Responsibility | Status and evidence |
|---|---|---|
| `hardware/de1_soc/` | Expected Quartus project, board wrapper, enhancement RTL, IP Tcl, ROMs, and build manifest | Current checkout is incomplete: expected source files and `build.json` are absent; the directory contains mainly ignored Quartus output. |
| `hardware/pin/` | Board pin assignments and timing constraints | Active board inputs; see [hardware README](../../hardware/README.md#L5-L14). |
| `hardware/qsys/` | Platform Designer input systems and local generated trees | `.qsys` inputs are canonical; generated subtrees are outputs. |
| `hardware/generation/` | Future tool-generation specifications and adapters | Preparation workspace; no active RTL-generation adapter is established. |
| `hardware/verification/` | Imported test and fixture snapshots | Immutable intake material, not current RTL regression. |
| `hardware/archive/` | Historical Quartus input/output payload | Local and Git-ignored; use current sources for new builds. |
| `software/hps/` | ARM Linux application, address header, and cross-build entry point | Active source; target is currently `vga_simple_display`. |
| `software/python/` | Image conversion, staging, checking, archiving, and failure logging | Active developer tooling and tests. |
| `software/matlab/` | Historical algorithm prototype | Not automatically a golden fixed-point model. |
| `docs/`, `paper/`, `ref/` | Specifications, decisions, research, publication, and references | Versioned documentation with separate provenance rules. |
| `build/` | Run output, snapshots, logs, validation sandboxes, and retained evidence | Generated/retained workspace; never a canonical source tree. |

## 4. Source-to-build flow

```text
Canonical inputs:
  hardware/de1_soc + hardware/pin + hardware/qsys
              |
              v
  build_fpga.py: stage (copy, hash, and rewrite staged paths)
              |
              v
  build/quartus/vision_1x1/runs/<run-id>/
              |
              v
  Qsys generation: VGA_Subsystem -> Video_In_Subsystem -> Computer_System
              |
              v
  Quartus compile -> report, bitstream, and run logs
```

HPS builds use a separate frozen source snapshot:

```text
software/hps/src + include + build scripts
              |
              v
  WSL/Linux ARM cross-build
              |
              v
  build/hps/linux/runs/<run-id>/{sources,logs,bin,run.json}
              |
              v
  build/hps/linux/bin/vga_simple_display on successful publication
```

Run from the repository root:

```bash
python software/python/check_project.py
python software/python/build_fpga.py stage       # validate and copy inputs
python software/python/build_fpga.py generate    # stage and generate Qsys
python software/python/build_fpga.py compile     # stage, generate, and compile
```

`compile` includes staging and generation; the three commands are alternatives that create separate runs, not three edits to one mutable directory. The checker does not prove RTL correctness, timing closure, or board operation. See [automatic build](automatic-build.md), [HPS build](vscode-hps-build.md), and [verification](verification.md).

## 5. Inventory snapshot and interpretation

The captured snapshot contains **789 directories below the repository root**, **4,464 regular files**, and a maximum depth of **17 levels**. Because `.` is represented separately, the CSV contains **790 data rows plus the header**. The counts include Git-ignored directories. The inventory excluded `.git` at every level, did not follow symlinks/junctions/reparse points, read cloud placeholders as metadata only, and excluded its own three output files. It recorded **zero skipped links/special files** and **zero metadata-read errors**; completeness under the declared rules is `true`. See the `counts`, `rules`, `errors`, and `complete_under_declared_rules` fields in [directory-inventory-metadata.json](directory-inventory-metadata.json).

The capture began at `2026-10-04T06:17:35.413837+00:00`. The user's calendar context was `2026-10-04, Asia/Saigon`; these are recorded separately and are not a conversion of the machine clock.

| Top-level branch | Directories | Regular files | Maximum depth | Evidence |
|---|---:|---:|---:|---|
| `.github/` | 2 | 1 | 2 | [CSV line 3](directory-inventory.csv#L3) |
| `.vscode/` | 1 | 3 | 1 | [CSV line 5](directory-inventory.csv#L5) |
| `build/` | 682 | 2,448 | 17 | [CSV line 6](directory-inventory.csv#L6) |
| `data/` | 2 | 2 | 2 | [CSV line 688](directory-inventory.csv#L688) |
| `docs/` | 14 | 46 | 5 | [CSV line 690](directory-inventory.csv#L690) |
| `hardware/` | 66 | 1,864 | 6 | [CSV line 704](directory-inventory.csv#L704) |
| `paper/` | 8 | 22 | 4 | [CSV line 770](directory-inventory.csv#L770) |
| `ref/` | 2 | 30 | 2 | [CSV line 778](directory-inventory.csv#L778) |
| `software/` | 12 | 40 | 5 | [CSV line 780](directory-inventory.csv#L780) |

In the CSV, `depth` is measured from root 0; `is_leaf=true` means that no child directory was traversed, not that the directory is empty; `direct_file_count` counts immediate files and `recursive_file_count` includes descendants. `git_ignored` describes the directory path, not every file and not commit status. For example, `hardware/de1_soc/` is not ignored as a whole even though `.rpt`, `db/`, and other generated content is ignored.

The inventory is not atomic: the tree can change during or after capture. This guide is not live telemetry, a build log, or proof that generated files are current. Roles are inferred from paths, READMEs, manifests, and entry points and are not a content review of every file.

## 6. Build and evidence policy

- Keep source, tests, specifications, manifests, and small provenance records in Git when licensing and dependency closure are clear.
- Keep Quartus databases, generated Qsys trees, bitstreams, reports, caches, raw datasets, and local incident output ignored unless a specific evidence policy says otherwise.
- Treat `build/bug/<domain>/<incident-id>/` as a journal and evidence location, not a source location.
- A sandbox under `build/bug-validation/` can contain nested paths named `hardware`, `software`, or `build`; those paths remain test data and must not be mistaken for canonical sources.
- `build/quartus/vision_1x1/runs/<run-id>/` contains staged inputs and generated output. Edit the canonical source and create a new run rather than patching the snapshot.
- `build/hps/linux/runs/<run-id>/sources/software/hps/` is a frozen compiler input. Edit `software/hps/` and rebuild.
- A historical archive can have a `.sof`, reports, and metadata without a source commit. Record it as historical and do not combine its metrics with current results.

## 7. Recreating the inventory

The one-time generator is kept in the ignored build area. From the repository root:

```powershell
python build/documentation/directory-inventory/generate_directory_inventory.py
```

This overwrites the three documentation outputs only; it does not run a build or modify design sources. It does not follow links/reparse points, reads cloud placeholders as metadata, and hashes only the inventory artifacts—not project-file contents. If metadata cannot be read, the JSON records `errors` and sets `complete_under_declared_rules=false`; special entries are listed in `skipped_links_or_nonregular_entries`.

Line-number links refer to the file version used when this guide was written. JSON field names and CSV `relative_path` values are more stable references when regenerating the inventory. The inventory does not measure throughput, timing, image quality, resource usage, or board operation.
