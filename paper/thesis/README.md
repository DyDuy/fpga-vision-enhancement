# Graduation thesis / Báo cáo KLTN

Bốn bản báo cáo do chủ dự án cung cấp được lưu nguyên tên và nguyên byte tại:

```text
paper/thesis/
├── README.md
├── manifest.json
└── local/                          # Git-ignored, không có trong clean checkout
    ├── en/
    │   ├── 21_Cuốn báo cáo KLTN_Cao Khanh Duy_english.docx
    │   └── 21_Cuốn báo cáo KLTN_Cao Khanh Duy_english.pdf
    └── vi/
        ├── 21_Cuốn báo cáo KLTN_Cao Khanh Duy_vi.docx
        └── 21_Cuốn báo cáo KLTN_Cao Khanh Duy_vi.pdf
```

## Quy tắc lưu trữ

- DOCX là bản có thể chỉnh sửa; PDF là bản trình bày được cung cấp. Chưa xác minh hai định dạng hoặc hai ngôn ngữ có cùng nội dung/phiên bản.
- [manifest.json](manifest.json) ghi kích thước và SHA-256 của từng file; tất cả bản copy được kiểm tra khớp checksum.
- Tổng payload: 59759801 byte, khoảng 56,99 MiB. Không đưa trực tiếp vào Git trong bước này.
- Bản nguồn trong Downloads vẫn giữ nguyên. Không thay đổi nội dung hoặc tên file.
- Đây là tài liệu báo cáo, không phải nguồn synthesis, artifact build hay bằng chứng tự động về implementation hiện tại.
- Nội dung, chữ ký/thông tin cá nhân và quyền phân phối chưa được rà soát. Trước public hosting cần chủ dự án xác nhận quyền và tạo bản đã loại thông tin nhạy cảm nếu cần.
- Sau khi review, có thể xuất bản PDF bằng GitHub/GitLab Releases hoặc storage phù hợp và bổ sung URL/checksum. Bản đã chỉnh sửa cần checksum/record mới, không thay thế âm thầm bản gốc.

README và manifest có thể track; `local/` được ignore. Không dùng `git add -f` để bypass chính sách này nếu chưa review. Bản paper riêng vẫn nằm ở [`paper/article/`](../article/README.md).
