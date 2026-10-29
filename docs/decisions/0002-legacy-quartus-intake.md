# ADR 0002: Keep the research repository canonical and intake Quartus sources incrementally

## Source-intake update

Selected sources from the `LuanVan_SoC` Downloads snapshot were imported according to the [manifest](../migration/legacy-manifest.json) and [intake guide](../migration/legacy-intake.md). This intake has not passed the build or license gates and is not a pristine generated project. The historical `D:\` observations below are retained as provenance; current sources and checksums are recorded in the manifest. No reproducible-build claim has been made.

## Status

Accepted — 2026-09-30.

## Decision

Keep this repository canonical for specifications, models, RTL, verification, and board adapters under [ADR 0001](0001-repository-layout.md#L7-L13). Preserve the currently retained candidate inputs under [`hardware/archive/project-inputs/`](../../hardware/archive/project-inputs/) until a source manifest, dependency closure, license review, and clean-checkout test justify promotion to `hardware/de1_soc/`. Do **not** import the entire legacy tree or generated output.

The following `D:\` paths are read-only local observations from 2026-09-30 and are outside the repository: the legacy QPF declares Quartus 23.1 (`D:\kq_nghiencuu_Caitien\kq_nghiencuu1\LuanVan_SoC\DE1_SoC_Computer.qpf:20-31`); the QSF requires an SDC and `hex_decoder.v`, but those paths were absent during inventory (`D:\kq_nghiencuu_Caitien\kq_nghiencuu1\LuanVan_SoC\DE1_SoC_Computer.qsf:974-977`); and the QIP points to generated submodules including `dehazing_system_top.v` (`D:\kq_nghiencuu_Caitien\kq_nghiencuu1\LuanVan_SoC\Computer_System\synthesis\Computer_System.qip:8018`). These observations are not portable or reproducible from the repository until a dated manifest, dependency closure, and clean-checkout test exist.

## Alternatives and consequences

Importing the entire legacy tree, or making it the repository root, would mix sources of uncertain provenance and licensing with generated dependencies and turn an incomplete snapshot into an implicit baseline. Discarding it entirely would lose integration clues. Keep the original immutable outside the active source tree, and move only verified sources with a manifest, license review, recipe, and clean-checkout test. Until then, Quartus integration remains an intake activity, with no bitstream or timing guarantee. See the [integration gates](../architecture/repository-layout.md#integration-stages-and-gates).
