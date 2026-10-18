"""Behavior checks for local failure evidence; no build tools or board required."""

from concurrent.futures import ThreadPoolExecutor
import hashlib
import importlib.util
import json
import os
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest
from unittest.mock import patch


SCRIPT = Path(__file__).resolve().parents[1] / "bug_journal.py"
SPEC = importlib.util.spec_from_file_location("bug_journal", SCRIPT)
journal = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(journal)


class FailureJournalTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory(prefix="failure journal ")
        self.root = Path(self.temp.name).resolve()

    def tearDown(self):
        self.temp.cleanup()

    def load_record(self, incident):
        return json.loads((incident / "record.json").read_text(encoding="utf-8"))

    def test_log_refs_negative_exit_and_metadata_snapshot(self):
        run = self.root / "build" / "run with spaces"
        run.mkdir(parents=True)
        log = run / "compile.log"
        log.write_bytes(b"compiler start\nerror: missing symbol\n")
        original_hash = hashlib.sha256(log.read_bytes()).hexdigest()
        metadata = {"inputs": [Path("src/design.v")], "status": "failed"}
        with patch.object(journal, "_git_state", return_value={"head": "test", "dirty": True}):
            incident = journal.record_failure(
                self.root, "hardware", message="Missing symbol", exit_code=-9,
                phase="compile", run_directory=run.relative_to(self.root),
                record=metadata, logs=[log.relative_to(self.root)],
                command=["compiler", Path("src/design.v")],
            )
        metadata["status"] = "changed later"
        captured = self.load_record(incident)
        self.assertEqual(captured["exit_code"], -9)
        self.assertEqual(captured["run_directory"]["repository_relative_path"], "build/run with spaces")
        self.assertEqual(captured["logs"][0]["repository_relative_path"], "build/run with spaces/compile.log")
        self.assertEqual(captured["logs"][0]["absolute_path"], str(log))
        self.assertEqual(captured["run_metadata"]["status"], "failed")
        self.assertEqual(captured["run_metadata"]["inputs"], [str(Path("src/design.v"))])
        self.assertEqual(hashlib.sha256(log.read_bytes()).hexdigest(), original_hash)
        self.assertIn("error: missing symbol", (incident / "diagnostics.log").read_text(encoding="utf-8"))
        self.assertIsNone(captured["confirmed_root_cause"])
        self.assertIsNone(captured["verification"])
        self.assertIn("Chưa xác nhận", (incident / "journal.md").read_text(encoding="utf-8"))

    def test_bounded_capture_missing_evidence_and_unavailable_git(self):
        log = self.root / "long.log"
        original = b"BEGIN-EVIDENCE\n" + b"x" * (journal.MAX_LOG_BYTES * 4) + b"\nEND-EVIDENCE\n"
        log.write_bytes(original)
        source = self.root / "source.v"
        source.write_text("module private_source; endmodule", encoding="utf-8")
        binary = self.root / "binary.log"
        binary.write_bytes(b"binary\x00content")
        waveform = self.root / "trace.vcd"
        waveform.write_text("waveform content", encoding="utf-8")
        with patch.object(journal.subprocess, "run", side_effect=FileNotFoundError("git unavailable")):
            incident = journal.record_failure(
                self.root, "software", message="Compiler failed", exit_code=23,
                logs=[log, self.root / "missing.log", source, binary, waveform],
            )
        captured = self.load_record(incident)
        evidence = captured["logs"]
        self.assertTrue(evidence[0]["truncated"])
        self.assertEqual(evidence[0]["original_size_bytes"], len(original))
        self.assertLessEqual(evidence[0]["excerpt_bytes"], journal.MAX_LOG_BYTES)
        self.assertEqual(evidence[1]["status"], "unavailable")
        self.assertEqual([item["status"] for item in evidence[2:]], ["skipped"] * 3)
        diagnostic = (incident / "diagnostics.log").read_text(encoding="utf-8")
        self.assertIn("BEGIN-EVIDENCE", diagnostic)
        self.assertIn("END-EVIDENCE", diagnostic)
        self.assertIn("TRUNCATED", diagnostic)
        self.assertNotIn("private_source", diagnostic)
        self.assertNotIn("waveform content", diagnostic)
        self.assertIsNone(captured["git"]["head"])
        self.assertIsNone(captured["git"]["dirty"])
        self.assertTrue(captured["git"]["limitations"])
        self.assertEqual(log.read_bytes(), original)
        self.assertEqual({path.name for path in incident.iterdir()}, {"record.json", "journal.md", "diagnostics.log"})

    def test_timeout_keeps_basic_incident(self):
        with patch.object(journal.subprocess, "run", side_effect=subprocess.TimeoutExpired("git", 3)):
            incident = journal.record_failure(self.root, "generation", message="Generator stopped")
        self.assertEqual(self.load_record(incident)["message"], "Generator stopped")
        self.assertIsNone(self.load_record(incident)["git"]["dirty"])

    def test_directory_log_is_skipped(self):
        directory = self.root / "directory.log"
        directory.mkdir()
        with patch.object(journal, "_git_state", return_value={"head": None, "dirty": None}):
            incident = journal.record_failure(self.root, "hardware", message="Build failed", logs=[directory])
        evidence = self.load_record(incident)["logs"][0]
        self.assertEqual(evidence["status"], "skipped")
        self.assertIn("regular file", evidence["limitation"])
        self.assertEqual(evidence["excerpt_bytes"], 0)

    @unittest.skipUnless(os.name == "posix", "POSIX FIFO behavior")
    def test_fifo_log_is_skipped_without_waiting_for_writer(self):
        fifo = self.root / "pipe.log"
        os.mkfifo(fifo)
        # Run capture in a bounded child: a regression cannot hang the test
        # process, and the test never opens the FIFO or supplies a writer.
        result = subprocess.run(
            [sys.executable, str(SCRIPT), "--root", str(self.root), "--domain", "hardware",
             "--message", "Build failed", "--log", str(fifo)],
            capture_output=True, text=True, check=False, timeout=15,
        )
        self.assertEqual(result.returncode, 0, result.stderr)
        incidents = list((self.root / "build" / "bug" / "hardware").iterdir())
        self.assertEqual(len(incidents), 1)
        evidence = self.load_record(incidents[0])["logs"][0]
        self.assertEqual(evidence["status"], "skipped")
        self.assertEqual(evidence["excerpt_bytes"], 0)

    def test_descriptor_check_rejects_stat_open_replacement(self):
        log = self.root / "race.log"
        log.write_text("Do not read a nonregular replacement", encoding="utf-8")
        nonregular = os.stat_result((0o010600, 0, 0, 1, 0, 0, 0, 0, 0, 0))
        with patch.object(journal, "_git_state", return_value={"head": None, "dirty": None}):
            with patch.object(journal.os, "fstat", return_value=nonregular):
                with patch.object(journal.os, "fdopen", side_effect=AssertionError("nonregular descriptor must not be read")):
                    incident = journal.record_failure(self.root, "hardware", message="Build failed", logs=[log])
        evidence = self.load_record(incident)["logs"][0]
        self.assertEqual(evidence["status"], "skipped")
        self.assertIn("Opened object", evidence["limitation"])

    def test_concurrent_incidents_preserve_existing_notes(self):
        base = journal.initialize(self.root)
        help_path = base / "README.md"
        help_path.write_text("My retained notes", encoding="utf-8")
        with patch.object(journal, "_git_state", return_value={"head": None, "dirty": None}):
            with ThreadPoolExecutor(max_workers=4) as executor:
                incidents = list(executor.map(
                    lambda number: journal.record_failure(self.root, "hardware", message=f"Failure {number}"),
                    range(8),
                ))
        self.assertEqual(len(set(incidents)), 8)
        self.assertEqual(help_path.read_text(encoding="utf-8"), "My retained notes")
        for number, incident in enumerate(incidents):
            self.assertEqual(self.load_record(incident)["message"], f"Failure {number}")
        note_path = incidents[0] / "journal.md"
        note_path.write_text("Confirmed correction", encoding="utf-8")
        journal.initialize(self.root)
        self.assertEqual(note_path.read_text(encoding="utf-8"), "Confirmed correction")

    def test_cli_init_manual_capture_and_invalid_options(self):
        result = subprocess.run([sys.executable, str(SCRIPT), "--root", str(self.root), "--init"],
                                capture_output=True, text=True, check=False)
        self.assertEqual(result.returncode, 0, result.stderr)
        base = self.root / "build" / "bug"
        for domain in journal.DOMAINS:
            self.assertTrue((base / domain).is_dir())
            self.assertEqual(list((base / domain).iterdir()), [])
        invalid = subprocess.run([sys.executable, str(SCRIPT), "--root", str(self.root), "--init", "--message", "bad"],
                                 capture_output=True, text=True, check=False)
        self.assertEqual(invalid.returncode, 2)
        self.assertEqual(list((base / "hardware").iterdir()), [])
        captured = subprocess.run(
            [sys.executable, str(SCRIPT), "--root", str(self.root), "--domain", "hardware",
             "--message", "GUI compile failed", "--phase", "fit", "--exit-code", "-15",
             "--log", "missing.log"], capture_output=True, text=True, check=False,
        )
        self.assertEqual(captured.returncode, 0, captured.stderr)
        incidents = list((base / "hardware").iterdir())
        self.assertEqual(len(incidents), 1)
        self.assertEqual(self.load_record(incidents[0])["exit_code"], -15)


if __name__ == "__main__":
    unittest.main()
