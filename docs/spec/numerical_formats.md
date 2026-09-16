# Đặc tả số học

Chưa có Q-format chính thức. Trước khi gọi model hoặc RTL là bit-accurate, phải ghi cho từng khâu:

- signed/unsigned và số bit integer/fraction;
- độ rộng tích lũy và phép chia/xấp xỉ;
- rounding mode;
- saturation hoặc wrap;
- miền hợp lệ của tham số;
- sai số cực đại và sai số chất lượng ảnh chấp nhận được.

Proof-of-concept `DehazingCore` hiện dùng `UInt`, phép cộng modulo và không đại diện cho số học của thuật toán khử sương.
