# Paper ↔ Implementation review

## Cập nhật sau khi đọc lại nguồn

Nguồn Downloads hiện đã thay đổi: đã tìm thấy và nhập riêng candidate 1×1/LUT/declared 11-cycle, ROM và SDC. Xem [current snapshot review](../../docs/research/current-snapshot-review.md). Các đối chiếu bên dưới vẫn áp dụng cho **baseline 15×15 ban đầu**, không phủ nhận sự tồn tại candidate mới. Candidate gần paper nhưng chưa đạt bit-exact/build/timing validation; power report và fitter report khác ngày.

## 1. Phạm vi

Đối chiếu bản DOCX *A Real-Time FPGA-Based Vision Enhancement System* với nguồn đã nhập từ `LuanVan_SoC`. Đây là rà soát tài liệu/mã nguồn, không chạy lại synthesis, simulation hay board test.

Kết luận chính: **chưa thể coi RTL legacy trong repository là implementation tái lập đúng bản paper**. Khác biệt không chỉ là tên file hay cấu trúc thư mục mà nằm ở thuật toán, spatial window, latency và tài nguyên.

## 2. Ma trận đối chiếu

| Hạng mục | Paper | Repository hiện tại | Hệ quả |
|---|---|---|---|
| Core chính | Point-processing 1×1 | [RGB30 legacy](../../docs/history/README.md) có dark channel 15×15 | Hai kiến trúc khác nhau |
| Transmission | HSV-modulated exponential qua LUT 65536×10-bit | `max(100, 1023 - 3 * dark)` | Không phải cùng estimator |
| Spatial refinement | Không cần | `refinement_15x15_fix` box average | Không thể áp dụng tuyên bố zero line buffer |
| Pixel latency | 11 chu kỳ | `UD_DELAY=17957`, `TOTAL_DELAY=18603` enabled cycles | Chưa có RTL/trace cho latency paper |
| Atmospheric threshold | 220/1023 | `i_t < 200` trong RGB30 | Khác tham số |
| Atmospheric temporal filter | `(15*A + max_frame)/16` | Có cấu trúc tương tự, cập nhật có điều kiện `max_r > 50` | Có tương đồng nhưng không đủ để khẳng định equivalence |
| Transmission floor | 102/1023 | LUT reciprocal dùng mốc 100; transmission raw minimum thực tế 258 | Cần model fixed-point đúng version |
| Gamma | Gamma 1,4 qua LUT | RGB30 không có gamma; RGB24 baseline có một quy ước gamma khác | Không có output path đúng paper được xác định |
| Sharpening | Không được mô tả trong pipeline paper | RGB30 có Laplacian sharpening `k=2` | Biến đổi đầu ra khác |
| Backpressure | FIFO headroom 16, packet delay 11 | RGB30 dùng `i_en=src_ready`, delay RAM; có điểm stall cần kiểm thử | Không áp dụng nguyên mô tả flow control paper |
| Model | Fixed-point bit-exact | [MATLAB legacy](../../software/matlab/Thuat_toan.m) dùng dark 15×15, guided filter, sharpening, gamma nhập | Chưa phải golden model paper |
| On-board input | Demo ảnh tĩnh, camera là bước tiếp theo | [HPS viewer](../../docs/history/README.md) nạp HEX vào FPGA SDRAM | Phù hợp ý tưởng demo, chưa là chứng cứ camera streaming |
| Tài nguyên | 6279 ALM, 1113243 memory bit, 8 DSP | Báo cáo gốc snapshot legacy: 3928 ALM, 2215198 bit, 7 DSP | Các report thuộc build khác nhau; không thay thế nhau |

Số liệu báo cáo legacy ở hàng cuối được quan sát trong file `DE1_SoC_Computer.fit.summary` của snapshot gốc ngoài repository; báo cáo thô không được nhập. Không dùng nó như bằng chứng clean-checkout build.

Chisel `DehazingCore` hiện có là PoC cộng 5 và không được paper chứng minh là core dehazing.

## 3. Những điểm bản thảo cần làm rõ

### 3.1. Số lượng scene

Abstract ghi “three hazy scenes”, trong khi Table 1 và phần kết quả liệt kê **bốn** scene. Cần thống nhất số lượng và xác định ảnh đầu vào tương ứng.

### 3.2. Hai bộ edge metric không cùng pipeline

Từ `nO/nP` của bảng chính, tính lại được:

- Scene 1: +40,82%.
- Scene 2: +6,58%.
- Scene 3: +28,54%.
- Scene 4: +48,25%.

Cột `e(base/prop.)` lại là reimplementation độc lập, đúng như footnote: proposed lần lượt +30,2%, −18,6%, +1,3%, +38,0%. Không gộp hai bộ số liệu hoặc dùng chúng như xác minh chéo đã đạt.

Đoạn giới thiệu Figure 3 gọi Scene 3 là “largest quantitative gain”, nhưng Scene 4 có `e` lớn nhất; Scene 3 có **mức tăng mean gradient** lớn nhất. Cần nêu metric cụ thể thay vì gọi chung “gain”.

### 3.3. Miền chuẩn hóa transmission và atmospheric threshold

Paper nói S/V chuẩn hóa, `omega=1` và:

$$
T'=\exp(-J_{dark}/K),\qquad K\ge1
$$

**Nếu** `Jdark` cũng chuẩn hóa trong [0,1], công thức này cho `T' >= exp(-1) ≈ 0,368`. Khi đó không có pixel đạt điều kiện `T' < 220/1023 ≈ 0,215`, và floor 0,1 không được kích hoạt. Nếu `Jdark` dùng thang 8-bit hoặc scale khác, cần ghi rõ scale đó trong công thức và generator.

Đây là kiểm tra có điều kiện theo toán học, không kết luận ROM thực tế chắc chắn sai: ROM/model tương ứng chưa được cung cấp. Cần chốt miền giá trị, lượng tử hóa, điều kiện khi tập pixel ứng viên rỗng, giá trị khởi tạo `A` và trường hợp pixel đen.

### 3.4. Camera, DDR và phạm vi “no frame buffer”

Abstract giới hạn on-board demonstration ở ảnh tĩnh và ghi camera-to-display là bước tiếp theo. Phần architecture vẫn mô tả camera input 27 MHz và các CDC. Cần phân biệt block dự kiến, block được sinh/tích hợp và block được thử nghiệm.

“No external frame buffer” nên giới hạn ở thuật toán estimation/core single-pass, không đồng nghĩa toàn hệ thống không có SDRAM/DDR buffer. Paper mô tả HPS DDR3 buffer; viewer legacy hiện ghi vào **FPGA SDRAM**, không phải HPS DDR3. Cần sơ đồ/address map đúng phiên bản để xác định đường thực tế.

### 3.5. CDC không được chứng minh chỉ bằng STA

Bản thảo ghi các domain là “mutually exclusive clock groups” và cho rằng closure bảo đảm không metastability/frame drop. Cần rà lại cách khai SDC: các clock chạy đồng thời nhưng không đồng bộ thường cần async-domain treatment phù hợp, không tự mặc định là mutually exclusive.

STA slack dương không thay thế CDC review, asynchronous FIFO verification, reset-domain crossing hoặc MTBF calculation. Tuyên bố `MTBF > 10^9 years` cần tham số device, tần số/data activity, synchronizer depth và báo cáo tương ứng.

### 3.6. Latency, throughput và frame rate

11 chu kỳ là pipeline latency mỗi pixel; 3,072 ms là thời gian lý tưởng để truyền 307200 pixel ở 100 MHz. Không gọi 3,072 ms là latency end-to-end HPS/camera/display đã đo, hoặc suy ra sustained FPS thực tế nếu chưa có log không stall/blanking.

### 3.7. Công suất và phạm vi tài nguyên

- 824,12 mW là estimate vectorless của FPGA, HPS off, không phải công suất toàn board.
- 3 DSP là core; 8 DSP là toàn hệ thống.
- 20% ALM và 27% memory là toàn hệ thống theo Table 2.
- Wall-plug 2,5–4 W được mô tả là mức điển hình; cần đo nếu muốn dùng làm kết quả thực nghiệm.
- So sánh ALM Cyclone V với slice LUT Zynq không phải so sánh đơn vị tương đương.

### 3.8. Citation và cross-reference

Cần rà lại toàn bộ đánh số reference. Ví dụ theo danh mục cuối DOCX:

- He et al. nằm ở [10], nhưng Introduction có chỗ dẫn [11].
- Kumar et al. nằm ở [5], nhưng đoạn giới thiệu dẫn [6].
- Lee et al. nằm ở [6], nhưng Introduction dẫn [7].
- Lightweight CNN paper nằm ở [9], nhưng đoạn deep models dẫn [10].
- Introduction nhắc Table 3, trong tài liệu đọc được có Table 1 và Table 2.

Không tự sửa bản DOCX trong bước này; các điểm trên được ghi để tác giả rà soát.

## 4. Artifact cần có để tái lập paper

- [ ] Git commit/tag xác định phiên bản point-processing 1×1/LUT/11-cycle.
- [ ] RTL chính, wrapper Avalon-ST, FIFO parameters và SOP/EOP timing contract.
- [ ] Transmission/reciprocal/gamma LUT generators; rounding, clipping và scale đầy đủ.
- [ ] ROM contents/checksum hoặc script tái sinh xác định.
- [ ] Floating-point và fixed-point reference models đúng phiên bản.
- [ ] Stimulus/golden output cho 640×480; regression bit-exact và log lỗi lớn nhất.
- [ ] Reset, stall, invalid bubble, frame boundary và atmospheric-update tests.
- [ ] Qsys, SDC, pin constraints, tool/IP versions; clean-checkout build recipe.
- [ ] Post-fit resource, STA/Fmax và power reports cùng cấu hình.
- [ ] Scene assets có quyền dùng, metric scripts, crop/resize/color conventions.
- [ ] Baseline reimplementation và synthetic-proxy generation protocol.
- [ ] Board configuration, clock thực chạy, ảnh/log demo và đo FPS/power nếu có.

Chưa hoàn tất các mục này thì nên mô tả repository là **legacy baseline + documentation of the paper**, không phải released reproducible implementation of the paper.
