# Build artifacts

Thư mục này dành cho artifact đã tạo bởi công cụ hoặc được tiếp nhận từ build lịch sử, không phải mã nguồn RTL.

## Phân tách lưu trữ

- `hardware/archive/`: bản lưu cục bộ, **Git-ignored**; không có trong clean checkout.
- `docs/history/builds/hardware/<build-id>/`: manifest, checksum, metrics JSON và tóm tắt Markdown có thể track trong Git.
- `build/`: working directory cho các lần generate/compile mới; không dùng làm archive bất biến.

## Generated project đầy đủ trên máy

`local/qsys/luanvan_soc-current/` chứa nguyên ba thư mục `Computer_System/`, `VGA_Subsystem/`, `Video_In_Subsystem/` và các đầu vào root đi kèm: **975 file, khoảng 86,77 MiB**. Payload nằm trong project nhưng Git-ignored. Xem [snapshot record và manifest](builds/platform/luanvan_soc-current/README.md). Không mặc định các generated system đã đồng bộ hoặc build được.

## Snapshot đã nhập

`local/quartus/legacy-output-2026-05-02/` chứa toàn bộ 17 file của snapshot `LuanVan_SoC/output_files`, được phân loại:

```text
bitstreams/    .sof (và .rbf/.pof/.jic nếu có ở build khác)
reports/       .rpt, .summary, .smsg
programming/   .cdf
metadata/      .pin, .jdi, .sld, .done và file phụ trợ khác
```

Xem [historical build record](builds/hardware/legacy-output-2026-05-02/README.md). Snapshot không được xác nhận khớp RTL hiện tại hoặc phiên bản paper; không tự nạp bitstream vào board.

## Hosting và bảo mật

Sau khi kiểm tra quyền phân phối, có thể đóng gói artifact cho GitHub/GitLab Releases hoặc object storage, bổ sung URL vào manifest và giữ SHA-256. Không force-add `hardware/archive/` hoặc tự bật LFS cho mọi output.

Báo cáo thô và CDF có thể chứa absolute paths/tên máy. Giữ nguyên payload trong archive cục bộ để checksum có ý nghĩa; nếu cần công khai bản đã redact, tạo artifact mới với checksum mới và mô tả transformation. `.cdf` gốc có đường dẫn máy cũ và không phải recipe portable.
