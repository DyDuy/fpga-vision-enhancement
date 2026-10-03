# Historical Quartus build — legacy-output-2026-05-02

## Nguồn và trạng thái

Bản lưu từ `LuanVan_SoC/output_files`, do chủ dự án cung cấp. ID lấy ngày **2026-05-02 ghi trong báo cáo build**, không phải ngày archive hoặc commit source.

- 17 file, tổng 29975654 byte (28,59 MiB), được copy nguyên byte và kiểm tra SHA-256.
- Payload cục bộ: `hardware/archive/quartus/legacy-output-2026-05-02/` (Git-ignored).
- [manifest.json](manifest.json): vị trí, kích thước, checksum từng file; thời điểm archive nằm ở `archived_at_utc`.
- [metrics.json](metrics.json): nội dung fit summary và 24 timing summary entries được trích xuất.
- Source commit: **chưa xác định**. Không khẳng định bitstream khớp RTL đang track.
- Đây là build lịch sử; chưa chạy lại Quartus hoặc nạp board trong bước tổ chức artifact.

## Phân loại file

| Vị trí trong archive | Nội dung | Số file |
|---|---|---:|
| `bitstreams/` | `DE1_SoC_Computer.sof` | 1 |
| `reports/` | asm/eda/fit/flow/map/sta `.rpt`, fit/map `.smsg`, fit/map/sta `.summary` | 11 |
| `programming/` | `.cdf` gốc | 1 |
| `metadata/` | `.done`, `.jdi`, `.pin`, `.sld` | 4 |

Thư mục nguồn này **không có `.rbf`**. File `output_file.rbf` ở root legacy là nguồn khác và không được tự ghép vào snapshot này.

## Kết quả ghi trong báo cáo

| Đại lượng | Giá trị |
|---|---|
| Flow status | Successful — Sat May 02 01:01:20 2026 |
| Fitter status | Successful — Sat May 02 01:00:17 2026 |
| Compile tool | Quartus Prime 18.1.0 Build 625, Lite Edition |
| Revision / top | DE1_SoC_Computer |
| Family / device | Cyclone V / 5CSEMA5F31C6 |
| ALM | 3308 / 32070 — 10% |
| Registers, post-fit | 4245 |
| Pins | 326 / 457 — 71% |
| Block memory bits | 1418810 / 4065280 — 35% |
| RAM blocks | 182 / 397 — 46% |
| DSP blocks | 13 / 87 — 15% |
| PLL / DLL | 2 / 6; 1 / 4 |

Analysis & Synthesis summary ghi 4281 register, còn post-fit ghi 4245; tài liệu này dùng số post-fit, không trộn hai giai đoạn.

### Timing summary

| Corner | Setup slack (ns) | Hold slack (ns) |
|---|---:|---:|
| Slow 1100mV 85°C | +1,730 | +0,143 |
| Slow 1100mV 0°C | +1,727 | +0,162 |
| Fast 1100mV 85°C | +2,110 | +0,084 |
| Fast 1100mV 0°C | +2,110 | +0,077 |

Các dòng trên trong summary đều chỉ tới clock HPS DDR3 PHY `afi_clk_write_clk`; TNS ghi 0. Summary còn có recovery/removal/minimum pulse width entries và yêu cầu xem DDR report cho kết quả DDR đầy đủ.

Không suy ra Fmax, latency core, constraint coverage, CDC correctness hoặc camera FPS từ bảng này. “Flow Successful” và các slack này không thay thế timing sign-off độc lập cho toàn hệ thống.

## Phân biệt ba nguồn số liệu

| Nguồn | ALM | Memory bits | DSP |
|---|---:|---:|---:|
| Snapshot `output_files` này, 2026-05-02 | 3308 | 1418810 | 13 |
| Báo cáo root legacy, 2026-05-11, đã quan sát khi intake | 3928 | 2215198 | 7 |
| Paper Table 2 | 6279 | 1113243 | 8 |

Ba bộ số liệu thuộc provenance khác nhau. Snapshot này không phải bằng chứng trực tiếp cho Table 2 của paper hoặc cho nguồn RGB30 đã nhập. Xem [paper review](../../../../../paper/article/implementation-review.md) và [source intake](../../../../migration/legacy-intake.md).

## CDF và sử dụng bitstream

CDF được giữ nguyên và có metadata Quartus **23.1std**, khác tool **18.1** trong báo cáo compile; có thể đã được chỉnh bởi phiên bản Programmer khác, chưa xác định quan hệ thời gian. CDF tham chiếu `C:/LuanVan_SoC/output_files/`, không phải đường dẫn repository hiện tại.

Muốn dùng Programmer: kiểm tra thiết bị/board, quyền sử dụng artifact và source version; tạo chain cục bộ trỏ đến `.sof` trong archive thay vì sửa payload đã hash. `.sof` là SRAM configuration artifact, không phải `.rbf` cho Linux FPGA manager. Không tự chuyển đổi hoặc công bố hai định dạng là tương đương khi chưa có conversion recipe.

## Kiểm tra archive cục bộ

Từ repository root:

```sh
python software/python/verify_artifact_manifest.py docs/history/builds/hardware/legacy-output-2026-05-02/manifest.json
```

Clean checkout chỉ có record/manifest, không có payload. Muốn có payload cần copy lại từ bản nguồn đúng checksum hoặc tải từ Release/object storage khi URL được bổ sung. Không xóa thư mục Downloads nguồn sau bước này.

## Chính sách publish

Track README, manifest và metrics; không track bitstream/reports/raw metadata. Trước public release, kiểm tra Intel/IP terms và thông tin máy trong report/CDF. Public download URL hiện chưa có, chưa có tag hoặc release liên kết.
