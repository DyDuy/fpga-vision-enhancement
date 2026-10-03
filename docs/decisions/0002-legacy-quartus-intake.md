# ADR 0002: Giữ repo nghiên cứu làm gốc và tiếp nhận Quartus theo giai đoạn

## Cập nhật tiếp nhận nguồn

Nguồn chọn lọc từ snapshot Downloads `LuanVan_SoC` đã được nhập theo [manifest](../migration/legacy-manifest.json) và [hướng dẫn](../migration/legacy-intake.md). Đây là intake chưa đạt gate build/license, không phải nguyên bản generated project. Các quan sát `D:\\` bên dưới được giữ như lịch sử; nguồn hiện tại và checksum xem manifest. Chưa có cam kết build tái lập.

## Trạng thái

Accepted — 2026-09-30.

## Quyết định

Giữ repo này làm gốc cho spec, model, RTL, verification và board adapter theo [ADR 0001](0001-repository-layout.md#L7-L13); dành [`hardware/archive/sources/boards/de1_soc/quartus/`](../history/README.md) cho project được thẩm định sau này, **không** nhập nguyên thư mục legacy hoặc output sinh. Các đường dẫn `D:\` sau đây là quan sát từ kiểm kê read-only cục bộ ngày 2026-09-30, **ngoài repo**, không phải nguồn kiểm chứng được từ checkout: legacy QPF khai Quartus 23.1 (`D:\kq_nghiencuu_Caitien\kq_nghiencuu1\LuanVan_SoC\DE1_SoC_Computer.qpf:20-31`); QSF yêu cầu SDC và `hex_decoder.v` nhưng hai path đó vắng mặt tại lúc kiểm kê (`D:\kq_nghiencuu_Caitien\kq_nghiencuu1\LuanVan_SoC\DE1_SoC_Computer.qsf:974-977`), còn QIP trỏ tới generated submodules gồm `dehazing_system_top.v` (`D:\kq_nghiencuu_Caitien\kq_nghiencuu1\LuanVan_SoC\Computer_System\synthesis\Computer_System.qip:8018`). Quan sát này không portable hoặc tái lập từ repo cho tới khi có manifest/hash có ngày, dependency closure và kiểm tra từ clean checkout; chưa thể khẳng định build được. Xem [các gate](../architecture/repository-layout.md#d-giai-đoạn-tích-hợp-và-điều-kiện-qua-cổng).

## Phương án đã cân nhắc và hệ quả

Nhập nguyên legacy hoặc lấy legacy làm repo root sẽ trộn source chưa rõ nguồn/quyền với generated dependencies và biến một snapshot thiếu tham chiếu thành baseline ngầm; bỏ legacy hoàn toàn thì mất manh mối tích hợp. Giữ bản gốc bất biến ngoài repo, chỉ chuyển nguồn được xác minh cùng manifest, license, recipe và kiểm tra build từ clean checkout; cho tới đó Quartus chỉ là placeholder, không có cam kết bitstream hay timing ([quy tắc ignore](../../.gitignore#L1-L29), [test plan](../development/verification.md#L8-L11)).
