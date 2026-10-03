# Repository layout và ranh giới tiếp nhận

> **Cập nhật sau tiếp nhận:** đã nhập chọn lọc nguồn từ snapshot Downloads `LuanVan_SoC`. Bố cục, manifest, dependency thiếu và recipe hiện tại nằm tại [legacy intake](../migration/legacy-intake.md). Các mô tả “placeholder/chưa nhập” bên dưới là trạng thái trước tiếp nhận và được giữ làm bối cảnh quyết định; không phải trạng thái hiện tại. Gate build/hardware/archive/sources/verification/license vẫn chưa đóng.

Tài liệu này phân biệt **hiện có** với **mục tiêu**, không coi scaffold là implementation hay bằng chứng build. [Yêu cầu](../spec/requirements.md#L7-L23), [roadmap](../ROADMAP.md#L3-L37) và [ADR 0001](../decisions/0001-repository-layout.md#L7-L13) là điểm neo; [ADR 0002](../decisions/0002-legacy-quartus-intake.md) ghi quyết định tiếp nhận legacy.

## A. Bố cục, module và luồng

| Vị trí | Hiện có | Mục tiêu / ranh giới |
|---|---|---|
| [`docs/`](..) | Spec, kiến trúc mục tiêu và roadmap ([requirements](../spec/requirements.md#L1-L23), [overview](overview.md#L1-L24)). | Quyết định, hợp đồng giao tiếp và [nguồn tham khảo](../../ref/literature.md) trước khi chốt thuật toán. |
| [`model/`](../../software/matlab/README.md) | Chỗ dành cho model; dehazing model chưa được kiểm chứng trong [test plan](../development/verification.md#L8-L9). | Floating-point rồi fixed-point, sinh vector và đo sai số ([roadmap](../ROADMAP.md#L9-L19)). |
| [`hardware/archive/sources/rtl/chisel/`](../history/README.md#L15-L35) | `DehazingCore` cộng 5 modulo, chỉ có pixelIn/pixelOut, chưa có valid/ready hay frame markers ([source](../history/README.md#L19-L25)). | Lõi streaming độc lập board; [RTL ownership](../history/README.md) là vị trí thay thế nếu chọn ([overview](overview.md#L18-L24)). |
| [`hardware/archive/sources/verification/`](../development/verification.md#L3-L11) | Test PoC được ghi nhận; model/RTL/board test còn planned. | Checker bit-accurate, reset/stall/frame-boundary và vector có nguồn gốc ([requirements](../spec/requirements.md#L16-L21)). |
| [`hardware/archive/sources/boards/de1_soc/`](../history/README.md) | Các README scaffold; [`quartus/`](../history/README.md) là placeholder, không có project được nhận. | `top/` và `platform/` sở hữu board adapter/HPS/interconnect, `constraints/` sở hữu timing/pins, `software/python/` sở hữu recipe ([board README](../history/README.md)). |
| [`software/`](../../software/README.md), `host/` | Vị trí dự kiến cho phần mềm; không khẳng định đường điều khiển đang hoạt động ([roadmap](../ROADMAP.md#L27-L31)). | Cấu hình HPS/host và vận chuyển dữ liệu theo hợp đồng đã chốt ([roadmap](../ROADMAP.md#L27-L31)). |
| [`data/`](../../data/README.md), [`hardware/archive/sources/experiments/`](../history/README.md), [`docs/history/builds/`](../history/builds/README.md), [`paper/`](../../paper/README.md) | Chỗ quản trị dữ liệu/thử nghiệm/kết quả/bản thảo. | Giữ đầu vào bất biến, lưu cấu hình/commit/tool version và bằng chứng ([roadmap](../ROADMAP.md#L33-L37)). |

Luồng **mục tiêu**, không phải netlist hiện tại ([overview](overview.md#L3-L16)):

```text
image/video source -> board input adapter -> pixel stream -> preprocessing
  -> estimation -> restoration -> pixel stream -> board output adapter -> sink
HPS/host config -------------------------------> control/parameters
model -> golden vectors -> checker <------------ core RTL observations
```

Lõi sở hữu phép biến đổi pixel; adapter sở hữu camera/display, HPS, DDR và bus theo [ADR 0001](../decisions/0001-repository-layout.md#L7-L13). Interface đích cần pixel và valid/ready, dấu frame/line, control/status, clock/reset; **tên tín hiệu, định dạng, reset, stall và timing chưa chốt** ([interfaces](../spec/interfaces.md#L1-L13), [dataflow](dataflow.md#L5-L12)). Không nối PoC hiện tại vào board như thể đã có hợp đồng đó ([source](../history/README.md#L19-L25)).

## B. Cơ sở quyết định và nguồn

Các giả định về thuật toán, cửa sổ/line buffer, atmospheric light và DDR vẫn mở ([dataflow](dataflow.md#L3-L12)); chốt chúng bằng model, phép đo và nguồn trong [references](../../ref/literature.md) trước khi chọn RTL. Tách board khỏi core để kiểm chứng riêng theo [ADR 0001](../decisions/0001-repository-layout.md#L7-L13). Không gán throughput, tài nguyên hoặc chất lượng ảnh khi chưa đo ([requirements](../spec/requirements.md#L16-L23)).

## C. Chính sách nguồn và môi trường (mục tiêu)

- Track trong Git: spec, model/RTL do dự án sở hữu, test/checker, vector mẫu nhỏ có provenance, cấu hình pin/timing và recipe project **sau khi** dependency và quyền phân phối được xác minh. Không track output chỉ vì nó nằm trong project legacy; xác nhận license/IP riêng trước khi nhập ([ADR 0002](../decisions/0002-legacy-quartus-intake.md)).
- `.gitignore` hiện loại `build/`, Quartus `db/`, `incremental_db/`, `output_files/`, bitstreams, Chisel `target/`/`generated/`, `data/raw/`, `data/external/` và `docs/history/builds/generated/` ([rules](../../.gitignore#L1-L43)). Không commit cache, netlist sinh, báo cáo thô hay khóa bí mật ([rules](../../.gitignore#L45-L56)).
- Dataset/artifact lớn: lưu ngoài Git với URI, checksum, license, phiên bản và script lấy dữ liệu; chỉ cân nhắc Git LFS cho tập nhỏ có quyền phân phối và ngân sách hosting rõ ràng. Chưa có LFS policy/CI triển khai trong tài liệu này; future CI nên chạy test PoC, link/provenance checks và sau đó model–RTL regression; Quartus build chỉ khi có tool/license, project closure và runner xác định ([test plan](../development/verification.md#L3-L11), [requirements](../spec/requirements.md#L16-L23)).
- `hardware/archive/sources/rtl/chisel/build.sbt` định nghĩa Scala 2.12.13/Chisel 3.5.6/chiseltest 0.5.6 ([build](../history/README.md#L1-L27)); legacy QPF khai Quartus 23.1 (`D:\kq_nghiencuu_Caitien\kq_nghiencuu1\LuanVan_SoC\DE1_SoC_Computer.qpf:20-31`, kiểm kê read-only cục bộ ngày 2026-09-30, ngoài repo). Đây là metadata, **không** là xác nhận môi trường đầy đủ hoặc build tái lập.

## D. Giai đoạn tích hợp và điều kiện qua cổng

1. **Kiểm kê read-only:** giữ nguyên thư mục legacy ngoài repo, lập manifest/hash, phân loại handwritten/generated/vendor và license. Quan sát cục bộ ngày 2026-09-30: QSF chỉ ra QIP, SDC và `hex_decoder.v` (`D:\kq_nghiencuu_Caitien\kq_nghiencuu1\LuanVan_SoC\DE1_SoC_Computer.qsf:974-977`). Hai file SDC/decoder không tìm thấy ở path QSF yêu cầu khi kiểm kê; QIP chỉ tới generated `submodules/dehazing_system_top.v` (`D:\kq_nghiencuu_Caitien\kq_nghiencuu1\LuanVan_SoC\Computer_System\synthesis\Computer_System.qip:8018`). Các path `D:\` ở ngoài repo, không portable hoặc tái lập từ checkout cho tới khi có manifest/hash có ngày, dependency closure và kiểm tra từ clean checkout. Gate: xác minh nguồn gốc, tính đầy đủ và quyền sử dụng; không copy source đoán định.
2. **Chốt hợp đồng:** đóng pixel format/clock/reset, sideband, stall, địa chỉ control và nguồn ảnh/đích ([interfaces](../spec/interfaces.md#L3-L13), [requirements](../spec/requirements.md#L7-L14)). Gate: model/vector và checker độc lập cùng review interface.
3. **Tiếp nhận chọn lọc:** chỉ chuyển các nguồn cần thiết được quyền track sang `hardware/archive/sources/boards/de1_soc/` sau manifest và dependency closure; nếu sinh IP, lưu recipe/version/license và chứng minh regeneration, giữ output ngoài Git theo [.gitignore](../../.gitignore#L1-L29). Gate: tham chiếu file khép kín và build từ clean checkout với phiên bản tool ghi rõ; nếu chưa đạt, tiếp tục gọi là legacy intake chưa hoàn tất.
4. **Đo tích hợp:** chạy regression, timing, tài nguyên, thông lượng và điều kiện đo trên board, ghi cả thất bại ([requirements](../spec/requirements.md#L16-L23), [roadmap](../ROADMAP.md#L27-L37)). Không tuyên bố reproducible build hay hiệu năng trước log và artifact đã xác minh.
