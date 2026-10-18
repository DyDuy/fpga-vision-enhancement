"""Cross-compile a frozen HPS source snapshot and retain each build attempt."""

from datetime import datetime, timezone
import fnmatch
import hashlib
import json
import os
from pathlib import Path
import shlex
import shutil
import signal
import subprocess
import sys
import uuid


ROOT = Path(__file__).resolve().parents[2]
APPS = ("vga_simple_display",)
# Keep the legacy utility's debug/no-optimization contract and board Linux ABI.
FLAGS = ["-std=gnu11", "-Wall", "-Wextra", "-g3", "-O0", "-mcpu=cortex-a9",
         "-mfpu=vfpv3-d16", "-mfloat-abi=hard", "-Isoftware/hps/include"]


def utc_now():
    return datetime.now(timezone.utc).isoformat(timespec="microseconds")


def sha256(data):
    return hashlib.sha256(data).hexdigest()


def journal_failure(code, message, phase, run=None, arguments=()):
    """Keep diagnostics best effort; journal errors cannot replace build errors."""
    try:
        # Direct execution starts with software/hps on sys.path, whereas the
        # shared journal lives in software/python. Import only on failure so a
        # missing/broken optional recorder never prevents a successful build.
        helper_directory = str(ROOT / "software/python")
        if helper_directory not in sys.path:
            sys.path.insert(0, helper_directory)
        from bug_journal import record_failure

        record = dict(run.data) if run is not None else {
            "status": "failed", "exit_code": code,
            "requested_arguments": list(arguments),
        }
        # A finalization error may leave run.json at its previous state. The
        # journal describes the observed failure and retains that original file.
        record.update(status="failed", exit_code=code, error=message)
        incident = record_failure(
            ROOT, "software", message=message, exit_code=code, phase=phase,
            run_directory=run.path if run is not None else None,
            record=record,
            logs=(run.path / "logs/build.log",) if run is not None else (),
            command=[sys.executable, str(Path(__file__).resolve()), *arguments],
        )
        print(f"Failure journal: {incident}", file=sys.stderr)
    except (Exception, KeyboardInterrupt) as error:
        print(f"Warning: cannot write failure journal: {error}", file=sys.stderr)


def validate_target(arguments):
    """Share the public Bash validation, including historical target errors."""
    if len(arguments) > 1:
        return None, "Usage: bash software/hps/build.sh [all|vga_simple_display]"
    target = (arguments[0] or "all") if arguments else "all"
    if target == "memory_benchmark":
        return None, ("Unsupported app: memory_benchmark source "
                      "software/hps/src/memory_benchmark.c is absent; "
                      "any retained binary is historical.")
    if target not in ("all", *APPS):
        return None, f"Unknown app: {target}"
    return target, None


class BuildFailure(Exception):
    def __init__(self, message, exit_code=1):
        super().__init__(message)
        self.exit_code = exit_code


class BuildRun:
    def __init__(self, target):
        self.started = datetime.now(timezone.utc)
        run_id = self.started.strftime("%Y%m%dT%H%M%S.%fZ") + "-" + uuid.uuid4().hex[:8]
        self.path = ROOT / "build/hps/linux/runs" / run_id
        self.path.mkdir(parents=True, exist_ok=False)
        for name in ("sources", "logs", "bin"):
            (self.path / name).mkdir()
        self.log = (self.path / "logs/build.log").open("w", encoding="utf-8")
        self.committed = False
        self.data = {
            "schema_version": 1, "run_id": run_id, "time_zone": "UTC",
            "time_start": self.started.isoformat(timespec="microseconds"),
            "time_end": None, "status": "running", "requested_target": target,
            "apps": list(APPS if target == "all" else (target,)),
            "compiler_flags": FLAGS, "compiler": {"requested": os.environ.get("CC") or
                                                     "arm-linux-gnueabihf-gcc"},
            "git": {"available": False, "reason": "not yet probed"},
            "inputs": [], "outputs": [], "commands": [], "exit_code": None,
        }
        self.save()

    def save(self):
        temporary = self.path / "run.json.tmp"
        temporary.write_text(json.dumps(self.data, indent=2, ensure_ascii=False) + "\n",
                             encoding="utf-8")
        os.replace(temporary, self.path / "run.json")

    def say(self, message):
        print(message, flush=True)
        self.log.write(message + "\n")
        self.log.flush()

    def command(self, phase, argv, cwd=ROOT):
        record = {"phase": phase, "argv": [str(arg) for arg in argv],
                  "cwd": str(cwd), "time_start": utc_now(), "exit_code": None}
        self.data["commands"].append(record)
        self.save()
        self.say(f"[{phase}] {shlex.join(record['argv'])}")
        output = []
        process = None
        try:
            # One ordered stream captures both stdout and stderr, and remains
            # visible in the VS Code task terminal instead of hiding diagnostics.
            process = subprocess.Popen(record["argv"], cwd=cwd, stdout=subprocess.PIPE,
                                       stderr=subprocess.STDOUT)
            for line in iter(process.stdout.readline, b""):
                text = line.decode("utf-8", errors="replace")
                output.append(text)
                sys.stdout.write(text)
                sys.stdout.flush()
                self.log.write(text)
                self.log.flush()
            process.wait()
            record["exit_code"] = process.returncode
        except KeyboardInterrupt:
            if process is not None:
                process.terminate()
                try:
                    process.wait(timeout=5)
                except subprocess.TimeoutExpired:
                    process.kill()
                    process.wait()
                record["exit_code"] = process.returncode
            raise
        except OSError as error:
            record["error"] = str(error)
            record["exit_code"] = 1
            raise BuildFailure(f"Cannot execute {phase}: {error}") from error
        finally:
            if process is not None and process.stdout is not None:
                process.stdout.close()
            record["time_end"] = utc_now()
            pending_error = sys.exc_info()[1]
            try:
                self.save()
            except Exception as save_error:
                if pending_error is not None:
                    # A failed write must not replace an interruption or an
                    # execution failure already propagating from the command.
                    print(f"Warning: cannot save command metadata: {save_error}",
                          file=sys.stderr)
                elif record["exit_code"]:
                    raise BuildFailure(
                        f"{phase} exited with {record['exit_code']}; "
                        f"cannot save command metadata: {save_error}",
                        record["exit_code"],
                    ) from save_error
                else:
                    raise
        return record["exit_code"], "".join(output)

    def snapshot(self):
        paths = {ROOT / "software/hps/build.sh", Path(__file__).resolve()}
        for directory in ("src", "include"):
            for suffix in (".c", ".h"):
                paths.update((ROOT / "software/hps" / directory).rglob("*" + suffix))
        for source in sorted(paths):
            relative = source.relative_to(ROOT)
            data = source.read_bytes()
            destination = self.path / "sources" / relative
            destination.parent.mkdir(parents=True, exist_ok=True)
            destination.write_bytes(data)
            self.data["inputs"].append({"repo_path": relative.as_posix(),
                                        "snapshot_path": "sources/" + relative.as_posix(),
                                        "size_bytes": len(data), "sha256": sha256(data)})
            self.save()
        # A sorted path/hash list identifies the captured inputs independently
        # of Git HEAD, including unstaged or untracked source changes.
        identity = json.dumps([(entry["repo_path"], entry["sha256"])
                               for entry in self.data["inputs"]], separators=(",", ":"))
        self.data["input_set_sha256"] = sha256(identity.encode("utf-8"))
        self.save()

    def git_identity(self):
        git = shutil.which("git")
        if git is None:
            self.data["git"] = {"available": False, "reason": "git executable not found"}
            self.save()
            return
        head_code, head = self.command("git-head", [git, "rev-parse", "HEAD"])
        status_code, status = self.command("git-status", [git, "status", "--porcelain=v1",
                                                          "--untracked-files=all"])
        if head_code or status_code:
            self.data["git"] = {"available": False, "reason": "Git identity probe failed",
                                "head_exit_code": head_code, "status_exit_code": status_code}
        else:
            self.data["git"] = {"available": True, "head": head.strip(),
                                "dirty": bool(status.strip()), "status_porcelain": status}
        self.save()

    def toolchain(self):
        requested = self.data["compiler"]["requested"]
        compiler = shutil.which(requested)
        if compiler is None:
            raise BuildFailure(f"ARM Linux compiler not found: {requested}. "
                               "Install gcc-arm-linux-gnueabihf and libc6-dev-armhf-cross in WSL Ubuntu.")
        # which() can return ./wrapper (or a relative PATH entry). Compilation
        # changes cwd to the snapshot, so anchor the executable at the repo now.
        compiler = str((ROOT / compiler).absolute())
        self.data["compiler"]["resolved_path"] = compiler
        code, version = self.command("compiler-version", [compiler, "--version"])
        self.data["compiler"]["version"] = version.strip()
        if code:
            raise BuildFailure("Compiler --version failed", code)
        code, machine = self.command("compiler-machine", [compiler, "-dumpmachine"])
        self.data["compiler"]["dumpmachine"] = machine.strip()
        if code:
            raise BuildFailure("Compiler -dumpmachine failed", code)
        self.save()
        if not fnmatch.fnmatchcase(machine.strip(), "arm*-linux-gnueabihf"):
            raise BuildFailure(f"CC must be an ARM Linux hard-float compiler, got: {machine.strip()}")
        code, linker_name = self.command("linker-path", [compiler, "-print-prog-name=ld"])
        linker = shutil.which(linker_name.strip()) if not code else None
        if linker:
            code, version = self.command("binutils-version", [linker, "--version"])
            self.data["binutils"] = {"resolved_path": linker, "version": version.strip(),
                                     "exit_code": code}
        else:
            self.data["binutils"] = {"available": False, "reason": "linker probe unavailable"}
        self.save()
        return compiler

    def build(self, compiler):
        for app in self.data["apps"]:
            source = Path("software/hps/src") / (app + ".c")
            snapshot_root = self.path / "sources"
            if not (snapshot_root / source).is_file():
                raise BuildFailure(f"Missing source in snapshot: {source}")
            binary = self.path / "bin" / app
            argv = [compiler, *FLAGS, str(source), "-o", str(binary)]
            code, _ = self.command("compile-" + app, argv, cwd=snapshot_root)
            if code:
                raise BuildFailure(f"Build failed for {app}; compiler exit code {code}", code)
            data = binary.read_bytes()
            self.data["outputs"].append({"app": app, "path": "bin/" + app,
                                         "size_bytes": len(data), "sha256": sha256(data)})
            self.save()
            self.say(f"Built archived ELF: {binary}")

    def commit_success(self):
        # The current registry has one application. Prepare all fallible logging
        # and metadata work before replacing its last-good convenience binary.
        output = self.data["outputs"][0]
        binary = self.path / output["path"]
        stable = ROOT / "build/hps/linux/bin" / output["app"]
        stable.parent.mkdir(parents=True, exist_ok=True)
        temporary = stable.with_name("." + output["app"] + "." + self.data["run_id"] + ".tmp")
        try:
            shutil.copy2(binary, temporary)
            # WSL/Linux: pending SIGINT/SIGTERM are delivered only after the
            # replace and flag agree. An accepted commit is never relabeled failed.
            previous_mask = signal.pthread_sigmask(signal.SIG_BLOCK,
                                                   {signal.SIGINT, signal.SIGTERM})
            try:
                self.data.update(status="succeeded", exit_code=0, time_end=utc_now())
                output["convenience_path"] = stable.relative_to(ROOT).as_posix()
                self.say(f"Artifacts ready; committing {stable}. Run: {self.path}")
                self.save()
                self.log.close()
                os.replace(temporary, stable)
                self.committed = True
            finally:
                signal.pthread_sigmask(signal.SIG_SETMASK, previous_mask)
        finally:
            if not self.committed:
                try:
                    temporary.unlink(missing_ok=True)
                except OSError:
                    pass  # An unused temporary file cannot replace the old ELF.

    def finish(self, code, error=None):
        if code == 0:
            self.commit_success()
            return
        self.data.update(status="failed", exit_code=code, time_end=utc_now())
        for output in self.data["outputs"]:
            output.pop("convenience_path", None)
        if error:
            self.data["error"] = error
        # A precommit close/replace failure must still permit a failed record.
        self.save()
        if self.log.closed:
            self.log = (self.path / "logs/build.log").open("a", encoding="utf-8")
        if error:
            self.say(error)
        self.say(f"Build {self.data['status']}. Run: {self.path}")
        self.log.close()


def main():
    arguments = sys.argv[1:]
    target, validation_error = validate_target(arguments)
    if validation_error:
        print(validation_error, file=sys.stderr)
        journal_failure(2, validation_error, "arguments", arguments=arguments)
        return 2
    run = None
    code, error = 1, "Build did not complete"
    phase = "run-initialization"
    phase_command_start = 0

    def interrupted(signum, _frame):
        if run is None or not run.committed:
            raise KeyboardInterrupt(f"Interrupted by signal {signum}")

    signal.signal(signal.SIGINT, interrupted)
    signal.signal(signal.SIGTERM, interrupted)
    try:
        run = BuildRun(target)
        run.say(f"HPS build run: {run.path}")
        phase = "snapshot"
        run.snapshot()
        phase = "git-identity"
        run.git_identity()
        phase = "toolchain"
        phase_command_start = len(run.data["commands"])
        compiler = run.toolchain()
        phase = "build"
        phase_command_start = len(run.data["commands"])
        run.build(compiler)
        phase = "commit"
        run.finish(0)
        code, error = 0, None
    except BuildFailure as failure:
        code, error = failure.exit_code, str(failure)
    except KeyboardInterrupt as interruption:
        code, error = 130, str(interruption) or "Build interrupted"
    except Exception as failure:
        code, error = 1, str(failure)
    finally:
        if run is None or not run.committed:
            if run is None:
                print(error, file=sys.stderr)
            else:
                # Preserve the primary exit code even when final metadata or
                # log writes fail (for example a full/unwritable filesystem).
                try:
                    run.finish(code, error)
                except (Exception, KeyboardInterrupt) as finalization_error:
                    print(f"Warning: cannot finalize failed run: {finalization_error}",
                          file=sys.stderr)
                    error += f"; failed run finalization: {finalization_error}"
                    print(error, file=sys.stderr)
                if (phase in ("toolchain", "build")
                        and len(run.data["commands"]) > phase_command_start):
                    phase = run.data["commands"][-1]["phase"]
            journal_failure(code, error, phase, run, arguments)
    # Unix signal return codes are retained in JSON, normalized for the CLI.
    return 0 if run is not None and run.committed else (code if code >= 0 else 128 - code)


if __name__ == "__main__":
    sys.exit(main())
