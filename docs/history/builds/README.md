# Results

Store selected evidence with provenance. Do not mix historical reports with newly reproduced results.

## Hardware build records

- [`hardware/legacy-root-mixed-2026-07-28/`](hardware/legacy-root-mixed-2026-07-28/README.md): 24 root artifacts from a later source; the fitter date (July 28) and power date (July 10) differ, so they must not be assumed to be one build.
- [`hardware/legacy-output-2026-05-02/`](hardware/legacy-output-2026-05-02/README.md): 17-artifact Quartus `output_files` snapshot with SHA-256 manifest, metrics JSON, and summary. The source commit is unknown; no new build or board validation has been performed.

## Organization rules

- `docs/history/builds/hardware/<build-id>/`: trackable README, manifest, and small metrics files.
- `hardware/archive/quartus/<build-id>/`: bitstreams, raw reports, Programmer files, and metadata; Git-ignored. See [artifact policy](../artifact-policy.md).
- `build/`: working directory for new generation and compilation, not immutable build evidence.
- `docs/history/builds/generated/`: temporary generated results; do not track.

Each build ID must identify one snapshot. Record the tool version, device, report source, source commit (or `unknown`), checksum, and measurement conditions. Do not present paper data as a result of the current RTL without verification.

## Importing output from another build

```sh
python software/python/archive_quartus_outputs.py /path/to/output_files --build-id unique-build-id
python software/python/verify_artifact_manifest.py docs/history/builds/hardware/unique-build-id/manifest.json
```

The script preserves the payload, verifies checksums, and refuses to overwrite an existing build ID. After import, add a separate README describing the evidence and link it to the source commit/configuration if known. A clean checkout does not contain the local payload; use a Release or object store after rights review and record its URL in the manifest.
