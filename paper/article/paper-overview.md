# A Real-Time FPGA-Based Vision Enhancement System

> Tổng quan bằng tiếng Việt dựa trên DOCX do chủ dự án cung cấp. Mọi kết quả thực nghiệm dưới đây là **số liệu được bản thảo công bố**, chưa được tái lập trong repository. Các điểm chưa nhất quán được tách tại [implementation-review.md](implementation-review.md).

## 1. Thông tin bài báo

| Thuộc tính | Nội dung |
|---|---|
| Tiêu đề | A Real-Time FPGA-Based Vision Enhancement System |
| Tác giả ghi trong bản thảo | Duy K. Cao; Kien T. Truong |
| Đơn vị | Faculty of Physics and Engineering Physics, University of Science (HCMUS), Vietnam National University–Ho Chi Minh City, Vietnam |
| Nền tảng | Intel Cyclone V DE1-SoC, FPGA `5CSEMA5F31C6`, ARM Cortex-A9 HPS |
| Ngôn ngữ/công cụ | Verilog, MATLAB, ModelSim, Quartus/Platform Designer |
| Từ khóa | FPGA-based vision enhancement; Hybrid SoC architecture; Dark Channel Prior; Real-time image processing; Halo-artifact removal |
| Trạng thái xuất bản | Chưa xác nhận; file được cung cấp có hậu tố `Final_Submission` |
| DOI / venue | Không xác định từ tài liệu được cung cấp |

## 2. Bài toán và hướng tiếp cận

Sương mù, bụi và khói làm giảm tương phản và khả năng nhận dạng trong ảnh camera, ảnh hưởng đến giám sát, xe tự hành và các hệ thống IoT. Bài báo chọn xử lý tại thiết bị để tránh độ trễ truyền dữ liệu và yêu cầu tài nguyên của xử lý đám mây/deep learning.

Hướng thiết kế là kết hợp:

- **HPS:** cấu hình ngoại vi, quản lý buffer và điều phối hệ thống.
- **FPGA:** pipeline khử sương mù theo luồng pixel.
- **Biến đổi theo từng pixel:** loại bỏ cửa sổ không gian và spatial refinement để giảm line buffer, chi phí tính toán và độ trễ.
- **LUT:** chuyển các phép phi tuyến và phép chia thành truy cập bảng cùng nhân/dịch bit.

Bản thảo phân biệt cách này với DCP cổ điển: khi cửa sổ là 1×1, phương pháp không còn dựa trên thống kê dark channel của một patch không gian; đây là ánh xạ min-channel/HSV được gợi ý bởi mô hình tán xạ.

## 3. Đóng góp kỹ thuật được trình bày

1. Điều biến transmission bằng Saturation và Value, nhằm hạn chế over-enhancement ở cạnh nhiều màu và vùng sáng mà không cần guided filter, bilateral filter hoặc soft matting.
2. Khai thác đẳng thức dark channel 1×1 để biểu diễn estimator bằng hai biến độc lập `Cmax` và `Cmin`, rồi gom toàn bộ phép tính phi tuyến vào một LUT 65536×10-bit.
3. Dùng reciprocal LUT cho restoration, loại bỏ divider trong datapath.
4. Pipeline công bố thông lượng 1 pixel/clock, latency 11 chu kỳ và timing closure tại 100 MHz.
5. Kiểm chứng RTL với fixed-point model MATLAB/ModelSim và trình diễn đường ảnh tĩnh SDRAM/VGA trên board.

## 4. Thuật toán

Các công thức dưới đây được viết lại từ phương trình Word/OMML, không lấy từ phần text thuần vì text thuần làm mất phân số và số mũ.

### 4.1. Mô hình tán xạ

$$
J_{Hazy}(x)=J_{RL}(x)T_R(x)+A_G\bigl(1-T_R(x)\bigr)
$$

Trong đó `J_Hazy` là ảnh quan sát, `J_RL` là scene radiance, `A_G` là atmospheric light và `T_R` là transmission. Mô hình chiều sâu:

$$
T_R(x)=\exp\bigl(-\beta D_{Map}(x)\bigr)
$$

### 4.2. Dark channel và hai feature độc lập

$$
J_{dark}(x)=\min_{y\in N_k(x)}\min_{\tau\in\{R,G,B\}}J_{Hazy}^{\tau}(y)
$$

Với `N_k = 1×1`:

$$
J_{dark}=C_{min},\qquad C_{max}=\max(R,G,B),\qquad C_{min}=\min(R,G,B)
$$

Trong cùng miền chuẩn hóa:

$$
V=C_{max},\qquad S=\frac{C_{max}-C_{min}}{C_{max}},\qquad J_{dark}=V(1-S)
$$

Ở pixel đen `Cmax=0`, phép chia cần quy ước riêng, ví dụ `S=0`; generator LUT phải xác định rõ trường hợp này. Trên phần cứng, địa chỉ bảng vẫn là cặp feature 8-bit; quy tắc chuẩn hóa từ 8-bit sang công thức phải được ghi trong model/generator.

### 4.3. Transmission có điều biến HSV

$$
K(x)=\exp\left(S(x)^4\bigl(V(x)+S(x)\bigr)^{0.01}\right)
$$

$$
T'_R(x)=\exp\left(-\omega\frac{J_{dark}(x)}{K(x)}\right),\qquad\omega=1
$$

Bản thảo mô tả `K` khoảng 1,00–2,74. Cửa sổ 1×1 tránh hiệu ứng trộn vùng lân cận do patch; `K` đóng vai trò bảo vệ theo đặc trưng màu. Đây là cơ chế được bài báo đề xuất, không phải chứng minh rằng mọi dạng halo đều bị loại bỏ trên mọi ảnh.

### 4.4. Atmospheric light

Chọn vùng có transmission thấp:

$$
A_G=\max_{y\in\{x\mid T'_R(x)<T_0\}}J_{Hazy}(y),\qquad T_0=\frac{220}{1023}\approx0.215
$$

Cực đại của frame hiện tại được dùng ở frame tiếp theo và làm mượt:

$$
A_G(f)=\frac{15A_G(f-1)+M_{frame}}{16}
$$

Bản thảo ghi thời gian hội tụ đến sai lệch khoảng 5% là 46 frame, tương đương khoảng 1,55 s tại 30 fps. Vì vậy scene cut là một giới hạn: atmospheric light có thể còn mang giá trị của cảnh cũ trong giai đoạn chuyển tiếp.

### 4.5. Restoration và gamma

Transmission được floor tại:

$$
T_{floor}=\frac{102}{1023}\approx0.1
$$

Sau floor, khôi phục từng kênh:

$$
J_{enh}(x)=\frac{J_{Hazy}(x)-A_G}{\max(T'_R(x),T_{floor})}+A_G
$$

Giới hạn kết quả về miền 8-bit, rồi gamma:

$$
J_{\gamma}(x)=255\left(\frac{J_{enh}(x)}{255}\right)^{\gamma},\qquad\gamma=1.4
$$

Bản thảo chọn gamma 1,4 qua sweep 1,0–1,8 nhằm cân bằng tăng khả năng nhìn thấy cạnh và điều chỉnh độ sáng. Không nên nhầm công thức mũ `gamma` ở đây với quy ước dùng `1/gamma` trong một số implementation khác.

## 5. Kiến trúc phần cứng theo paper

```text
RGB pixel
   │
   ▼
Cmax/Cmin comparator trees
   │  {Cmax, Cmin}: địa chỉ 16-bit
   ▼
Transmission LUT → transmission floor
   │                    │
   │                    └─ Atmospheric light estimation
   ▼
Reciprocal LUT + signed RGB restoration + clipping
   │
   ▼
Gamma LUTs
   │
   ▼
Output FIFO / VGA path

SOP/EOP: delay-matched song song với datapath
```

### 5.1. LUT và số học

| Thành phần | Kích thước / chức năng theo bản thảo |
|---|---|
| Transmission LUT | 65536×10-bit = 655360 bit = 80 KiB; 64 M10K |
| Reciprocal LUT | 1024×14-bit; chứa `floor(2^20 / T_fixed)` cho các địa chỉ hợp lệ |
| Gamma LUT | 3 bảng 256×8-bit |
| Tổng dung lượng bảng | 675840 bit = 82,5 KiB |
| Restoration | Trừ signed, nhân reciprocal, dịch phải 10 bit, cộng atmospheric light, clip |
| DSP riêng core | 3 multiplier cho R/G/B |
| Spatial line buffer | Không có trong core 1×1 được mô tả |

Bản thảo dùng đơn vị “KB”; tài liệu này dùng KiB khi quy đổi theo 1024 byte. Cần generator để xác định nội dung các địa chỉ không dùng (`Cmin > Cmax`) và reciprocal tại `T=0`; không thể suy ra ROM hoàn chỉnh chỉ từ kích thước bảng.

### 5.2. Clock và luồng điều khiển

- Video input: 27 MHz; core: 100 MHz; VGA: 25 MHz.
- Avalon-ST truyền pixel/packet; Avalon-MM dùng điều khiển và truy cập bộ nhớ.
- Bản thảo mô tả asynchronous FIFO tại các clock-domain crossing và đồng bộ con trỏ Gray.
- Backpressure được hấp thụ bởi output FIFO, với biên dự phòng 16 entry lớn hơn latency 11 chu kỳ.
- SOP/EOP được delay-match với dữ liệu.

Đây là mô tả kiến trúc của paper. Muốn xác minh CDC cần RTL, constraint và báo cáo tương ứng; timing slack dương không tự chứng minh không có metastability hoặc frame drop.

### 5.3. Latency khác với thời gian một frame

| Đại lượng | Giá trị được bài báo nêu / suy ra từ cấu hình |
|---|---|
| Latency mỗi pixel | 11 chu kỳ = 110 ns tại 100 MHz |
| Throughput lý tưởng | 1 pixel/clock, khi truyền liên tục |
| Quét 307200 pixel tại 50 MHz | 6,144 ms, chưa cộng overhead hệ thống |
| Quét 307200 pixel tại 100 MHz | 3,072 ms, chưa cộng overhead hệ thống |
| Demo trên board | Đường ảnh tĩnh; Table 2 ghi demonstrated tại 50 MHz |
| Camera-to-display liên tục | Bản abstract ghi là bước tiếp theo |

Thời gian quét pixel không phải FPS thực đo của camera/VGA và không bao gồm blanking, nạp dữ liệu HPS, stall hay thời gian buffer.

## 6. Kiểm chứng được bản thảo công bố

- Fixed-point model MATLAB tạo expected output cho frame 640×480.
- ModelSim đưa cùng stimulus qua Avalon-ST và so sánh từng pixel.
- Kết quả được báo cáo là **bit-exact, 0 LSB** so với fixed-point model.
- Transmission LUT: sai số tuyệt đối tối đa `4,87×10^-4`, xấp xỉ 0,50 LSB ở miền 10-bit.
- Reciprocal LUT: sai số tương đối tối đa 0,09%.
- Gamma LUT: bản thảo báo cáo độ chính xác nửa LSB.

Bit-exact với model lượng tử hóa không đồng nghĩa không có sai số so với floating-point hoặc ảnh ground truth. Testbench, model, ROM và log chứng minh các kết quả này chưa được xác định trong repository hiện tại.

## 7. Kết quả chất lượng ảnh

Bản thảo dùng đánh giá không cần ground truth dựa trên visible edges: Sobel gradient vượt ngưỡng 0,05. Với `nO` và `nP` là số cạnh nhìn thấy trước/sau:

$$
e=\frac{n_P-n_O}{n_O}
$$

Dữ liệu dưới đây lấy từ Table 1; cột `e` được tính lại trực tiếp từ hai cột số cạnh, không lấy từ baseline reimplementation độc lập.

| Scene | nO | nP | e tính từ nO/nP | Mean gradient O → P | Saturated pixel P |
|---|---:|---:|---:|---|---:|
| 1 | 112372 | 158247 | +40,82% | 0,0645 → 0,1112 | 0,02% |
| 2 | 108873 | 116038 | +6,58% | 0,0592 → 0,0781 | 0,01% |
| 3 | 181015 | 232677 | +28,54% | 0,1364 → 0,3190 | 0,05% |
| 4 | 104520 | 154954 | +48,25% | 0,0621 → 0,1125 | 0,03% |

Saturated pixel của ảnh gốc được ghi 0,00% cho cả bốn scene. Bản thảo tổng hợp mức tăng visible edges 6,6–48,3% và mean gradient 31,9–133,9%.

### Baseline độc lập — không trộn với bảng trên

Cột cuối của Table 1 lấy từ một reimplementation khác, theo chú thích của tác giả:

| Scene | e guided-filter DCP baseline (%) | e proposed reimplementation (%) |
|---|---:|---:|
| 1 | +56,0 | +30,2 |
| 2 | +21,6 | −18,6 |
| 3 | +20,9 | +1,3 |
| 4 | +61,2 | +38,0 |

Vì không phải pipeline sinh `nO/nP` ở bảng chính, các giá trị này không thay thế `e` tính từ bảng chính. Đặc biệt Scene 2 reimplementation có giá trị âm; không thể phát biểu rằng mọi implementation đều cải thiện mọi scene.

Trên một synthetic proxy pair, paper báo cáo proposed so với baseline: **PSNR 18,6 vs 15,1 dB; SSIM 0,952 vs 0,899**. Đây không phải kết quả ground-truth trên toàn bộ các scene hazy ở Table 1.

## 8. Tài nguyên, timing và công suất

Số liệu Table 2 được trình bày cho **toàn hệ thống**, không chỉ core:

| Đại lượng | Số liệu bản thảo |
|---|---|
| ALM | 6279 / 32070 — 20% |
| Register | 4875 |
| Block memory | 1113243 / 4065280 bit — 27% |
| RAM block | 144 / 397 |
| DSP toàn hệ thống | 8 / 87 — 9% |
| DSP dehazing core | 3; 5 còn lại được gán cho YCrCb-to-RGB converter |
| PLL / DLL | 2 / 6; 1 / 4 |
| Clock closure được báo cáo | 100 MHz, Slow/Fast × 0/85°C |
| Restricted Fmax | 121,64 MHz tại slow 85°C |
| Worst setup / hold slack | +1,727 ns / +0,077 ns, trên HPS DDR3 PHY |
| FPGA on-chip thermal power | 824,12 mW |
| Phân rã power | Static 422,64; dynamic 282,24; I/O 119,24 mW |
| Điều kiện power estimate | Quartus vectorless, toggle rate 12,5%, HPS off |
| Core dynamic riêng | Bản thảo ghi dưới 65 mW |

Không dùng 824,12 mW như công suất toàn board hoặc phép đo wall-plug. Mức 2,5–4,0 W được bản thảo nêu là mức board điển hình, không có bằng chứng đo mới trong repository.

So sánh với Lee et al. trên Zynq-7000 XC7Z045/DCI 4K chỉ mang tính bối cảnh: khác thiết bị, độ phân giải và đơn vị logic; không phải benchmark tương đương trực tiếp.

## 9. Giới hạn và hướng phát triển

- Điểm xử lý 1×1 giảm tài nguyên/độ trễ, nhưng không giữ giả định prior theo patch của DCP cổ điển.
- Atmospheric light có độ trễ liên frame và phản ứng chậm khi scene cut.
- Bằng chứng on-board được mô tả cho ảnh tĩnh; camera-to-display liên tục chưa được chứng minh hoàn chỉnh trong abstract.
- Đánh giá ít scene và baseline chưa tune; cần dataset/protocol rõ ràng trước kết luận tổng quát.
- Cần bổ sung nguồn LUT, fixed-point model, regression logs, SDC và báo cáo cùng commit để tái lập.
- Hướng tương lai trong conclusion: CNN-based dynamic atmospheric light và multi-spectral fusion; đây chưa phải chức năng đã triển khai.

## 10. Tài liệu tham khảo trọng tâm

Theo danh sách References của DOCX (chưa kiểm chứng độc lập thông tin thư mục):

- He, Sun, Tang: *Single Image Haze Removal Using Dark Channel Prior*, IEEE TPAMI 33, 2341–2353 (2011).
- Lee, Ngo, Kang: *Design of an FPGA-Based High-Quality Real-Time Autonomous Dehazing System*, Remote Sensing 14, 1852 (2022).
- Ngo et al.: *Automating a Dehazing System by Self-Calibrating on Haze Conditions*, Sensors 21, 6373 (2021).
- Ngo et al.: *Visibility Restoration: A Systematic Review and Meta-Analysis*, Sensors 21, 2625 (2021).
- Hautière et al.: *Blind Contrast Enhancement Assessment by Gradient Ratioing at Visible Edges*, Image Anal Stereol 27, 87; bản thảo ghi năm 2011, cần đối chiếu metadata gốc.
- Snider: *Advanced Digital System Design using SoC FPGAs: An Integrated Hardware/Software Approach* (2023).
- Bailey: *Image Processing Using FPGAs* (2019).

Không sử dụng số reference trong phần thân DOCX như nguồn đã xác minh: một số số trích dẫn đang không khớp danh mục. Chi tiết xem [review](implementation-review.md).
