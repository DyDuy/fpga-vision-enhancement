# Kiến trúc bộ nhớ

Chưa có memory map hoặc register map được chốt.

Nguyên tắc ban đầu:

- line buffer thuộc lõi xử lý nếu cần cho cửa sổ cục bộ;
- frame buffer và DMA thuộc adapter SoC/board;
- tham số và status có một nguồn mô tả máy đọc được trong `configs/registers/` khi register map được chốt;
- không duy trì các bản header C và package RTL chỉnh tay độc lập.
