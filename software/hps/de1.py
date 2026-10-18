#!/usr/bin/env python3
"""Build the current C app against a retained SDK; explicitly upload/run over SSH."""
import argparse
from collections import deque
from datetime import datetime, timezone
import hashlib
import json
import os
from pathlib import Path, PurePosixPath
import re
import shutil
import signal
import subprocess
import sys
import uuid

ROOT = Path(__file__).resolve().parents[2]
APP = "vga_simple_display"
DEFAULT_SDK = Path.home() / ".local/share/de1-sdk/linaro-12.11-armhf"
SDK_RECORDS = ("SDK_MANIFEST.sha256", "SDK_SYMLINKS.tsv", "SDK_INFO.txt")
HOST = re.compile(r"[A-Za-z0-9][A-Za-z0-9_.-]{0,252}\Z")
USER = re.compile(r"[A-Za-z_][A-Za-z0-9_.-]{0,63}\Z")
HEX = re.compile(r"(?:0[xX])?[0-9a-fA-F]{1,6}\Z")


class WorkflowError(Exception):
    def __init__(self, message, code=1):
        super().__init__(message)
        self.code = code if code > 0 else 128 - code


def sha256(path):
    digest = hashlib.sha256()
    with Path(path).open("rb") as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(block)
    return digest.hexdigest()


def sdk_file(sdk, relative):
    """Interpret target-absolute symlinks within the SDK, never the host root."""
    if PurePosixPath(relative).is_absolute():
        raise WorkflowError("SDK path must be relative")
    pending, resolved = deque(PurePosixPath(relative).parts), []
    links = 0
    while pending:
        part = pending.popleft()
        if part == "..":
            if not resolved:
                raise WorkflowError("SDK path escapes its root")
            resolved.pop()
        elif part not in ("", "."):
            candidate = sdk.joinpath(*resolved, part)
            if candidate.is_symlink():
                links += 1
                if links > 40:
                    raise WorkflowError("SDK symlink loop")
                target = PurePosixPath(os.readlink(candidate))
                if target.is_absolute():
                    resolved.clear()
                pending.extendleft(reversed(target.parts[1:] if target.is_absolute()
                                            else target.parts))
            else:
                resolved.append(part)
    return sdk.joinpath(*resolved)


def verify_sdk(sdk, session):
    if not sdk.is_dir():
        raise WorkflowError("SDK missing: " + str(sdk) + ". See README_REMOTE.md.")
    for name in SDK_RECORDS:
        source = sdk / name
        if not source.is_file() or source.is_symlink():
            raise WorkflowError("SDK record missing/not regular: " + str(source))
        shutil.copyfile(source, session.path / name)
    manifest_lines = (sdk / SDK_RECORDS[0]).read_text(encoding="utf-8").splitlines()
    if not manifest_lines:
        raise WorkflowError("SDK manifest is empty")
    for line in manifest_lines:
        match = re.fullmatch(r"([a-f0-9]{64}) [ *](.+)", line)
        if not match or sha256(sdk_file(sdk, match[2])) != match[1]:
            raise WorkflowError("SDK manifest mismatch: " + line[:160])
    for line in (sdk / SDK_RECORDS[1]).read_text(encoding="utf-8").splitlines():
        relative, target = line.split("\t", 1)
        if PurePosixPath(target).is_absolute():
            raise WorkflowError("SDK must have relocated relative symlinks: " + relative)
        link = sdk_file(sdk, str(PurePosixPath(relative).parent)) / PurePosixPath(relative).name
        if not link.is_symlink() or os.readlink(link) != target:
            raise WorkflowError("SDK symlink mismatch: " + relative)
    original_links = sdk / "SDK_SYMLINKS_ORIGINAL.tsv"
    if original_links.is_file() and not original_links.is_symlink():
        shutil.copyfile(original_links, session.path / original_links.name)
    session.data["sdk"] = {"path": str(sdk), "records": {
        name: sha256(sdk / name) for name in SDK_RECORDS}}
    if original_links.is_file():
        session.data["sdk"]["records"][original_links.name] = sha256(original_links)
    session.save()


def read_config(path):
    if not path.is_file():
        raise WorkflowError("Configure software/hps/de1.local.json from "
                            "de1.config.example.json; no SSH connection attempted.", 2)
    data = json.loads(path.read_text(encoding="utf-8-sig"))
    if not isinstance(data, dict):
        raise WorkflowError("SSH config must be a JSON object.", 2)
    host, user, port = data.get("host", ""), data.get("user", ""), data.get("port", 22)
    if not isinstance(host, str) or not HOST.fullmatch(host):
        raise WorkflowError("Set host to an SSH alias, DNS name or IPv4 address "
                            "in de1.local.json; no SSH connection attempted.", 2)
    if not isinstance(user, str) or (user and not USER.fullmatch(user)):
        raise WorkflowError("Invalid SSH user; leave blank to use your SSH alias.", 2)
    if type(port) is not int or not 1 <= port <= 65535:
        raise WorkflowError("SSH port must be an integer from 1 to 65535.", 2)
    return {"host": host, "user": user, "port": port}


def validate_image(path):
    if not path.is_file() or path.stat().st_size > 8 * 1024 * 1024:
        raise WorkflowError("Input must be a regular RGB24 hex file, at most 8 MiB.", 2)
    count = 0
    with path.open(encoding="ascii") as stream:
        for line in stream:
            for token in line.split():
                count += 1
                if count > 640 * 480 or not HEX.fullmatch(token):
                    raise WorkflowError("Input needs exactly 307200 RGB24 hex "
                                        "tokens, each 0..FFFFFF.", 2)
    if count != 640 * 480:
        raise WorkflowError("Input has " + str(count) + " tokens; expected 307200.", 2)


class Session:
    def __init__(self, command):
        self.identifier = datetime.now(timezone.utc).strftime("%Y%m%dT%H%M%SZ") + "-" + uuid.uuid4().hex[:12]
        self.path = ROOT / "build/hps/remote/runs" / self.identifier
        self.path.mkdir(parents=True, exist_ok=False)
        (self.path / "release").mkdir()
        self.data = {"command": command, "session": self.identifier, "status": "running",
                     "commands": [], "helpers": {}, "exit_code": None}
        for name in ("de1.py", "de1.sh", "legacy-cc.sh", "de1.ps1"):
            source = ROOT / "software/hps" / name
            if source.is_file():
                shutil.copyfile(source, self.path / name)
                self.data["helpers"][name] = sha256(source)
        self.save()
        print("DE1 workflow: " + str(self.path), flush=True)

    def save(self):
        temporary = self.path / "workflow.json.tmp"
        temporary.write_text(json.dumps(self.data, indent=2, ensure_ascii=False) + "\n",
                             encoding="utf-8")
        os.replace(temporary, self.path / "workflow.json")

    def command(self, phase, argv, env=None):
        record = {"phase": phase, "argv": [str(arg) for arg in argv],
                  "start_utc": datetime.now(timezone.utc).isoformat(), "exit_code": None}
        self.data["commands"].append(record)
        self.save()
        output = []
        process = None
        try:
            with (self.path / (phase + ".log")).open("wb") as log:
                process = subprocess.Popen(record["argv"], cwd=ROOT, env=env,
                                           stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
                try:
                    for line in iter(process.stdout.readline, b""):
                        log.write(line)
                        log.flush()
                        text = line.decode("utf-8", errors="replace")
                        output.append(text)
                        print(text, end="", flush=True)
                    record["exit_code"] = process.wait()
                except KeyboardInterrupt:
                    process.send_signal(signal.SIGINT)
                    try:
                        process.wait(timeout=5)
                    except subprocess.TimeoutExpired:
                        process.terminate()
                        process.wait(timeout=5)
                    record["exit_code"] = 130
                    raise WorkflowError("Interrupted; inspect board process state if SSH disconnected.", 130)
        finally:
            if process is not None and process.stdout is not None:
                process.stdout.close()
            record["end_utc"] = datetime.now(timezone.utc).isoformat()
            self.save()
        if record["exit_code"]:
            raise WorkflowError(phase + " failed; see " + str(self.path / (phase + ".log")),
                                record["exit_code"])
        return "".join(output)


def check_elf(binary, sdk, session):
    outputs = {}
    env = dict(os.environ, LC_ALL="C")
    for label, option in (("header", "-h"), ("attributes", "-A"), ("loader", "-l"),
                          ("versions", "--version-info"), ("needed", "-d")):
        outputs[label] = session.command("check-" + label,
                                        ["arm-linux-gnueabihf-readelf", option, binary], env)
    if not re.search(r"Class:\s+ELF32", outputs["header"]) or not re.search(
            r"Machine:\s+ARM\s", outputs["header"]):
        raise WorkflowError("ELF must be 32-bit ARM")
    if "Tag_ABI_VFP_args: VFP registers" not in outputs["attributes"]:
        raise WorkflowError("ELF does not declare the required ARM hard-float ABI")
    loader = re.search(r"Requesting program interpreter:\s*([^\]]+)", outputs["loader"])
    if not loader or loader[1] not in ("/lib/ld-linux-armhf.so.3",
                                       "/lib/arm-linux-gnueabihf/ld-linux.so.3"):
        raise WorkflowError("Unexpected or missing ARMhf loader")
    if not sdk_file(sdk, loader[1].lstrip("/")).is_file():
        raise WorkflowError("ELF loader absent from SDK")
    versions = re.findall(r"\bGLIBC_(\d+(?:\.\d+)+)\b", outputs["versions"])
    if not versions or any(tuple(map(int, value.split("."))) > (2, 15)
                           for value in versions) or re.search(r"\bGLIBC_(?!\d)[A-Za-z_]", outputs["versions"]):
        raise WorkflowError("ELF requires unknown/private GLIBC or a version above 2.15")
    # Resolve the complete NEEDED closure using only the retained target runtime.
    queue = deque(re.findall(r"\(NEEDED\).*?\[([^\]]+)\]", outputs["needed"]))
    checked = {}
    while queue:
        library = queue.popleft()
        if library in checked:
            continue
        if not re.fullmatch(r"[A-Za-z0-9_.+-]+", library):
            raise WorkflowError("Unsafe NEEDED library name")
        candidates = [sdk_file(sdk, base + "/" + library) for base in
                      ("lib/arm-linux-gnueabihf", "usr/lib/arm-linux-gnueabihf", "lib", "usr/lib")]
        found = next((path for path in candidates if path.is_file()), None)
        if found is None:
            raise WorkflowError("Runtime library absent from SDK: " + library)
        checked[library] = {"path": str(found), "sha256": sha256(found)}
        dynamic = session.command("dependency-" + library,
                                  ["arm-linux-gnueabihf-readelf", "-d", found], env)
        queue.extend(re.findall(r"\(NEEDED\).*?\[([^\]]+)\]", dynamic))
    session.data["elf"] = {"path": str(binary), "sha256": sha256(binary),
                           "max_glibc": max(versions, key=lambda value: tuple(map(int, value.split(".")))),
                           "loader": loader[1], "needed": checked}
    session.save()
    return binary


def build_checked(sdk, session):
    env = dict(os.environ, CC=str(ROOT / "software/hps/legacy-cc.sh"), DE1_SDK=str(sdk))
    output = session.command("build", ["bash", "software/hps/build.sh", APP], env)
    prefix = "HPS build run: "
    run_line = next((line[len(prefix):] for line in output.splitlines()
                     if line.startswith(prefix)), None)
    if run_line is None:
        raise WorkflowError("Existing builder did not report its archived run")
    run = Path(run_line).resolve()
    if run.parent != (ROOT / "build/hps/linux/runs").resolve():
        raise WorkflowError("Unexpected archived build path")
    record = json.loads((run / "run.json").read_text(encoding="utf-8"))
    if record["status"] != "succeeded" or record["apps"] != [APP]:
        raise WorkflowError("Archived build is not a successful current-app build")
    binary = run / "bin" / APP
    if not any(item["app"] == APP and item["sha256"] == sha256(binary)
               for item in record["outputs"]):
        raise WorkflowError("Archived build output hash mismatch")
    session.data["build_run"] = str(run)
    return check_elf(binary, sdk, session)


def deploy(binary, image, config, session):
    release = session.path / "release"
    staged_binary = release / APP
    shutil.copyfile(binary, staged_binary)
    if sha256(staged_binary) != session.data["elf"]["sha256"]:
        raise WorkflowError("Binary changed after validation")
    names = [APP] + (["input_image.hex"] if image else [])
    metadata = {"session": session.identifier, "app": APP, "build_run": session.data["build_run"],
                "sdk": session.data["sdk"], "elf": session.data["elf"],
                "files": {name: sha256(release / name) for name in names}}
    (release / "release.json").write_text(json.dumps(metadata, indent=2) + "\n", encoding="utf-8")
    names.append("release.json")
    (release / "SHA256SUMS").write_text("".join(sha256(release / name) + "  " + name + "\n"
                                               for name in names), encoding="ascii")
    names.append("SHA256SUMS")
    destination = ((config["user"] + "@") if config["user"] else "") + config["host"]
    ssh = ["ssh", "-p", str(config["port"]), "-o", "StrictHostKeyChecking=yes",
           "-o", "ConnectTimeout=10", destination]
    relative = "de1-releases/" + session.identifier
    remote = '"$HOME/' + relative + '"'
    create = ('umask 077; test ! -L "$HOME/de1-releases" && '
              '(test -d "$HOME/de1-releases" || mkdir -m 700 "$HOME/de1-releases") && '
              'mkdir -m 700 ' + remote)
    session.command("remote-create", [*ssh, create])
    session.command("upload", ["scp", "-O", "-P", str(config["port"]),
                              "-o", "StrictHostKeyChecking=yes", "-o", "ConnectTimeout=10",
                              *[str(release / name) for name in names], destination + ":" + relative + "/"])
    session.command("remote-verify", [*ssh, "cd " + remote +
                                     " && sha256sum -c SHA256SUMS && chmod 700 " + APP])
    session.data["remote_release"] = relative
    session.save()
    print("Verified remote release: ~/" + relative, flush=True)
    if image:
        # PTY keeps the legacy application's stdout line-buffered and permits Ctrl+C.
        session.command("run", [ssh[0], "-tt", *ssh[1:],
                               "cd " + remote + " && exec ./" + APP + " ./input_image.hex"])


def main(arguments=None):
    parser = argparse.ArgumentParser(description=__doc__)
    commands = parser.add_subparsers(dest="command", required=True)
    commands.add_parser("build")
    check = commands.add_parser("check")
    check.add_argument("binary", nargs="?")
    push = commands.add_parser("push")
    push.add_argument("--run", metavar="RGB24_HEX_FILE")
    args = parser.parse_args(arguments)
    session = None
    code = 1
    try:
        if sys.platform != "linux":
            raise WorkflowError("Use de1.ps1 on Windows or de1.sh inside WSL/Linux.", 2)
        config = read_config(ROOT / "software/hps/de1.local.json") if args.command == "push" else None
        session = Session(args.command)
        sdk = Path(os.environ.get("DE1_SDK", str(DEFAULT_SDK))).expanduser().resolve()
        verify_sdk(sdk, session)
        image = None
        if args.command == "push" and args.run:
            original = Path(args.run).expanduser()
            image = session.path / "release/input_image.hex"
            if not original.is_file() or original.stat().st_size > 8 * 1024 * 1024:
                raise WorkflowError("Input file missing or above 8 MiB.", 2)
            shutil.copyfile(original, image)
            validate_image(image)
            session.data["input"] = {"source": str(original.absolute()), "sha256": sha256(image)}
        if args.command == "check":
            binary = Path(args.binary).expanduser().resolve() if args.binary else (
                ROOT / "build/hps/linux/bin" / APP)
            check_elf(binary, sdk, session)
        else:
            binary = build_checked(sdk, session)
            if config is not None:
                deploy(binary, image, config, session)
        code = 0
    except (WorkflowError, OSError, ValueError, KeyError) as error:
        code = error.code if isinstance(error, WorkflowError) else 1
        print("ERROR: " + str(error), file=sys.stderr)
        if session:
            session.data["error"] = str(error)
    finally:
        if session:
            session.data.update(status="succeeded" if code == 0 else "failed", exit_code=code)
            session.save()
    return code


if __name__ == "__main__":
    sys.exit(main())

