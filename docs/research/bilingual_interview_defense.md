# Bilingual Interview and Peer-Review Guide

## A Real-Time FPGA-Based Vision Enhancement System

**Project scope:** `C:/Research/fpga-vision-enhancement.partial-20261107`

**Primary sources:**

- **P** — *A Real-Time FPGA-Based Vision Enhancement System*, supplied PDF, 8 pages. Citations use `P p.X, Section/Figure/Table`.
- **S** — *ICEBA 2026 FPGA Poster VI*, supplied PDF, 1 page. Citations use `S p.1, section heading/table/caption`.
- **R** — the maintained source and documentation tree at `C:/Research/fpga-vision-enhancement`.
- **R-partial** — the snapshot named by the project path above. A historical report or manuscript result is not treated as a measurement reproduced by the current checkout.

This guide is designed for a research interview, thesis defense, or constructive peer review. Each item gives an English question, a Vietnamese translation, answer guidance in both languages, and evidence to verify. A proposed experiment is explicitly labelled **proposal**; it is not reported as completed.

**Tiếng Việt:** Tài liệu dùng cho phỏng vấn nghiên cứu, bảo vệ luận văn và phản biện học thuật có tính xây dựng. Mỗi mục có câu hỏi tiếng Anh, bản dịch tiếng Việt, hướng trả lời song ngữ và nguồn kiểm chứng. Thí nghiệm chưa thực hiện được ghi rõ là **đề xuất**, không trình bày như kết quả đã hoàn thành.

## Evidence discipline before the interview

The paper reports a one-pixel-per-clock pipeline, 11-cycle latency, a 100 MHz timing result, bit-exact MATLAB/ModelSim comparison, and a still-image board demonstration (P pp.1, 4–7). The poster states that continuous camera-to-display operation remains unverified and that its 824.12 mW value is a vectorless Quartus estimate with HPS disabled (S p.1, sections 05–06). The current repository documentation identifies the preserved RTL as a candidate archive and says that active-source closure, timing closure, fixed-point equivalence, and board operation are not established from the checkout (R [docs/research/current-snapshot-review.md:5-7,31-33](<C:/Research/fpga-vision-enhancement/docs/research/current-snapshot-review.md:5>); R [docs/development/verification.md:24-33](<C:/Research/fpga-vision-enhancement/docs/development/verification.md:24>)). Keep these evidence layers separate in every answer.

## 1. Research objective, contribution, and scope

### 1. What is the precise research problem?

**EN question:** What problem does the system solve, and what are the input, output, constraints, and success criteria?

**VI translation:** Hệ thống giải quyết chính xác bài toán nào, đầu vào, đầu ra, các ràng buộc và tiêu chí thành công là gì?

**EN answer guidance:** Define the input as an RGB pixel stream or a $640\times480$ still-image path, the output as an enhanced RGB stream, and the constraints as FPGA area, memory, DSP count, clock rate, latency, and image-quality preservation. Separate the algorithmic objective (visibility enhancement) from the implementation objective (streaming fixed-point hardware). The paper frames the platform as an Intel Cyclone V DE1-SoC with HPS/FPGA partitioning (P p.1, Abstract; p.4, Section 3).

**VI hướng dẫn trả lời:** Nêu đầu vào là dòng pixel RGB hoặc đường ảnh tĩnh $640\times480$, đầu ra là dòng RGB đã tăng cường, và các ràng buộc gồm tài nguyên FPGA, bộ nhớ, DSP, tần số, độ trễ và bảo toàn chất lượng ảnh. Tách mục tiêu thuật toán khỏi mục tiêu hiện thực phần cứng. Bài báo đặt hệ thống trên Intel Cyclone V DE1-SoC và phân hoạch HPS/FPGA (P tr.1, Tóm tắt; tr.4, Mục 3).

**Evidence:** P pp.1,4; R-partial [README.md](<C:/Research/fpga-vision-enhancement.partial-20261107/README.md:13>) (project overview and reported-results boundary).

### 2. What is the main contribution, and what is an engineering consequence rather than a scientific contribution?

**EN question:** Which part is the novel method, which part is the hardware realization, and which claims are integration evidence?

**VI translation:** Phần nào là phương pháp mới, phần nào là hiện thực phần cứng, và phần nào chỉ là bằng chứng tích hợp?

**EN answer guidance:** Identify the HSV-modulated transmission function as the method contribution, the $1\times1$ feature-to-LUT mapping and reciprocal/gamma tables as hardware contributions, and the HPS/FPGA streaming pipeline as system integration. Do not present the $1\times1$ identity itself as a new theorem; the paper explicitly calls it an algebraic consequence of the window choice (P p.3, Section 2).

**VI hướng dẫn trả lời:** Xác định hàm truyền sáng điều biến HSV là đóng góp phương pháp, ánh xạ đặc trưng $1\times1$ sang LUT cùng các bảng nghịch đảo/gamma là đóng góp phần cứng, còn pipeline HPS/FPGA là tích hợp hệ thống. Không gọi đồng nhất thức $1\times1$ là định lý mới; bài báo nói rõ đây là hệ quả đại số của việc chọn cửa sổ (P tr.3, Mục 2).

**Evidence:** P pp.2–5; P p.3, paragraph after Eq. (3).

### 3. What does “real-time” mean in this work?

**EN question:** What operational definition of real-time is being used, and which end-to-end stages are included?

**VI translation:** “Thời gian thực” được định nghĩa vận hành như thế nào và những khối nào của đường truyền được tính vào?

**EN answer guidance:** State the measurable claim narrowly: one pixel per core clock and a calculated 3.07 ms/480p frame at 100 MHz or 6.14 ms at 50 MHz under continuous streaming. The paper and poster exclude stalls, blanking, camera latency, and display latency, and the board evidence is a still-image path; therefore continuous camera-to-display real-time operation remains a validation target (P p.1; S p.1, sections 05–06).

**VI hướng dẫn trả lời:** Trình bày hẹp theo số đo được: lõi xử lý một pixel mỗi chu kỳ và thời gian tính toán lý thuyết 3,07 ms/khung ở 100 MHz hoặc 6,14 ms ở 50 MHz khi dòng liên tục. Bài báo và poster loại trừ stall, blanking, độ trễ camera/màn hình; bằng chứng trên bo là đường ảnh tĩnh, nên camera–màn hình liên tục vẫn là mục tiêu kiểm chứng (P tr.1; S tr.1, Mục 05–06).

**Evidence:** P p.1, Abstract; P p.5, Section 3; S p.1, sections 05–06.

### 4. Which claims are historical reported results rather than current-checkout results?

**EN question:** How would you prevent a reviewer from confusing manuscript results with evidence from this repository snapshot?

**VI translation:** Bạn ngăn reviewer nhầm kết quả trong bài báo với bằng chứng từ snapshot hiện tại của repository như thế nào?

**EN answer guidance:** Point to the provenance boundary. The preserved RTL is under `R-partial/hardware/archive/project-inputs/`; the active Quartus project and source closure are not established. State the exact commit, RTL hash, ROM hashes, QSF/SDC, tool build, and reports required before calling a result reproduced. The current review explicitly says historical values remain historical unless tied to those artifacts (R [hardware/README.md:13-17](<C:/Research/fpga-vision-enhancement/hardware/README.md:13>); R [docs/research/current-snapshot-review.md:5-7,29-33](<C:/Research/fpga-vision-enhancement/docs/research/current-snapshot-review.md:5>)).

**VI hướng dẫn trả lời:** Chỉ ra ranh giới nguồn gốc. RTL bảo tồn nằm trong `R-partial/hardware/archive/project-inputs/`; project Quartus hoạt động và source closure chưa được xác lập. Muốn gọi là tái lập phải ghi commit, hash RTL/ROM, QSF/SDC, phiên bản tool và report. Tài liệu hiện tại nói các giá trị lịch sử chỉ có giá trị lịch sử nếu thiếu liên kết đó (R [hardware/README.md:13-17](<C:/Research/fpga-vision-enhancement/hardware/README.md:13>); R [docs/research/current-snapshot-review.md:5-7,29-33](<C:/Research/fpga-vision-enhancement/docs/research/current-snapshot-review.md:5>)).

**Evidence:** R [hardware/README.md:13-17](<C:/Research/fpga-vision-enhancement/hardware/README.md:13>); R [docs/research/current-snapshot-review.md:5-7,29-33](<C:/Research/fpga-vision-enhancement/docs/research/current-snapshot-review.md:5>).

### 5. What is the strongest falsifiable claim?

**EN question:** Which claim could be disproved by a controlled experiment?

**VI translation:** Khẳng định nào có thể bị bác bỏ bằng một thí nghiệm có kiểm soát?

**EN answer guidance:** A suitable claim is that the HSV-modulated $1\times1$ estimator reduces resource cost while maintaining useful enhancement without spatial refinement. Falsify it by comparing a matched classical DCP/guided-filter baseline and a spatial-filter ablation at equal resolution, clock, image set, and quality metrics. Treat the current baseline as preliminary and untuned (P p.6, Table 1 footnote).

**VI hướng dẫn trả lời:** Một khẳng định có thể kiểm chứng là estimator $1\times1$ điều biến HSV giảm tài nguyên nhưng vẫn tăng cường hữu ích mà không cần refinement không gian. Bác bỏ hoặc ủng hộ bằng baseline DCP/guided-filter và ablation bộ lọc không gian với cùng độ phân giải, xung, tập ảnh và chỉ số. Baseline hiện tại chỉ là sơ bộ, chưa tinh chỉnh (P tr.6, chú thích Bảng 1).

**Evidence:** P pp.2–3,6; **proposal:** matched baseline and ablation protocol.

## 2. Physical model and algorithm

### 6. Why is a $1\times1$ dark-channel window defensible?

**EN question:** What is gained and what is lost by replacing the classical spatial prior with a $1\times1$ window?

**VI translation:** Việc thay prior không gian cổ điển bằng cửa sổ $1\times1$ đem lại và làm mất điều gì?

**EN answer guidance:** Explain that the spatial minimum becomes vacuous and the dark channel reduces to the per-pixel channel minimum. This removes line buffers and window-induced halos, but it also removes the patch-level statistical prior of classical DCP. The paper acknowledges that the resulting mapping is motivated by the scattering model rather than being the classical patch prior itself (P p.3, Section 2).

**VI hướng dẫn trả lời:** Giải thích rằng phép min theo không gian trở thành tầm thường và dark channel giảm thành min ba kênh tại từng pixel. Điều này loại bộ đệm dòng và halo do cửa sổ, nhưng cũng loại thông tin thống kê theo vùng của DCP cổ điển. Bài báo thừa nhận mapping mới dựa trên mô hình tán xạ chứ không còn là prior theo patch (P tr.3, Mục 2).

**Evidence:** P p.3, Eq. (3) discussion; R [docs/research/current-snapshot-review.md:11-15](<C:/Research/fpga-vision-enhancement/docs/research/current-snapshot-review.md:11>).

### 7. Can you derive the identity used by the estimator?

**EN question:** Derive $J_{\mathrm{dark}}=C_{\min}=V(1-S)$ for the $1\times1$ case and state the domain assumptions.

**VI translation:** Hãy suy ra $J_{\mathrm{dark}}=C_{\min}=V(1-S)$ trong trường hợp $1\times1$ và nêu các giả định về miền giá trị.

**EN answer guidance:** With $V=C_{\max}$ and $S=(C_{\max}-C_{\min})/C_{\max}$ for $C_{\max}>0$, $V(1-S)=C_{\min}$. Handle the zero-maximum case explicitly because the normalized saturation formula otherwise divides by zero. Explain how the RTL or LUT generator defines black pixels and rounding.

**VI hướng dẫn trả lời:** Với $V=C_{\max}$ và $S=(C_{\max}-C_{\min})/C_{\max}$ khi $C_{\max}>0$, ta có $V(1-S)=C_{\min}$. Phải nêu riêng trường hợp $C_{\max}=0$, vì công thức S chia cho 0. Giải thích RTL hoặc trình sinh LUT xử lý pixel đen và làm tròn thế nào.

**Evidence:** P p.3, paragraph after Eq. (3); **open verification point:** the current review found no generator proving the exact LUT formula (R [docs/research/current-snapshot-review.md:16-19](<C:/Research/fpga-vision-enhancement/docs/research/current-snapshot-review.md:16>)).

### 8. How were the exponents and $\omega$ selected?

**EN question:** What data, search grid, objective, and validation split support exponents 4 and 0.01 and $\omega=1$?

**VI translation:** Dữ liệu, lưới tìm kiếm, hàm mục tiêu và cách tách validation nào hỗ trợ số mũ 4, 0.01 và $\omega=1$?

**EN answer guidance:** The paper says the exponents were chosen empirically and that sweeping exponent 1 from 2 to 6 changed mean $e$ by at most 0.1% (P p.3). Ask for the actual images, randomization, parameter grid, and whether the scenes were reused for selection and reporting. A stronger protocol would reserve validation scenes and report sensitivity to $\omega$, $T_0$, and $T_{\mathrm{floor}}$ (**proposal**).

**VI hướng dẫn trả lời:** Bài báo nói các số mũ được chọn thực nghiệm và quét số mũ thứ nhất từ 2 đến 6 làm thay đổi mean $e$ tối đa 0,1% (P tr.3). Hãy yêu cầu ảnh, cách ngẫu nhiên hóa, lưới tham số và việc có dùng lại cảnh để chọn và báo cáo hay không. Quy trình mạnh hơn là dành riêng validation và báo cáo độ nhạy với $\omega$, $T_0$, $T_{\mathrm{floor}}$ (**đề xuất**).

**Evidence:** P p.3, Eq. (4) paragraph; P p.6, Table 1 scope.

### 9. What is the role of the transmission floor?

**EN question:** Why is $T_{\mathrm{floor}}=102/1023\approx0.1$, and what error or artifact does it bound?

**VI translation:** Vì sao chọn $T_{\mathrm{floor}}=102/1023\approx0.1$, và nó chặn sai số hoặc artifact nào?

**EN answer guidance:** It limits inverse-model noise amplification to approximately $10\times$ in dark regions (P p.4, Eq. (6); p.6). Discuss the tradeoff: a larger floor reduces noise amplification but can under-correct dense haze; a smaller floor can amplify quantization and sensor noise. Show a sweep with saturation rate, edge metrics, and noise amplification (**proposal**).

**VI hướng dẫn trả lời:** Sàn giới hạn khuếch đại nhiễu khi đảo mô hình ở khoảng $10\times$ trong vùng tối (P tr.4, (6); tr.6). Phân tích đánh đổi: sàn lớn giảm khuếch đại nhưng có thể khử sương thiếu; sàn nhỏ tăng khuếch đại nhiễu và lượng tử hóa. Nên quét tham số cùng tỷ lệ bão hòa, chỉ số biên và khuếch đại nhiễu (**đề xuất**).

**Evidence:** P pp.4,6; R-partial [dehazing_system_top.v:360-373](<C:/Research/fpga-vision-enhancement.partial-20261107/hardware/archive/project-inputs/dehazing_system_top.v:360>).

### 10. How is atmospheric light estimated and updated?

**EN question:** Explain the threshold, running maximum, one-frame update, and scene-cut behavior.

**VI translation:** Hãy giải thích ngưỡng, cực đại tích lũy, cập nhật từng khung và hành vi khi chuyển cảnh.

**EN answer guidance:** The paper uses $T_0=220/1023\approx0.215$, accumulates the brightest qualifying pixel, and updates $A_f=(15A_{f-1}+M_f)/16$. It reports about 46 frames, or 1.55 s at 30 fps, to settle within 5% after a scene cut (P p.3; S p.1, section 02/06). Explain whether this lag is acceptable for the target application and how a scene-cut detector could be evaluated (**proposal**).

**VI hướng dẫn trả lời:** Bài báo dùng $T_0=220/1023\approx0.215$, tích lũy pixel sáng nhất thỏa điều kiện và cập nhật $A_f=(15A_{f-1}+M_f)/16$. Sau chuyển cảnh, thời gian hội tụ trong 5% được báo khoảng 46 khung, tức 1,55 s ở 30 fps (P tr.3; S tr.1, Mục 02/06). Cần giải thích độ trễ có chấp nhận được không và đánh giá bộ phát hiện scene-cut thế nào (**đề xuất**).

**Evidence:** P p.3, Eq. (5) paragraph; S p.1, section 06; R-partial [dehazing_system_top.v:486-517](<C:/Research/fpga-vision-enhancement.partial-20261107/hardware/archive/project-inputs/dehazing_system_top.v:486>).

### 11. Does the current ROM implement the published formula?

**EN question:** What is the provenance, normalization, rounding rule, and hash of each LUT used in the build?

**VI translation:** Nguồn gốc, chuẩn hóa, quy tắc làm tròn và hash của từng LUT trong build là gì?

**EN answer guidance:** Do not infer formula equivalence from ROM dimensions alone. The preserved source loads `transmission_lut_data.hex`, and the review records that no generator proving the intended formula was located (R-partial [dehazing_system_top.v:323-327](<C:/Research/fpga-vision-enhancement.partial-20261107/hardware/archive/project-inputs/dehazing_system_top.v:323>); R [docs/research/current-snapshot-review.md:16-19](<C:/Research/fpga-vision-enhancement/docs/research/current-snapshot-review.md:16>)). Provide a generator, fixed-point specification, boundary vectors, and SHA-256 hashes (**proposal**).

**VI hướng dẫn trả lời:** Không suy ra tương đương công thức chỉ từ kích thước ROM. Nguồn bảo tồn nạp `transmission_lut_data.hex`, còn review ghi chưa tìm thấy trình sinh chứng minh công thức (R-partial [dehazing_system_top.v:323-327](<C:/Research/fpga-vision-enhancement.partial-20261107/hardware/archive/project-inputs/dehazing_system_top.v:323>); R [docs/research/current-snapshot-review.md:16-19](<C:/Research/fpga-vision-enhancement/docs/research/current-snapshot-review.md:16>)). Cần cung cấp trình sinh, đặc tả fixed-point, vector biên và hash SHA-256 (**đề xuất**).

**Evidence:** R [docs/research/current-snapshot-review.md:16-19](<C:/Research/fpga-vision-enhancement/docs/research/current-snapshot-review.md:16>); R-partial [dehazing_system_top.v:323-327,474-484](<C:/Research/fpga-vision-enhancement.partial-20261107/hardware/archive/project-inputs/dehazing_system_top.v:323>).

### 12. How should the 80 KB and 82.5 KB statements be reconciled?

**EN question:** The paper uses 80 KB for the transmission table and 82.5 KB for on-chip tables. Are these different scopes or units?

**VI translation:** Bài báo dùng 80 KB cho bảng truyền sáng và 82,5 KB cho toàn bộ bảng on-chip. Đây là khác nhau về phạm vi hay đơn vị?

**EN answer guidance:** Recalculate explicitly: $65{,}536\times10$ bits is 655,360 bits, while adding a $1{,}024\times14$ reciprocal table and three $256\times8$ gamma tables gives 675,840 bits, approximately 82.5 KiB under a binary convention. State whether “KB” means KiB and identify which tables are included. Treat this as a clarification request, not an error accusation (P p.5, Fig. 2 paragraph; P p.7, Table 2 note).

**VI hướng dẫn trả lời:** Tính rõ: $65{,}536\times10$ bit bằng 655.360 bit; cộng bảng nghịch đảo $1{,}024\times14$ và ba bảng gamma $256\times8$ được 675.840 bit, xấp xỉ 82,5 KiB theo quy ước nhị phân. Nêu “KB” là KB hay KiB và phạm vi bảng nào. Đây là yêu cầu làm rõ, chưa phải kết luận sai (P tr.5, đoạn Hình 2; tr.7, chú thích Bảng 2).

**Evidence:** P pp.5,7; S p.1, sections 03–05.

## 3. RTL, fixed-point arithmetic, and numerical behavior

### 13. What is the fixed-point format at each stage?

**EN question:** Give the signedness, integer bits, fractional bits, rounding, and clipping rule for transmission, reciprocal, restoration, and gamma.

**VI translation:** Hãy nêu dấu, số bit phần nguyên/thập phân, làm tròn và clipping cho truyền sáng, nghịch đảo, khôi phục và gamma.

**EN answer guidance:** Map the preserved RTL's 10-bit transmission, 14-bit reciprocal, 18-bit signed difference registers, and 32-bit product registers to a written fixed-point contract (R-partial [dehazing_system_top.v:316-320,393-416](<C:/Research/fpga-vision-enhancement.partial-20261107/hardware/archive/project-inputs/dehazing_system_top.v:316>)). The preserved RTL scales `i_t_raw` by `STRENGTH=256`, clamps to `T_FLOOR=102`, multiplies signed channel differences by the reciprocal, shifts by 10, and clips to 8-bit outputs (R-partial [dehazing_system_top.v:360-380,385-471](<C:/Research/fpga-vision-enhancement.partial-20261107/hardware/archive/project-inputs/dehazing_system_top.v:360>)).

**VI hướng dẫn trả lời:** Lập đặc tả fixed-point từ RTL bảo tồn: transmission 10 bit, reciprocal 14 bit, thanh ghi hiệu có dấu 18 bit và thanh ghi tích 32 bit (R-partial [dehazing_system_top.v:316-320,393-416](<C:/Research/fpga-vision-enhancement.partial-20261107/hardware/archive/project-inputs/dehazing_system_top.v:316>)). RTL bảo tồn scale `i_t_raw` bằng `STRENGTH=256`, clamp ở `T_FLOOR=102`, nhân hiệu có dấu với nghịch đảo, shift 10 bit và clip đầu ra 8 bit (R-partial [dehazing_system_top.v:360-380,385-471](<C:/Research/fpga-vision-enhancement.partial-20261107/hardware/archive/project-inputs/dehazing_system_top.v:360>)).

**Evidence:** P pp.5–6; R-partial [dehazing_system_top.v:360-380,385-471](<C:/Research/fpga-vision-enhancement.partial-20261107/hardware/archive/project-inputs/dehazing_system_top.v:360>).

### 14. Is truncation or rounding used after reciprocal multiplication?

**EN question:** What is the bias introduced by the arithmetic right shift, and how is it included in the error budget?

**VI translation:** Phép dịch phải số học tạo bias nào và bias đó được đưa vào ngân sách sai số ra sao?

**EN answer guidance:** The RTL uses arithmetic shifts before adding atmospheric light and clipping (R-partial [dehazing_system_top.v:446-469](<C:/Research/fpga-vision-enhancement.partial-20261107/hardware/archive/project-inputs/dehazing_system_top.v:446>)). Ask for directed vectors around zero, negative differences, and half-LSB boundaries. The paper's table quantization bounds (P p.6) do not by themselves prove that every pipeline rounding operation is covered.

**VI hướng dẫn trả lời:** RTL dùng phép dịch phải số học trước khi cộng ánh sáng khí quyển và clipping (R-partial [dehazing_system_top.v:446-469](<C:/Research/fpga-vision-enhancement.partial-20261107/hardware/archive/project-inputs/dehazing_system_top.v:446>)). Yêu cầu vector có hiệu âm, gần 0 và đúng biên nửa LSB. Sai số lượng tử của bảng trong bài báo (P tr.6) chưa tự chứng minh mọi phép làm tròn trong pipeline đã được bao phủ.

**Evidence:** R-partial [dehazing_system_top.v:446-469](<C:/Research/fpga-vision-enhancement.partial-20261107/hardware/archive/project-inputs/dehazing_system_top.v:446>); P p.6.

### 15. How are zero, maximum, and invalid pixel values handled?

**EN question:** What happens for $C_{\max}=0$, all-white pixels, missing ROM entries, and invalid Avalon-ST bubbles?

**VI translation:** Hệ thống xử lý thế nào với $C_{\max}=0$, pixel trắng toàn phần, mục ROM thiếu và bubble Avalon-ST không hợp lệ?

**EN answer guidance:** The mathematical HSV expression needs a defined zero-maximum convention. The RTL initializes some registers and ROM values, but a complete answer requires reset, invalid-data, and ROM-file behavior tests. The current review specifically calls startup, invalid-data, and adaptation behavior unverified (R [docs/research/current-snapshot-review.md:19-21](<C:/Research/fpga-vision-enhancement/docs/research/current-snapshot-review.md:19>)).

**VI hướng dẫn trả lời:** Công thức HSV cần quy ước riêng khi cực đại bằng 0. RTL có khởi tạo một số thanh ghi/ROM, nhưng câu trả lời đầy đủ phải gồm reset, dữ liệu invalid và lỗi file ROM. Review hiện tại ghi các hành vi startup, invalid-data và adaptation chưa được xác minh (R [docs/research/current-snapshot-review.md:19-21](<C:/Research/fpga-vision-enhancement/docs/research/current-snapshot-review.md:19>)).

**Evidence:** R [docs/research/current-snapshot-review.md:19-21](<C:/Research/fpga-vision-enhancement/docs/research/current-snapshot-review.md:19>); R-partial [dehazing_system_top.v:323-356,474-484](<C:/Research/fpga-vision-enhancement.partial-20261107/hardware/archive/project-inputs/dehazing_system_top.v:323>).

### 16. Does the atmospheric-light estimator have reachable qualifying pixels?

**EN question:** Can the current ROM and refinement constants actually produce $t<220$ for a valid pixel?

**VI translation:** Với ROM và hằng số refinement hiện tại, pixel hợp lệ có thực sự tạo được $t<220$ không?

**EN answer guidance:** This must be checked, not assumed. The current review observes that with `STRENGTH=256` and the observed ROM range, steady-state values may not fall below the atmospheric threshold, so the maximum estimator may have no qualifying pixel (R [docs/research/current-snapshot-review.md:16-20](<C:/Research/fpga-vision-enhancement/docs/research/current-snapshot-review.md:16>)). Produce a reachability analysis over all 65,536 addresses and a directed simulation (**proposal**).

**VI hướng dẫn trả lời:** Đây là điểm phải kiểm tra bằng dữ liệu. Review hiện tại quan sát rằng với `STRENGTH=256` và miền giá trị ROM quan sát được, giá trị ổn định có thể không thấp hơn ngưỡng khí quyển, khiến estimator không có pixel thỏa điều kiện (R [docs/research/current-snapshot-review.md:16-20](<C:/Research/fpga-vision-enhancement/docs/research/current-snapshot-review.md:16>)). Cần phân tích reachability đủ 65.536 địa chỉ và mô phỏng có chủ đích (**đề xuất**).

**Evidence:** R [docs/research/current-snapshot-review.md:16-20](<C:/Research/fpga-vision-enhancement/docs/research/current-snapshot-review.md:16>); R-partial [dehazing_system_top.v:360-373,512-515](<C:/Research/fpga-vision-enhancement.partial-20261107/hardware/archive/project-inputs/dehazing_system_top.v:360>).

### 17. How is latency proven rather than declared?

**EN question:** What waveform demonstrates the claimed 11-cycle latency from accepted input to valid output?

**VI translation:** Dạng sóng nào chứng minh độ trễ 11 chu kỳ từ input được nhận đến output hợp lệ?

**EN answer guidance:** Define the transaction boundary using `snk_valid && snk_ready` and `src_valid && src_ready`, then measure SOP, EOP, pixel order, and backpressure cases. The preserved RTL declares `TOTAL_DELAY=11`, but the review says declared latency is not independently measured (R-partial [dehazing_system_top.v:18-24](<C:/Research/fpga-vision-enhancement.partial-20261107/hardware/archive/project-inputs/dehazing_system_top.v:18>); R [docs/research/current-snapshot-review.md:21](<C:/Research/fpga-vision-enhancement/docs/research/current-snapshot-review.md:21>)).

**VI hướng dẫn trả lời:** Định nghĩa ranh giới giao dịch bằng `snk_valid && snk_ready` và `src_valid && src_ready`, sau đó đo SOP, EOP, thứ tự pixel và trường hợp backpressure. RTL khai báo `TOTAL_DELAY=11`, nhưng review nói độ trễ khai báo chưa được đo độc lập (R-partial [dehazing_system_top.v:18-24](<C:/Research/fpga-vision-enhancement.partial-20261107/hardware/archive/project-inputs/dehazing_system_top.v:18>); R [docs/research/current-snapshot-review.md:21](<C:/Research/fpga-vision-enhancement/docs/research/current-snapshot-review.md:21>)).

**Evidence:** P p.5; R-partial [dehazing_system_top.v:18-24,26-43,143-149](<C:/Research/fpga-vision-enhancement.partial-20261107/hardware/archive/project-inputs/dehazing_system_top.v:18>); R [docs/research/current-snapshot-review.md:21](<C:/Research/fpga-vision-enhancement/docs/research/current-snapshot-review.md:21>).

### 18. Is backpressure safe in the current RTL?

**EN question:** What happens when `src_ready` deasserts during a valid pixel, and is every data and sideband register held consistently?

**VI translation:** Điều gì xảy ra khi `src_ready` hạ trong lúc pixel hợp lệ, và mọi thanh ghi dữ liệu/sideband có được giữ đồng nhất không?

**EN answer guidance:** The top-level assigns `snk_ready=src_ready` and uses `i_en=src_ready` (R-partial [dehazing_system_top.v:18-19](<C:/Research/fpga-vision-enhancement.partial-20261107/hardware/archive/project-inputs/dehazing_system_top.v:18>)). Ask for a stall-insertion regression covering arbitrary bursts, bubbles, SOP/EOP, and FIFO almost-full behavior. The review notes that ROMs run every clock while the main pipeline can stall, which requires explicit alignment testing (R [docs/research/current-snapshot-review.md:21](<C:/Research/fpga-vision-enhancement/docs/research/current-snapshot-review.md:21>)).

**VI hướng dẫn trả lời:** Top-level gán `snk_ready=src_ready` và `i_en=src_ready` (R-partial [dehazing_system_top.v:18-19](<C:/Research/fpga-vision-enhancement.partial-20261107/hardware/archive/project-inputs/dehazing_system_top.v:18>)). Cần regression chèn stall ngẫu nhiên, bubble, SOP/EOP và FIFO almost-full. Review ghi ROM vẫn chạy mỗi clock khi pipeline chính stall, nên phải kiểm tra căn chỉnh rõ ràng (R [docs/research/current-snapshot-review.md:21](<C:/Research/fpga-vision-enhancement/docs/research/current-snapshot-review.md:21>)).

**Evidence:** R-partial [dehazing_system_top.v:18-19,314-358](<C:/Research/fpga-vision-enhancement.partial-20261107/hardware/archive/project-inputs/dehazing_system_top.v:18>); R [docs/research/current-snapshot-review.md:21](<C:/Research/fpga-vision-enhancement/docs/research/current-snapshot-review.md:21>).

### 19. Are reset and frame-boundary semantics complete?

**EN question:** How are reset release, warm-up cycles, SOP/EOP, and partial frames handled?

**VI translation:** Hệ thống xử lý nhả reset, chu kỳ warm-up, SOP/EOP và frame thiếu như thế nào?

**EN answer guidance:** Require assertions that no stale pixel or sideband exits after reset, that every accepted SOP has one matching delayed SOP, and that EOP cannot precede the corresponding pixel. The current review notes that `common_delay_line` does not use `i_v` and that its memory is not cleared on reset (R [docs/research/current-snapshot-review.md:21](<C:/Research/fpga-vision-enhancement/docs/research/current-snapshot-review.md:21>)).

**VI hướng dẫn trả lời:** Yêu cầu assertion bảo đảm không phát pixel/sideband cũ sau reset, mỗi SOP được nhận có đúng một SOP trễ tương ứng và EOP không đi trước pixel. Review ghi `common_delay_line` không dùng `i_v` và bộ nhớ không được xóa khi reset (R [docs/research/current-snapshot-review.md:21](<C:/Research/fpga-vision-enhancement/docs/research/current-snapshot-review.md:21>)).

**Evidence:** R [docs/research/current-snapshot-review.md:21](<C:/Research/fpga-vision-enhancement/docs/research/current-snapshot-review.md:21>); R-partial [dehazing_system_top.v:26-43,143-149](<C:/Research/fpga-vision-enhancement.partial-20261107/hardware/archive/project-inputs/dehazing_system_top.v:26>).

### 20. How do clipping and signed arithmetic affect image fidelity?

**EN question:** Why is clipping to [0,255] safe, and how much of the image is clipped under difficult haze?

**VI translation:** Vì sao clipping về [0,255] an toàn, và bao nhiêu ảnh bị clip trong sương dày?

**EN answer guidance:** Explain that clipping protects 8-bit output range but can hide over-restoration and create saturated highlights. The paper reports saturated-pixel fractions of 0.01–0.05% for four scenes (P p.6, Table 1; S p.1, section 04), which is useful evidence but not a full distributional analysis. Add histograms and scene-stratified results (**proposal**).

**VI hướng dẫn trả lời:** Clipping bảo vệ miền 8 bit nhưng có thể che over-restoration và tạo highlight bão hòa. Bài báo báo cáo tỷ lệ pixel bão hòa 0,01–0,05% trên bốn cảnh (P tr.6, Bảng 1; S tr.1, Mục 04), đây là bằng chứng hữu ích nhưng chưa phải phân tích đầy đủ. Nên bổ sung histogram và kết quả theo loại cảnh (**đề xuất**).

**Evidence:** P p.6, Table 1 and p.7; R-partial [dehazing_system_top.v:454-471](<C:/Research/fpga-vision-enhancement.partial-20261107/hardware/archive/project-inputs/dehazing_system_top.v:454>).

## 4. FPGA/HPS architecture and streaming integration

### 21. Why partition work between HPS and FPGA?

**EN question:** Which functions belong on the ARM HPS, which on the fabric, and what transfer overhead is introduced?

**VI translation:** Chức năng nào đặt trên ARM HPS, chức năng nào trên FPGA fabric và overhead truyền dữ liệu là gì?

**EN answer guidance:** The paper assigns peripheral configuration, DDR3 buffers, and supervision to HPS, while video input, dehazing, and VGA run in the fabric (P p.4). The HPS application maps `/dev/mem`, writes a $640\times480$ image to SDRAM, enables Pixel DMA, and then waits (R-partial [software/hps/src/vga_simple_display.c:18-65](<C:/Research/fpga-vision-enhancement.partial-20261107/software/hps/src/vga_simple_display.c:18>)). Quantify load, DMA, and display latency separately (**proposal**).

**VI hướng dẫn trả lời:** Bài báo giao cấu hình ngoại vi, buffer DDR3 và giám sát cho HPS; video input, dehazing và VGA chạy trên fabric (P tr.4). Ứng dụng HPS map `/dev/mem`, ghi ảnh $640\times480$ vào SDRAM, bật Pixel DMA rồi chờ (R-partial [software/hps/src/vga_simple_display.c:18-65](<C:/Research/fpga-vision-enhancement.partial-20261107/software/hps/src/vga_simple_display.c:18>)). Cần đo riêng thời gian nạp, DMA và hiển thị (**đề xuất**).

**Evidence:** P p.4; R-partial [software/hps/src/vga_simple_display.c:18-65](<C:/Research/fpga-vision-enhancement.partial-20261107/software/hps/src/vga_simple_display.c:18>).

### 22. How are the multiple clock domains crossed safely?

**EN question:** What CDC structures, synchronizers, and constraints protect the 27 MHz input, 100 MHz core, 25 MHz VGA, and HPS/DDR paths?

**VI translation:** Các cấu trúc CDC, synchronizer và constraint nào bảo vệ các miền 27 MHz, 100 MHz, 25 MHz và HPS/DDR?

**EN answer guidance:** The manuscript describes dual-clock asynchronous FIFOs, Gray-coded pointers, multi-stage synchronizers, and mutually exclusive clock groups (P p.4). Ask for CDC reports, MTBF assumptions, reset sequencing, and a frame-drop test. Current documentation warns that active QSF/SDC closure and I/O/exception coverage must be reviewed before timing sign-off (R [hardware/README.md:15-17](<C:/Research/fpga-vision-enhancement/hardware/README.md:15>); R [docs/research/current-snapshot-review.md:23-27](<C:/Research/fpga-vision-enhancement/docs/research/current-snapshot-review.md:23>)).

**VI hướng dẫn trả lời:** Bản thảo mô tả FIFO bất đồng bộ hai clock, con trỏ Gray, synchronizer nhiều tầng và nhóm clock loại trừ lẫn nhau (P tr.4). Hãy yêu cầu CDC report, giả định MTBF, thứ tự reset và kiểm tra mất frame. Tài liệu hiện tại cảnh báo phải review QSF/SDC, I/O và exception trước khi ký timing (R [hardware/README.md:15-17](<C:/Research/fpga-vision-enhancement/hardware/README.md:15>); R [docs/research/current-snapshot-review.md:23-27](<C:/Research/fpga-vision-enhancement/docs/research/current-snapshot-review.md:23>)).

**Evidence:** P p.4, Fig. 1; R [hardware/README.md:15-17](<C:/Research/fpga-vision-enhancement/hardware/README.md:15>); R [docs/research/current-snapshot-review.md:23-27](<C:/Research/fpga-vision-enhancement/docs/research/current-snapshot-review.md:23>).

### 23. What is the exact Avalon-ST contract?

**EN question:** State the meaning of valid, ready, SOP, EOP, and the RGB30 packing at both interfaces.

**VI translation:** Hãy nêu chính xác ý nghĩa valid, ready, SOP, EOP và cách đóng gói RGB30 ở hai giao diện.

**EN answer guidance:** The preserved top module exposes 30-bit stream data, valid/ready, and SOP/EOP; RGB channels occupy bits [29:22], [19:12], and [9:2] (R-partial [dehazing_system_top.v:7-22](<C:/Research/fpga-vision-enhancement.partial-20261107/hardware/archive/project-inputs/dehazing_system_top.v:7>)). Explain how the two unused bits per channel are handled, how original/bypass data is aligned, and which interface owns backpressure.

**VI hướng dẫn trả lời:** Top module bảo tồn có dữ liệu stream 30 bit, valid/ready và SOP/EOP; kênh RGB nằm ở [29:22], [19:12], [9:2] (R-partial [dehazing_system_top.v:7-22](<C:/Research/fpga-vision-enhancement.partial-20261107/hardware/archive/project-inputs/dehazing_system_top.v:7>)). Cần giải thích hai bit dư mỗi kênh, căn chỉnh dữ liệu bypass/original và interface nào điều khiển backpressure.

**Evidence:** R-partial [dehazing_system_top.v:7-22,143-159](<C:/Research/fpga-vision-enhancement.partial-20261107/hardware/archive/project-inputs/dehazing_system_top.v:7>).

### 24. Does the still-image HPS path demonstrate a live camera pipeline?

**EN question:** What evidence distinguishes an SDRAM-fed still image from continuous camera-to-display operation?

**VI translation:** Bằng chứng nào phân biệt đường ảnh tĩnh từ SDRAM với hoạt động camera–màn hình liên tục?

**EN answer guidance:** The HPS program reads one HEX image, writes the $640\times480$ buffer, starts DMA, and sleeps in an infinite loop (R-partial [vga_simple_display.c:33-65](<C:/Research/fpga-vision-enhancement.partial-20261107/software/hps/src/vga_simple_display.c:33>)). The poster explicitly says camera-to-display remains unverified (S p.1, section 06). State the missing capture, buffering, rate-matching, and frame-drop evidence rather than extrapolating from the still demo.

**VI hướng dẫn trả lời:** Chương trình HPS đọc một file HEX, ghi buffer $640\times480$, bật DMA và ngủ trong vòng lặp vô hạn (R-partial [vga_simple_display.c:33-65](<C:/Research/fpga-vision-enhancement.partial-20261107/software/hps/src/vga_simple_display.c:33>)). Poster nói rõ camera–màn hình chưa được kiểm chứng (S tr.1, Mục 06). Hãy nêu bằng chứng còn thiếu về capture, buffering, rate matching và mất frame, không suy diễn từ demo tĩnh.

**Evidence:** R-partial [software/hps/src/vga_simple_display.c:33-65](<C:/Research/fpga-vision-enhancement.partial-20261107/software/hps/src/vga_simple_display.c:33>); S p.1, section 06.

### 25. How are image dimensions and memory stride guaranteed?

**EN question:** Why is the stride `(y << 10)+x` correct for a $640\times480$ image, and what happens for another resolution?

**VI translation:** Vì sao stride `(y << 10)+x` đúng cho ảnh $640\times480$ và điều gì xảy ra với độ phân giải khác?

**EN answer guidance:** The code uses a 1024-word row stride while populating 640 columns (R-partial [vga_simple_display.c:33-50](<C:/Research/fpga-vision-enhancement.partial-20261107/software/hps/src/vga_simple_display.c:33>)). Explain the SDRAM address contract, padding, DMA descriptor assumptions, and bounds checks. The paper's pointwise operator claim is resolution-invariant for arithmetic, but the HPS memory and display system still require dimension-specific integration checks (P p.6; R-partial [README.md:117](<C:/Research/fpga-vision-enhancement.partial-20261107/README.md:117>)).

**VI hướng dẫn trả lời:** Code dùng stride 1024 word cho mỗi hàng nhưng điền 640 cột (R-partial [vga_simple_display.c:33-50](<C:/Research/fpga-vision-enhancement.partial-20261107/software/hps/src/vga_simple_display.c:33>)). Cần giải thích hợp đồng địa chỉ SDRAM, padding, descriptor DMA và kiểm tra bounds. Claim pointwise resolution-invariant chỉ áp dụng arithmetic; HPS memory và display vẫn cần kiểm tra theo độ phân giải (P tr.6; R-partial [README.md:117](<C:/Research/fpga-vision-enhancement.partial-20261107/README.md:117>)).

**Evidence:** R-partial [software/hps/src/vga_simple_display.c:33-50](<C:/Research/fpga-vision-enhancement.partial-20261107/software/hps/src/vga_simple_display.c:33>); P p.6.

### 26. What is the bypass mode used for?

**EN question:** How does the original/processed switch support debugging and fair comparison?

**VI translation:** Chế độ bypass original/processed hỗ trợ debug và so sánh công bằng như thế nào?

**EN answer guidance:** Describe bypass as a timing and visual reference: it should preserve the delayed original stream while the processed path is selected. Verify that both paths share identical SOP/EOP and valid timing. The preserved RTL exposes `sw_bypass` and delayed raw data, but a regression must prove frame alignment (R-partial [dehazing_system_top.v:6-16,143-159](<C:/Research/fpga-vision-enhancement.partial-20261107/hardware/archive/project-inputs/dehazing_system_top.v:6>)).

**VI hướng dẫn trả lời:** Bypass là tham chiếu timing và hình ảnh: phải giữ dòng gốc đã trễ để chuyển lựa chọn với dòng xử lý. Xác minh hai đường có SOP/EOP và valid giống nhau. RTL bảo tồn có `sw_bypass` và raw data đã trễ, nhưng regression phải chứng minh căn chỉnh frame (R-partial [dehazing_system_top.v:6-16,143-159](<C:/Research/fpga-vision-enhancement.partial-20261107/hardware/archive/project-inputs/dehazing_system_top.v:6>)).

**Evidence:** R-partial [dehazing_system_top.v:6-16,143-159](<C:/Research/fpga-vision-enhancement.partial-20261107/hardware/archive/project-inputs/dehazing_system_top.v:6>); R [README.md](<C:/Research/fpga-vision-enhancement/README.md:58>) architecture section.

## 5. Verification, reproducibility, and experimental design

### 27. What exactly does “bit-exact” cover?

**EN question:** Which inputs, models, ROM files, pipeline states, and handshakes were included in the 0-LSB comparison?

**VI translation:** Những input, model, file ROM, trạng thái pipeline và handshake nào được bao phủ trong so sánh 0-LSB?

**EN answer guidance:** The paper reports one $640\times480$ fixed-point MATLAB/ModelSim stream comparison with 0-LSB agreement (P pp.5–6). Ask for the commit, stimulus hash, ROM hashes, simulator version, reset sequence, and whether stalls, bubbles, frame boundaries, and negative restoration values were exercised. The current verification plan marks RTL equivalence as planned, not available (R [docs/development/verification.md:24-33](<C:/Research/fpga-vision-enhancement/docs/development/verification.md:24>)).

**VI hướng dẫn trả lời:** Bài báo báo cáo một so sánh stream $640\times480$ giữa MATLAB fixed-point và ModelSim với sai số 0 LSB (P tr.5–6). Yêu cầu commit, hash stimulus/ROM, phiên bản simulator, reset sequence và kiểm tra stall, bubble, biên frame, giá trị khôi phục âm. Verification plan hiện tại đánh dấu equivalence RTL là planned, chưa có (R [docs/development/verification.md:24-33](<C:/Research/fpga-vision-enhancement/docs/development/verification.md:24>)).

**Evidence:** P pp.5–6; R [docs/development/verification.md:24-33](<C:/Research/fpga-vision-enhancement/docs/development/verification.md:24>).

### 28. How would you build a reference model that is independent enough?

**EN question:** How do you avoid reproducing the same RTL mistake in MATLAB and the testbench?

**VI translation:** Làm thế nào tránh lặp cùng một lỗi RTL trong MATLAB và testbench?

**EN answer guidance:** Use an independently written high-precision model, then a separate fixed-point model generated from a written specification. Compare intermediate quantities, not only final pixels; include property-based tests for monotonicity, clipping, floor behavior, and address coverage. This is a **proposal**, because the repository review found no current fixed-point equivalence evidence (R [docs/development/verification.md:28-30](<C:/Research/fpga-vision-enhancement/docs/development/verification.md:28>)).

**VI hướng dẫn trả lời:** Dùng model độ chính xác cao viết độc lập, sau đó model fixed-point riêng dựa trên đặc tả bằng văn bản. So sánh cả trung gian, kiểm tra tính đơn điệu, clipping, floor và phủ địa chỉ. Đây là **đề xuất**, vì review chưa thấy bằng chứng equivalence hiện tại (R [docs/development/verification.md:28-30](<C:/Research/fpga-vision-enhancement/docs/development/verification.md:28>)).

**Evidence:** R [docs/development/verification.md:24-33](<C:/Research/fpga-vision-enhancement/docs/development/verification.md:24>); R [docs/research/current-snapshot-review.md:16-21](<C:/Research/fpga-vision-enhancement/docs/research/current-snapshot-review.md:16>).

### 29. Which assertions should be added to the stream interface?

**EN question:** Name temporal properties for valid/ready, SOP/EOP, ordering, and latency.

**VI translation:** Hãy nêu các thuộc tính thời gian cho valid/ready, SOP/EOP, thứ tự và độ trễ.

**EN answer guidance:** Include stability while valid and not ready, no output without prior accepted input, one-to-one pixel conservation, SOP/EOP preservation, and constant latency when no stalls. Add a stall-aware relation when backpressure is present. These are **proposed checks**, not claims that the current repository has passed them.

**VI hướng dẫn trả lời:** Bao gồm giữ ổn định dữ liệu khi valid=1 và ready=0, không có output nếu chưa nhận input, bảo toàn một-một pixel, bảo toàn SOP/EOP và latency cố định khi không stall. Thêm quan hệ có xét backpressure. Đây là **kiểm tra đề xuất**, chưa phải kết quả đã đạt trong repository.

**Evidence:** R [docs/development/verification.md:28-33](<C:/Research/fpga-vision-enhancement/docs/development/verification.md:28>); R-partial [dehazing_system_top.v:18-24,143-149](<C:/Research/fpga-vision-enhancement.partial-20261107/hardware/archive/project-inputs/dehazing_system_top.v:18>).

### 30. What is the minimum regression suite?

**EN question:** Which directed and randomized tests are necessary before board deployment?

**VI translation:** Cần những test directed và randomized tối thiểu nào trước khi triển khai lên bo?

**EN answer guidance:** Require black/white/primary-color ramps, constant images, random pixels, dense and thin haze proxies, reset during idle and active traffic, random stalls, missing/extra EOP, and scene-cut transitions. Record seeds, simulator/tool versions, ROM hashes, waveforms, and pass/fail artifacts. The verification plan currently lists reset, stalls, frame boundaries, timing, and throughput as unavailable/planned (R [docs/development/verification.md:26-33](<C:/Research/fpga-vision-enhancement/docs/development/verification.md:26>)).

**VI hướng dẫn trả lời:** Cần ảnh đen/trắng/màu cơ bản, ramp, ảnh hằng, pixel ngẫu nhiên, proxy sương dày/mỏng, reset khi idle và đang truyền, stall ngẫu nhiên, EOP thiếu/thừa và chuyển cảnh. Ghi seed, phiên bản tool, hash ROM, waveform và artifact pass/fail. Verification plan hiện đánh dấu các mục này planned/chưa có (R [docs/development/verification.md:26-33](<C:/Research/fpga-vision-enhancement/docs/development/verification.md:26>)).

**Evidence:** R [docs/development/verification.md:26-33](<C:/Research/fpga-vision-enhancement/docs/development/verification.md:26>); **proposal:** regression matrix.

### 31. How should reproducibility be packaged?

**EN question:** What artifacts allow an independent researcher to rerun the claim?

**VI translation:** Cần đóng gói những artifact nào để nhà nghiên cứu độc lập chạy lại khẳng định?

**EN answer guidance:** Freeze the source commit, QPF/QSF/QSYS/SDC, tool version, ROM and test-vector hashes, simulator command, synthesis reports, timing constraints, power settings, and board bitstream hash. Keep generated logs separate from source. The current build guide records that manual Quartus compilation had unresolved timing-constraint warnings and clean-checkout reproduction remains unverified (R [docs/development/verification.md:18](<C:/Research/fpga-vision-enhancement/docs/development/verification.md:18>)).

**VI hướng dẫn trả lời:** Cố định commit, QPF/QSF/QSYS/SDC, phiên bản tool, hash ROM/vector, lệnh simulator, report synthesis/timing, cấu hình power và hash bitstream. Tách log sinh ra khỏi source. Build guide ghi compilation thủ công còn cảnh báo constraint và reproduction checkout sạch chưa xác minh (R [docs/development/verification.md:18](<C:/Research/fpga-vision-enhancement/docs/development/verification.md:18>)).

**Evidence:** R [docs/development/verification.md:16-18](<C:/Research/fpga-vision-enhancement/docs/development/verification.md:16>); R [docs/research/current-snapshot-review.md:31-42](<C:/Research/fpga-vision-enhancement/docs/research/current-snapshot-review.md:31>).

### 32. What does source-check CI actually prove?

**EN question:** Which failures are caught by `check_project.py`, and which hardware behaviors remain outside its scope?

**VI translation:** `check_project.py` bắt được lỗi nào và hành vi phần cứng nào vẫn nằm ngoài phạm vi?

**EN answer guidance:** It checks active inputs, Qsys XML, IP paths, ROM dimensions, Python tooling, byte compilation, and optional HPS C syntax. It does not execute board MMIO, prove RTL equivalence, establish timing closure, or validate end-to-end video (R [docs/development/verification.md:3-18,33](<C:/Research/fpga-vision-enhancement/docs/development/verification.md:3>)).

**VI hướng dẫn trả lời:** Script kiểm tra input hoạt động, Qsys XML, đường dẫn IP, kích thước ROM, Python tooling, byte compilation và cú pháp C HPS tùy chọn. Nó không chạy MMIO trên bo, không chứng minh RTL equivalence, timing closure hay video end-to-end (R [docs/development/verification.md:3-18,33](<C:/Research/fpga-vision-enhancement/docs/development/verification.md:3>)).

**Evidence:** R [docs/development/verification.md:3-18,33](<C:/Research/fpga-vision-enhancement/docs/development/verification.md:3>).

## 6. Image-quality evaluation and statistics

### 33. Why use visible-edge gain without ground truth?

**EN question:** What does the visible-edge metric measure, and what important properties does it not measure?

**VI translation:** Chỉ số tăng biên nhìn thấy đo điều gì và không đo được những tính chất quan trọng nào?

**EN answer guidance:** It counts Sobel-gradient pixels above 0.05 and computes $e=(n_P-n_O)/n_O$, with mean gradient and saturated-pixel fraction as companion quantities (P p.5, Section 4.1). It does not establish faithful radiance recovery, color accuracy, semantic utility, or absence of ringing. The paper itself reports no ground truth and uses a blind assessment (P p.5).

**VI hướng dẫn trả lời:** Chỉ số đếm pixel có gradient Sobel trên 0,05 và tính $e=(n_P-n_O)/n_O$, kèm gradient trung bình và tỷ lệ pixel bão hòa (P tr.5, Mục 4.1). Nó không chứng minh khôi phục radiance đúng, màu sắc, ích lợi ngữ nghĩa hay không có ringing. Bài báo nói rõ không có ground truth và dùng đánh giá mù (P tr.5).

**Evidence:** P pp.5–7, Section 4.1 and Table 1.

### 34. Is edge increase necessarily an improvement?

**EN question:** How would you distinguish recovered structure from amplified noise or halos?

**VI translation:** Làm thế nào phân biệt cấu trúc được khôi phục với nhiễu hoặc halo bị khuếch đại?

**EN answer guidance:** Combine edge metrics with no-reference quality, color-difference, noise amplification, halo-specific tests, and downstream detection/tracking performance. Inspect negative examples and report cases where edge count rises while perceptual fidelity falls. The paper reports that the untuned baseline can have higher edge counts, so edge count alone is not a sufficient decision rule (P p.7).

**VI hướng dẫn trả lời:** Kết hợp chỉ số biên với chất lượng không reference, sai khác màu, khuếch đại nhiễu, test halo và hiệu quả detection/tracking. Báo cả ca edge tăng nhưng fidelity giảm. Bài báo cho biết baseline chưa tinh chỉnh có thể có edge count cao hơn, nên edge count không đủ để quyết định (P tr.7).

**Evidence:** P pp.6–7; **proposal:** artifact-aware evaluation.

### 35. Is four-scene evaluation statistically adequate?

**EN question:** What population does four scenes represent, and what uncertainty can be reported?

**VI translation:** Bốn cảnh đại diện cho quần thể nào và có thể báo cáo bất định ra sao?

**EN answer guidance:** Four scenes are an illustrative sample, not a basis for strong population inference. The paper reports per-scene values but no repeated runs, confidence intervals, or dataset split (P p.6, Table 1). A stronger study would use a pre-registered scene set, at least five independent runs where stochasticity exists, bootstrap confidence intervals, and scene-level rather than pixel-level uncertainty (**proposal**).

**VI hướng dẫn trả lời:** Bốn cảnh chỉ là mẫu minh họa, chưa đủ suy luận quần thể mạnh. Bài báo báo giá trị từng cảnh nhưng không có repeated runs, khoảng tin cậy hay chia tập dữ liệu (P tr.6, Bảng 1). Nghiên cứu mạnh hơn cần tập cảnh định trước, ít nhất năm lần chạy khi có ngẫu nhiên, bootstrap CI và bất định theo cảnh (**đề xuất**).

**Evidence:** P pp.5–7; S p.1, section 04.

### 36. Is the guided-filter baseline fair?

**EN question:** What makes the baseline comparison comparable, and what is still missing?

**VI translation:** Điều gì làm so sánh baseline công bằng và còn thiếu gì?

**EN answer guidance:** The table labels the guided-filter DCP baseline as preliminary, untuned, independently reimplemented, and not the pipeline that produced the main $n,\bar g,\sigma$ values (P p.6, Table 1 footnote). Ask for identical input normalization, parameter tuning protocol, resolution, hardware budget, and implementation quality. Treat the comparison as contextual evidence, not a decisive superiority claim.

**VI hướng dẫn trả lời:** Bảng ghi baseline guided-filter DCP là sơ bộ, chưa tinh chỉnh, reimplementation độc lập và không phải pipeline tạo các giá trị $n,\bar g,\sigma$ chính (P tr.6, chú thích Bảng 1). Cần hỏi chuẩn hóa input, quy trình tuning, độ phân giải, ngân sách phần cứng và chất lượng hiện thực có giống nhau không. Xem đây là bằng chứng ngữ cảnh, chưa phải khẳng định ưu thế quyết định.

**Evidence:** P p.6, Table 1 footnote; P p.7.

### 37. What do the synthetic PSNR and SSIM numbers establish?

**EN question:** What is the synthetic proxy, and why should its PSNR/SSIM generalize to real haze?

**VI translation:** Proxy tổng hợp là gì và vì sao PSNR/SSIM của nó có thể khái quát cho sương thực?

**EN answer guidance:** The paper reports PSNR 18.6 vs 15.1 dB and SSIM 0.952 vs 0.899 on a synthetic proxy pair (P p.7). Ask how the proxy was generated, whether its parameters were tuned, and whether it resembles the target sensor/environment. These values are evidence for that proxy only, not a universal real-scene claim.

**VI hướng dẫn trả lời:** Bài báo báo cáo PSNR 18,6 so với 15,1 dB và SSIM 0,952 so với 0,899 trên một cặp proxy tổng hợp (P tr.7). Hỏi cách sinh proxy, tham số có tuning không và mức tương đồng với cảm biến/môi trường mục tiêu. Đây chỉ là bằng chứng cho proxy đó, không phải khẳng định chung cho cảnh thực.

**Evidence:** P p.7, end of Section 4.1.

### 38. How would you design an ablation study?

**EN question:** Which components should be removed or varied one at a time?

**VI translation:** Nên bỏ hoặc thay đổi từng thành phần nào trong ablation?

**EN answer guidance:** Compare: (a) per-pixel min-channel without $K$, (b) the HSV modulation with exponent changes, (c) a lower/upper transmission floor, (d) gamma disabled or varied, $e$ atmospheric recursion disabled, and (f) a spatial-filter baseline. Keep input scenes, fixed-point width, and clock constant. Report image quality, latency, ALMs, RAM, DSP, and power (**proposal**).

**VI hướng dẫn trả lời:** So sánh: (a) min-channel không có $K$, (b) điều biến HSV với số mũ khác, (c) sàn truyền sáng thấp/cao, (d) tắt hoặc thay gamma, $e$ tắt recursion khí quyển và (f) baseline lọc không gian. Giữ cảnh, fixed-point và clock cố định. Báo chất lượng, latency, ALM, RAM, DSP và power (**đề xuất**).

**Evidence:** P pp.3–5; **proposal:** component ablation matrix.

### 39. How do you reconcile the reported scene count?

**EN question:** The abstract says “three hazy scenes,” while Table 1 and the poster report four scenes. Which dataset revision is authoritative?

**VI translation:** Tóm tắt nói “ba cảnh có sương”, trong khi Bảng 1 và poster báo cáo bốn cảnh. Phiên bản tập dữ liệu nào là nguồn chính thức?

**EN answer guidance:** Identify this as a provenance/versioning question, not as a numerical correction made by assumption. The abstract reports three scenes (P p.1), whereas Table 1 lists Scenes 1–4 (P p.6) and the poster also lists four (S p.1, section 04). State the exact image list, revision date or commit, and recalculate the summary range from the same table before publication.

**VI hướng dẫn trả lời:** Xem đây là câu hỏi về nguồn gốc/phiên bản, không tự sửa số liệu. Tóm tắt báo ba cảnh (P tr.1), còn Bảng 1 liệt kê Cảnh 1–4 (P tr.6) và poster cũng liệt kê bốn cảnh (S tr.1, Mục 04). Cần nêu danh sách ảnh, ngày/commit phiên bản và tính lại khoảng tóm tắt từ cùng một bảng trước khi công bố.

**Evidence:** P pp.1,6; S p.1, section 04.

## 7. Timing, resources, and power

### 40. What exactly is included in the reported resource numbers?

**EN question:** Do ALM, memory, DSP, PLL, and power values describe the core or the complete system?

**VI translation:** Các giá trị ALM, memory, DSP, PLL và power mô tả riêng lõi hay toàn hệ thống?

**EN answer guidance:** Table 2 reports the complete system, while three of eight DSP blocks are attributed to the proposed core and five to the YCrCb-to-RGB converter (P pp.5,7). Always label core-only versus system-wide numbers. The poster also labels ALM, RAM, and DSP as full-system values (S p.1, section 05).

**VI hướng dẫn trả lời:** Bảng 2 báo toàn hệ thống; ba trong tám DSP thuộc lõi đề xuất và năm DSP thuộc bộ chuyển YCrCb-to-RGB (P tr.5,7). Luôn ghi rõ số liệu riêng lõi hay toàn hệ thống. Poster cũng trình bày ALM, RAM và DSP theo toàn hệ thống (S tr.1, Mục 05).

**Evidence:** P pp.5,7, Table 2; S p.1, section 05.

### 41. How was timing closure established?

**EN question:** Which clocks, paths, corners, constraints, and reports support the 100 MHz claim?

**VI translation:** Clock, path, corner, constraint và report nào hỗ trợ khẳng định đóng timing ở 100 MHz?

**EN answer guidance:** The paper reports four-corner closure and restricted Fmax 121.64 MHz at the slow 85°C corner (P p.7). Ask for the exact Quartus version, SDC, unconstrained-path report, false-path justification, and worst data paths. The current project documentation records unresolved timing-constraint warnings in a manual Quartus 18.1 report and says clean reproduction is unverified (R [docs/development/verification.md:18](<C:/Research/fpga-vision-enhancement/docs/development/verification.md:18>)).

**VI hướng dẫn trả lời:** Bài báo báo closure bốn corner và Fmax giới hạn 121,64 MHz ở slow 85°C (P tr.7). Cần yêu cầu phiên bản Quartus, SDC, report unconstrained path, lý do false path và worst path. Tài liệu dự án ghi còn cảnh báo constraint trong report Quartus 18.1 thủ công và reproduction sạch chưa xác minh (R [docs/development/verification.md:18](<C:/Research/fpga-vision-enhancement/docs/development/verification.md:18>)).

**Evidence:** P p.7, Table 2; R [docs/development/verification.md:18](<C:/Research/fpga-vision-enhancement/docs/development/verification.md:18>); R [docs/research/current-snapshot-review.md:23-33](<C:/Research/fpga-vision-enhancement/docs/research/current-snapshot-review.md:23>).

### 42. Does one pixel per clock imply a 30 fps end-to-end system?

**EN question:** What throughput, blanking, stall, and buffering assumptions connect core throughput to display frame rate?

**VI translation:** Những giả định về throughput, blanking, stall và buffering nào liên kết throughput lõi với frame rate màn hình?

**EN answer guidance:** One pixel per clock at 100 MHz is a core service rate, not a complete camera/display guarantee. The poster explicitly excludes blanking, stalls, and camera/display latency from 3.07/6.14 ms calculations (S p.1, sections 05–06). Measure sustainable accepted and emitted pixels across all clock crossings and FIFO occupancy (**proposal**).

**VI hướng dẫn trả lời:** Một pixel mỗi chu kỳ ở 100 MHz là tốc độ phục vụ của lõi, chưa phải bảo đảm camera/màn hình hoàn chỉnh. Poster loại trừ blanking, stall và latency camera/màn hình khỏi phép tính 3,07/6,14 ms (S tr.1, Mục 05–06). Cần đo pixel nhận/phát bền vững và occupancy FIFO qua mọi CDC (**đề xuất**).

**Evidence:** P p.1; S p.1, sections 05–06.

### 43. What does the 824.12 mW power number mean?

**EN question:** Which assumptions make the Quartus power value an estimate rather than a board measurement?

**VI translation:** Những giả định nào khiến 824,12 mW là ước lượng Quartus chứ không phải đo trên bo?

**EN answer guidance:** It is vectorless on-chip thermal power with HPS off and a 12.5% toggle rate, split into static, dynamic, and I/O components; the poster says no stimulus vectors were used (P p.7; S p.1, section 05). Distinguish it from typical 2.5–4 W wall-plug context and the isolated core’s reported <65 mW dynamic value. A board measurement with a stated workload is **proposal**.

**VI hướng dẫn trả lời:** Đây là power nhiệt on-chip vectorless, tắt HPS, toggle 12,5%, chia static/dynamic/I/O; poster nói không dùng vector kích thích (P tr.7; S tr.1, Mục 05). Phân biệt với wall-plug 2,5–4 W và dynamic <65 mW của riêng lõi. Đo công suất trên bo với workload xác định là **đề xuất**.

**Evidence:** P p.7, Table 2 and paragraph; S p.1, section 05.

### 44. Is the comparison with Lee et al. like-for-like?

**EN question:** What prevents a direct efficiency ranking across the two devices and resolutions?

**VI translation:** Điều gì ngăn việc xếp hạng hiệu suất trực tiếp giữa hai thiết bị và độ phân giải?

**EN answer guidance:** The paper compares a Cyclone V $640\times480$ design with a Zynq-7000 DCI 4K result and explicitly says the comparison is not like-for-like (P p.7, Table 2 note). Use the comparison only for context; normalize workload, resolution, clock, quality, and system scope before any ranking (**proposal**).

**VI hướng dẫn trả lời:** Bài báo so sánh Cyclone V $640\times480$ với kết quả Zynq-7000 DCI 4K và nói rõ không cùng điều kiện (P tr.7, chú thích Bảng 2). Chỉ dùng để tham khảo; muốn xếp hạng phải chuẩn hóa workload, độ phân giải, clock, chất lượng và phạm vi hệ thống (**đề xuất**).

**Evidence:** P p.7, Table 2 and note.

## 8. Strong constructive challenges

### 45. Could the method be called DCP after choosing $1\times1$?

**EN question:** Is the algorithm still a statistical dark-channel prior, or a min-channel/HSV mapping motivated by the scattering model?

**VI translation:** Sau khi chọn $1\times1$, thuật toán còn là statistical dark-channel prior hay là mapping min-channel/HSV dựa trên mô hình tán xạ?

**EN answer guidance:** Use the paper's careful wording: the $1\times1$ choice makes the spatial prior vacuous, and the estimator is a per-pixel mapping motivated by scattering; the contribution is $K(x)$ and its hardware collapse, not the algebraic identity (P p.3). This distinction improves scientific precision.

**VI hướng dẫn trả lời:** Dùng cách diễn đạt thận trọng của bài báo: $1\times1$ làm prior không gian trở nên tầm thường, estimator là mapping theo pixel dựa trên tán xạ; đóng góp là $K(x)$ và việc quy về phần cứng, không phải đồng nhất thức đại số (P tr.3). Phân biệt này làm thuật ngữ chính xác hơn.

**Evidence:** P p.3, Section 2.

### 46. What is the most serious reproducibility risk?

**EN question:** Which missing artifact could most easily invalidate a claimed result?

**VI translation:** Artifact thiếu nào có thể dễ nhất làm mất hiệu lực của kết quả được tuyên bố?

**EN answer guidance:** A strong answer is the missing linkage among active source closure, LUT contents, constraints, bitstream, and reported measurements. The current review says no source/bitstream equivalence, timing closure, fixed-point equivalence, or board operation is established (R [docs/research/current-snapshot-review.md:29-33](<C:/Research/fpga-vision-enhancement/docs/research/current-snapshot-review.md:29>)). State a staged recovery plan rather than claiming completion.

**VI hướng dẫn trả lời:** Câu trả lời mạnh là thiếu liên kết giữa source hoạt động, nội dung LUT, constraint, bitstream và phép đo. Review ghi chưa xác lập source/bitstream equivalence, timing closure, fixed-point equivalence hay board operation (R [docs/research/current-snapshot-review.md:29-33](<C:/Research/fpga-vision-enhancement/docs/research/current-snapshot-review.md:29>)). Hãy nêu kế hoạch khôi phục theo giai đoạn, không khẳng định đã hoàn tất.

**Evidence:** R [docs/research/current-snapshot-review.md:29-42](<C:/Research/fpga-vision-enhancement/docs/research/current-snapshot-review.md:29>).

### 47. What failure mode would you investigate first on hardware?

**EN question:** If the display is wrong, which observables separate LUT, CDC, latency, memory-map, and VGA faults?

**VI translation:** Nếu màn hình sai, quan sát nào giúp tách lỗi LUT, CDC, latency, memory-map và VGA?

**EN answer guidance:** Use the bypass switch, known-color ramps, a loopback pattern, SOP/EOP counters, FIFO occupancy, DMA status, and per-stage valid probes. Confirm HPS addresses against the generated system before changing RTL. The HPS program directly maps `/dev/mem` and uses fixed base symbols, so memory-map mismatch is a concrete diagnostic branch (R-partial [vga_simple_display.c:19-31,56-61](<C:/Research/fpga-vision-enhancement.partial-20261107/software/hps/src/vga_simple_display.c:19>)).

**VI hướng dẫn trả lời:** Dùng bypass, ramp màu chuẩn, pattern loopback, bộ đếm SOP/EOP, occupancy FIFO, trạng thái DMA và probe valid từng stage. Đối chiếu địa chỉ HPS với hệ thống sinh ra trước khi sửa RTL. Chương trình map `/dev/mem` và dùng symbol base cố định, nên mismatch memory-map là nhánh chẩn đoán cụ thể (R-partial [vga_simple_display.c:19-31,56-61](<C:/Research/fpga-vision-enhancement.partial-20261107/software/hps/src/vga_simple_display.c:19>)).

**Evidence:** R-partial [software/hps/src/vga_simple_display.c:19-31,56-61](<C:/Research/fpga-vision-enhancement.partial-20261107/software/hps/src/vga_simple_display.c:19>); R-partial [dehazing_system_top.v:143-159](<C:/Research/fpga-vision-enhancement.partial-20261107/hardware/archive/project-inputs/dehazing_system_top.v:143>).

### 48. How would you defend the method against a learned baseline?

**EN question:** What would a fair FPGA comparison with a lightweight CNN require?

**VI translation:** Một so sánh FPGA công bằng với CNN nhẹ cần những điều kiện nào?

**EN answer guidance:** Match sensor input, output quality target, resolution, latency definition, batch size, clock, device, memory, power measurement, and training/inference data. Report accuracy and hardware cost together; do not infer that a LUT method dominates learned methods from the current four-scene study. The paper motivates low-cost edge constraints but does not report such a matched CNN experiment (P pp.1–2).

**VI hướng dẫn trả lời:** Phải khớp input cảm biến, mục tiêu chất lượng, độ phân giải, định nghĩa latency, batch, clock, device, memory, power và dữ liệu train/inference. Báo chất lượng cùng chi phí phần cứng; không suy ra LUT vượt CNN từ nghiên cứu bốn cảnh hiện tại. Bài báo nêu động cơ edge nhưng chưa báo thí nghiệm CNN khớp điều kiện (P tr.1–2).

**Evidence:** P pp.1–2; **proposal:** matched CNN baseline.

### 49. What would make the next paper materially stronger?

**EN question:** Name three experiments that would change the strength of the evidence, not just add more figures.

**VI translation:** Nêu ba thí nghiệm làm thay đổi sức mạnh bằng chứng, thay vì chỉ thêm hình.

**EN answer guidance:** A defensible set is: (1) reproducible active-source build with timing/ROM/bitstream hashes; (2) matched baselines and ablations on a larger pre-specified dataset with confidence intervals; (3) measured camera-to-display throughput, frame drops, latency, and board power. These directly address the evidence gaps documented in R [docs/research/current-snapshot-review.md:35-43](<C:/Research/fpga-vision-enhancement/docs/research/current-snapshot-review.md:35>).

**VI hướng dẫn trả lời:** Bộ ba hợp lý là: (1) build source hoạt động tái lập được kèm hash timing/ROM/bitstream; (2) baseline và ablation công bằng trên tập dữ liệu lớn hơn, định trước, có khoảng tin cậy; (3) đo throughput camera–màn hình, mất frame, latency và power trên bo. Ba mục này đánh trúng các gap trong R [docs/research/current-snapshot-review.md:35-43](<C:/Research/fpga-vision-enhancement/docs/research/current-snapshot-review.md:35>).

**Evidence:** R [docs/research/current-snapshot-review.md:35-43](<C:/Research/fpga-vision-enhancement/docs/research/current-snapshot-review.md:35>); S p.1, section 06.

## 9. Forward-looking design questions

### 50. How would you reduce scene-cut adaptation lag?

**EN question:** What alternatives preserve temporal stability while reacting faster than the 46-frame recursion?

**VI translation:** Có thể giảm độ trễ thích nghi khi chuyển cảnh thế nào mà vẫn giữ ổn định thời gian?

**EN answer guidance:** Evaluate a scene-cut detector, adaptive smoothing factor, dual-timescale estimator, or reset-on-cut policy. Measure overshoot, flicker, settling time, and false cuts on controlled transitions. These are **proposal options**; the reported system uses the fixed $15/16$ recursion (P p.3; S p.1).

**VI hướng dẫn trả lời:** Đánh giá scene-cut detector, hệ số smoothing thích nghi, estimator hai thang thời gian hoặc reset khi chuyển cảnh. Đo overshoot, flicker, thời gian hội tụ và false cut trên chuyển cảnh có kiểm soát. Đây là **phương án đề xuất**; hệ thống báo cáo dùng recursion cố định $15/16$ (P tr.3; S tr.1).

**Evidence:** P p.3; S p.1, sections 02 and 06.

### 51. How would you extend from $1\times1$ to spatial context without losing the hardware advantage?

**EN question:** What bounded-memory design could add context while preserving throughput?

**VI translation:** Thiết kế bộ nhớ giới hạn nào có thể thêm ngữ cảnh mà vẫn giữ throughput?

**EN answer guidance:** Consider a small line buffer, separable/streaming filter, tiled windows, or a selectable $1\times1$/$3\times3$ mode. Quantify added RAM, latency, DSP, border policy, and halo behavior. The $1\times1$ design intentionally removes line buffers, so any extension must report the resource/quality tradeoff (P pp.2–5).

**VI hướng dẫn trả lời:** Có thể xét line buffer nhỏ, bộ lọc separable/streaming, cửa sổ tiled hoặc mode chọn $1\times1$/$3\times3$. Định lượng RAM, latency, DSP, xử lý biên và halo. Thiết kế $1\times1$ cố ý loại line buffer, nên mở rộng phải báo đánh đổi tài nguyên/chất lượng (P tr.2–5).

**Evidence:** P pp.2–5; **proposal:** selectable spatial-context architecture.

### 52. What is needed for a safe deployment workflow?

**EN question:** Which checks must pass before replacing a board bitstream or HPS executable?

**VI translation:** Những kiểm tra nào phải đạt trước khi thay bitstream hoặc executable HPS trên bo?

**EN answer guidance:** Require matching commit IDs, verified SHA-256 for bitstream and ROMs, compiled C/header memory-map agreement, a quiesce procedure for DMA, rollback artifact, and a smoke test with bypass enabled. The repository deployment documentation warns that source commit, executing version, and configured FPGA can diverge; treat deployment as a controlled evidence step (R-partial [README.md](<C:/Research/fpga-vision-enhancement.partial-20261107/README.md:13>), Board update workflow).

**VI hướng dẫn trả lời:** Cần commit ID khớp, SHA-256 bitstream/ROM, C/header cùng memory map, quy trình dừng DMA, artifact rollback và smoke test có bypass. Tài liệu deployment cảnh báo commit source, phiên bản đang chạy và FPGA đã cấu hình có thể khác nhau; triển khai phải là bước có kiểm soát và ghi bằng chứng (R-partial [README.md](<C:/Research/fpga-vision-enhancement.partial-20261107/README.md:13>), phần Board update workflow).

**Evidence:** R-partial [README.md:206](<C:/Research/fpga-vision-enhancement.partial-20261107/README.md:206>); R [docs/research/current-snapshot-review.md:41-43](<C:/Research/fpga-vision-enhancement/docs/research/current-snapshot-review.md:41>).

### 53. What is the next scientifically meaningful application metric?

**EN question:** How will you show that enhancement improves a downstream vision task rather than only image statistics?

**VI translation:** Làm thế nào chứng minh tăng cường ảnh cải thiện tác vụ thị giác downstream chứ không chỉ các thống kê ảnh?

**EN answer guidance:** Select a task such as detection, tracking, or depth estimation; freeze the task model and compare hazy, enhanced, and reference conditions with task-level metrics and latency. Report failure cases and whether enhancement harms already-clear scenes. The paper motivates autonomous driving and surveillance but does not report a downstream task experiment (P p.1, Abstract/Introduction).

**VI hướng dẫn trả lời:** Chọn tác vụ như detection, tracking hoặc depth; cố định model tác vụ và so sánh điều kiện sương, enhanced và reference bằng metric tác vụ cùng latency. Báo ca thất bại và việc ảnh rõ có bị hại không. Bài báo nêu động lực autonomous driving/surveillance nhưng chưa có thí nghiệm downstream (P tr.1, Tóm tắt/Mở đầu).

**Evidence:** P p.1; **proposal:** downstream-task evaluation.

## 10. Ten rapid-fire questions / Mười câu hỏi nhanh

1. **EN:** Why $1\times1$? **VI:** Vì sao $1\times1$? **EN expected:** It removes the spatial minimum and line buffers while changing the classical DCP prior. **VI trọng tâm:** Nó loại phép min không gian và bộ đệm dòng, đồng thời thay đổi prior DCP cổ điển (P p.3).
2. **EN:** What is the core latency? **VI:** Độ trễ lõi là bao nhiêu? **EN expected:** 11 cycles, or 110 ns at 100 MHz. **VI trọng tâm:** 11 chu kỳ, tương đương 110 ns ở 100 MHz (P p.5; S p.1, section 03).
3. **EN:** What is the throughput claim? **VI:** Khẳng định về thông lượng là gì? **EN expected:** One pixel per clock under continuous streaming; complete camera/display operation requires separate validation. **VI trọng tâm:** Một pixel mỗi chu kỳ khi stream liên tục; camera–màn hình hoàn chỉnh cần kiểm chứng riêng (P p.1; S p.1, section 06).
4. **EN:** What is the transmission floor? **VI:** Sàn truyền sáng là bao nhiêu? **EN expected:** Approximately one tenth, limiting inverse noise gain near tenfold. **VI trọng tâm:** Khoảng một phần mười, giới hạn khuếch đại nhiễu khi đảo mô hình khoảng mười lần (P p.4, Eq. (6)).
5. **EN:** How fast does atmospheric light adapt after a cut? **VI:** Ánh sáng khí quyển thích nghi sau chuyển cảnh nhanh thế nào? **EN expected:** Approximately 46 frames, or 1.55 s at 30 fps, to the stated 5% tolerance. **VI trọng tâm:** Khoảng 46 khung, tương đương 1,55 s ở 30 fps, tới mức sai lệch 5% được nêu (P p.3; S p.1, section 06).
6. **EN:** What does 0 LSB cover? **VI:** 0 LSB bao phủ gì? **EN expected:** The reported MATLAB/ModelSim comparison on a $640\times480$ frame; request stimulus and protocol coverage. **VI trọng tâm:** Phép so sánh MATLAB/ModelSim đã báo trên khung $640\times480$; cần yêu cầu phạm vi stimulus và protocol (P pp.5–6; R [verification.md:24-33](<C:/Research/fpga-vision-enhancement/docs/development/verification.md:24>)).
7. **EN:** How many DSPs are in the core? **VI:** Lõi dùng bao nhiêu DSP? **EN expected:** Three in the core, eight system-wide. **VI trọng tâm:** Ba DSP trong lõi, tám DSP toàn hệ thống (P pp.5,7; S p.1, section 05).
8. **EN:** Is 824.12 mW measured? **VI:** 824,12 mW có phải số đo không? **EN expected:** It is a vectorless Quartus estimate with HPS off and a 12.5% toggle setting. **VI trọng tâm:** Đó là ước lượng Quartus không vector kích thích, tắt HPS, cài toggle 12,5% (P p.7; S p.1, section 05).
9. **EN:** Is the baseline tuned? **VI:** Baseline đã được tinh chỉnh chưa? **EN expected:** The paper labels it preliminary, untuned, and independently reimplemented. **VI trọng tâm:** Bài báo ghi đó là baseline sơ bộ, chưa tinh chỉnh và hiện thực lại độc lập (P p.6, Table 1 footnote).
10. **EN:** What remains unverified? **VI:** Còn gì chưa xác minh? **EN expected:** The current checkout lacks established active-source closure and reproduced timing/equivalence evidence, while continuous camera-to-display verification remains pending. **VI trọng tâm:** Checkout hiện tại chưa xác lập source closure hoạt động và bằng chứng tái lập timing/equivalence; camera–màn hình liên tục cũng còn chờ kiểm chứng (R [current-snapshot-review.md:5-7,31-43](<C:/Research/fpga-vision-enhancement/docs/research/current-snapshot-review.md:5>); S p.1, section 06).

## Defense checklist / Danh sách chuẩn bị bảo vệ

The following items are preparation recommendations. / Các mục sau là khuyến nghị chuẩn bị.

- **EN:** State the exact source tree, commit, tool version, device, clock, and artifact hashes before presenting a number. **VI:** Nêu đúng cây nguồn, commit, phiên bản tool, device, clock và hash artifact trước khi trình bày số liệu.
- **EN:** Label results as reported, reproduced, measured, calculated, or proposed. **VI:** Gắn nhãn kết quả là được báo cáo, đã tái lập, đã đo, đã tính hay mới đề xuất.
- **EN:** Distinguish core-only, full-system, FPGA on-chip, and wall-plug power. **VI:** Phân biệt công suất riêng lõi, toàn hệ thống, on-chip FPGA và công suất từ ổ cắm.
- **EN:** Explain the $1\times1$ choice, black-pixel handling, LUT generation, fixed-point rounding, floor, clipping, and atmospheric-light startup. **VI:** Giải thích lựa chọn $1\times1$, pixel đen, sinh LUT, làm tròn fixed-point, floor, clipping và khởi động ánh sáng khí quyển.
- **EN:** Show waveforms for reset, stalls, SOP/EOP, bypass, and frame transitions. **VI:** Chuẩn bị waveform reset, stall, SOP/EOP, bypass và chuyển frame.
- **EN:** Separate accepted-pixel throughput, core latency, frame processing time, and end-to-end latency. **VI:** Tách thông lượng pixel được nhận, độ trễ lõi, thời gian xử lý khung và độ trễ toàn hệ thống.
- **EN:** Present the image metrics with dataset, baseline, ground-truth, and statistical limitations. **VI:** Trình bày metric ảnh cùng giới hạn tập dữ liệu, baseline, ground truth và thống kê.
- **EN:** Bring QSF/QSYS/SDC, unconstrained-path and CDC reports, ROM/vector hashes, and a bitstream checksum. **VI:** Chuẩn bị QSF/QSYS/SDC, report unconstrained-path và CDC, hash ROM/vector và checksum bitstream.
- **EN:** Link historical results to exact sources, tools, and artifacts before treating them as current evidence. **VI:** Liên kết kết quả lịch sử với đúng source, tool và artifact trước khi coi là bằng chứng hiện tại.
- **EN:** Answer criticism with a falsifiable experiment and an acceptance criterion. **VI:** Đáp lại phản biện bằng thí nghiệm có thể bác bỏ và tiêu chí chấp nhận cụ thể.

## Source register

1. **P:** [C:/Users/Duy Khanh/Downloads/53_20260916_A_real_time_FPGA_based_vision_enhancement_system_Final_Submission (2).pdf](<C:/Users/Duy Khanh/Downloads/53_20260916_A_real_time_FPGA_based_vision_enhancement_system_Final_Submission (2).pdf>), 8 pages. Used for equations, algorithm parameters, architecture, verification, image-quality tables, resource/timing/power claims, and stated limitations.
2. **S:** [C:/Users/Duy Khanh/Downloads/ICEBA_2026_FPGA_Poster_VI.pptx.pdf](<C:/Users/Duy Khanh/Downloads/ICEBA_2026_FPGA_Poster_VI.pptx.pdf>), 1 page. Used for the poster's four-scene table, 50 MHz still-image board scope, 46-frame adaptation statement, and vectorless power caveat.
3. **R-partial:** [C:/Research/fpga-vision-enhancement.partial-20261107/hardware/archive/project-inputs/dehazing_system_top.v](<C:/Research/fpga-vision-enhancement.partial-20261107/hardware/archive/project-inputs/dehazing_system_top.v>), especially lines 7–24, 97–118, 314–380, 385–484, and 486–517; `software/hps/src/vga_simple_display.c:18-65`.
4. **R:** [C:/Research/fpga-vision-enhancement/hardware/README.md:13-19](<C:/Research/fpga-vision-enhancement/hardware/README.md:13>); `docs/research/current-snapshot-review.md:5-45`; `docs/development/verification.md:14-33`.

The source register is a navigation aid. The evidence citations beside each question are the authoritative traceability for that item.
