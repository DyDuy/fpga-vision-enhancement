# Historical records and artifact policy

The current checkout is intended to use one active FPGA source set under `hardware/de1_soc/`, one HPS source tree under `software/hps/`, and one root `build/` workspace. The FPGA source set is currently incomplete: the expected active manifest and principal source files are absent from `hardware/de1_soc/`.

`hardware/archive/project-inputs/` preserves a candidate legacy source snapshot, including the QPF/QSF, board wrapper, candidate RTL/IP Tcl, LUT files, and HPS inputs. It is historical intake, not an automatic fallback and not an active edit location. `hardware/archive/quartus/` preserves generated reports, bitstreams, and metadata as historical evidence.

The earlier `docs/migration/legacy-manifest.json` and related records contain historical destinations under `hardware/archive/sources/`. Those destinations are not present in the current checkout; their availability fields and hashes remain audit evidence, not live paths. [`one-build-1x1-only.json`](one-build-1x1-only.json) records the earlier scope decision and removed/retained payloads.

`docs/history/builds/` contains build metrics and manifests. A checksum proves retained bytes, not source/generated equivalence, standalone archive compileability, timing closure, or hardware compatibility. Do not run historical commands or treat old source paths as current edit locations.

Generated files, private documents, bitstreams, datasets, and reference PDFs remain local/ignored unless a separate provenance, licensing, and publication policy approves them. Preserve checksums and source/tool context for any retained evidence.
