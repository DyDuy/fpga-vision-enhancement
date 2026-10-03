# Root artifacts — mixed historical timestamps

24 selected report/bitstream/metadata files (49309795 bytes) copied from current `LuanVan_SoC` root, not its `output_files/` directory. Archive ID uses July 28 fitter date; this collection is **not assumed to be one coherent build**.

- Local ignored payload: `hardware/archive/quartus/legacy-root-mixed-2026-07-28/`.
- [manifest.json](manifest.json): file-by-file checksums and archive provenance.
- [metrics.json](metrics.json): fitter/timing summary extraction, not new measurements.
- Source commit and RBF conversion provenance: unknown.

July 28 fitter: Quartus 18.1, 5CSEMA5F31C6, 6279 ALM, 4875 registers, 1113243 memory bits, 144 RAM blocks, 8 DSP. These match the paper resource table but have not been tied to a reproducible source commit.

July 10 power summary: 824.12 mW total (282.24 dynamic, 422.64 static, 119.24 I/O); confidence **Low: user provided insufficient toggle rate data**. Do not attribute this to July 28 fit without further evidence.

SOF and four `output_file*.rbf` payloads are preserved; no conversion or board compatibility validation performed. Original paths/dates may appear in raw reports. Public rights/privacy review required before releasing payloads.

```sh
python software/python/verify_artifact_manifest.py docs/history/builds/hardware/legacy-root-mixed-2026-07-28/manifest.json
```

See [current-source research review](../../../../research/current-snapshot-review.md). Earlier May 2 output_files archive remains separate and unchanged.
