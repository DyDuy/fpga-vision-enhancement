# DE1-SoC pin and timing inputs

- `de1_soc_pins.qsf`: 757 physical pin/I/O assignments extracted unchanged from the active project QSF. Do pin edits here; do not duplicate them in the project QSF.
- `DE1_SoC_Computer.sdc`: active timing constraints. Presence does not imply constraint coverage/timing sign-off.

`../de1_soc/DE1_SoC_Computer.qsf` sources the pin QSF and references the SDC through relative paths. The automatic build copies these inputs into each flat working run and rebases the references. Pin assignments are applied once.

Raw `.pin` output reports remain historical evidence in the archive, not another set of editable assignments. [Layout record](../../docs/history/pin-qsys-layout.json).
