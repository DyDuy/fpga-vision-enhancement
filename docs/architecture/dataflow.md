# Dataflow

Mục tiêu là một pixel vào và một pixel ra theo streaming sau khi pipeline được lấp đầy. Các khâu cần cửa sổ ảnh phải dùng line buffer có kích thước suy ra từ kernel và chiều rộng ảnh.

Các quyết định chưa chốt:

- thuật toán khử sương cuối cùng và kích thước cửa sổ;
- cách ước lượng atmospheric light: theo frame, theo tile hoặc do HPS cung cấp;
- có lưu frame trong DDR hay xử lý thuần streaming;
- cơ chế stall và giữ sideband khi pipeline backpressure.

Mỗi quyết định phải được kiểm tra bằng model và thông lượng bộ nhớ trước khi triển khai.
