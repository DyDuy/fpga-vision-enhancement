"""Tests for portable tooling; these do not validate dehazing RTL."""
import importlib.util
from pathlib import Path
import tempfile
import unittest

from PIL import Image

ROOT = Path(__file__).resolve().parents[3]
SPEC = importlib.util.spec_from_file_location("image_hex", ROOT / "software/python/image_hex.py")
TOOLS = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(TOOLS)


class ImageHexTests(unittest.TestCase):
    def test_rgb_order_and_round_trip(self):
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory)
            image = Image.new("RGB", (2, 1))
            image.putdata([(255, 0, 1), (0, 128, 255)])
            image.save(path / "input.png")
            TOOLS.image_to_hex(path / "input.png", path / "frame.hex", 2, 1)
            self.assertEqual((path / "frame.hex").read_text(), "ff0001\n0080ff\n")
            TOOLS.hex_to_image(path / "frame.hex", path / "result.png", 2, 1)
            with Image.open(path / "result.png") as result:
                self.assertEqual(result.tobytes(), image.tobytes())

    def test_unknown_pixel_is_rejected(self):
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory)
            (path / "frame.hex").write_text("xxxxxx\n")
            with self.assertRaises(ValueError):
                TOOLS.hex_to_image(path / "frame.hex", path / "result.png", 1, 1)

    def test_wrong_frame_size_is_rejected(self):
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory)
            (path / "frame.hex").write_text("ffffff\n")
            with self.assertRaises(ValueError):
                TOOLS.hex_to_image(path / "frame.hex", path / "result.png", 2, 1)


if __name__ == "__main__":
    unittest.main()
