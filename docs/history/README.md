# Historical records — selected project is now 1x1 only

The active FPGA source is only `hardware/de1_soc/`; HPS source is only `software/hps/`. Root `build/` is the single output/workspace directory.

At the owner's request, archived 15x15/RGB24/Chisel sources, retired preparation tools and stale 15x15 generated core/backup files were removed. [one-build-1x1-only.json](one-build-1x1-only.json) records removed source hashes and build consolidation. Original source-intake manifests remain audit records; entries marked unavailable are no longer retained source inputs.

`hardware/archive/quartus/` keeps historical report/bitstream evidence, not active code. `hardware/archive/qsys/` keeps the current 1x1 generated snapshot, with stale older spatial-core files filtered out. Its manifest now describes **973 retained files** and explicitly records removed payloads/original counts; it is not represented as the unmodified original 975-file snapshot.

`builds/` contains metrics and manifests. Earlier [deduplication record](deduplication.json) describes the previous exact-duplicate cleanup; current scope is documented by the later 1x1-only record. Do not run historical commands or treat old source paths as current edit locations.

Checksum verification proves retained bytes, not source/generated equivalence, standalone archive compileability or hardware compatibility. Artifacts/private documents are local and ignored; small audit records remain publishable candidates.
