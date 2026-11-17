# FPGA Vision Enhancement — Academic Defense & Interview Q&A

## Bộ câu hỏi–trả lời phản biện học thuật và phỏng vấn kỹ sư vi mạch

**Project:** *A Real-Time FPGA-Based Vision Enhancement System*  
**Platform:** Terasic DE1-SoC, Intel Cyclone V SoC `5CSEMA5F31C6`  
**Authors shown in the submitted paper:** Duy K. Cao and Kien T. Truong  
**Languages:** English and Vietnamese

---

## 0. Cách sử dụng tài liệu này / How to use this document

Tài liệu này được xây dựng từ:

- source tree của project `fpga-vision-enhancement`;
- manuscript *A Real-Time FPGA-Based Vision Enhancement System*;
- poster ICEBA 2026;
- các RTL/HPS/configuration/verification records còn trong repository.

> **Important evidence note.** The signed-license PDF inside the OneDrive project folder was a cloud-only placeholder during the audit session and could not be hydrated by the local file provider. Its publication/technical content was therefore not used as an independent source; the technical claims below were cross-checked against the readable final-submission PDF, poster PDF, tracked manuscript text, RTL, HPS code, and repository README. Do not claim that the license page itself proves a technical result.

### Evidence labels

- **[R] Reported:** số liệu được báo cáo trong paper/poster hoặc historical build record.
- **[S] Source-observed:** có thể đối chiếu trong source/configuration của repository.
- **[A] Audit caveat:** điểm cần nói cẩn thận vì current checkout, historical artifact và paper có thể không cùng một revision.
- **[N] Next validation:** chưa nên trình bày như kết quả đã chứng minh; cần đo hoặc tái tạo thêm.

### Nguyên tắc trả lời khi phỏng vấn

1. Trả lời trực tiếp bằng một câu kết luận trước.
2. Nêu đúng phạm vi: **still-image board demonstration** khác với **continuous camera-to-display validation**.
3. Phân biệt **throughput**, **latency**, **frame time**, **timing closure** và **end-to-end latency**.
4. Khi số liệu là historical/reported, nói rõ: “In the submitted build/report…” thay vì “the current source always does…”.
5. Không gọi bộ xử lý 1×1 là classical patch-based DCP. Cách gọi chính xác hơn là **DCP-inspired min-channel/HSV-modulated per-pixel enhancement**.
6. Nếu chưa có bằng chứng, trả lời: “I have not claimed that yet; the required experiment is …”. Đây là câu trả lời kỹ thuật tốt hơn việc đoán.

---

# 1. Bản giới thiệu nhanh / Executive pitch

## 1.1. Câu trả lời 30 giây bằng tiếng Việt

> Đây là một hệ thống tăng cường khả năng nhìn trong ảnh có sương mù trên DE1-SoC, sử dụng kiến trúc đồng thiết kế ARM–FPGA. HPS chạy Linux để nạp ảnh RGB 640×480 vào SDRAM và điều khiển DMA; FPGA thực hiện một pipeline xử lý streaming theo từng pixel. Thay vì dùng cửa sổ dark-channel lớn và bộ lọc refinement tốn line buffer, tôi dùng đặc trưng `Cmax/Cmin` của từng pixel, một transmission LUT 65,536×10-bit, reciprocal LUT và gamma LUT. Core đạt one pixel per clock, độ trễ báo cáo 11 chu kỳ; bản trình diễn ảnh tĩnh chạy ở 50 MHz và timing của một post-fit build được báo cáo đóng ở 100 MHz. MATLAB và ModelSim khớp bit-exact; bốn cảnh thử nghiệm báo cáo tăng 6.6–48.3% số cạnh nhìn thấy. Giới hạn quan trọng là đây là bộ tăng cường per-pixel nhỏ gọn; continuous camera-to-display chưa được xác nhận đầy đủ trong current evidence.

## 1.2. 30-second answer in English

> This project is an ARM–FPGA co-designed visibility-enhancement system for hazy images on the Terasic DE1-SoC. The Linux HPS loads a 640×480 RGB image into SDRAM and controls the pixel DMA, while the FPGA runs a streaming per-pixel pipeline. Instead of a large patch-based dark-channel computation and a spatial refinement filter, the design uses per-pixel `Cmax/Cmin` features, a 65,536-entry 10-bit transmission LUT, reciprocal lookup, and gamma lookup. The reported core sustains one pixel per clock with 11 cycles of latency; the still-image board demonstration used 50 MHz, while a post-fit build reported timing closure at 100 MHz. The MATLAB fixed-point model and ModelSim RTL matched bit for bit, and four scenes showed 6.6–48.3% more visible edges. The honest scope is a compact per-pixel enhancer; continuous camera-to-display operation is not yet fully validated in the current evidence set.

## 1.3. Bảng số liệu cần nhớ / Essential data sheet

| Hạng mục / Item | Giá trị / Value | Trạng thái |
|---|---:|---|
| FPGA SoC | Cyclone V `5CSEMA5F31C6` on DE1-SoC | [R][S] |
| Image used in HPS demo | 640×480 RGB24, HEX input | [R][S] |
| Core architecture | 1 pixel/clock, streaming | [R][S] |
| Reported core latency | 11 cycles = 110 ns at 100 MHz | [R] |
| Demonstrated still-image clock | 50 MHz; 6.14 ms active pixels/frame | [R] |
| Reported 100-MHz active-pixel time | 3.07 ms/frame | [R] |
| Transmission table | 65,536 × 10-bit = 655,360 bits ≈ 80 KiB | [R][S] |
| Reciprocal table | 1,024 × 14-bit | [R][S] |
| Gamma tables | 3 × 256 × 8-bit | [R][S] |
| Total on-chip table size reported | 675,840 bits ≈ 82.5 KiB | [R] |
| Core DSP use | 3 multipliers/DSP blocks | [R][S] |
| Complete system DSP use | 8 / 87 | [R] |
| Complete system ALMs | 6,279 / 32,070 = 20% | [R] |
| Complete system block memory | 1,113,243 / 4,065,280 bits = 27% | [R] |
| Reported restricted Fmax | 121.64 MHz, slow 85 °C corner | [R][A] |
| Power estimate | 824.12 mW on-chip, vectorless, HPS off | [R][A] |
| Core dynamic estimate | <65 mW | [R][A] |
| Transmission floor | `102/1023 ≈ 0.1` | [R][S] |
| Gamma exponent | `γ = 1.4` | [R][S] |
| Atmospheric-light threshold | `220/1023 ≈ 0.215` | [R][S] |
| Atmospheric adaptation | 1/16 update; approximately 46 frames to within 5% after a cut | [R] |
| Visible-edge gain | +6.6% to +48.3% over four scenes | [R] |
| RTL/reference agreement | 0 LSB error for the reported 640×480 co-simulation | [R] |

> **Unit caution:** `80 KB` in the paper means approximately 80 KiB of 10-bit table storage when calculated from bits. Use the exact bit count if a reviewer asks.

---

# 2. Câu hỏi nền tảng và đóng góp / Scope and contribution questions

## Q01 — Vấn đề nghiên cứu là gì? / What problem does the project solve?

**VI — Trả lời:** Ảnh từ camera trong môi trường sương mù, bụi hoặc haze bị giảm tương phản và giảm số lượng chi tiết nhìn thấy. Với embedded vision, thuật toán phải đồng thời đạt chất lượng hình ảnh, độ trễ thấp, thông lượng ổn định, tài nguyên và công suất phù hợp. Dự án giải quyết bài toán bằng một pipeline FPGA streaming để giảm chi phí phần cứng của dehazing và tránh việc đưa toàn bộ ảnh lên cloud hoặc chạy một CNN lớn.

**EN — Answer:** Haze, fog, and dust reduce image contrast and the number of visible structures. An embedded implementation must balance image quality, latency, deterministic throughput, FPGA resources, and power. This project addresses that trade-off with a streaming FPGA pipeline rather than sending the image to the cloud or using a large CNN.

**Evidence:** [R][S]

## Q02 — Hệ thống của bạn thực sự gồm những khối nào? / What exactly is the system?

**VI — Trả lời:** Hệ thống gồm HPS ARM Cortex-A9 chạy Linux, SDRAM, các bridge HPS–FPGA, pixel DMA, các khối chuyển đổi/resampling video, dehazing core, VGA path và các clock-domain crossings. Trong still-image path, HPS nạp file RGB24 HEX vào SDRAM; DMA phát pixel qua stream; FPGA xử lý và đưa kết quả tới VGA. Camera input subsystem có trong Platform Designer, nhưng việc camera chạy liên tục end-to-end cần được đánh giá riêng.

**EN — Answer:** It is not only an RTL filter. The system contains the ARM Cortex-A9 HPS running Linux, SDRAM, HPS–FPGA bridges, pixel DMA, video conversion/resampling blocks, the dehazing core, VGA output, and clock-domain crossings. In the still-image path, the HPS loads an RGB24 HEX file into SDRAM, DMA streams pixels through the FPGA, and the processed stream reaches VGA. A video-input subsystem exists, but continuous camera end-to-end operation must be validated separately.

## Q03 — Ba đóng góp kỹ thuật chính là gì? / What are the main technical contributions?

**VI — Trả lời:** Tôi sẽ nêu ba đóng góp, không phóng đại: (1) đề xuất transmission estimator điều chế min-channel bằng saturation và value để giảm enhancement quá mức ở biên màu; (2) đồng thiết kế thuật toán với phần cứng, biến estimator thành LUT 65,536 địa chỉ và loại divider/exponential khỏi datapath; (3) xây dựng core streaming one-pixel-per-clock, fixed-point reference và RTL co-simulation bit-exact. Đóng góp không phải là phát minh ra identity `Cmin = V(1-S)`; identity đó là hệ quả của việc chọn cửa sổ 1×1.

**EN — Answer:** I would state three contributions without overclaiming: (1) an HSV-modulated min-channel transmission estimator intended to reduce over-enhancement at chromatic edges; (2) algorithm–hardware co-design that collapses the estimator into a 65,536-entry lookup and removes divider/exponential arithmetic from the datapath; and (3) a one-pixel-per-clock fixed-point RTL pipeline with bit-exact MATLAB/ModelSim co-simulation. The `Cmin = V(1-S)` identity itself is not claimed as a new mathematical discovery; it follows from choosing a 1×1 window.

## Q04 — Tính mới nằm ở thuật toán hay ở kiến trúc? / Is the novelty algorithmic or architectural?

**VI — Trả lời:** Tính mới chính của project nằm ở sự kết hợp algorithm–architecture. Phần algorithm đưa ra hàm `K(S,V)` và cách dùng nó để điều chế transmission; phần architecture biến toàn bộ hàm phi tuyến thành LUT có địa chỉ từ hai đặc trưng 8-bit, sau đó dùng reciprocal/gamma LUT. Vì vậy tôi sẽ gọi đây là một đóng góp co-design và triển khai phần cứng, không tuyên bố rằng 1×1 DCP hay LUT nói chung là hoàn toàn mới.

**EN — Answer:** The strongest novelty claim is the joint algorithm–architecture design. The algorithm defines the `K(S,V)` modulation and the resulting transmission mapping; the architecture makes the nonlinear function a LUT addressed by two 8-bit features and uses reciprocal/gamma tables for the remaining nonlinear operations. I would describe it as a co-design and implementation contribution, not as a claim that 1×1 DCP or LUTs are individually new.

## Q05 — Vì sao chọn FPGA thay vì CPU, GPU hoặc CNN? / Why FPGA instead of a CPU, GPU, or CNN?

**VI — Trả lời:** FPGA phù hợp khi cần throughput xác định, pipeline liên tục, latency thấp và không muốn phụ thuộc vào hệ điều hành trong đường dữ liệu pixel. Thuật toán này có nhiều phép tính trên từng pixel và có thể thay bằng LUT, nên FPGA khai thác được song song theo pipeline với bộ nhớ on-chip. CPU vẫn phù hợp cho điều khiển và nạp ảnh; GPU/CNN có thể cho chất lượng cao hơn nhưng thường đòi hỏi nhiều bộ nhớ, MAC và năng lượng hơn. So sánh công bằng phải giữ cùng resolution, chất lượng, clock, tool flow và end-to-end definition.

**EN — Answer:** FPGA is attractive when deterministic throughput, low latency, and a continuous pixel pipeline matter. The algorithm is mostly per-pixel and its nonlinear functions can be represented by on-chip tables, which maps well to FPGA parallelism and local memory. The CPU remains useful for control and image loading. A CNN or GPU may provide better perceptual quality, but usually at higher memory, MAC, and power cost; any comparison must use the same resolution, quality target, clock, tool flow, and end-to-end definition.

## Q06 — Vì sao chọn DE1-SoC? / Why use the DE1-SoC?

**VI — Trả lời:** DE1-SoC có Cyclone V FPGA và HPS ARM Cortex-A9 trên cùng một chip, có SDRAM, VGA và các bridge HPS–FPGA. Điều đó cho phép chứng minh hardware–software partition bằng một platform giáo dục/nghiên cứu giá hợp lý. Đây không phải là tuyên bố rằng DE1-SoC là platform tối ưu cho mọi sản phẩm; nó là một test vehicle phù hợp để kiểm chứng mapping, streaming, fixed point và integration.

**EN — Answer:** The DE1-SoC combines a Cyclone V FPGA fabric with an ARM Cortex-A9 HPS, SDRAM, VGA, and HPS–FPGA bridges. That makes it a practical research platform for demonstrating hardware–software partitioning at relatively low cost. It is a validation platform, not a claim that this board is optimal for every commercial product.

## Q07 — Bạn gọi đây là dehazing như thế nào khi dùng cửa sổ 1×1? / How can you call it dehazing with a 1×1 window?

**VI — Trả lời:** Đây là câu hỏi phản biện quan trọng. Với cửa sổ 1×1, bộ xử lý không còn là classical DCP theo nghĩa patch-based statistical prior của He et al. nữa. Cách nói chính xác là **DCP-inspired min-channel/HSV-modulated per-pixel visibility enhancement**. Project giữ scattering-model inversion và min-channel intuition, nhưng đánh đổi spatial context để đạt streaming nhỏ gọn và tránh halo do cửa sổ.

**EN — Answer:** This is an important reviewer point. With a 1×1 window, the method is no longer the classical patch-based statistical DCP of He et al. A more accurate description is **DCP-inspired min-channel/HSV-modulated per-pixel visibility enhancement**. The design keeps the scattering-model inversion and min-channel intuition but trades spatial context for a compact streaming datapath and the avoidance of window-induced halos.

## Q08 — “Real-time” trong project nghĩa chính xác là gì? / What does “real-time” mean here?

**VI — Trả lời:** Ở cấp core, real-time nghĩa là có thể xử lý streaming one pixel/clock với thông lượng đủ cho 640×480 ở frame rate mục tiêu và latency xác định. Ở cấp hệ thống, phải tính cả camera, blanking, FIFO, VGA, DMA, HPS và display. Bằng chứng hiện có mạnh nhất cho core và still-image path; continuous camera-to-display chưa nên tuyên bố là đã chứng minh hoàn chỉnh.

**EN — Answer:** At core level, real-time means a deterministic one-pixel-per-clock stream with sufficient throughput for the target 640×480 frame rate. At system level, camera timing, blanking, FIFO behavior, VGA, DMA, HPS, and display latency must also be included. The strongest evidence is for the core and the still-image path; a complete continuous camera-to-display claim should wait for end-to-end validation.

## Q09 — Phạm vi những gì project chưa làm là gì? / What is explicitly outside the demonstrated scope?

**VI — Trả lời:** Project chưa chứng minh đầy đủ continuous camera-to-display operation trên current checkout, chưa có wall-plug power measurement, chưa có ground-truth evaluation rộng, và chưa có matching current-commit timing sign-off được tái tạo hoàn toàn. Ngoài ra, HPS utility dùng `/dev/mem` và phù hợp controlled demonstration hơn là production driver. Nêu giới hạn này trước khi bị hỏi sẽ làm câu trả lời đáng tin hơn.

**EN — Answer:** The project does not yet provide complete current-checkout continuous camera-to-display validation, a wall-plug power measurement, a broad ground-truth quality study, or a fully reproduced timing sign-off tied unambiguously to the current commit. The HPS utility also uses `/dev/mem`, so it is better viewed as a controlled demonstration utility than a production driver.

## Q10 — Bạn đóng góp cá nhân ở đâu? / What was your personal contribution?

**VI — Trả lời mẫu:** Tôi sẽ chỉ nhận những phần có thể chứng minh bằng commit, RTL, script hoặc lab record. Cách trình bày an toàn là: tôi chịu trách nhiệm hoặc trực tiếp tham gia vào việc chuyển thuật toán sang fixed point/LUT, xây dựng RTL pipeline, tích hợp Qsys/HPS–FPGA và verification; đồng tác giả/mentor đóng góp ở phần formulation, review và hướng nghiên cứu theo đúng contribution statement. Nếu được hỏi chi tiết, tôi chỉ rõ file, test và quyết định kỹ thuật mình đã thực hiện.

**EN — Sample answer:** I would claim only work supported by commits, RTL, scripts, or lab records. A defensible description is that I directly contributed to the fixed-point/LUT mapping, RTL pipeline, Qsys/HPS–FPGA integration, and verification, while the co-author/advisor contributed to formulation, review, and research direction according to the contribution statement. I would then point to concrete files, tests, and engineering decisions rather than making a vague “I did everything” claim.

---

# 3. Câu hỏi về mô hình và thuật toán / Algorithm and mathematical model

## Q11 — Mô hình scattering được sử dụng là gì? / What scattering model do you use?

**VI — Trả lời:** Mô hình là

\[
I(x)=J(x)t(x)+A(1-t(x)), \qquad t(x)=e^{-\beta d(x)},
\]

trong đó `I` là ảnh quan sát có haze, `J` là scene radiance cần khôi phục, `A` là atmospheric light và `t` là transmission. Project không ước lượng depth trực tiếp; transmission được xấp xỉ từ đặc trưng màu/min-channel rồi dùng để đảo mô hình.

**EN — Answer:** The model is

\[
I(x)=J(x)t(x)+A(1-t(x)), \qquad t(x)=e^{-\beta d(x)},
\]

where `I` is the hazy observation, `J` is the desired scene radiance, `A` is atmospheric light, and `t` is transmission. The design does not estimate depth explicitly; it estimates transmission from color/min-channel features and then inverts the model.

## Q12 — Dark Channel Prior cổ điển hoạt động như thế nào? / How does classical DCP work?

**VI — Trả lời:** Classical DCP tìm giá trị nhỏ nhất trên cả channel màu và một spatial patch: `dark(x)=min_{y∈Ω(x)} min_c I^c(y)`. Trong vùng không haze, một số pixel có channel rất thấp nên dark channel gần zero; haze làm giá trị này tăng. Sau đó cần atmospheric-light estimation và refinement, thường là soft matting hoặc guided filter. Các bước spatial này gây line-buffer, memory và latency đáng kể trên FPGA.

**EN — Answer:** Classical DCP computes a minimum over both color channels and a local spatial patch: `dark(x)=min_{y∈Ω(x)} min_c I^c(y)`. In haze-free regions, at least one channel is often small, so the dark channel is near zero; haze raises it. Atmospheric-light estimation and a refinement step then follow, commonly soft matting or a guided filter. Those spatial operations create line-buffer, memory, and latency costs in FPGA hardware.

## Q13 — Vì sao `Cmax/Cmin` đủ cho estimator? / Why are `Cmax` and `Cmin` sufficient?

**VI — Trả lời:** Với pixel RGB đã normalize, `V=Cmax` và `S=(Cmax-Cmin)/Cmax`. Suy ra `Cmin=V(1-S)`. Khi chọn cửa sổ 1×1, dark channel chính là `Cmin`, nên cặp `(Cmax,Cmin)` chứa đủ thông tin mà estimator hiện tại sử dụng. Đây là giảm số biến cho phần cứng, không phải khẳng định rằng mọi thông tin màu của pixel đều được bảo toàn.

**EN — Answer:** For a normalized RGB pixel, `V=Cmax` and `S=(Cmax-Cmin)/Cmax`, so `Cmin=V(1-S)`. With a 1×1 window, the dark channel is simply `Cmin`; therefore `(Cmax,Cmin)` is sufficient for the features used by this estimator. This reduces the hardware input dimensionality; it does not mean that all color information is preserved by the estimator.

## Q14 — Hàm modulation `K(S,V)` là gì và tác dụng ra sao? / What is `K(S,V)` and what does it do?

**VI — Trả lời:** Paper dùng dạng

\[
K(S,V)=\exp\left(S^4(V+S)^{0.01}\right),\qquad
 t'(x)=\exp\left(-\frac{J_{dark}(x)}{K(S,V)}\right),
\]

với `λ=1` trong cấu hình báo cáo. Khi saturation tăng, `K` tăng và làm exponent bớt mạnh, nhờ đó giảm xu hướng transmission sụt quá thấp tại biên có màu hoặc vùng sáng. Trong haze ngoài trời dày, saturation thường nhỏ nên `K` gần 1 và không điều chế quá mức.

**EN — Answer:** The paper uses

\[
K(S,V)=\exp\left(S^4(V+S)^{0.01}\right),\qquad
 t'(x)=\exp\left(-\frac{J_{dark}(x)}{K(S,V)}\right),
\]

with `λ=1` in the reported configuration. As saturation increases, `K` increases and reduces the magnitude of the negative exponent, limiting an overly small transmission at colorful edges or bright structures. In dense outdoor haze, saturation is usually low, so `K` remains close to one and does not strongly modulate the estimate.

## Q15 — Các mũ 4 và 0.01 có cơ sở vật lý không? / Are exponents 4 and 0.01 physically derived?

**VI — Trả lời:** Không nên nói chúng được suy ra hoàn toàn từ vật lý. Đây là các hyperparameter thực nghiệm được chọn qua sweep trên tập cảnh của project. Paper báo cáo sweep exponent chính trong khoảng 2–6 làm thay đổi mean edge metric khoảng 0.1%, nhưng bằng chứng vẫn là tập thử nghiệm giới hạn. Câu trả lời học thuật là: chúng là empirical design parameters, cần validation rộng hơn để chứng minh khả năng tổng quát.

**EN — Answer:** They should not be presented as fully physics-derived constants. They are empirical design parameters selected through sweeps on the project scenes. The paper reports that sweeping the main exponent from 2 to 6 changed the mean edge metric by about 0.1%, but the evidence set is limited. The academically correct answer is that broader validation is still needed to establish generalization.

## Q16 — Vì sao phải đặt transmission floor 0.1? / Why impose a transmission floor of 0.1?

**VI — Trả lời:** Radiance recovery có phép chia cho `t`; nếu `t` quá nhỏ, nhiễu và sai số lượng tử bị khuếch đại rất mạnh. Đặt `t_floor≈0.1` giới hạn gain nghịch đảo khoảng 10 lần. Trên phần cứng, `T_FLOOR=102` trên thang 10-bit. Đây là trade-off: floor cao hơn ổn định hơn nhưng có thể bỏ sót haze dày; floor thấp hơn tăng enhancement nhưng dễ tạo noise, clipping và màu giả.

**EN — Answer:** Radiance recovery divides by `t`; when `t` is very small, noise and quantization error are amplified severely. Setting `t_floor≈0.1` limits inverse gain to roughly 10×. In RTL this is `T_FLOOR=102` on a 10-bit scale. It is a trade-off: a higher floor is more stable but may under-correct dense haze; a lower floor gives stronger enhancement but increases noise, clipping, and color artifacts.

## Q17 — Atmospheric light được ước lượng như thế nào? / How is atmospheric light estimated?

**VI — Trả lời:** Với các pixel có transmission thấp hơn ngưỡng `t0=220/1023≈0.215`, core giữ giá trị sáng nhất đủ điều kiện, tức maximum channel `p_m`. Giá trị này được cập nhật theo frame. Vì pipeline không giữ toàn bộ frame bên ngoài, thiết kế dùng running maximum của frame hiện tại và áp dụng giá trị đã lọc cho frame kế tiếp.

**EN — Answer:** For pixels whose transmission is below `t0=220/1023≈0.215`, the core keeps the brightest eligible value, represented by the maximum channel `p_m`. That value is updated once per frame. Since the pipeline does not require an external full-frame store for this operation, the design uses a running maximum from the current frame and applies the filtered value to the next frame.

## Q18 — Công thức temporal smoothing là gì? / What is the temporal smoothing formula?

**VI — Trả lời:** Công thức báo cáo là

\[
A_f=\frac{15A_{f-1}+M_f}{16}.
\]

Đây là exponential moving average đơn giản với hệ số 1/16. Nó làm giảm flicker giữa các frame nhưng tạo một frame lag và phản ứng chậm sau scene cut. Paper ước tính cần khoảng 46 frame, tương đương 1.55 s ở 30 fps, để tiến đến trong vòng 5% giá trị mới trong điều kiện đã nêu.

**EN — Answer:** The reported update is

\[
A_f=\frac{15A_{f-1}+M_f}{16}.
\]

This is a simple 1/16 exponential moving average. It reduces frame-to-frame flicker but introduces a one-frame lag and slow adaptation after a scene cut. The paper estimates about 46 frames, or 1.55 s at 30 fps, to reach within 5% of the new value under the stated assumptions.

## Q19 — Vì sao dùng một giá trị `A` scalar thay vì RGB vector? / Why use scalar `A` instead of an RGB vector?

**VI — Trả lời:** Scalar atmospheric light giảm bộ nhớ trạng thái, logic điều khiển và chi phí truyền dữ liệu trong core. Nó phù hợp với mục tiêu visibility enhancement nhỏ gọn. Tuy nhiên, đây là một simplification so với các implementation ước lượng `A_R,A_G,A_B`; trong cảnh có atmospheric color mạnh, scalar `A` có thể gây color bias. Đây là limitation cần nêu rõ, không nên gọi là mô hình đầy đủ nhất.

**EN — Answer:** A scalar atmospheric value reduces state, control logic, and data movement in the core, which supports a compact implementation. It is suitable for the stated visibility-enhancement objective. However, it is a simplification compared with estimating `A_R,A_G,A_B`; strongly colored atmospheric light may produce color bias. This should be stated as a limitation rather than hidden.

## Q20 — Công thức khôi phục radiance là gì? / What is the radiance-recovery equation?

**VI — Trả lời:** Sau khi có `A` và transmission đã floor, hệ thống dùng

\[
J_{enh}(x)=\frac{I(x)-A}{\max(t'(x),0.1)}+A.
\]

Trong RTL, phần `I-A` là signed difference, nhân với reciprocal LUT, shift theo fixed-point scale, cộng lại `A`, rồi clip về [0,255]. Cách này giữ datapath không có divider.

**EN — Answer:** After obtaining `A` and the floored transmission, the system uses

\[
J_{enh}(x)=\frac{I(x)-A}{\max(t'(x),0.1)}+A.
\]

The RTL forms a signed `I-A` difference, multiplies it by a reciprocal-table value, shifts according to the fixed-point scale, adds `A`, and clips to [0,255]. Thus the datapath contains no divider.

## Q21 — Vì sao cần gamma correction `γ=1.4`? / Why add gamma correction with `γ=1.4`?

**VI — Trả lời:** Inversion scattering thường làm ảnh sáng lên mạnh, đặc biệt khi transmission thấp. Gamma correction được dùng để điều chỉnh brightness sau restoration:

\[
J_{out}=255\left(\frac{J_{enh}}{255}\right)^{\gamma}.
\]

`γ=1.4` là giá trị empirical từ sweep; nó không phải hằng số phổ quát. LUT riêng cho ba channel loại bỏ phép lũy thừa khỏi datapath.

**EN — Answer:** Scattering inversion can lift brightness strongly, particularly at low transmission. Gamma correction compensates that effect:

\[
J_{out}=255\left(\frac{J_{enh}}{255}\right)^{\gamma}.
\]

The reported `γ=1.4` comes from an empirical sweep and is not universal. Three channel LUTs replace the exponentiation in hardware.

## Q22 — Pixel đen hoàn toàn xử lý thế nào? / What happens for an all-black pixel?

**VI — Trả lời:** Với `Cmax=0`, biểu thức saturation dạng chia trực tiếp sẽ không xác định về mặt số học. Implementation tránh phép chia trong datapath bằng cách dùng LUT đã sinh trước theo `Cmax/Cmin`; địa chỉ `(0,0)` phải được định nghĩa rõ trong generator/LUT, thường theo một policy bảo thủ. Đây là một edge case phải có test vector riêng; không nên chỉ dựa vào công thức liên tục.

**EN — Answer:** For `Cmax=0`, direct saturation computation would be undefined. The implementation avoids runtime division by using a precomputed LUT indexed by `(Cmax,Cmin)`, so address `(0,0)` must be explicitly defined by the LUT generator. This is an edge case that deserves a dedicated test vector rather than being assumed correct from the continuous equation.

## Q23 — Những failure cases nào dễ xảy ra? / What are likely failure cases?

**VI — Trả lời:** Các trường hợp rủi ro gồm cảnh không có haze nhưng có saturation cao, vật thể sáng bị coi là atmospheric light, vùng rất tối chứa noise, cảnh có haze không đồng nhất theo không gian, thay đổi cảnh đột ngột và ảnh có color cast. Do không có spatial refinement, thuật toán không mô hình hóa local depth/haze variation tốt. Từ đó tôi sẽ nói project là visibility enhancer có giới hạn, không phải một dehazer tổng quát cho mọi điều kiện.

**EN — Answer:** Risk cases include haze-free scenes with strong saturation, bright objects being selected as atmospheric light, dark noisy regions, spatially nonuniform haze, abrupt scene changes, and colored atmospheric light. Because there is no spatial refinement, the design does not model local depth or haze variation as well as a full patch-based method. Therefore it is best described as a constrained visibility enhancer, not a universal dehazer.

## Q24 — So với guided filter/soft matting, trade-off là gì? / What is the trade-off against guided filtering or soft matting?

**VI — Trả lời:** Guided filter và soft matting sử dụng spatial context nên có thể làm transmission mượt hơn và giữ cấu trúc tốt hơn, nhưng cần line buffers, local statistics và nhiều memory bandwidth. Thiết kế này bỏ spatial refinement, đổi lại có datapath ngắn, không cần line buffer và thuận lợi cho one-pixel-per-clock. Đổi lại, chất lượng có thể kém hơn ở vùng haze không đồng nhất hoặc cấu trúc cần context.

**EN — Answer:** Guided filtering and soft matting use spatial context, so they can refine transmission more effectively, but they require line buffers, local statistics, and additional memory bandwidth. This design removes spatial refinement, giving a shorter and more regular one-pixel-per-clock datapath without a line buffer. The trade-off is lower robustness in spatially varying haze or structures that need neighborhood context.

---

# 4. Fixed-point, LUT và tài nguyên toán học / Fixed-point and LUT questions

## Q25 — Vì sao transmission LUT có đúng 65,536 địa chỉ? / Why exactly 65,536 transmission entries?

**VI — Trả lời:** `Cmax` và `Cmin` mỗi biến có 8 bit. Ghép chúng thành địa chỉ 16 bit: `{Cmax,Cmin}`, nên có `2^16=65,536` địa chỉ. Mỗi entry lưu transmission 10 bit. Tổng storage là `65,536×10=655,360 bits`, tương đương khoảng 80 KiB theo cách tính binary.

**EN — Answer:** `Cmax` and `Cmin` are each 8-bit values. Concatenating them as `{Cmax,Cmin}` creates a 16-bit address, hence `2^16=65,536` entries. Each entry stores a 10-bit transmission, for `65,536×10=655,360 bits`, approximately 80 KiB in binary storage terms.

## Q26 — Reciprocal LUT dùng fixed-point scale nào? / What fixed-point scale does the reciprocal LUT use?

**VI — Trả lời:** RTL lưu gần đúng `2^20/t` trong bảng 14-bit, với `t` là transmission 10-bit và đã floor. Sau khi nhân signed difference, RTL shift phải 10 bit, nên về gần đúng ta có `(I-A)×(2^20/t) >> 10 = (I-A)×2^10/t`, tương ứng với chia cho `t/1024`. Ý tưởng chính là đổi phép chia thành một phép nhân và shift xác định.

**EN — Answer:** The RTL stores an approximation of `2^20/t` in a 14-bit table, where `t` is the 10-bit floored transmission. After multiplying the signed difference, the result is shifted right by 10 bits, giving approximately `(I-A)×(2^20/t)>>10 = (I-A)×2^10/t`, which corresponds to division by `t/1024`. The key transformation is division into a table lookup, multiply, and deterministic shift.

## Q27 — Tại sao không dùng divider hoặc exponential IP? / Why not use divider or exponential IP cores?

**VI — Trả lời:** Divider và exponential hardware thường làm tăng area, latency, routing pressure và power; chúng cũng khó giữ throughput một pixel mỗi clock nếu không pipeline sâu. Vì input range đã biết và 8-bit, LUT là lựa chọn hợp lý: computation được chuyển offline sang table generation, còn runtime chỉ đọc RAM và thực hiện multiply/add/clip. Giá phải trả là memory, quantization error và độ linh hoạt thấp hơn.

**EN — Answer:** Divider and exponential IP can increase area, latency, routing pressure, and power, and may require deeper pipelines to sustain one pixel per clock. Because the input ranges are bounded and 8-bit, LUTs move the nonlinear computation offline; runtime needs RAM reads plus multiply/add/clip. The cost is on-chip memory, quantization error, and less flexibility when parameters change.

## Q28 — Tại sao transmission dùng 10 bit? / Why use a 10-bit transmission value?

**VI — Trả lời:** 10 bit cho 1,024 mức transmission, giảm lượng tử hóa so với 8 bit nhưng vẫn phù hợp với LUT và RAM trên Cyclone V. Paper báo cáo sai số tuyệt đối lớn nhất của transmission LUT khoảng `4.87×10^-4`, tương đương khoảng 0.50 LSB trên thang 10-bit. Đây là mức cân bằng giữa chất lượng số, kích thước RAM và độ rộng multiplier.

**EN — Answer:** A 10-bit transmission provides 1,024 levels, reducing quantization relative to 8 bits while remaining practical for FPGA RAM and multipliers. The paper reports a maximum absolute transmission-table error of about `4.87×10^-4`, approximately 0.50 LSB on a 10-bit scale. It is a compromise between numerical quality, memory size, and datapath width.

## Q29 — Ba loại LUT dùng bao nhiêu memory? / How much memory do the LUTs use?

**VI — Trả lời:** Transmission LUT là 655,360 bits. Reciprocal LUT là `1,024×14=14,336 bits`. Ba gamma LUT là `3×256×8=6,144 bits`. Tổng ba nhóm khoảng `675,840 bits`, tức khoảng 82.5 KiB. Con số complete-system memory lớn hơn vì còn Qsys/video/HPS RAM và các IP khác.

**EN — Answer:** The transmission table uses 655,360 bits. The reciprocal table uses `1,024×14=14,336 bits`. Three gamma tables use `3×256×8=6,144 bits`. Together they total about `675,840 bits`, or 82.5 KiB. Complete-system memory is larger because it includes Qsys/video/HPS components and other IP storage.

## Q30 — Quantization error được xác định thế nào? / How do you quantify quantization error?

**VI — Trả lời:** Tính giá trị bằng floating/double precision từ công thức, sau đó so sánh với giá trị table fixed-point trên toàn bộ hoặc toàn miền input hợp lệ. Paper báo cáo transmission max absolute error 0.50 LSB, reciprocal relative error 0.09% và gamma table đạt half-LSB precision. Cần nói rõ đó là table-function error; nó không tự động chứng minh output image error bằng 0 trong mọi input nếu các bước khác thay đổi.

**EN — Answer:** Compute the function in floating or double precision over the valid input domain, quantize it into the target fixed-point representation, and compare the table output against the high-precision reference. The paper reports 0.50-LSB maximum transmission error, 0.09% reciprocal relative error, and half-LSB gamma precision. These are table-function error bounds; they do not automatically prove zero image error for every possible implementation variant.

## Q31 — Bit-exact nghĩa là gì? / What does bit-exact mean?

**VI — Trả lời:** Với cùng input frame, cùng fixed-point conventions, cùng LUT contents, cùng rounding/truncation và cùng clipping, output từng pixel từng channel của ModelSim trùng với MATLAB fixed-point reference, tức sai khác 0 LSB trong test được báo cáo. Nó không có nghĩa rằng ảnh phần cứng ngoài đời sẽ luôn giống tuyệt đối do camera noise, clock/FIFO lỗi, reset hoặc sai khác version/tool.

**EN — Answer:** For the same input frame, fixed-point conventions, LUT contents, rounding/truncation rules, and clipping, every output pixel and channel from ModelSim matched the MATLAB fixed-point reference in the reported test, giving 0-LSB difference. It does not mean a physical camera system will always match perfectly; sensor noise, FIFO behavior, reset, clocking, and tool/version differences remain separate concerns.

## Q32 — LUT được sinh và kiểm soát version như thế nào? / How should LUT generation be version-controlled?

**VI — Trả lời:** Generator phải ghi rõ input formula, parameter `γ`, `T_FLOOR`, transmission scale, rounding mode, endian/hex format và checksum. LUT phải được coi là derived artifact nhưng cần freeze cùng commit hoặc regenerate deterministic trong build. Khi thay hyperparameter, phải regenerate LUT, chạy reference, RTL simulation và kiểm tra resource/timing lại; không được thay một file `.hex` thủ công mà không cập nhật provenance.

**EN — Answer:** The generator should record the formula, `γ`, `T_FLOOR`, transmission scale, rounding mode, hex/endian format, and checksum. The LUT is a derived artifact, but it must be reproducible from a commit or frozen with explicit provenance. Whenever a parameter changes, regenerate the LUT, rerun the reference and RTL tests, and recheck resource and timing; manually replacing a `.hex` file is not sufficient.

## Q33 — Tại sao không dùng CORDIC hoặc polynomial approximation? / Why not CORDIC or polynomial approximation?

**VI — Answer / Trả lời:**

**VI:** CORDIC hoặc polynomial có thể giảm RAM và tăng khả năng điều chỉnh runtime, nhưng cần pipeline arithmetic, coefficient storage, range reduction và proof về sai số. Với miền input nhỏ, LUT cho latency và verification đơn giản hơn. Tôi sẽ chọn lại bằng design-space exploration nếu target chuyển sang 1080p/4K, cần runtime reconfiguration hoặc block RAM là bottleneck.

**EN:** CORDIC or polynomial approximations may reduce RAM and offer more runtime flexibility, but they require arithmetic pipelines, coefficient storage, range reduction, and an error proof. For this bounded input domain, LUTs simplify latency and verification. I would revisit that choice for a 1080p/4K target, runtime reconfiguration, or a design in which block RAM becomes the limiting resource.

## Q34 — Có thể thay `γ`, `T_FLOOR`, hoặc `K` runtime không? / Can `γ`, `T_FLOOR`, or `K` be changed at run time?

**VI — Trả lời:** Bản hiện tại chủ yếu compile-time/LUT-time configurable. `STRENGTH=256` và `T_FLOOR=102` được gắn trong RTL; gamma và transmission functions nằm trong ROM. Runtime tuning sẽ cần register interface, nhiều LUT bank hoặc interpolation, cùng cơ chế đồng bộ theo frame để tránh đổi bảng giữa chừng. Đây là hướng mở rộng chứ không phải capability đã chứng minh của bản demo.

**EN — Answer:** The current design is primarily configurable at compile time or LUT-generation time. `STRENGTH=256` and `T_FLOOR=102` are RTL parameters, while gamma and transmission functions are stored in ROMs. Runtime tuning would require a register interface, multiple table banks or interpolation, and frame-safe update control so that a table is not changed mid-frame. That is future work, not a demonstrated runtime feature.

## Q35 — 8-bit input ảnh hưởng khả năng tổng quát thế nào? / How does 8-bit input limit generality?

**VI — Trả lời:** LUT address và gamma table hiện giả định RGB 8-bit. Nếu sensor 10/12 bit, số địa chỉ tăng rất nhanh hoặc cần quantize trước, partition table, interpolation hoặc đổi feature representation. Vì vậy kết quả hiện tại gắn với 8-bit RGB, 640×480 và cấu hình LUT cụ thể; không được tự động ngoại suy cho mọi sensor.

**EN — Answer:** The LUT address and gamma tables assume 8-bit RGB input. A 10- or 12-bit sensor would greatly increase the address space unless the design quantizes the features, partitions the table, or uses interpolation or a different representation. Therefore the current results are tied to 8-bit RGB, 640×480, and the stated LUT configuration; they do not automatically generalize to every sensor.

---

# 5. RTL, streaming và clock-domain crossing / RTL and streaming questions

## Q36 — Hãy mô tả pipeline RTL theo từng stage. / Describe the RTL pipeline stage by stage.

**VI — Trả lời:** Stage đầu tính `Cmax/Cmin` bằng comparator tree. Stage `dark_channel_1x1` đăng ký hai feature. `transmission_engine` đọc transmission ROM qua các read stages. `refinement_1x1` áp dụng scale và transmission floor. Atmospheric-light estimator chạy song song trên pixel đã delay-align. `image_restoration_soc` tạo signed difference, nhân reciprocal, shift, cộng `A` và clip. `gamma_correction_soc` đọc ba gamma LUT. Original pixel và packet signals được delay song song để bypass hoặc so sánh.

**EN — Answer:** The first stage computes `Cmax/Cmin` with comparator trees. The 1×1 dark-channel stage registers those features. The transmission engine reads the transmission ROM through registered read stages. The refinement stage applies scaling and the transmission floor. Atmospheric-light estimation runs in parallel on the delay-aligned pixel. The restoration stage forms signed differences, multiplies by the reciprocal, shifts, adds `A`, and clips. The gamma stage reads three channel LUTs. The original pixel and packet signals are delayed in parallel for bypass or comparison.

## Q37 — 11 cycles latency khác gì one pixel per clock? / How is 11-cycle latency different from one pixel per clock?

**VI — Trả lời:** Latency là thời gian từ pixel đầu vào đến chính pixel đó ở đầu ra: 11 chu kỳ, tương đương 110 ns ở 100 MHz. Throughput là khoảng cách giữa hai pixel đầu ra liên tiếp sau khi pipeline đầy: một pixel mỗi chu kỳ. Vì vậy pipeline có thể mất 11 cycles để cho pixel đầu tiên nhưng sau đó vẫn phát một pixel/cycle.

**EN — Answer:** Latency is the time from an input pixel to that same pixel at the output: 11 cycles, or 110 ns at 100 MHz. Throughput is the spacing between consecutive output pixels after the pipeline is full: one pixel per cycle. Thus the first pixel takes 11 cycles, but the steady-state stream can still produce one pixel every cycle.

## Q38 — Backpressure được xử lý thế nào? / How is backpressure handled?

**VI — Trả lời:** Top-level RTL dùng `src_ready` để tạo `i_en` và gán `snk_ready=src_ready`; khi downstream không sẵn sàng, pipeline giữ trạng thái thay vì tiếp tục shift. Packet/valid data chỉ tiến khi enable. Tuy nhiên cần phân biệt “có cơ chế stall” với “đã chứng minh mọi stall pattern”: verification phải test random backpressure, bubble, SOP/EOP và full/empty FIFO.

**EN — Answer:** The top-level RTL uses `src_ready` as `i_en` and assigns `snk_ready=src_ready`; when downstream is not ready, the pipeline stops shifting rather than consuming new data. Valid, data, and packet signals advance under the same enable. Having a stall mechanism is not the same as proving every stall pattern, so verification should include random backpressure, bubbles, SOP/EOP, and FIFO full/empty conditions.

## Q39 — Vì sao phải delay original pixel và SOP/EOP? / Why delay the original pixel and SOP/EOP?

**VI — Trả lời:** Core xử lý có nhiều register stages nên pixel output bị trễ. Nếu bypass/original pixel hoặc SOP/EOP không trễ cùng số chu kỳ, output frame sẽ lệch dữ liệu và packet boundary. Thiết kế dùng delay line cho payload/valid và packet signals; `TOTAL_DELAY=11` là contract cần được kiểm chứng bằng assertion hoặc waveform, không nên chỉ tin vào tên parameter.

**EN — Answer:** The processing core contains multiple register stages, so the processed pixel is delayed. If the bypass/original pixel or SOP/EOP signals are not delayed by the same number of enabled cycles, the output frame becomes misaligned. The design uses delay lines for payload, valid, and packet signals; `TOTAL_DELAY=11` is a timing contract that should be checked with assertions or waveforms rather than trusted only by parameter names.

## Q40 — Avalon-ST và ready/valid cần bảo đảm điều gì? / What must Avalon-ST ready/valid guarantee?

**VI — Trả lời:** Khi `valid=1` và `ready=0`, sender phải giữ data, SOP/EOP và các sideband ổn định. Khi transfer xảy ra, cả hai phải high trong cùng chu kỳ. Mọi pipeline stage có thể stall phải giữ đồng bộ data/valid/packet. Đây là nơi dễ có lỗi hơn phép toán; tôi sẽ ưu tiên assertions cho stability under stall, no data loss, no duplication và frame-boundary conservation.

**EN — Answer:** When `valid=1` and `ready=0`, the sender must hold data, SOP/EOP, and sidebands stable. A transfer occurs only when both are high. Every stage that can stall must preserve data/valid/packet alignment. This is often a larger risk than the arithmetic itself, so I would use assertions for stability under stall, no loss, no duplication, and preservation of frame boundaries.

## Q41 — Clock domains trong hệ thống là gì? / What clock domains are present?

**VI — Trả lời:** Paper mô tả video input khoảng 27 MHz, core 100 MHz và VGA khoảng 25 MHz; HPS DDR3 có clock/PHY riêng. Các domain giao tiếp qua dual-clock asynchronous FIFO, Gray-coded pointers và synchronizer nhiều tầng. Cần nói “reported architecture uses…”; để khẳng định current implementation sạch CDC phải xem SDC, generated Qsys và CDC/timing report tương ứng.

**EN — Answer:** The paper describes approximately 27 MHz video input, a 100 MHz core, and approximately 25 MHz VGA, with a separate HPS DDR3 clock/PHY domain. Crossings use dual-clock asynchronous FIFOs, Gray-coded pointer synchronization, and multi-stage synchronizers. The safe wording is “the reported architecture uses…”; current implementation quality still requires matching SDC, generated Qsys, and CDC/timing evidence.

## Q42 — Vì sao dùng async FIFO thay vì chỉ synchronize từng bus? / Why use an asynchronous FIFO rather than synchronizing a bus bit by bit?

**VI — Trả lời:** Một bus pixel và các control signals phải được chuyển cùng nhau, trong khi hai clock không có phase relationship cố định. Synchronize từng bit có thể làm các bit của cùng pixel ổn định ở những thời điểm khác nhau. Async FIFO tách write/read clock, bảo toàn word ordering và dùng pointer synchronization để truyền trạng thái đầy/rỗng an toàn.

**EN — Answer:** A pixel bus and its control signals must cross together between unrelated clocks. Bit-by-bit synchronization can make different bits of one pixel settle at different times. An asynchronous FIFO separates write and read clocks, preserves word ordering, and uses synchronized pointers to communicate full/empty state safely.

## Q43 — Reset cần được thiết kế thế nào? / How should reset be designed?

**VI — Trả lời:** Reset phải đưa valid về zero, clear delay lines/pointers, đặt output deterministic và release đồng bộ trong từng clock domain. Với async reset assertion nhưng synchronous deassertion, cần synchronizer riêng cho mỗi domain. Testbench phải kiểm tra reset giữa frame, reset khi FIFO có dữ liệu và first-SOP sau reset. Một ảnh đúng sau reset không đủ để chứng minh reset protocol hoàn chỉnh.

**EN — Answer:** Reset must clear valid, delay-line state, FIFO pointers, and produce deterministic outputs, with deassertion synchronized per clock domain. If asynchronous assertion is used, deassertion should still be synchronized in each domain. The testbench should exercise reset between frames, reset with FIFO contents, and the first SOP after reset; a single successful boot is not enough to prove reset correctness.

## Q44 — Tại sao atmospheric estimator chạy song song? / Why is atmospheric estimation parallelized?

**VI — Trả lời:** Estimator cần pixel brightness và transmission thấp; nó không cần nằm trong critical path của restoration nếu output frame kế tiếp dùng `A` đã lọc. Chạy song song giúp giữ throughput và tránh thêm nhiều cycle vào per-pixel path. State chủ yếu là running maximum, frame-boundary control và filtered `A`, nên chi phí nhỏ hơn việc lưu toàn bộ frame.

**EN — Answer:** The estimator needs pixel brightness and low-transmission status, but it need not sit in the critical path of restoration if the filtered `A` is applied to the next frame. Running it in parallel preserves throughput and avoids adding a large serial latency. Its state is mainly a running maximum, frame-boundary control, and filtered `A`, which is much cheaper than storing a full frame.

## Q45 — Vì sao không lưu cả frame để estimate `A` chính xác hơn? / Why not buffer the whole frame for a more accurate `A`?

**VI — Trả lời:** Full-frame buffering có thể cho phép hai-pass hoặc random access nhưng tăng memory, bandwidth, latency và control complexity. Mục tiêu của project là streaming, nên dùng running maximum và temporal smoothing. Nếu chất lượng atmospheric-light là ưu tiên cao hơn, frame buffer hoặc HPS-assisted two-pass có thể là hướng mở rộng, nhưng khi đó trade-off real-time/resource phải đo lại.

**EN — Answer:** A full-frame buffer could enable a two-pass or random-access estimator, but it increases memory, bandwidth, latency, and control complexity. The project targets streaming, so it uses a running maximum and temporal smoothing. If atmospheric-light accuracy becomes the priority, a frame buffer or HPS-assisted two-pass design is possible, but the real-time and resource trade-offs must then be remeasured.

## Q46 — Bus pixel được đóng gói như thế nào? / How is the pixel bus packed?

**VI — Trả lời:** RTL top-level dùng stream 30 bit, với mỗi channel RGB 8 bit và các bit padding theo format Avalon/video path. Input lấy `snk_data[29:22]`, `[19:12]`, `[9:2]`; output đóng gói lại tương tự. Khi debug, phải kiểm tra RGB order, byte alignment, padding bits và endian giữa HEX, SDRAM, DMA, resampler và core; rất nhiều lỗi “thuật toán sai” thực ra là lỗi format.

**EN — Answer:** The top-level stream is 30 bits, carrying three 8-bit RGB channels with format-specific padding. The RTL extracts `snk_data[29:22]`, `[19:12]`, and `[9:2]`, and repacks the output similarly. Debugging must verify RGB order, byte alignment, padding bits, and endianness across the HEX file, SDRAM, DMA, resampler, and core; many apparent algorithm errors are actually format errors.

## Q47 — Rủi ro RTL nào bạn đã nhận diện? / What RTL risks have you identified?

**VI — Trả lời:** Các rủi ro chính là delay mismatch, signed/unsigned arithmetic, overflow trước khi clip, stall không giữ payload, reset/first-frame state, frame-boundary timing, ROM initialization và CDC. Trong archived RTL snapshot, `atmospheric_light_est` còn có token `beginS`, là một compile blocker nếu đúng là file được đưa vào build. Vì vậy tôi không nên tuyên bố current checkout compile sạch chỉ dựa trên historical `.sof` hoặc generated artifacts.

**EN — Answer:** The main risks are delay mismatch, signed/unsigned arithmetic, overflow before clipping, failure to hold payload under stall, reset/first-frame state, frame-boundary timing, ROM initialization, and CDC. In the archived RTL snapshot, `atmospheric_light_est` contains the token `beginS`, which would be a compile blocker if that exact file is in the build. Therefore I should not claim that the current checkout compiles cleanly merely because a historical `.sof` or generated artifact exists.

## Q48 — Authored source và generated source khác nhau thế nào? / What is the difference between authored and generated source?

**VI — Trả lời:** Authored source là RTL/Qsys/pin/configuration mà nhóm sửa; generated source là output của Platform Designer/Quartus. Generated files có thể tồn tại từ một revision khác và không chứng minh canonical source hiện tại tái tạo được bitstream. Khi reproducibility, phải freeze input manifest, tool version, generated IP version, constraints, LUT checksum và final artifact checksum.

**EN — Answer:** Authored source is the RTL, Qsys, pin, and configuration material edited by the team; generated source is emitted by Platform Designer/Quartus. Generated files can survive from a different revision and do not prove that the current canonical inputs reproduce the bitstream. Reproducibility requires an input manifest, tool version, generated-IP version, constraints, LUT checksums, and final-artifact checksums.

---

# 6. HPS, memory và deployment / HPS, memory, and deployment

## Q49 — HPS làm gì và FPGA làm gì? / What belongs on the HPS and what belongs in the FPGA?

**VI — Trả lời:** HPS phụ trách Linux, đọc file input, nạp SDRAM, map bridge bằng `/dev/mem`, điều khiển pixel DMA và giám sát hệ thống. FPGA phụ trách datapath pixel, LUT, streaming, clock crossings và VGA/video IP. Đây là partition theo control/memory management trên HPS và deterministic data-plane trên FPGA.

**EN — Answer:** The HPS runs Linux, reads the input file, loads SDRAM, maps the bridges through `/dev/mem`, controls the pixel DMA, and supervises the system. The FPGA implements the pixel datapath, LUTs, streaming, clock crossings, and video/VGA IP. This is a control/memory-management versus deterministic data-plane partition.

## Q50 — HPS program nạp ảnh như thế nào? / How does the HPS program load an image?

**VI — Trả lời:** Utility mở `/dev/mem`, mmap HPS-to-FPGA và lightweight bridge, trỏ vào SDRAM và DMA control registers, sau đó đọc từng token RGB24 từ HEX file vào SDRAM. Code dùng row stride `1,024` word thông qua `(y<<10)+x`, dù ảnh chỉ rộng 640 pixel, giúp alignment và address generation đơn giản. Cuối cùng utility bật DMA và giữ process chạy để hệ thống hiển thị.

**EN — Answer:** The utility opens `/dev/mem`, maps the HPS-to-FPGA and lightweight bridge regions, obtains pointers to SDRAM and DMA control registers, and reads RGB24 HEX tokens into SDRAM. It uses a 1,024-word row stride through `(y<<10)+x` even though the visible image is 640 pixels wide, simplifying alignment and address generation. It then enables DMA and remains running while the display operates.

## Q51 — Vì sao dùng `/dev/mem`? Có production-ready không? / Why use `/dev/mem`, and is it production-ready?

**VI — Trả lời:** `/dev/mem` là cách nhanh để prototype và chứng minh memory map mà không phải viết kernel driver. Tuy nhiên nó thiếu abstraction, permission model và error handling của production driver; cần kiểm tra mmap, file parsing, DMA stop/quiesce, cache coherency và signal handling kỹ hơn. Vì vậy tôi gọi đây là lab/demo utility, không phải driver production hoàn chỉnh.

**EN — Answer:** `/dev/mem` is a fast way to prototype and validate a memory map without writing a kernel driver. It lacks the abstraction, permission model, and robustness of a production driver; mmap, file parsing, DMA stop/quiesce, cache coherency, and signal handling need stronger treatment. I would describe it as a lab/demo utility, not a finished production driver.

## Q52 — SDRAM và FPGA bridge có bottleneck không? / Can SDRAM or the bridge become a bottleneck?

**VI — Trả lời:** Có thể. Core one pixel/clock chỉ nói về compute datapath; end-to-end throughput còn phụ thuộc SDRAM bursts, DMA, arbitration, clock conversion, FIFO depth và display timing. Với 640×480 RGB ở 30 fps, payload active khoảng 27.65 MB/s cho một chiều RGB24, chưa tính overhead và các chiều đọc/ghi; thiết kế phải kiểm tra burst efficiency và worst-case contention thay vì suy ra từ Fmax.

**EN — Answer:** Yes. One pixel per clock describes only the compute datapath; end-to-end throughput also depends on SDRAM bursts, DMA, arbitration, clock conversion, FIFO depth, and display timing. For 640×480 RGB24 at 30 fps, the active-pixel payload is roughly 27.65 MB/s in one direction before overhead and any additional reads/writes. Burst efficiency and worst-case contention must be measured rather than inferred from Fmax.

## Q53 — Camera path hiện ở trạng thái nào? / What is the current status of the camera path?

**VI — Trả lời:** Platform sources có video-input subsystem và clock khoảng 27 MHz trong architecture report. Tuy nhiên README/verification record phân biệt rõ: still-image board path đã được báo cáo, còn continuous camera-to-display cần thêm integration evidence. Câu trả lời đúng là “camera path is present in the architecture and is a next validation target,” không phải “camera streaming đã được chứng minh hoàn chỉnh.”

**EN — Answer:** The Platform Designer sources include a video-input subsystem and the architecture report describes an approximately 27 MHz input domain. However, the README and verification record distinguish the reported still-image board path from a continuous camera-to-display path that still needs integration evidence. The correct answer is that the camera path exists architecturally and is a next validation target, not that it has already been fully demonstrated.

## Q54 — VGA path ảnh hưởng kết quả thế nào? / How does the VGA path affect results?

**VI — Trả lời:** VGA có clock khoảng 25 MHz, pixel DMA/display FIFO và timing riêng. Output từ core có thể nhanh hơn display; FIFO/clock crossing phải hấp thụ chênh lệch và không overflow/underflow. Vì vậy frame time 3.07/6.14 ms của core là active-pixel compute time, không phải toàn bộ camera-to-screen latency.

**EN — Answer:** VGA uses an approximately 25 MHz domain with its own pixel DMA/display FIFO and timing. The core can produce pixels faster than the display consumes them, so FIFOs and clock crossings must absorb the rate difference without overflow or underflow. Therefore the 3.07/6.14 ms core frame figures are active-pixel compute times, not complete camera-to-screen latency.

## Q55 — Vì sao không để HPS xử lý toàn bộ ảnh? / Why not process the whole image on the HPS?

**VI — Trả lời:** HPS có thể chạy reference hoặc low-rate control, nhưng per-pixel dehazing gồm nhiều phép toán và LUT lookup liên tục. FPGA cho throughput xác định và không chiếm CPU trong từng pixel. Ngược lại, HPS dễ debug và thay thuật toán hơn; kiến trúc hiện tại dùng HPS cho control/load và FPGA cho data-plane để cân bằng hai yêu cầu.

**EN — Answer:** The HPS can run a reference or low-rate control path, but per-pixel enhancement involves many operations and continuous table lookups. The FPGA provides deterministic throughput without consuming the CPU for every pixel. The HPS is easier to modify and debug, so the design uses the HPS for control/loading and the FPGA for the streaming data plane.

## Q56 — Quy trình deploy an toàn cần gì? / What is required for a safe deployment flow?

**VI — Trả lời:** Bitstream và C/header phải cùng memory-map contract. Cần kiểm tra source commit, compile native trên board, hash bitstream sau SCP, dừng process/DMA cũ trước khi thay `.rbf`, load FPGA rồi mới chạy application, và lưu log/manifest. Không nên thay `.rbf` khi DMA còn active vì có thể tạo trạng thái không xác định.

**EN — Answer:** The bitstream and C/header files must share the same memory-map contract. A safe flow checks the source commit, compiles natively on the board, verifies the bitstream hash after transfer, quiesces the old process/DMA before replacement, loads the FPGA, and then starts the application while preserving logs and manifests. Replacing an `.rbf` while DMA is active can create an undefined state.

## Q57 — Nếu người phỏng vấn hỏi “board demo có phải live video không?” / If asked whether the board demo is live video, what do you say?

**VI — Trả lời:** Tôi sẽ nói rõ: “The submitted demonstration is a still-image SDRAM-to-VGA path. It proves board integration of the image path, not a complete continuously captured camera pipeline.” Nếu có video ghi lại board, video đó chỉ là qualitative evidence; không tự chứng minh FPS, latency, no-drop hoặc current-commit reproducibility.

**EN — Answer:** I would say: “The submitted demonstration is a still-image SDRAM-to-VGA path. It demonstrates board integration of the image path, not a complete continuously captured camera pipeline.” A board video is qualitative evidence; by itself it does not prove FPS, latency, no dropped frames, or reproducibility from the current commit.

---

# 7. Timing, throughput, resource và power / Performance and implementation questions

## Q58 — 6.14 ms/frame ở 50 MHz được tính như thế nào? / How is 6.14 ms/frame at 50 MHz calculated?

**VI — Trả lời:** Ảnh có `640×480=307,200` active pixels. Với one pixel per clock ở 50 MHz, thời gian active-pixel là `307,200 / 50,000,000 ≈ 6.144 ms`. Ở 100 MHz là khoảng 3.072 ms. Các con số này loại trừ blanking, stalls, camera capture, SDRAM arbitration và display latency.

**EN — Answer:** The image has `640×480=307,200` active pixels. At one pixel per clock and 50 MHz, the active-pixel time is `307,200/50,000,000 ≈ 6.144 ms`. At 100 MHz it is about 3.072 ms. These numbers exclude blanking, stalls, camera capture, SDRAM arbitration, and display latency.

## Q59 — Core có đủ cho 30 fps không? / Is the core fast enough for 30 fps?

**VI — Trả lời:** Về compute capacity lý thuyết, có. 30 fps cho 640×480 cần khoảng 9.216 million active pixels/s; 50 MHz one-pixel-per-clock cung cấp 50 million pixel transfers/s trước khi tính stall, nên có headroom. Nhưng câu trả lời end-to-end phải đo camera/display clocks, blanking, FIFO, DMA và frame drops. Vì vậy “core is capable” đúng hơn “entire system is proven at 30 fps.”

**EN — Answer:** At the compute-capacity level, yes. 30 fps at 640×480 requires about 9.216 million active pixels per second, while a 50 MHz one-pixel-per-clock core offers 50 million transfers per second before stalls. End-to-end proof still requires measuring camera/display timing, blanking, FIFO behavior, DMA, and dropped frames. Therefore “the core is capable” is safer than “the entire system has been proven at 30 fps.”

## Q60 — Vì sao demo 50 MHz nhưng paper nói timing 100 MHz? / Why 50 MHz in the demo but 100 MHz in the paper?

**VI — Trả lời:** 50 MHz là clock vận hành của still-image board demonstration được ghi nhận. 100 MHz là target/closed timing của một post-fit implementation record, cho biết core có margin theo báo cáo. Hai con số không mâu thuẫn nếu nói rõ chúng thuộc hai context; không được dùng kết quả 100 MHz để ngụ ý board demo đã chạy continuous 100 MHz nếu chưa có log/bitstream tương ứng.

**EN — Answer:** 50 MHz is the clock recorded for the still-image board demonstration. 100 MHz is the target/closed timing of a reported post-fit implementation record. They are not contradictory when their contexts are stated. The 100 MHz result must not be presented as proof that the physical board demonstration ran continuously at 100 MHz unless the matching log and bitstream are available.

## Q61 — Restricted Fmax 121.64 MHz nghĩa là gì? / What does a restricted Fmax of 121.64 MHz mean?

**VI — Trả lời:** Đây là tần số tối đa theo path/constraint được Quartus báo cáo ở slow 85 °C corner của post-fit build. Nó không đồng nghĩa với FPS end-to-end và không tự động chứng minh mọi clock domain đều closure. Cần kiểm tra clock definitions, false/multicycle paths, unconstrained-path warnings và worst setup/hold slack. Repository audit cũng ghi nhận current evidence chưa đủ để gắn historical Fmax với current checkout.

**EN — Answer:** It is the maximum frequency reported for the constrained path in a post-fit build at the slow 85 °C corner. It is not the same as end-to-end FPS and does not by itself prove that every clock domain is closed. Clock definitions, false/multicycle paths, unconstrained warnings, and worst setup/hold slack must be reviewed. The repository audit also separates this historical Fmax from the current checkout.

## Q62 — 20% ALM có phải chỉ core không? / Does 20% ALM refer only to the core?

**VI — Trả lời:** Không. Số `6,279/32,070 ALMs = 20%` là complete-system post-fit result, gồm dehazing core, HPS interfaces, video input, VGA và IP liên quan. Core-only utilization phải trích riêng từ synthesis hierarchy hoặc report. Khi so sánh với một paper khác, phải cùng định nghĩa scope.

**EN — Answer:** No. The `6,279/32,070 ALMs = 20%` figure is a complete-system post-fit result including the dehazing core, HPS interfaces, video input, VGA, and related IP. Core-only utilization must come from a hierarchical synthesis report. Comparisons with other papers are meaningful only when the scope is defined consistently.

## Q63 — Tại sao core có 3 DSP nhưng system có 8 DSP? / Why three DSPs in the core but eight in the system?

**VI — Trả lời:** Core restoration cần ba signed multipliers, tương ứng R/G/B. Các DSP còn lại thuộc video conversion, đặc biệt YCrCb-to-RGB hoặc IP liên quan. Vì vậy phải phân biệt “proposed core uses 3 DSPs” với “complete design uses 8 DSPs.”

**EN — Answer:** The restoration stage uses three signed multipliers, one per RGB channel. The remaining DSPs belong to video conversion or related IP, including the YCrCb-to-RGB path. Therefore “the proposed core uses 3 DSPs” and “the complete design uses 8 DSPs” are both correct but refer to different scopes.

## Q64 — Power 824.12 mW có phải đo thực tế không? / Is 824.12 mW a physical measurement?

**VI — Trả lời:** Không. Đây là Quartus Power Analyzer estimate: vectorless, toggle rate 12.5%, HPS off, gồm static, core dynamic và I/O components. Nó không phải wall-plug measurement của board, không bao gồm đầy đủ DDR3/regulator/USB/display. Câu trả lời đúng là “estimated on-chip FPGA power”; muốn claim system power cần đo bằng instrument dưới workload xác định.

**EN — Answer:** No. It is a Quartus Power Analyzer estimate using vectorless activity, a 12.5% toggle assumption, and HPS off, with static, core dynamic, and I/O components. It is not a wall-plug board measurement and does not fully include DDR3, regulators, USB, or display power. The correct wording is “estimated on-chip FPGA power”; a system-power claim requires instrumented measurement under a defined workload.

## Q65 — So sánh với Lee et al. có công bằng không? / Is the comparison with Lee et al. fair?

**VI — Trả lời:** Chỉ có giá trị tham khảo, không phải apples-to-apples benchmark. Paper đối chiếu device class khác, resolution khác, architecture khác và scope resource khác. Tôi sẽ dùng comparison để chỉ ra design point, không kết luận rằng project tốt hơn tuyệt đối. Benchmark công bằng cần cùng input, resolution, quality metric, clock/power methodology và end-to-end definition.

**EN — Answer:** It is contextual, not an apples-to-apples benchmark. The compared work uses a different device class, resolution, architecture, and resource scope. I would use the table to position the design point, not to claim absolute superiority. A fair benchmark requires the same input, resolution, quality metric, clock/power methodology, and end-to-end definition.

## Q66 — Nếu tăng lên 1080p hoặc 4K thì vấn đề gì xảy ra? / What changes for 1080p or 4K?

**VI — Trả lời:** Với pointwise core, số pixel tăng nên compute time tăng tuyến tính nếu giữ một pixel/clock; LUT size không đổi nếu input vẫn 8-bit. Bottleneck sẽ chuyển sang memory bandwidth, DMA, camera/display clocks, FIFO depth và board I/O. 4K còn có thể đòi hỏi nhiều pixels/clock hoặc clock cao hơn. Vì vậy “resolution-invariant transfer function” không đồng nghĩa “same end-to-end throughput.”

**EN — Answer:** For a pointwise core, pixel count increases linearly with processing time at one pixel per clock; LUT size stays the same if the input remains 8-bit. The bottleneck shifts toward memory bandwidth, DMA, camera/display clocks, FIFO depth, and board I/O. 4K may require multiple pixels per clock or a higher clock. A resolution-invariant transfer function is not the same as resolution-invariant end-to-end throughput.

## Q67 — Critical path có thể nằm ở đâu? / Where is the likely critical path?

**VI — Trả lời:** Các ứng viên là ROM read/addressing, signed multiplier/add/shift, wide comparator, routing giữa các M10K/DSP và clock-crossing interface. Pipeline đã tách lookup và arithmetic để đạt 100 MHz theo historical report. Muốn tối ưu tiếp, cần xem actual STA path, không nên đoán chỉ từ số DSP; có thể thêm register, đổi ROM style, giảm fan-out hoặc floorplan.

**EN — Answer:** Candidates include ROM read/addressing, signed multiply/add/shift, wide comparator logic, routing between M10K and DSP resources, and clock-crossing interfaces. The pipeline separates lookup and arithmetic to meet the reported 100 MHz target. Further optimization should be driven by the actual STA path: extra registers, a different ROM style, lower fan-out, or placement changes may help.

---

# 8. Verification và image-quality evaluation / Verification and image-quality questions

## Q68 — Bạn đã verify những gì? / What exactly did you verify?

**VI — Trả lời:** Reported verification có MATLAB fixed-point reference, ModelSim streaming cùng frame 640×480 qua Avalon-ST và so sánh pixel-by-pixel, cho 0 LSB output error. Ngoài ra có quantization error checks và resource/timing records. Tuy nhiên current CI chủ yếu kiểm tra source/tooling; không nên nhầm với full RTL simulation, synthesis reproduction hoặc board regression.

**EN — Answer:** The reported verification includes a MATLAB fixed-point reference, ModelSim streaming of the same 640×480 frame through Avalon-ST, and pixel-by-pixel comparison with 0-LSB output error. There are also quantization-error checks and resource/timing records. However, current CI primarily covers source/tooling checks; it should not be confused with a complete RTL simulation, synthesis reproduction, or board regression.

## Q69 — Metric visible-edge được tính thế nào? / How is the visible-edge metric computed?

**VI — Trả lời:** Dùng Sobel gradient magnitude; pixel được coi là visible edge nếu magnitude vượt `0.05`. Gọi `n_O` là số cạnh ở ảnh gốc và `n_P` ở ảnh processed, edge gain là

\[
e=(n_P-n_O)/n_O.
\]

Ngoài ra paper báo cáo mean gradient magnitude và tỷ lệ pixel pure black/white để theo dõi clipping/saturation.

**EN — Answer:** A Sobel gradient magnitude is computed, and a pixel is counted as a visible edge when the magnitude exceeds `0.05`. If `n_O` is the original edge count and `n_P` is the processed count,

\[
e=(n_P-n_O)/n_O.
\]

The paper also reports mean gradient magnitude and the fraction of pure-black or pure-white pixels to monitor clipping/saturation.

## Q70 — Kết quả bốn scene cụ thể là gì? / What are the four scene results?

**VI — Trả lời:** Số visible edges tăng lần lượt: Scene 1 `112,372→158,247` (+40.8%), Scene 2 `108,873→116,038` (+6.6%), Scene 3 `181,015→232,677` (+28.5%), Scene 4 `104,520→154,954` (+48.3%). Mean gradient cũng tăng từ `0.0645→0.1112`, `0.0592→0.0781`, `0.1364→0.3190`, `0.0621→0.1125`. Saturated output fraction được báo cáo ở mức 0.01–0.05%.

**EN — Answer:** Visible edges increase as follows: Scene 1 `112,372→158,247` (+40.8%), Scene 2 `108,873→116,038` (+6.6%), Scene 3 `181,015→232,677` (+28.5%), and Scene 4 `104,520→154,954` (+48.3%). Mean gradient increases from `0.0645→0.1112`, `0.0592→0.0781`, `0.1364→0.3190`, and `0.0621→0.1125`. Reported saturated output fractions are 0.01–0.05%.

## Q71 — Edge gain có chứng minh ảnh tốt hơn không? / Does edge gain prove better image quality?

**VI — Trả lời:** Không. Edge gain chỉ cho biết nhiều gradient vượt ngưỡng hơn; nó có thể tăng do ringing, noise hoặc over-sharpening. Vì vậy phải đọc cùng mean gradient, clipping, visual inspection và ideally PSNR/SSIM với ground truth. Project có preliminary synthetic proxy comparison, nhưng không nên biến nó thành bằng chứng đầy đủ cho mọi cảnh tự nhiên.

**EN — Answer:** No. Edge gain only says that more gradients crossed a threshold; it can also increase due to ringing, noise, or over-sharpening. It should be interpreted with mean gradient, clipping, visual inspection, and ideally PSNR/SSIM against ground truth. The project includes a preliminary synthetic-proxy comparison, but that is not sufficient evidence for all natural scenes.

## Q72 — Vì sao không dùng PSNR/SSIM cho toàn bộ evaluation? / Why not use PSNR/SSIM for all evaluation?

**VI — Trả lời:** Real hazy scenes thường không có clean reference đồng thời với cùng camera/viewpoint, nên PSNR/SSIM không luôn khả dụng. Blind visible-edge assessment cho phép đánh giá tương đối trên ảnh thực nhưng không đo đầy đủ fidelity hoặc color accuracy. Evaluation tốt hơn sẽ dùng dataset có paired ground truth, object-detection/tracking downstream metric, user study và no-reference perceptual metric.

**EN — Answer:** Real hazy scenes often lack a clean reference captured from the same viewpoint and camera, so PSNR/SSIM is not always available. Blind visible-edge assessment enables relative evaluation on real images but does not fully measure fidelity or color accuracy. A stronger evaluation would combine paired-ground-truth datasets, downstream detection/tracking metrics, user studies, and no-reference perceptual measures.

## Q73 — Tại sao abstract nói ba scene nhưng table/poster có bốn? / Why does the abstract say three scenes while the table/poster show four?

**VI — Trả lời:** Đây là editorial inconsistency phải chủ động sửa hoặc giải thích. Table 1 và poster trình bày bốn scene; con số range 6.6–48.3% cũng đến từ bốn scene. Khi thuyết trình, tôi sẽ nói rõ “four scenes in Table 1” và thừa nhận abstract cần chỉnh thành four nếu đó là bản final được dùng.

**EN — Answer:** This is an editorial inconsistency that should be corrected or explicitly acknowledged. Table 1 and the poster show four scenes, and the 6.6–48.3% range comes from those four scenes. In a presentation I would say “four scenes in Table 1” and acknowledge that the abstract should be corrected to four if that is the final evidence set.

## Q74 — Baseline guided-filter khác với proposed metric thế nào? / How does the guided-filter baseline differ from the proposed metric?

**VI — Trả lời:** Paper ghi rõ cột `e (base/prop.)` là preliminary independent reimplementation, baseline chưa tune và không phải cùng pipeline tạo ra các số `n`, mean gradient ở các cột trước. Do đó không được trộn `+40.8%` của proposed visible-edge table với `+30.2` hoặc `+38.0` của preliminary baseline column như cùng một phép đo. Đây là một điểm reviewer rất dễ hỏi.

**EN — Answer:** The paper explicitly states that the `e (base/prop.)` column comes from a preliminary independent reimplementation, with an untuned baseline, and not from the same pipeline that generated the preceding `n` and mean-gradient columns. Therefore the proposed visible-edge gains such as +40.8% must not be mixed with baseline-column values such as +30.2 or +38.0 as if they were the same measurement.

## Q75 — Board result và ModelSim result khác nhau thế nào? / How do board and ModelSim results differ?

**VI — Trả lời:** ModelSim cho biết RTL transfer function và protocol với stimulus cụ thể. Board demo cho biết integration vật lý của một path, nhưng hình quay màn hình có thể bị ảnh hưởng bởi camera exposure, display, cable và scaling. Board result cần gắn với source commit, `.sof/.rbf` checksum, clock, input checksum, switch setting và capture method nếu muốn dùng như evidence định lượng.

**EN — Answer:** ModelSim validates the RTL transfer function and protocol for a defined stimulus. A board demonstration validates physical integration of a path, but a filmed display is affected by camera exposure, display behavior, cabling, and scaling. Quantitative board evidence should be tied to a source commit, `.sof/.rbf` checksum, clock, input checksum, switch settings, and capture method.

## Q76 — Test plan mạnh hơn cần có gì? / What would a stronger test plan contain?

**VI — Trả lời:** Cần test directed vectors cho black/white/gray, channel ties, `Cmax=0`, `t` tại floor, signed negative `I-A`, clipping và gamma endpoints; random pixel/reference tests; full-frame bit-exact; random backpressure; reset giữa frame; SOP/EOP; FIFO overflow/underflow; CDC; nhiều scene/illumination; và board loop với frame counter/no-drop monitor. Mỗi test cần lưu input, expected output, tool version, seed và checksum.

**EN — Answer:** The plan should include directed vectors for black/white/gray pixels, channel ties, `Cmax=0`, transmission at the floor, signed negative `I-A`, clipping, and gamma endpoints; random reference tests; full-frame bit-exact comparison; random backpressure; reset between frames; SOP/EOP; FIFO overflow/underflow; CDC; varied scenes and illumination; and a board loop with frame counters and a no-drop monitor. Every test should preserve input, expected output, tool version, seed, and checksum.

## Q77 — Reproducibility checklist trước khi công bố là gì? / What is the reproducibility checklist before publication?

**VI — Trả lời:** Cần pin commit, Quartus version, device revision, Qsys/IP versions, pin/SDC, LUT generator and checksums, input images, testbench, expected HEX/BMP, synthesis/STA/power reports, final bitstream checksum, board clock/switch settings, HPS image/toolchain và exact run commands. Nếu một số trường chưa có, ghi `NOT_RUN` hoặc `NOT_REPRODUCED`, không điền số ước lượng.

**EN — Answer:** Pin the source commit, Quartus version, device revision, Qsys/IP versions, pin/SDC files, LUT generator and checksums, input images, testbench, expected HEX/BMP outputs, synthesis/STA/power reports, final bitstream checksum, board clock/switch settings, HPS image/toolchain, and exact run commands. If an item is missing, mark it `NOT_RUN` or `NOT_REPRODUCED` rather than filling in an estimate.

---

# 9. Câu hỏi phản biện khó / Difficult reviewer objections

## Q78 — “Đây không phải DCP thật.” Bạn trả lời thế nào? / “This is not real DCP.” How do you respond?

**VI — Trả lời:** Tôi đồng ý một phần với cách phân loại đó. Classical DCP dùng patch statistics; khi `Ω=1×1`, spatial prior biến mất. Vì vậy cách gọi chính xác là DCP-inspired per-pixel estimator based on min-channel and scattering inversion. Điểm đóng góp của project là thiết kế estimator/hardware phù hợp embedded streaming, không phải tuyên bố tái tạo toàn bộ classical DCP.

**EN — Answer:** I would agree with the qualification. Classical DCP uses patch statistics, while `Ω=1×1` removes the spatial prior. Therefore the precise description is a DCP-inspired per-pixel estimator based on min-channel information and scattering inversion. The contribution is an embedded streaming estimator/hardware design, not a claim to reproduce all of classical DCP.

## Q79 — “Không có refinement thì halo đã thực sự bị loại bỏ chưa?” / “Without refinement, are halos really removed?”

**VI — Trả lời:** Không nên nói “removed in all cases.” Cửa sổ 1×1 loại bỏ nguồn halo do spatial min window tại boundary, còn `K(S,V)` điều chế chromatic sensitivity để giảm collapse của transmission. Điều đó có thể suppress một class of halos, nhưng không chứng minh mọi artifact biến mất; cần đánh giá edge-localized artifact với baseline guided filter trên nhiều cảnh.

**EN — Answer:** I would not say “removed in all cases.” The 1×1 choice removes the source of boundary halos caused by spatial min windows, while `K(S,V)` reduces chromatic over-response. This can suppress a class of halos, but it does not prove that every artifact disappears. Edge-localized artifact evaluation against a guided-filter baseline is still needed.

## Q80 — “K là empirical, vậy khoa học ở đâu?” / “If K is empirical, where is the scientific contribution?”

**VI — Trả lời:** Empirical design không đồng nghĩa không khoa học, nhưng phải báo cáo rõ parameter search, dataset, objective và sensitivity. Contribution ở đây là hypothesis rằng saturation/value modulation có thể giảm transmission over-estimation trong một architecture không có spatial refinement, sau đó được kiểm tra bằng fixed-point experiments và hardware mapping. Để mạnh hơn, cần ablation `K=1`, sweep exponent, cross-dataset evaluation và statistical confidence.

**EN — Answer:** An empirical design is not automatically unscientific, but the search procedure, data, objective, and sensitivity must be explicit. The hypothesis is that saturation/value modulation can reduce transmission over-response in an architecture without spatial refinement; the project then evaluates that hypothesis and maps it to hardware. Stronger evidence would include a `K=1` ablation, exponent sweeps, cross-dataset testing, and statistical confidence intervals.

## Q81 — “Scalar A sẽ làm sai màu.” / “A scalar will distort color.”

**VI — Trả lời:** Đây là limitation hợp lý. Scalar `A` giảm resource và hợp với visibility enhancement, nhưng không biểu diễn atmospheric color đầy đủ. Tôi sẽ đề xuất phiên bản tiếp theo dùng vector `A_R,A_G,A_B`, hoặc estimate color ratio chậm hơn trên HPS/frame-level, sau đó truyền ba giá trị vào core. Cải tiến đó phải đánh đổi thêm registers, multipliers, bandwidth và validation.

**EN — Answer:** That is a valid limitation. Scalar `A` reduces resources and suits a compact visibility enhancer, but it does not represent atmospheric color completely. A next version could estimate `A_R,A_G,A_B`, or estimate color ratios at frame level on the HPS and pass three values to the core. The cost in registers, arithmetic, bandwidth, and validation would need to be measured.

## Q82 — “One-frame lag không chấp nhận được trong video.” / “A one-frame lag is unacceptable for video.”

**VI — Trả lời:** Một frame lag ở steady state thường nhỏ so với frame period, nhưng adaptation sau scene cut có thể chậm khoảng 1.55 s ở 30 fps theo mô hình báo cáo. Vì vậy tôi không phủ nhận objection. Các giải pháp là scene-change detector, reset/accelerate EMA khi histogram thay đổi, dual-time-constant filter hoặc frame-buffered two-pass estimate. Bản hiện tại ưu tiên hardware simplicity.

**EN — Answer:** One-frame lag may be small relative to the frame period in steady state, but the reported adaptation after a scene cut can take about 1.55 s at 30 fps. I would not dismiss the objection. Possible fixes include scene-change detection, EMA acceleration when the histogram changes, a dual-time-constant filter, or a frame-buffered two-pass estimate. The current design prioritizes hardware simplicity.

## Q83 — “Edge gain chỉ là artifact.” / “The edge gain may just be an artifact.”

**VI — Trả lời:** Đúng, edge count đơn lẻ không đủ. Cần kiểm tra noise amplification, halo/ringing, color error, local contrast, saturated pixels và downstream detection accuracy. Tôi sẽ trình bày edge gain như một no-reference indicator, không phải proof of perceptual superiority. Ground-truth paired data hoặc task-level metrics là bước xác nhận tiếp theo.

**EN — Answer:** That is possible; edge count alone is insufficient. We need to inspect noise amplification, halos/ringing, color error, local contrast, saturated pixels, and downstream detection accuracy. I present edge gain as a no-reference indicator, not proof of perceptual superiority. Paired ground-truth data or task-level metrics are the next validation step.

## Q84 — “Paper và repo không cùng một implementation.” / “The paper and repository may not be the same implementation.”

**VI — Trả lời:** Tôi sẽ không phủ nhận nếu chưa có manifest chứng minh. Historical post-fit numbers và current source snapshot phải được liên kết bằng commit, input hashes, tool version và bitstream checksum. Nếu chưa liên kết được, tôi gọi đó là reported historical result, không phải reproduced current result. Đây là cách bảo vệ tính trung thực và cũng là việc cần hoàn thiện của project.

**EN — Answer:** I would not deny that without a matching manifest. Historical post-fit numbers and the current source snapshot must be linked by commit, input hashes, tool version, and bitstream checksum. Until that link is established, I describe the values as reported historical results rather than reproduced current results. That is the honest and technically useful position.

## Q85 — “Current checkout không compile.” / “The current checkout does not compile.”

**VI — Trả lời:** Nếu kiểm tra cho thấy lỗi, tôi sẽ tách ba lớp: source artifact hiện tại, generated artifact cũ và result đã báo cáo trong paper. Archived RTL có token `beginS` cần sửa/đối chiếu; current active source boundary cũng cần làm rõ. Tôi không dùng một `.sof` cũ để chứng minh source hiện tại compile. Bước sửa đúng là tạo clean build từ canonical inputs và lưu log.

**EN — Answer:** If the check confirms a failure, I would separate three layers: the current authored source, older generated artifacts, and the result reported in the paper. The archived RTL contains an apparent `beginS` token that must be corrected or reconciled, and the active source boundary must be clarified. I would not use an old `.sof` to prove that the current source compiles. The proper fix is a clean build from canonical inputs with preserved logs.

## Q86 — “100 MHz timing closure nhưng source có unconstrained warning?” / “How can you claim 100 MHz closure with unconstrained warnings?”

**VI — Trả lời:** Hai điều có thể cùng xuất hiện nếu một report ghi closure cho các path được constraint nhưng toàn design còn warning. Cần kiểm tra SDC coverage, clock groups, false paths, generated clocks và unconstrained endpoints. Tôi sẽ nói “the submitted post-fit report reported closure under its constraints,” không nói “the entire current design is fully timing-proven” cho đến khi warning được giải quyết.

**EN — Answer:** Both can occur if a report closes timing for constrained paths while the design still contains warnings. SDC coverage, clock groups, false paths, generated clocks, and unconstrained endpoints must be reviewed. I would say “the submitted post-fit report reported closure under its constraints,” not “the entire current design is fully timing-proven,” until the warnings are resolved.

## Q87 — “Power estimate quá thấp vì HPS off.” / “The power estimate is low because HPS is off.”

**VI — Trả lời:** Đúng, đó là lý do phải ghi rõ scope. `824.12 mW` là FPGA on-chip estimate với HPS off và vectorless activity; không phải total board power khi HPS, DDR3, camera và VGA hoạt động. Muốn đưa ra con số hệ thống, cần current/voltage measurement tại workload thực và tách idle, HPS-only, FPGA-only và full-pipeline cases.

**EN — Answer:** That is why the scope must be explicit. `824.12 mW` is an on-chip FPGA estimate with HPS off and vectorless activity; it is not total board power with HPS, DDR3, camera, and VGA active. A system-level number requires current/voltage measurement under the actual workload, separating idle, HPS-only, FPGA-only, and full-pipeline cases.

## Q88 — “Tại sao không dùng CNN?” / “Why not use a CNN?”

**VI — Trả lời:** CNN có thể học prior mạnh hơn và tốt hơn trên nhiều domain, nhưng cần model memory, MAC arrays, quantization/training data và thường khó giải thích hơn. Project chọn thuật toán deterministic, LUT-friendly để nghiên cứu cost-constrained embedded pipeline trên Cyclone V. Đây là design-point decision, không phải tuyên bố CNN kém hơn về chất lượng.

**EN — Answer:** A CNN can learn a stronger prior and may achieve better quality across domains, but it requires model memory, MAC arrays, training data, and more complex quantization and verification. This project chooses a deterministic, LUT-friendly algorithm for a cost-constrained Cyclone V pipeline. That is a design-point decision, not a claim that CNNs are inferior in image quality.

## Q89 — “Kết quả bốn cảnh quá ít để kết luận.” / “Four scenes are too few for a conclusion.”

**VI — Trả lời:** Tôi đồng ý rằng bốn scene chỉ đủ cho preliminary demonstration, không đủ để khẳng định generalization. Kết luận nên giới hạn ở việc “the tested scenes showed…” thay vì “the method always improves…”. Evaluation tiếp theo cần dataset đa dạng hơn, nhiều haze density, illumination, color temperature, sensor noise và paired/no-reference metrics.

**EN — Answer:** I agree that four scenes are enough only for a preliminary demonstration, not for a generalization claim. The conclusion should say “the tested scenes showed…” rather than “the method always improves…”. A stronger evaluation needs more haze densities, illumination conditions, color temperatures, sensor noise levels, and paired/no-reference metrics.

## Q90 — Nếu có thêm sáu tháng, bạn sẽ làm gì? / What would you do with six more months?

**VI — Trả lời:** Thứ tự ưu tiên của tôi là: (1) clean reproducible build tied to one commit; (2) fix/verify canonical RTL and timing constraints; (3) maintained Avalon-ST testbench với stall/reset/frame-boundary assertions; (4) camera-to-display integration và frame-drop counter; (5) paired dataset plus ablation/baseline study; (6) measured board power; (7) vector atmospheric light hoặc adaptive scene-change response. Tôi ưu tiên evidence quality trước việc thêm thuật toán phức tạp.

**EN — Answer:** My priority order would be: (1) a clean reproducible build tied to one commit; (2) correction and verification of canonical RTL and timing constraints; (3) a maintained Avalon-ST testbench with stall/reset/frame-boundary assertions; (4) camera-to-display integration with a frame-drop counter; (5) a paired dataset plus ablation and baseline study; (6) measured board power; and (7) vector atmospheric light or faster scene-change response. I would improve evidence quality before adding algorithmic complexity.

---

# 10. Câu hỏi phỏng vấn kỹ sư / Engineering interview questions

## Q91 — Bug khó nhất có thể kể là gì? / What was the hardest bug?

**VI — Trả lời mẫu:** Một bug đáng kể trong loại hệ thống này thường là output hình ảnh lệch hoặc sai màu dù arithmetic nhìn đúng. Tôi sẽ mô tả cách khoanh vùng: kiểm tra RGB packing → valid/ready → delay alignment → LUT address/hex format → signed arithmetic → board DMA. Sau đó dùng một pixel impulse, một frame nhỏ và waveform để chứng minh từng boundary. Câu trả lời phải kể process, không chỉ kể “tôi sửa được”.

**EN — Sample answer:** A representative difficult bug in this class of system is a shifted or incorrectly colored output even though the arithmetic appears correct. I would describe the isolation sequence: RGB packing, valid/ready, delay alignment, LUT address/hex format, signed arithmetic, and board DMA. Then I would use a pixel impulse, a small frame, and waveforms to prove each boundary. The value is the debugging process, not merely saying that the bug was fixed.

## Q92 — Bạn debug hardware/software boundary thế nào? / How do you debug the hardware/software boundary?

**VI — Trả lời:** Tôi chia boundary thành contracts: address map, data format, stride, clock, reset, DMA enable/stop và expected checksum. Mỗi contract có một test độc lập: HPS memory read/write, DMA bypass, core bypass/enhanced switch, known-color bars, frame counter và loopback. Chỉ sau khi từng contract đúng mới ghép toàn hệ thống.

**EN — Answer:** I divide the boundary into contracts: address map, data format, stride, clock, reset, DMA enable/stop, and expected checksum. Each contract gets an independent test: HPS memory read/write, DMA bypass, core bypass/enhanced selection, known-color bars, frame counter, and loopback. Only after those contracts pass do I combine the complete system.

## Q93 — Quyết định trade-off quan trọng nhất là gì? / What was the most important trade-off?

**VI — Trả lời:** Trade-off cốt lõi là bỏ spatial context để đạt compact streaming. Điều đó giảm line buffer, memory traffic và latency, nhưng giảm khả năng xử lý spatially varying haze và có thể ảnh hưởng quality. Các quyết định khác—10-bit transmission, `T_FLOOR=0.1`, scalar `A`, gamma LUT—đều là cách điều chỉnh quality, resource và numerical stability quanh trade-off đó.

**EN — Answer:** The central trade-off is removing spatial context to obtain a compact streaming datapath. This reduces line buffers, memory traffic, and latency, but weakens handling of spatially varying haze and may reduce quality. The 10-bit transmission, `T_FLOOR=0.1`, scalar `A`, and gamma LUT are further trade-offs among quality, resources, and numerical stability.

## Q94 — Nếu không biết câu trả lời trong interview thì nói gì? / What should you say when you do not know?

**VI — Trả lời mẫu:** “Tôi chưa có measurement đủ để kết luận điều đó. Dựa trên architecture, tôi dự đoán …; để xác nhận, tôi sẽ chạy test …, dùng instrument/report … và kiểm tra acceptance criterion …”. Đây là cách trả lời có trách nhiệm. Tránh bịa số FPS, power hoặc timing.

**EN — Sample answer:** “I do not have enough measurement to claim that yet. Based on the architecture, my hypothesis is …; to verify it, I would run …, use … as the instrument/report, and check … as the acceptance criterion.” This is a strong engineering answer. Do not invent FPS, power, or timing numbers.

## Q95 — Nếu thiết kế lại từ đầu, bạn thay đổi gì? / What would you change in a redesign?

**VI — Trả lời:** Tôi sẽ giữ LUT-friendly co-design nhưng làm rõ canonical source, tạo testbench trước, thêm assertions và frame counters, dùng explicit ROM initialization, parameterized RGB/scalar-vector `A`, scene-change detector và measured power. HPS utility sẽ chuyển sang driver/controlled DMA API tốt hơn. Về chất lượng, tôi sẽ benchmark 1×1, guided filter và một lightweight CNN trên cùng dataset.

**EN — Answer:** I would keep the LUT-friendly co-design but establish a canonical source boundary, create the testbench first, add assertions and frame counters, use explicit ROM initialization, parameterize RGB/scalar-vector `A`, add scene-change detection, and measure power. I would also replace the `/dev/mem` demo utility with a more controlled driver/DMA interface. For quality, I would benchmark the 1×1 method, guided filtering, and a lightweight CNN on the same dataset.

## Q96 — Hãy kết luận project trong 60 giây. / Give a 60-second conclusion.

**VI — Trả lời mẫu:**

> Đóng góp của project là một điểm cân bằng giữa chất lượng và chi phí phần cứng. Bằng cách chọn estimator per-pixel và đồng thiết kế với fixed-point LUT, hệ thống loại divider/exponential khỏi datapath, đạt one pixel/clock với 3 DSP trong core và độ trễ báo cáo 11 cycles. HPS đảm nhiệm control/memory, FPGA đảm nhiệm streaming data-plane. Reference và RTL khớp bit-exact trong test được báo cáo; bốn scene cho thấy tăng visible-edge 6.6–48.3%. Tôi cũng phân biệt rõ các giới hạn: 1×1 không phải classical patch DCP, atmospheric-light là scalar và có lag, board evidence chủ yếu là still-image path, còn continuous camera và current-commit reproducibility cần được hoàn thiện.

**EN — Sample answer:**

> The project contributes a practical quality–hardware-cost trade-off. By choosing a per-pixel estimator and co-designing it with fixed-point lookup tables, the implementation removes divider and exponential arithmetic from the datapath, sustains one pixel per clock, uses three DSPs in the proposed core, and has a reported 11-cycle latency. The HPS handles control and memory management while the FPGA handles the streaming data plane. The reported reference/RTL test is bit-exact, and four scenes show 6.6–48.3% more visible edges. I also state the limits clearly: 1×1 is not classical patch-based DCP, atmospheric light is scalar and temporally filtered, the board evidence is primarily a still-image path, and continuous camera validation and current-commit reproducibility remain to be completed.

---

# 11. Flashcard công thức / Formula flashcards

### Scattering model

\[
I=Jt+A(1-t), \qquad t=e^{-\beta d}
\]

### Classical dark channel

\[
J_{dark}(x)=\min_{y\in\Omega(x)}\min_{c\in\{R,G,B\}}I^c(y)
\]

### 1×1 identity

\[
\Omega=1\times1 \Rightarrow J_{dark}=C_{min},
\qquad V=C_{max},
\qquad S=\frac{C_{max}-C_{min}}{C_{max}},
\qquad C_{min}=V(1-S)
\]

### Proposed modulation

\[
K(S,V)=\exp\left(S^4(V+S)^{0.01}\right),
\qquad t'=\exp\left(-\frac{J_{dark}}{K(S,V)}\right)
\]

### Atmospheric light update

\[
A_f=\frac{15A_{f-1}+M_f}{16}
\]

### Transmission floor

\[
t_{use}=\max(t',0.1)
\]

### Radiance recovery

\[
J_{enh}=\frac{I-A}{t_{use}}+A
\]

### Gamma

\[
J_{out}=255\left(\frac{J_{enh}}{255}\right)^{1.4}
\]

### Edge gain

\[
e=\frac{n_P-n_O}{n_O}
\]

### Frame active-pixel time

\[
T_{active}=\frac{640\times480}{f_{pixel}}
\]

- 50 MHz → approximately 6.14 ms.
- 100 MHz → approximately 3.07 ms.

---

# 12. Những câu không nên nói / Statements to avoid

| Không nên nói / Avoid | Nên nói / Better wording |
|---|---|
| “The project proves live 30-fps camera video.” | “The core has sufficient theoretical throughput; continuous camera-to-display still requires end-to-end validation.” |
| “This is exactly the classical DCP algorithm.” | “This is a 1×1 DCP-inspired min-channel/HSV-modulated per-pixel estimator.” |
| “824 mW is the board power.” | “824.12 mW is a Quartus on-chip estimate under the stated vectorless/HPS-off assumptions.” |
| “121.64 MHz proves the whole system runs at 121.64 MHz.” | “The reported restricted Fmax is 121.64 MHz for the stated post-fit timing context.” |
| “20% ALM is the dehazing core only.” | “20% is the reported complete-system utilization; core-only utilization must be separated.” |
| “0 LSB means the board output is always perfect.” | “The reported MATLAB–ModelSim fixed-point test had 0-LSB error for its stimulus and configuration.” |
| “More edges always means better quality.” | “Visible-edge gain is one no-reference indicator and must be interpreted with artifacts and task metrics.” |
| “The current repository definitely reproduces the paper.” | “A matching commit/tool/bitstream manifest is required before claiming reproduction.” |
| “The signed license proves the hardware result.” | “The license is a publication/legal document; technical evidence comes from paper, source, reports, and measurements.” |

---

# 13. Checklist trước buổi phỏng vấn / Before the interview

- [ ] Có thể vẽ block diagram trong 60 giây: HPS → SDRAM/DMA → stream → core → VGA.
- [ ] Giải thích được vì sao 1×1 làm `Cmin` và tại sao điều đó không còn là classical patch DCP.
- [ ] Nhớ phân biệt 50 MHz demonstration và 100 MHz reported timing closure.
- [ ] Nhớ `1 pixel/clock`, `11 cycles`, `640×480`, `T_FLOOR≈0.1`, `γ=1.4`.
- [ ] Nhớ 3 DSP cho core và 8 DSP cho complete system.
- [ ] Nhớ bốn edge gains: 40.8%, 6.6%, 28.5%, 48.3%.
- [ ] Biết nói rõ power là estimate, không phải wall-plug measurement.
- [ ] Biết nói rõ camera path/current-checkout reproducibility là giới hạn.
- [ ] Chuẩn bị một waveform/test vector cho stall, reset, SOP/EOP và signed clipping.
- [ ] Chuẩn bị câu trả lời về source typo `beginS`, generated artifacts và canonical source nếu interviewer hỏi code-level.
- [ ] Không học thuộc số liệu mà không học thuộc **scope và evidence status** của số liệu đó.

---

## Final positioning statement

**VI:** Đây là một project hardware–software co-design có giá trị ở việc biến một estimator dehazing giản lược thành datapath FPGA deterministic, nhỏ gọn và có thể kiểm chứng bằng fixed-point. Điểm mạnh là sự nhất quán giữa mô hình, LUT, RTL và streaming architecture. Điểm cần trung thực là chất lượng chưa đại diện cho mọi loại haze, 1×1 không thay thế hoàn toàn spatial DCP/refinement, và một số bằng chứng hiện vẫn là historical/report-level thay vì reproduction hoàn chỉnh của current checkout.

**EN:** This is a hardware–software co-design project whose value lies in turning a simplified visibility estimator into a deterministic, compact, fixed-point FPGA datapath. Its strengths are the alignment among the model, LUTs, RTL, and streaming architecture. The honest limitations are that quality is not universal across all haze conditions, 1×1 does not fully replace spatial DCP/refinement, and some evidence remains historical/report-level rather than a complete reproduction of the current checkout.
