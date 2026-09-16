# ADR 0001: Tách lõi xử lý khỏi adapter board

## Trạng thái

Accepted — 2026-09-16.

## Quyết định

Lõi xử lý ảnh trình bày interface streaming độc lập với DE1-SoC. Avalon, HPS, DDR, camera và display được triển khai bằng adapter dưới `fpga/`.

## Lý do

Seam này cho phép model/checker kiểm tra lõi, tái sử dụng trên board khác và cô lập lỗi tích hợp SoC khỏi lỗi thuật toán.
