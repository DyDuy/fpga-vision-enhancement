# Historical Qsys snapshot record

This record describes an earlier local snapshot of generated Platform Designer folders and companion project inputs. The original payload under `hardware/archive/qsys/luanvan_soc-current/` is **not present in the current checkout**; only this record and [`manifest.json`](manifest.json) remain. Do not treat the old path as an available source or generated workspace.

The historical snapshot reportedly contained `Computer_System`, `VGA_Subsystem`, and `Video_In_Subsystem` generated folders, Qsys inputs, SOPCINFO/Tcl files, board project inputs, candidate RTL/IP Tcl, LUT files, and HPS files. Its manifest records the retained provenance and source checksums where available. The original Downloads project was not modified by the intake.

The snapshot was not proof of source/bitstream equivalence or a reproducible Quartus build. Generated folders could contain outputs from different parent generations; missing/stale dependencies, absolute paths, timing exceptions, and external files required review. No board-programming claim follows from the snapshot.

For current work, use the actual inputs under `hardware/qsys/`, `hardware/pin/`, and the preserved candidate files under `hardware/archive/project-inputs/`. Use a separate ignored run under `build/`; do not recreate or edit the historical payload merely to satisfy this record.

The historical payload was Git-ignored. Do not force-add vendor-generated files or private documents without provenance and redistribution review.

If the manifest is applicable to a locally restored payload, verify it from the repository root with:

```sh
python software/python/verify_artifact_manifest.py docs/history/builds/platform/luanvan_soc-current/manifest.json
```
