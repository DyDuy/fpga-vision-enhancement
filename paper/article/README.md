# Paper — FPGA Vision Enhancement

Thư mục này lưu tài liệu Markdown về bài báo **A Real-Time FPGA-Based Vision Enhancement System**, liên quan đến dự án FPGA Vision Enhancement.

## Tài liệu

- [Tổng quan bài báo](paper-overview.md): tác giả, mục tiêu, đóng góp, công thức, kiến trúc, kết quả và giới hạn.
- [Đối chiếu bài báo với repository](implementation-review.md): khác biệt giữa kiến trúc công bố và nguồn legacy đang có; các điểm cần làm rõ trước khi tái lập hoặc cập nhật bản thảo.
- [Nguồn và dấu vết tài liệu](source-provenance.md): file DOCX đã đọc, checksum và phạm vi chuyển đổi.

## Quy tắc diễn giải

1. **“Bài báo công bố” không đồng nghĩa “repository đã tái lập”.** Các số liệu chất lượng ảnh, timing, công suất và độ trễ được ghi theo bản thảo, không phải phép đo mới.
2. Paper mô tả kiến trúc point-processing 1×1/LUT/11-cycle. RTL RGB30 được nhập từ `LuanVan_SoC` hiện dùng cửa sổ 15×15 và delay buffer lớn; chưa xác định được commit mã nguồn tương ứng với paper.
3. Các file Markdown là bản diễn giải bằng tiếng Việt, không phải bản dịch toàn văn hoặc bản manuscript thay thế DOCX.
4. Không suy đoán DOI, hội nghị, trạng thái chấp nhận hay ngày xuất bản từ tên file `Final_Submission`.
5. DOCX và hình gốc không được chép vào repository trong bước này. Cần kiểm tra quyền phân phối trước khi công khai manuscript hoặc ảnh.

## Liên quan

- [Legacy intake](../../docs/migration/legacy-intake.md)
- [Manifest mã nguồn](../../docs/migration/legacy-manifest.json)
- [Kế hoạch kiểm chứng](../../docs/development/verification.md)
- [Publication workspace](../README.md)
