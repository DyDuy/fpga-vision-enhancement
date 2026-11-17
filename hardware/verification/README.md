# FPGA vision verification workspace

This directory is the spec-first design-verification workspace for the 640x480 dehazing stream. The historical intake under `intake-20261004/` is immutable provenance; new checks write only to `manifests/runs/` and `reports/`.

## Scope

The active contract covers the `dehazing_system_top` Avalon-ST sink/source, 30-bit packed RGB, 640x480 frames (307200 pixels), bypass/processed selection, reset, backpressure, frame markers, fixed-point clipping, and the declared 5-cycle pixel alignment and 11-cycle total latency. Qsys integration is represented by the generated `Computer_System` QIP in the active project.

## Flow

```text
spec/ -> scripts/check_contract.py -> vectors/ -> simulator (pending)
                       |                  -> manifests/runs/<UTC>_<seed>/
                       +-> rtl/filelists + sva templates
```

`check_contract.py` is the current executable gate. Simulator, scoreboard, SVA binding, coverage collection, timing closure, and board replay remain pending until a supported simulator and a reviewed testbench are selected. The legacy testbench is retained as evidence and is not a passing regression.

## Layout

- `spec/`: requirements, data contract, and requirement traceability.
- `model/`: planned float and fixed-point reference models; no unverified golden output is promoted.
- `vectors/`: immutable test-vector contracts for smoke, stall, boundary, and malformed cases.
- `rtl/filelists/`: source lists for simulator integration.
- `sva/`: protocol assertion template; bind names must be finalized against the simulator DUT.
- `regressions/`, `coverage/`, `reports/`, `manifests/`: suite definitions and run evidence.
- `intake-20261004/`: preserved historical snapshot; do not edit or use as a generated-output workspace.

## Reproducibility and closure

Each run records UTC time, seed, source hashes, fixture hashes, command, and status. A release candidate requires every requirement to have passing evidence, no unwaived assertion or scoreboard failures, reviewed coverage, and separate Quartus timing/resource and DE1-SoC replay gates. A contract check passing does not imply algorithmic correctness or hardware timing closure.
