"""Fresh staging tests; no vendor tools invoked."""
import importlib.util
import contextlib
import io
import json
from pathlib import Path
import tempfile
import unittest
from unittest import mock

ROOT = Path(__file__).resolve().parents[3]
SPEC = importlib.util.spec_from_file_location("build_fpga", ROOT / "software/python/build_fpga.py")
BUILD = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(BUILD)


class BuildStagingTests(unittest.TestCase):
    def test_stage_current_sources_and_rebase_descriptor(self):
        config = BUILD.load_config(ROOT / "hardware/de1_soc/build.json")
        with tempfile.TemporaryDirectory() as folder:
            stage = Path(folder).resolve() / "run"
            records = BUILD.stage_inputs(config, stage)
            self.assertGreater(len(records), 10)
            self.assertIn("PATH dehazing_system_top.v TOP_LEVEL_FILE", (stage / "dehazing_system_top_hw.tcl").read_text())
            project = (stage / "DE1_SoC_Computer.qsf").read_text()
            self.assertNotIn("hex_decoder.v", project)
            self.assertIn("source de1_soc_pins.qsf", project)
            self.assertIn("-name SDC_FILE DE1_SoC_Computer.sdc", project)
            self.assertIn("-name QIP_FILE Computer_System/synthesis/Computer_System.qip", project)
            self.assertNotIn("../pin/", project)
            self.assertNotIn("../qsys/", project)
            for name in config["required_inputs"]:
                self.assertTrue((stage / name).is_file(), name)

    def test_refuse_existing_stage(self):
        config = BUILD.load_config(ROOT / "hardware/de1_soc/build.json")
        with tempfile.TemporaryDirectory() as folder:
            with self.assertRaises(FileExistsError):
                BUILD.stage_inputs(config, Path(folder).resolve())

    def test_missing_input_is_reported_before_stage_creation(self):
        config = BUILD.load_config(ROOT / "hardware/de1_soc/build.json")
        config["required_inputs"].append("missing-input.v")
        with tempfile.TemporaryDirectory() as folder:
            stage = Path(folder).resolve() / "run"
            with self.assertRaises(ValueError):
                BUILD.stage_inputs(config, stage)
            self.assertFalse(stage.exists())


class BuildFailureJournalTests(unittest.TestCase):
    """Exercise the CLI failure boundary without Quartus or real incidents."""

    def setUp(self):
        self.folder = tempfile.TemporaryDirectory()
        self.addCleanup(self.folder.cleanup)
        # Production ROOT is resolved from __file__; normalize Windows short
        # temporary paths likewise before containment and relative-path checks.
        self.root = Path(self.folder.name).resolve()
        source = self.root / "hardware/design/rtl"
        source.mkdir(parents=True)
        (source / "top.v").write_text("module top; endmodule\n", encoding="utf-8")
        self.config = {"name": "test", "source_root": "hardware/design",
                       "stage_directories": ["rtl"], "required_inputs": ["top.v"],
                       "generation_order": ["System"], "family": "Cyclone V",
                       "device": "test-device", "project": "top"}
        self.config_path = self.root / "config.json"
        self.save_config()
        root_patch = mock.patch.object(BUILD, "ROOT", self.root)
        root_patch.start()
        self.addCleanup(root_patch.stop)
        self.journal = mock.Mock(return_value=self.root / "build/bug/hardware/incident")
        journal_patch = mock.patch.object(BUILD, "record_failure", self.journal)
        journal_patch.start()
        self.addCleanup(journal_patch.stop)

    def save_config(self):
        self.config_path.write_text(json.dumps(self.config), encoding="utf-8")

    def invoke(self, action="stage", failed=True):
        self.stdout, self.stderr = io.StringIO(), io.StringIO()
        with mock.patch.object(BUILD.sys, "argv", ["build_fpga.py", action, "--config", str(self.config_path)]), \
                contextlib.redirect_stdout(self.stdout), contextlib.redirect_stderr(self.stderr):
            if failed:
                with self.assertRaises(SystemExit) as raised:
                    BUILD.main()
                self.assertEqual(raised.exception.code, 1)
            else:
                self.assertIsNone(BUILD.main())
        if failed:
            self.journal.assert_called_once()
            self.assertEqual(self.journal.call_args.args, (self.root, "hardware"))
            self.incident = self.journal.call_args.kwargs

    def test_missing_and_invalid_config_are_captured_before_run(self):
        for contents in (None, "{broken json", '{"name": "../escape"}'):
            with self.subTest(contents=contents):
                self.journal.reset_mock()
                if contents is None:
                    self.config_path.unlink()
                else:
                    self.config_path.write_text(contents, encoding="utf-8")
                self.invoke()
                self.assertEqual(self.incident["phase"], "configuration")
                self.assertIsNone(self.incident["run_directory"])
                self.assertEqual(self.incident["record"]["cli_exit_code"], 1)
                self.assertFalse((self.root / "build/quartus").exists())

    def test_missing_tool_is_captured_without_run_directory(self):
        with mock.patch.object(BUILD, "find_tool", side_effect=ValueError("Cannot find qsys-generate")):
            self.invoke("generate")
        self.assertEqual(self.incident["phase"], "tool_discovery")
        self.assertIn("Cannot find", self.incident["message"])
        self.assertIsNone(self.incident["run_directory"])

    def test_missing_input_and_filename_collision_are_captured(self):
        for collision in (False, True):
            with self.subTest(collision=collision):
                self.journal.reset_mock()
                if collision:
                    other = self.root / "hardware/design/other"
                    other.mkdir()
                    (other / "top.v").write_text("different\n", encoding="utf-8")
                    self.config["stage_directories"].append("other")
                    self.config["required_inputs"] = ["top.v"]
                else:
                    self.config["required_inputs"].append("missing.v")
                self.save_config()
                self.invoke()
                self.assertEqual(self.incident["phase"], "staging")
                self.assertFalse(self.incident["record"]["stage_created"])
                self.assertEqual(self.incident["logs"], [])

    def test_failed_transformation_keeps_partial_run_and_metadata(self):
        descriptor = self.root / "hardware/design/rtl/test_hw.tcl"
        descriptor.write_text("no core fileset declaration", encoding="utf-8")
        self.invoke()
        self.assertIn("exactly once", self.incident["message"])
        stage = self.incident["run_directory"]
        self.assertTrue(self.incident["record"]["stage_created"])
        self.assertEqual(json.loads((stage / "run.json").read_text())["status"], "failed")

    def test_rejected_existing_stage_keeps_original_metadata(self):
        original_stage = BUILD.stage_inputs
        def collide(config, stage, record):
            stage.mkdir(parents=True)
            (stage / "run.json").write_text("existing evidence", encoding="utf-8")
            return original_stage(config, stage, record)
        with mock.patch.object(BUILD, "stage_inputs", side_effect=collide):
            self.invoke()
        self.assertFalse(self.incident["record"]["stage_created"])
        self.assertEqual((self.incident["run_directory"] / "run.json").read_text(), "existing evidence")

    def test_qsys_failure_keeps_raw_exit_code_command_and_log(self):
        with mock.patch.object(BUILD, "find_tool", return_value="qsys-generate"), \
                mock.patch.object(BUILD.subprocess, "run", return_value=BUILD.subprocess.CompletedProcess([], 23)):
            self.invoke("generate")
        self.assertEqual(self.incident["exit_code"], 23)
        self.assertEqual(self.incident["phase"], "generate:System")
        command = self.incident["record"]["commands"][0]
        self.assertEqual(command["argv"], self.incident["command"])
        self.assertEqual(command["returncode"], 23)
        self.assertIn("finished_at_utc", command)
        self.assertEqual(len(self.incident["logs"]), 1)
        self.assertTrue(self.incident["logs"][0].is_file())

    def test_quartus_failure_after_successful_generation_is_captured(self):
        def tools(command, **kwargs):
            if command[0] == "qsys-generate":
                qip = kwargs["cwd"] / "System/synthesis/System.qip"
                qip.parent.mkdir(parents=True)
                qip.write_text("generated", encoding="utf-8")
                return BUILD.subprocess.CompletedProcess(command, 0)
            return BUILD.subprocess.CompletedProcess(command, 17)
        with mock.patch.object(BUILD, "find_tool", side_effect=lambda root, relative, name: name), \
                mock.patch.object(BUILD.subprocess, "run", side_effect=tools):
            self.invoke("compile")
        self.assertEqual(self.incident["exit_code"], 17)
        self.assertEqual(self.incident["phase"], "compile")
        self.assertEqual(self.incident["record"]["generated_systems"], ["System"])
        self.assertEqual([item["returncode"] for item in self.incident["record"]["commands"]], [0, 17])

    def test_timeout_does_not_invent_child_return_code(self):
        with mock.patch.object(BUILD, "find_tool", return_value="qsys-generate"), \
                mock.patch.object(BUILD.subprocess, "run", side_effect=BUILD.subprocess.TimeoutExpired(["qsys-generate"], 1800)):
            self.invoke("generate")
        self.assertEqual(self.incident["exit_code"], 1)
        command = self.incident["record"]["commands"][0]
        self.assertIsNone(command["returncode"])
        self.assertEqual(command["status"], "timed_out")
        self.assertEqual(command["timeout_seconds"], 1800)

    def test_interruption_preserves_cli_one_and_incident_130(self):
        with mock.patch.object(BUILD, "find_tool", return_value="qsys-generate"), \
                mock.patch.object(BUILD.subprocess, "run", side_effect=KeyboardInterrupt):
            self.invoke("generate")
        self.assertEqual(self.incident["exit_code"], 130)
        self.assertEqual(self.incident["record"]["status"], "interrupted")
        self.assertIsNone(self.incident["record"]["commands"][0]["returncode"])

    def test_completed_stage_has_no_bug_incident(self):
        self.invoke(failed=False)
        self.journal.assert_not_called()
        record = json.loads(next((self.root / "build/quartus/test/runs").glob("*/run.json")).read_text())
        self.assertEqual(record["status"], "completed")
        self.assertEqual(record["cli_exit_code"], 0)

    def test_recorder_failure_does_not_replace_configuration_error(self):
        self.config_path.unlink()
        with self.assertRaises(FileNotFoundError) as missing:
            self.config_path.read_bytes()
        self.journal.side_effect = OSError("journal disk unavailable")
        self.invoke()
        # OSError formats its filename with repr; backslashes are escaped on
        # Windows. Compare the complete native error, not an unescaped path.
        self.assertEqual(self.incident["message"], str(missing.exception))
        self.assertIn(str(missing.exception), self.stderr.getvalue())
        self.assertIn("journal disk unavailable", self.stderr.getvalue())
        self.assertNotIn("Bug journal:", self.stdout.getvalue())

    def test_metadata_cleanup_failure_preserves_tool_error(self):
        original_write = BUILD.write_metadata
        def finalize(record, stage, runroot):
            if record["status"] == "failed":
                raise OSError("metadata disk unavailable")
            original_write(record, stage, runroot)
        with mock.patch.object(BUILD, "find_tool", return_value="qsys-generate"), \
                mock.patch.object(BUILD.subprocess, "run", return_value=BUILD.subprocess.CompletedProcess([], 23)), \
                mock.patch.object(BUILD, "write_metadata", side_effect=finalize):
            self.invoke("generate")
        self.assertEqual(self.incident["exit_code"], 23)
        self.assertIn("Tool exited 23", self.incident["message"])
        self.assertEqual(self.incident["record"]["metadata_errors"], ["metadata disk unavailable"])

    def test_completed_run_finalization_failure_is_journaled(self):
        original_write = BUILD.write_metadata
        def finalize(record, stage, runroot):
            if record["status"] == "completed":
                raise OSError("cannot finalize run")
            original_write(record, stage, runroot)
        with mock.patch.object(BUILD, "write_metadata", side_effect=finalize):
            self.invoke()
        self.assertEqual(self.incident["phase"], "finalization")
        self.assertEqual(self.incident["exit_code"], 1)


if __name__ == "__main__":
    unittest.main()
