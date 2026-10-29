# Documentation index

## Start here

- [System anatomy](architecture/system-anatomy.md): current hardware, software, dataflow, memory, and evidence boundaries.
- [Engineering repository map](architecture/engineering-layout.md): canonical ownership and layout.
- [Development workflow](development/workflow.md): environment, commands, verification, and release gates.
- [Contributing](../CONTRIBUTING.md): change and review expectations.

## Design and verification

- [Requirements](spec/requirements.md)
- [Interfaces](spec/interfaces.md)
- [Numerical formats](spec/numerical_formats.md)
- [Architecture](architecture/overview.md), [dataflow](architecture/dataflow.md), and [memory map](architecture/memory_map.md)
- [Verification plan](development/verification.md)

The specifications and architecture documents describe target concepts. They are not all closed contracts for the imported legacy implementation. Read the implementation-specific intake notes before treating a requirement as verified.

## Provenance and research

- [Updated snapshot review](research/current-snapshot-review.md): candidate 1×1, ROM/SDC/Video-In, and mixed-date reports; see the [manifest](migration/current-snapshot-manifest.json).
- [Source intake](migration/legacy-intake.md) and [manifest](migration/legacy-manifest.json)
- [Historical hardware build](history/builds/hardware/legacy-output-2026-05-02/README.md)
- [Paper documentation](../paper/article/README.md) and [implementation mismatch review](../paper/article/implementation-review.md)
- [Architectural decisions](decisions/0001-repository-layout.md) and [legacy decision](decisions/0002-legacy-quartus-intake.md)
- [Roadmap](ROADMAP.md) and [references](../ref/literature.md)

Signed-publication administration is private and is not repository documentation. Files ignored by Git remain local and do not constitute a project license.
