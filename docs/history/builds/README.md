# Results

Lưu bằng chứng chọn lọc kèm provenance, không trộn báo cáo lịch sử với kết quả đã tái lập.

## Hardware build records

- [`hardware/legacy-root-mixed-2026-07-28/`](hardware/legacy-root-mixed-2026-07-28/README.md): 24 artifact root từ nguồn cập nhật; fitter July 28 và power July 10 khác ngày, không mặc định cùng build.

- [`hardware/legacy-output-2026-05-02/`](hardware/legacy-output-2026-05-02/README.md): snapshot Quartus `output_files`, 17 artifact cục bộ, manifest SHA-256, metrics JSON và tóm tắt. Chưa xác định commit source; chưa chạy build/board validation mới.

## Quy tắc tổ chức

- `docs/history/builds/hardware/<build-id>/`: README, manifest và metrics nhỏ có thể track.
- `hardware/archive/quartus/<build-id>/`: bitstream, báo cáo thô, Programmer và metadata; Git-ignored. Xem [artifact policy](../artifact-policy.md).
- `build/`: working directory cho generate/compile mới, không dùng làm bằng chứng build bất biến.
- `docs/history/builds/generated/`: kết quả sinh tạm, không track.

Build ID phải riêng cho từng snapshot. Ghi rõ tool version, device, nguồn report, commit (hoặc chưa biết), checksum và điều kiện đo. Không dùng dữ liệu paper như kết quả của RTL hiện tại khi chưa xác minh.

## Nhập output của build khác

```sh
python software/python/archive_quartus_outputs.py /path/to/output_files --build-id unique-build-id
python software/python/verify_artifact_manifest.py docs/history/builds/hardware/unique-build-id/manifest.json
```

Script giữ nguyên payload, kiểm tra checksum và từ chối ghi đè build ID đã có. Sau import, bổ sung README phân tích riêng, liên kết source commit/configuration nếu xác định được. Clean checkout không chứa payload cục bộ; dùng Release/object storage sau khi review quyền phân phối, rồi ghi URL trong manifest.
