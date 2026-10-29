# Build artifacts

This area is for tool-generated artifacts or outputs received from historical builds, not RTL source code.

## Storage separation

- `hardware/archive/`: local, **Git-ignored** payload; absent from a clean checkout.
- `docs/history/builds/hardware/<build-id>/`: trackable manifests, checksums, metrics JSON, and Markdown summaries.
- `build/`: working directory for new generation and compilation runs; not an immutable archive.

## Complete generated project on the local machine

`local/qsys/luanvan_soc-current/` contains the three generated systems—`Computer_System/`, `VGA_Subsystem/`, and `Video_In_Subsystem/`—plus their root inputs: **975 files, approximately 86.77 MiB**. The payload is inside the project but Git-ignored. See the [snapshot record and manifest](builds/platform/luanvan_soc-current/README.md). Do not assume that the generated systems are synchronized or buildable.

## Imported snapshot

`local/quartus/legacy-output-2026-05-02/` contains all 17 files from the `LuanVan_SoC/output_files` snapshot:

```text
bitstreams/    .sof (and .rbf/.pof/.jic if present in another build)
reports/       .rpt, .summary, .smsg
programming/   .cdf
metadata/      .pin, .jdi, .sld, .done, and other support files
```

See the [historical build record](builds/hardware/legacy-output-2026-05-02/README.md). The snapshot has not been shown to match the current RTL or paper version; do not load the bitstream onto a board without a source and compatibility review.

## Hosting and security

After distribution rights are reviewed, artifacts may be packaged for GitHub/GitLab Releases or object storage. Add the URL to the manifest and retain the SHA-256 checksum. Do not force-add `hardware/archive/` or enable LFS indiscriminately for every output.

Raw reports and CDF files may contain absolute paths or machine names. Keep the original payload local when its checksum matters. If a redacted public copy is needed, create a new artifact with a new checksum and document the transformation. The original `.cdf` contains paths from the old machine and is not a portable recipe.
