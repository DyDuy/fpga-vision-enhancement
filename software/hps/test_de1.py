#!/usr/bin/env python3
"""Offline boundary tests: no compiler, SSH connection or hardware execution."""
import importlib.util
import json
import os
from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch

SPEC = importlib.util.spec_from_file_location("de1_workflow", Path(__file__).with_name("de1.py"))
de1 = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(de1)


class WorkflowTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory(prefix="de1 path có dấu ")
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        (self.root / "software/hps").mkdir(parents=True)
        self.addCleanup(patch.stopall)
        patch.object(de1, "ROOT", self.root).start()
        patch.object(de1.sys, "platform", "linux").start()
        patch.dict(os.environ, {"DE1_SDK": str(self.root / "sdk")}).start()

    def config(self, host="de1-test"):
        (self.root / "software/hps/de1.local.json").write_text(
            json.dumps({"host": host, "user": "tester", "port": 2222}), encoding="utf-8")

    def sdk(self, sdk, session):
        session.data["sdk"] = {"path": str(sdk), "records": {"fixture": "offline"}}

    def binary(self, sdk, session):
        binary = self.root / "compiled app"
        binary.write_bytes(b"offline fixture; never executable")
        session.data["build_run"] = "offline build"
        session.data["elf"] = {"sha256": de1.sha256(binary)}
        return binary

    def test_unconfigured_target_does_not_start_process(self):
        with patch.object(de1.subprocess, "Popen") as process:
            self.assertEqual(de1.main(["push"]), 2)
            self.config("")
            self.assertEqual(de1.main(["push"]), 2)
            process.assert_not_called()
        self.assertFalse((self.root / "build").exists())

    def test_compiler_failure_preserves_code_and_prevents_upload(self):
        self.config()
        with patch.object(de1, "verify_sdk", side_effect=self.sdk), \
                patch.object(de1.Session, "command",
                             side_effect=de1.WorkflowError("compiler failed", 17)) as command, \
                patch.object(de1, "deploy") as deploy:
            self.assertEqual(de1.main(["push"]), 17)
            self.assertEqual(command.call_args.args[0], "build")
            deploy.assert_not_called()

    def test_invalid_input_prevents_build_and_network(self):
        self.config()
        image = self.root / "ảnh input.hex"
        for text in ("00 01", "FFFFFF\n" * (640 * 480 - 1) + "1000000\n"):
            image.write_text(text, encoding="ascii")
            with patch.object(de1, "verify_sdk", side_effect=self.sdk), \
                    patch.object(de1, "build_checked") as build, \
                    patch.object(de1.subprocess, "Popen") as process:
                self.assertEqual(de1.main(["push", "--run", str(image)]), 2)
                build.assert_not_called()
                process.assert_not_called()

    def prepared(self):
        session = de1.Session("push")
        self.sdk(self.root / "sdk", session)
        binary = self.binary(self.root / "sdk", session)
        image = session.path / "release/input_image.hex"
        image.write_text("0\n" * (640 * 480), encoding="ascii")
        return session, binary, image

    def test_transfer_or_hash_failure_prevents_run(self):
        for failed_phase in ("upload", "remote-verify"):
            with self.subTest(phase=failed_phase):
                session, binary, image = self.prepared()
                phases = []

                def command(phase, argv, env=None):
                    phases.append(phase)
                    if phase == failed_phase:
                        raise de1.WorkflowError("fixture failure", 23)
                    return ""

                session.command = command
                with self.assertRaises(de1.WorkflowError) as error:
                    de1.deploy(binary, image, {"host": "de1-test", "user": "tester",
                                               "port": 2222}, session)
                self.assertEqual(error.exception.code, 23)
                self.assertNotIn("run", phases)

    def test_push_run_freezes_unicode_input_and_uses_argv(self):
        self.config()
        image = self.root / "ảnh nguồn có dấu.hex"
        image.write_text("aBcDef\n" * (640 * 480), encoding="ascii")
        calls = []

        def command(session, phase, argv, env=None):
            calls.append((phase, argv))
            return ""

        with patch.object(de1, "verify_sdk", side_effect=self.sdk), \
                patch.object(de1, "build_checked", side_effect=self.binary), \
                patch.object(de1.Session, "command", command):
            self.assertEqual(de1.main(["push", "--run", str(image)]), 0)
        self.assertEqual([phase for phase, _ in calls],
                         ["remote-create", "upload", "remote-verify", "run"])
        upload = calls[1][1]
        self.assertEqual(upload[:4], ["scp", "-O", "-P", "2222"])
        self.assertTrue(any("có dấu" in arg and arg.endswith("/input_image.hex")
                            for arg in upload))
        self.assertEqual(calls[-1][1][0:2], ["ssh", "-tt"])
        self.assertIn("exec ./vga_simple_display ./input_image.hex", calls[-1][1][-1])
        self.assertNotIn(str(image), calls[-1][1][-1])
        releases = list((self.root / "build/hps/remote/runs").glob("*/release"))
        frozen = releases[0] / "input_image.hex"
        self.assertEqual(de1.sha256(frozen), de1.sha256(image))
        record = json.loads((releases[0].parent / "workflow.json").read_text())
        self.assertEqual(record["status"], "succeeded")
        self.assertEqual(record["exit_code"], 0)

    def test_remote_run_exit_code_is_returned(self):
        self.config()
        image = self.root / "input.hex"
        image.write_text("0\n" * (640 * 480), encoding="ascii")

        def command(session, phase, argv, env=None):
            if phase == "run":
                raise de1.WorkflowError("remote process failed", 37)
            return ""

        with patch.object(de1, "verify_sdk", side_effect=self.sdk), \
                patch.object(de1, "build_checked", side_effect=self.binary), \
                patch.object(de1.Session, "command", command):
            self.assertEqual(de1.main(["push", "--run", str(image)]), 37)

    def test_sdk_rejects_absolute_link_before_build(self):
        sdk = self.root / "sdk"
        sdk.mkdir()
        (sdk / "target").write_text("fixture")
        (sdk / "link").symlink_to("/target")
        (sdk / "SDK_MANIFEST.sha256").write_text(de1.sha256(sdk / "target") + "  target\n")
        (sdk / "SDK_SYMLINKS.tsv").write_text("link\t/target\n")
        (sdk / "SDK_INFO.txt").write_text("offline fixture")
        with self.assertRaisesRegex(de1.WorkflowError, "relocated relative"):
            de1.verify_sdk(sdk, de1.Session("build"))


if __name__ == "__main__":
    unittest.main()

