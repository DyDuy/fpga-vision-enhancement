PYTHON ?= python
.PHONY: help check check-linux fpga-stage fpga-generate fpga-build hps-build verify-artifacts
help:
	@echo "check / check-linux : active inputs and Python tests; Linux adds HPS syntax"
	@echo "fpga-stage          : snapshot current editable inputs"
	@echo "fpga-generate       : fresh stage and generate all three Qsys"
	@echo "fpga-build          : fresh stage, Qsys generation, Quartus compile"
	@echo "hps-build           : ARM Linux applications (requires cross compiler)"
	@echo "verify-artifacts    : local historical archive checksum verification"
check:
	$(PYTHON) software/python/check_project.py
check-linux:
	$(PYTHON) software/python/check_project.py --hps-syntax
fpga-stage:
	$(PYTHON) software/python/build_fpga.py stage
fpga-generate:
	$(PYTHON) software/python/build_fpga.py generate
fpga-build:
	$(PYTHON) software/python/build_fpga.py compile
hps-build:
	bash software/hps/build.sh all
verify-artifacts:
	$(PYTHON) software/python/verify_artifact_manifest.py docs/history/builds/hardware/legacy-output-2026-05-02/manifest.json
