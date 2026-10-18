#!/usr/bin/env python3
"""Preserve a failure summary without changing the original build evidence."""

import argparse
from datetime import datetime, timezone
import json
import os
from pathlib import Path
import platform
import stat
import subprocess
import sys
import uuid


DOMAINS = ("hardware", "software", "generation")
MAX_LOG_BYTES = 128 * 1024
TEXT_LOG_SUFFIXES = {".log", ".txt", ".rpt", ".out", ".err", ".summary"}
HELP_TEXT = """# Nhật ký lỗi cục bộ

Mỗi sự cố có thư mục riêng trong `hardware/`, `software/` hoặc `generation/`:

- `record.json`: thời điểm UTC, mã thoát gốc, bước lỗi, Git/môi trường và tham chiếu run/log.
- `diagnostics.log`: thông báo lỗi và trích đoạn đầu/cuối log văn bản, tối đa 128 KiB/log.
- `journal.md`: chỗ ghi giả thuyết, nguyên nhân đã xác nhận, sửa đổi và kiểm chứng.

Log đầy đủ và nguồn của run vẫn ở đường dẫn gốc trong `record.json`; waveform,
binary, mã nguồn và cache không được sao chép vào sự cố. Không tự xác định nguyên nhân.
Giữ chứng cứ gốc và điền nhật ký sau khi xác minh. Không tự xóa lịch sử.

`build/` bị Git bỏ qua. Khi cần chia sẻ, chủ động xuất nhật ký/chứng cứ đã chọn
sang tài liệu có phiên bản; kiểm tra thông tin riêng tư trước khi chia sẻ.
Các build Python được tích hợp mới ghi tự động; GUI Quartus, chạy trên board và
các tool chưa tích hợp cần nhập log thủ công. Hướng dẫn: `docs/development/bug-logging.md`.
"""


def _utc_now():
    return datetime.now(timezone.utc).isoformat().replace("+00:00", "Z")


def _json_safe(value):
    if isinstance(value, dict):
        return {str(key): _json_safe(item) for key, item in value.items()}
    if isinstance(value, (list, tuple)):
        return [_json_safe(item) for item in value]
    if isinstance(value, (str, int, float, bool)) or value is None:
        return value
    return str(value)


def _reference(root, path):
    path = Path(path)
    absolute = (root / path).resolve() if not path.is_absolute() else path.resolve()
    try:
        relative = absolute.relative_to(root).as_posix()
    except ValueError:
        relative = None
    return {"supplied_path": str(path), "absolute_path": str(absolute),
            "repository_relative_path": relative}


def _git_state(root):
    state = {"head": None, "dirty": None, "limitations": []}
    for key, arguments in (
        ("head", ["rev-parse", "HEAD"]),
        ("dirty", ["status", "--porcelain", "--untracked-files=normal"]),
    ):
        try:
            result = subprocess.run(
                ["git", "-C", str(root), *arguments], capture_output=True,
                timeout=3, check=False,
            )
            if result.returncode:
                state["limitations"].append(
                    f"git {key}: exit {result.returncode}; "
                    + result.stderr[:1024].decode("utf-8", errors="replace")
                )
            else:
                state[key] = (bool(result.stdout.strip()) if key == "dirty"
                              else result.stdout.decode("ascii", errors="replace").strip())
        except (OSError, subprocess.TimeoutExpired) as error:
            state["limitations"].append(f"git {key}: {error}")
    return state


def initialize(root):
    """Create local journal folders and help without overwriting user notes."""
    root = Path(root).resolve()
    base = root / "build" / "bug"
    for domain in DOMAINS:
        (base / domain).mkdir(parents=True, exist_ok=True)
    try:
        with (base / "README.md").open("x", encoding="utf-8", newline="\n") as stream:
            stream.write(HELP_TEXT)
    except FileExistsError:
        pass
    return base


def _log_excerpt(root, supplied_path):
    evidence = _reference(root, supplied_path)
    evidence.update({"original_size_bytes": None, "excerpt_bytes": 0,
                     "truncated": False, "status": "unavailable"})
    path = Path(evidence["absolute_path"])
    try:
        original_stat = path.stat()
        evidence["original_size_bytes"] = original_stat.st_size
        if not stat.S_ISREG(original_stat.st_mode):
            evidence.update(status="skipped", limitation="Not a regular file; no diagnostic read attempted")
            return evidence, ""
        # Restrict capture to diagnostic text; user input cannot import a VCD,
        # executable, HDL source or simulator cache merely by passing --log.
        if path.suffix.lower() not in TEXT_LOG_SUFFIXES and path.name != "transcript":
            evidence.update(status="skipped", limitation="Not a supported text-log filename")
            return evidence, ""
        # A regular file may be replaced after stat. Nonblocking POSIX open
        # prevents a replacement FIFO from waiting for a writer; descriptor
        # checks reject all nonregular replacements before any read.
        flags = os.O_RDONLY | getattr(os, "O_BINARY", 0)
        if os.name == "posix":
            flags |= os.O_NONBLOCK | getattr(os, "O_NOFOLLOW", 0)
        descriptor = os.open(path, flags)
        try:
            opened_stat = os.fstat(descriptor)
            if not stat.S_ISREG(opened_stat.st_mode):
                evidence.update(status="skipped", limitation="Opened object is not a regular file; no diagnostic read attempted")
                return evidence, ""
            with os.fdopen(descriptor, "rb", closefd=False) as stream:
                size = opened_stat.st_size
                evidence["original_size_bytes"] = size
                if size <= MAX_LOG_BYTES:
                    chunks = [stream.read(MAX_LOG_BYTES)]
                else:
                    half = MAX_LOG_BYTES // 2
                    chunks = [stream.read(half)]
                    stream.seek(max(half, size - half))
                    chunks.append(stream.read(half))
                    evidence["truncated"] = True
        finally:
            os.close(descriptor)
        if any(b"\x00" in chunk for chunk in chunks):
            evidence.update(status="skipped", limitation="Binary/NUL data detected; no excerpt retained")
            return evidence, ""
        evidence.update(status="captured", excerpt_bytes=sum(map(len, chunks)),
                        encoding="UTF-8 with replacement for undecodable bytes")
        decoded = [chunk.decode("utf-8", errors="replace") for chunk in chunks]
        excerpt = "\n\n[TRUNCATED: omitted middle; full log at original path]\n\n".join(decoded)
        return evidence, excerpt
    except OSError as error:
        evidence["limitation"] = str(error)
        return evidence, ""


def _journal(message, incident_id):
    # Use a fenced block so an error containing Markdown cannot alter the form.
    fence = "`" * max(3, max((len(part) for part in message.split("\n")
                             if part and set(part) == {"`"}), default=0) + 1)
    return f"""# Nhật ký sự cố {incident_id}

## Triệu chứng quan sát

{fence}text
{message}
{fence}

Nguồn: [record.json — message, exit_code, phase](record.json),
[diagnostics.log — thông báo và trích đoạn log](diagnostics.log).

## Thay đổi hoặc lần chạy dẫn tới lỗi

Run/câu lệnh và phiên bản được ghi tại [record.json — run_directory, command, git, run_metadata](record.json).
Thay đổi nghi gây lỗi: chưa xác định; bổ sung tệp/dòng hoặc commit và điều kiện tái hiện.

## Chứng cứ quan sát

Đọc [diagnostics.log](diagnostics.log) và log đầy đủ theo [record.json — logs](record.json).
Ghi tệp/dòng log, thời điểm, đầu vào và kết quả đo có thể kiểm chứng: chưa bổ sung.

## Giả thuyết chưa xác nhận

Chưa xác định. Ghi giả thuyết riêng với chứng cứ ủng hộ/phản bác và cách kiểm tra.

## Nguyên nhân đã xác nhận

Chưa xác nhận. Chỉ cập nhật sau khi có chứng cứ kiểm tra/tái hiện.

## Điều chỉnh khắc phục

Chưa có. Ghi tệp/dòng, commit, lý do thay đổi và liên kết chứng cứ.

## Kiểm chứng sau sửa

Câu lệnh và môi trường: chưa thực hiện.
Kết quả, log, run, điều kiện board hoặc mô phỏng: chưa có.

## Trạng thái

Mở — cần phân tích. Khi đóng, ghi ngày, người xác minh và bằng chứng kiểm chứng.
"""


def record_failure(root, domain, *, message, exit_code=1, phase=None,
                   run_directory=None, record=None, logs=(), command=None):
    """Record one failure; callers must preserve their original error if this fails.

    Relative paths resolve against root. Only bounded textual diagnostics are
    copied; run metadata is a snapshot, and original run files remain untouched.
    """
    if domain not in DOMAINS:
        raise ValueError(f"domain must be one of {DOMAINS}")
    if not isinstance(exit_code, int) or isinstance(exit_code, bool):
        raise TypeError("exit_code must be an integer (negative signal codes are retained)")
    root = Path(root).resolve()
    message = str(message)
    base = initialize(root) / domain
    timestamp = _utc_now()
    # Exclusive directory creation, not a mutable central index, separates
    # simultaneous failures and prevents overwriting previous journal entries.
    for _ in range(8):
        incident_id = datetime.now(timezone.utc).strftime("%Y%m%dT%H%M%S.%fZ") + "-" + uuid.uuid4().hex
        incident = base / incident_id
        try:
            incident.mkdir()
            break
        except FileExistsError:
            continue
    else:
        raise FileExistsError("Unable to allocate a unique incident folder")
    payload = {
        "schema_version": 1, "format": "fpga-vision-enhancement.failure-journal",
        "incident_id": incident_id, "created_utc": timestamp,
        "domain": domain, "status": "open", "repository_root": str(root),
        "message": message, "exit_code": exit_code, "phase": _json_safe(phase),
        "run_directory": _reference(root, run_directory) if run_directory is not None else None,
        "command": _json_safe(command), "run_metadata": _json_safe(record),
        "git": _git_state(root),
        "environment": {"platform": platform.platform(), "python": sys.version,
                        "executable": sys.executable, "working_directory": str(Path.cwd()),
                        "wsl_distribution": os.environ.get("WSL_DISTRO_NAME")},
        "log_excerpt_limit_bytes": MAX_LOG_BYTES, "logs": [],
        "confirmed_root_cause": None, "corrective_change": None,
        "verification": None,
        "limitations": ["Build evidence only; root cause and board behavior require verification",
                        "Git state is observed at capture time, not an atomic source snapshot"],
    }
    with (incident / "diagnostics.log").open("x", encoding="utf-8", newline="\n") as stream:
        stream.write(f"Incident: {incident_id}\nUTC: {timestamp}\nDomain: {domain}\n"
                     f"Phase: {phase}\nOriginal exit code: {exit_code}\nMessage:\n{message}\n")
        for supplied_log in logs:
            evidence, excerpt = _log_excerpt(root, supplied_log)
            payload["logs"].append(evidence)
            stream.write("\n--- LOG REFERENCE ---\n" + json.dumps(evidence, ensure_ascii=False) + "\n")
            if excerpt:
                stream.write(excerpt + "\n")
    with (incident / "record.json").open("x", encoding="utf-8", newline="\n") as stream:
        json.dump(payload, stream, ensure_ascii=False, indent=2, allow_nan=False)
        stream.write("\n")
    with (incident / "journal.md").open("x", encoding="utf-8", newline="\n") as stream:
        stream.write(_journal(message, incident_id))
    return incident


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--root", type=Path, default=Path(__file__).resolve().parents[2])
    parser.add_argument("--init", action="store_true", help="Create folders/help without an incident")
    parser.add_argument("--domain", choices=DOMAINS)
    parser.add_argument("--message")
    parser.add_argument("--exit-code", type=int, default=1)
    parser.add_argument("--phase")
    parser.add_argument("--run-directory", type=Path)
    parser.add_argument("--log", type=Path, action="append", default=[])
    parser.add_argument("--command", help="Original command for a manually captured incident")
    args = parser.parse_args()
    if args.init:
        if any((args.domain, args.message, args.phase, args.run_directory, args.log, args.command)) or args.exit_code != 1:
            parser.error("--init accepts only --root; omit incident arguments")
        print(initialize(args.root))
        return 0
    if not args.domain or not args.message:
        parser.error("--domain and --message are required unless --init is used")
    print(record_failure(args.root, args.domain, message=args.message,
                         exit_code=args.exit_code, phase=args.phase,
                         run_directory=args.run_directory, logs=args.log, command=args.command))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
