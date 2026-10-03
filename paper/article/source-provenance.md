# Nguồn tài liệu paper

## DOCX đã đọc

- Tên file: `53_20260916_A_real_time_FPGA_based_vision_enhancement_system_Final_Submission.docx`.
- Nguồn: file trong thư mục Downloads do chủ dự án chỉ định; không phải bản tải từ publisher đã xác minh.
- Kích thước: 295927 byte.
- SHA-256:

```text
125bf0938b2fe6edc8af7247fb107ebd088e167c8b5fc04d73fb6caa40caa818
```

Tên file chứa `20260916`; đây là metadata trong tên, không được coi là ngày xuất bản hoặc ngày được chấp nhận. DOCX không được sao chép vào repository trong tác vụ này và chưa có public download URL.

## Phương pháp đọc và phạm vi chuyển đổi

- Đọc nội dung Open XML trong `word/document.xml`.
- Trích xuất toàn bộ các đoạn văn của abstract, introduction, thuật toán, kiến trúc, kết quả, conclusion và references.
- Đọc các hàng/cột của Table 1 và Table 2.
- Đọc các node Office Math (`m:t`) và cấu trúc fraction/exponent của phương trình (4) để phục hồi công thức đúng, thay vì dựa vào text thuần làm mất toán học.
- Ghi nhận captions Figure 1–3. DOCX chứa 6 media objects (2 EMF, 4 JPEG); không chuyển đổi hoặc đưa media vào Git, không khẳng định đã thẩm định chi tiết nội dung hình EMF.
- Tính lại visible-edge gain từ số đếm của Table 1 và phân biệt với cột baseline độc lập.
- Đối chiếu kiến trúc paper với RTL, MATLAB và HPS sources đã tiếp nhận trong repository.

Các Markdown là tài liệu giải thích/review, không phải bản sao định dạng Word. Không bảo đảm bảo toàn dàn trang, footnote layout, hình hoặc mọi metadata publisher.

## Provenance của số liệu

| Nhóm thông tin | Nguồn | Trạng thái |
|---|---|---|
| Tác giả, affiliation, title | DOCX | Đọc từ bản thảo |
| Công thức, LUT architecture | Nội dung và Office Math | Diễn giải lại, chưa chạy model |
| Edge counts, mean gradient, saturation | Table 1 | Chép số liệu; edge gain được tính lại |
| ALM, memory, DSP, timing, power | Table 2 và phần Results | Paper-reported, chưa xác minh bằng raw reports cùng build |
| Bit-exact 0 LSB | Phần Verification | Tuyên bố bản thảo; chưa có regression artifacts đúng version |
| Khác biệt với RTL legacy | Source repository / migration records | Rà soát mã và cấu hình, không synthesis |
| Citation metadata | References trong DOCX | Chưa xác minh độc lập |

## Quyền phân phối

Không tự gán license cho manuscript, ảnh hoặc tài liệu tham khảo. Trước khi bổ sung DOCX/PDF/hình vào public repository hoặc Releases, chủ dự án cần xác nhận quyền chia sẻ và chính sách publisher/venue nếu có.
