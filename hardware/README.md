# Hardware — 1x1 only

```text
hardware/
├── de1_soc/    QPF/QSF, board/core RTL, IP descriptor, ROM and build.json
├── pin/        editable physical assignments and timing SDC
├── qsys/       3 editable Qsys plus generated system folders (ignored)
├── generation/ editable system specifications and tool inputs
└── archive/    historical report/binary and companion-input records, not active source
```

See [generation workspace](generation/README.md) for tool inputs and the planned generation workflow.

Open `de1_soc/DE1_SoC_Computer.qpf` in Quartus. QSF references pin and Qsys paths relatively; build automation collects all three input directories into a fresh flat root-build run and rebases paths. There is only root `build/`, not hardware/build.

HPS source is only in software/hps. 15x15 source was removed. Historical files are not proof of current-source correctness. See [pin](pin/README.md), [Qsys](qsys/README.md) and [workflow](../docs/development/automatic-build.md).

Khi chạy `software/python/build_fpga.py stage|generate|compile`, lỗi cấu hình,
thiếu tool, staging, Qsys/Quartus, timeout hoặc ngắt chạy được ghi tự động vào
`build/bug/hardware/<incident-id>/`; mỗi sự cố có `record.json`,
`diagnostics.log` và `journal.md` để bổ sung nguyên nhân, điều chỉnh và kiểm chứng.
Hook ghi sự cố: [build_fpga.py:150](../software/python/build_fpga.py#L150),
ranh giới xử lý lỗi: [build_fpga.py:177](../software/python/build_fpga.py#L177).

Log đầy đủ vẫn nằm trong run gốc; nhật ký chỉ nhận tham chiếu và trích đoạn
`*.log`. Mã thoát của tool được giữ riêng, còn CLI build lỗi vẫn trả `1`.
Build hoàn tất không tạo sự cố; lỗi ghi nhật ký chỉ cảnh báo và giữ lỗi build gốc.
Nguồn: [build_fpga.py:150](../software/python/build_fpga.py#L150),
[build_fpga.py:225](../software/python/build_fpga.py#L225),
[build_fpga.py:242](../software/python/build_fpga.py#L242).
Quartus GUI, lệnh tool gọi trực tiếp và chạy trên board cần nhập log thủ công;
xem [hướng dẫn nhật ký lỗi](../docs/development/bug-logging.md).
