"""Fresh staging tests; no vendor tools invoked."""
import importlib.util
import json
from pathlib import Path
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[3]
SPEC = importlib.util.spec_from_file_location("build_fpga", ROOT / "software/python/build_fpga.py")
BUILD = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(BUILD)


class BuildStagingTests(unittest.TestCase):
    def test_stage_current_sources_and_rebase_descriptor(self):
        config = BUILD.load_config(ROOT / "hardware/de1_soc/build.json")
        with tempfile.TemporaryDirectory() as folder:
            stage = Path(folder) / "run"
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
                BUILD.stage_inputs(config, Path(folder))

    def test_missing_input_is_reported_before_stage_creation(self):
        config = BUILD.load_config(ROOT / "hardware/de1_soc/build.json")
        config["required_inputs"].append("missing-input.v")
        with tempfile.TemporaryDirectory() as folder:
            stage = Path(folder) / "run"
            with self.assertRaises(ValueError):
                BUILD.stage_inputs(config, stage)
            self.assertFalse(stage.exists())


if __name__ == "__main__":
    unittest.main()
