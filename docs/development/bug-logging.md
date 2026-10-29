# Failure logging and remediation journal

## A — Recording architecture and flow

```text
Integrated Python build fails          GUI/board/tool log supplied by the user
                  |                                  |
                  +---------> record_failure <--------+
                                    |
          build/bug/<hardware|software|generation>/<UTC-timestamp>-<uuid>/
                       |                 |                 |
                  record.json     diagnostics.log      journal.md
                  metadata        error excerpts       user notes

Full logs and the run source snapshot remain in their original locations.
```

Each incident has its own directory; concurrent failed builds cannot overwrite a shared index. `hardware/` is for Quartus/FPGA, `software/` is for HPS/Linux, and `generation/` is for HLS/Magma/Chisel/Halide. The API accepts only these three domains. See [valid domains, line 16](../../software/python/bug_journal.py#L16) and [API and per-incident directory creation, line 203](../../software/python/bug_journal.py#L203).

## B — Evidence and provenance

`record.json`, schema version 1, records the UTC time, error message and phase, original exit code—including negative codes—command, run/log references, caller-supplied metadata, Git HEAD and dirty state, and the Python/OS environment. Repository-local paths include relative and absolute forms; paths outside the repository remain absolute. If Git cannot be read, the value is `null` with a limitation instead of an invented version. See [path references, line 52](../../software/python/bug_journal.py#L52), [best-effort Git capture, line 63](../../software/python/bug_journal.py#L63), and [record fields, line 230](../../software/python/bug_journal.py#L230).

`diagnostics.log` stores the error message and up to 128 KiB from the beginning and end of each supplied text log. When content is truncated, it records that the middle was omitted together with the original size and path. Missing or unreadable logs are recorded as limitations. Only regular files are read; directories, devices, and FIFOs are ignored. Waveforms, binaries, source code, and caches are not imported as logs. Supported text logs use `.log`, `.txt`, `.rpt`, `.out`, `.err`, `.summary`, or the name `transcript`. Undecodable bytes are replaced, so exact byte comparison requires the original file. See [limits and file names, line 17](../../software/python/bug_journal.py#L17) and [bounded reads and missing evidence, line 101](../../software/python/bug_journal.py#L101).

When a run has staged its inputs, the incident metadata keeps the run reference and a copy of the builder input list and hashes. The full source remains in the run and is not copied again into `build/bug`. A failure before staging or snapshotting may have no source or run log to compare. The Git commit in `git.head` is observed when the incident is written; reproduce using both source hashes and dirty state. See the hardware staging, HPS snapshot, and metadata references in the builder sources.

`journal.md` separates observed symptoms, unconfirmed hypotheses, confirmed causes, changes, and verification. The initial cause, change, and verification fields in the record are `null`; the helper never guesses whether a failure is caused by hardware or an algorithm. See [journal template, line 155](../../software/python/bug_journal.py#L155) and [initial state, line 230](../../software/python/bug_journal.py#L230).

## C — Automatic builds and manual intake

Two entry points currently integrate the recorder:

| Entry point | When an incident is recorded | Domain and original logs |
|---|---|---|
| `python software/python/build_fpga.py stage\|generate\|compile` | Configuration, tool discovery, staging, metadata, Qsys/Quartus, timeout, or Ctrl+C failure. See [workflow, line 165](../../software/python/build_fpga.py#L165) and [tool timeout/interruption, line 117](../../software/python/build_fpga.py#L117). | `hardware/`; run logs are under `build/quartus/<name>/runs/<run-id>/logs/*.log`. |
| `bash software/hps/build.sh all` in WSL/Linux | Invalid target/parameters, run initialization, snapshot, toolchain, compiler, metadata, or interruption before successful publication. | `software/`; run logs are under `build/hps/linux/runs/<run-id>/logs/build.log`. |

`stage`, `generate`, and `compile` are alternatives; do not pass the literal string containing `|`. A successful build creates no incident. Warnings from a tool or compiler with exit code 0 do not become bugs automatically. The hardware CLI returns 1 on failure while `record.json.exit_code` retains the child-tool code when available; timeouts/internal failures use 1 and Ctrl+C uses 130. HPS retains the original failure code in JSON; a negative child signal is returned to the terminal as `128 - code`, while an early handler interruption uses 130.

Run commands from the repository root in the VS Code terminal. Python 3 is required; the helper uses the standard library and needs no additional package. The CLI derives the repository root from the script location, so it works on Windows and in a WSL checkout. See [imports and default root, line 264](../../software/python/bug_journal.py#L264).

```powershell
# Create the directories/help without creating a false incident.
python software/python/bug_journal.py --init

# Import a Quartus GUI failure; replace the paths with real evidence.
python software/python/bug_journal.py --domain hardware --phase fit --exit-code 1 --message "Quartus GUI: fitting failed" --log "build/quartus/vision_1x1/runs/RUN-ID/logs/quartus-compile.log" --run-directory "build/quartus/vision_1x1/runs/RUN-ID"

# Import a board Linux application log copied back to the host.
python software/python/bug_journal.py --domain software --phase board-runtime --exit-code 1 --message "HPS application failed on the board" --log "build/hps/board-runtime.log"
```

`RUN-ID` and `board-runtime.log` above are placeholders, not measured results. Repeat `--log` for multiple logs; use `--command` to preserve the original command. The CLI prints the new incident path. See [CLI declaration and recorder call, line 264](../../software/python/bug_journal.py#L264).

API example for a build entry point:

```python
from bug_journal import record_failure

incident = record_failure(
    root, "hardware", message="Quartus failed", exit_code=return_code,
    phase="compile", run_directory=run_dir, record=run_metadata,
    logs=[compile_log], command=compile_command,
)
```

Callers must handle recorder errors separately and preserve the build error and exit code. Both builders follow this rule: if recording fails, they warn and preserve the original build result. See [hardware recorder exception handling, line 161](../../software/python/build_fpga.py#L161) and [software recorder exception handling, line 58](../../software/hps/build_run.py#L58).

## D — Operation and limitations

Automatic recording applies only to the two entry points in section C. Quartus GUI work, direct C application runs on the board, and external HLS/Magma/Chisel/Halide commands require manual CLI intake; use `--domain generation` for RTL-generation tools. The recorder stores supplied evidence, does not monitor every process, and does not rerun builds or board tests. Historical failures are not imported automatically; add them only with verified logs and metadata.

After a fix, open the incident `journal.md` and record the file/line or commit, reproduction steps, verification command, new run/log, and observed result. Change the status to fixed only when the evidence is sufficient; editing Markdown does not update `record.json` automatically.

Log-reading cost is bounded by the number of logs and 128 KiB per log. Caller-provided metadata and message size have no separate limit. The two Git commands have a three-second timeout each. Git state is observed when the incident is written, not as an atomic snapshot of the build inputs. A log that is still being written may change after capture.

`build/bug` is ignored through `build/`. Recorder code and hooks in `software/`, and this guide in `docs/`, remain versionable. Back up incidents that matter before cleaning build output. To publish a journal, manually export the verified portion into versioned documentation while preserving evidence references. There is no automatic history deletion or journal export.

Behavioral checks are defined in [test_bug_journal.py, line 33](../../software/python/tests/test_bug_journal.py#L33): log preservation, negative exit codes, path/metadata capture, bounded excerpts, missing logs/Git, concurrency, and CLI/init. Read the separate validation report for actual results; this guide does not claim that an FPGA build or board run passed.
