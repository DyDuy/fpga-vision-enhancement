# Documentation index

## Start here

- [Engineering repository map](architecture/engineering-layout.md): canonical current ownership/layout.
- [Development workflow](development/workflow.md): environment, commands, verification and release gates.
- [Contributing](../CONTRIBUTING.md): change/review expectations.

## Design and verification

- [Requirements](spec/requirements.md)
- [Interfaces](spec/interfaces.md)
- [Numerical formats](spec/numerical_formats.md)
- [Architecture](architecture/overview.md), [dataflow](architecture/dataflow.md), [memory map](architecture/memory_map.md)
- [Verification plan](development/verification.md)

Specs/architecture contain target concepts; they are not all closed contracts for the imported legacy implementation. Read implementation-specific intake notes before treating a requirement as verified.

## Provenance and research

- [Updated snapshot review](research/current-snapshot-review.md): candidate 1×1, ROM/SDC/Video-In và mixed-date reports; [manifest](migration/current-snapshot-manifest.json).

- [Source intake](migration/legacy-intake.md) and [manifest](migration/legacy-manifest.json)
- [Historical hardware build](history/builds/hardware/legacy-output-2026-05-02/README.md)
- [Paper documentation](../paper/article/README.md) and [implementation mismatch review](../paper/article/implementation-review.md)
- [Architectural decisions](decisions/0001-repository-layout.md), [legacy decision](decisions/0002-legacy-quartus-intake.md)
- [Roadmap](ROADMAP.md), [references](../ref/literature.md)

Signed publication administration is private, not repository documentation. Files ignored by Git remain local and are not a project license.
