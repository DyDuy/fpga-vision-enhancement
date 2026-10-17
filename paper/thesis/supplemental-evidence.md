# Supplemental evidence: thesis, defense and research journal

This note records technical extracts reviewed from three files supplied by the project author. The original files are not hosted here. Selected image extracts are tracked in [`docs/assets/`](../../docs/assets/); file identities and exact source locations below allow comparison against the originals. This review inventory is separate from the four-file local archive in [`manifest.json`](manifest.json). The Vietnamese thesis checksum matches that manifest's existing PDF entry; it is not a newly identified revision.

## Source inventory

PDF page numbers below are **physical pages counted from 1**, including front matter. Printed page numbers refer to the labels on the pages. Slide numbers are counted from 1 in the supplied deck.

| ID | Owner-supplied filename | Size | Extent |
|---|---|---:|---:|
| T | `21_Cuốn báo cáo KLTN_Cao Khanh Duy_vi.pdf` | 4,409,922 bytes | 75 PDF pages |
| D | `21_PPT Báo cáo KLTN_Cao Khánh Duy.pptx` | 87,971,476 bytes | 31 slides |
| J | `Nhật ký.pdf` | 2,675,732 bytes | 30 PDF pages |

SHA-256 of the reviewed source bytes:

- **T:** `08501f924aa65f415d5d240a2d959e084390ba005a46ddc366ca1a3ff05d7f26`
- **D:** `b2578e726b0338dc8f7b0f22cf4670b07fbc842ea1f85b87f301121d78645765`
- **J:** `8d8924c683fa6806f5d5f1281650ac7aa311c938be7c9e55992275304b668962`

## Image results and setup

| Tracked asset | Exact source | Preservation / conversion |
|---|---|---|
| [`thesis-input.jpg`](../../docs/assets/thesis-input.jpg) | **T, Figure 3.3, PDF p. 44 / printed p. 29**, embedded JPEG `Image337` | 501 × 424 px; original JPEG bytes copied unchanged |
| [`thesis-enhanced.jpg`](../../docs/assets/thesis-enhanced.jpg) | **T, Figure 3.3, PDF p. 44 / printed p. 29**, embedded JPEG `Image338` | 516 × 436 px; original JPEG bytes copied unchanged |
| [`de1-soc-demo-setup.jpg`](../../docs/assets/de1-soc-demo-setup.jpg) | **D, slide 31, “Demo sản phẩm”**, embedded poster `ppt/media/image83.png` | 1,280 × 720 px; full frame converted to RGB JPEG using Pillow, quality 92, chroma subsampling 0; no crop or resize |
| [`de1-soc-demo.gif`](../../docs/assets/de1-soc-demo.gif) | **D, slide 31**, embedded `ppt/media/media1.mp4`, **2:33–2:45** | Silent, 12-second excerpt; 640 × 360 px; 60 frames sampled at 5 frames/s; export method below |

The Figure 3.3 pair illustrates the thesis's input and enhanced result. Its processing/capture provenance does not establish an FPGA screen capture. The underlying evaluation-image dataset and its distribution terms have not been established from these extracts; attribution remains with the thesis and no new license is assigned. **Source: T, Figure 3.3, PDF p. 44 / printed p. 29.**

The slide 31 poster shows the DE1-SoC/laptop demonstration setup. The selected recording excerpt shows the board, filmed display and switch interaction. These media do not identify the loaded bitstream or source commit, establish which switch state corresponds to a processing mode, or provide a quantitative image-quality comparison; camera exposure and filmed display colors limit any fidelity assessment. An earlier part of the source recording, approximately **1:30–1:50**, shows noisy display output; the selected excerpt is not evidence that the entire recorded run was free of display issues. **Source: D, slide 31, embedded poster and video at 1:30–1:50 and 2:33–2:45.**

The GIF is a derived viewing copy of the original 1,280 × 720 video. OpenCV 4.14.0 decoded samples at nominal source times `153.0 + 0.2 × i` seconds for `i = 0…59` (153.0–164.8 seconds, source interval `[153, 165)`). Frames were resized to 640 × 360 and encoded with Pillow as a silent GIF, using a 256-color adaptive palette per frame, optimization, disposal mode 1 and 200 ms per frame. The original poster's JPEG conversion used Pillow 12.2.0. **These export settings are presentation choices, not measurements of hardware frame rate or latency.** The source video remains unchanged and is not hosted here.

Asset SHA-256 records:

| File | SHA-256 |
|---|---|
| `thesis-input.jpg` (24,092 bytes) | `0ea36bd34a53a7c64d35f18ddf3461b3930538072234d89d68e59731edcb36a7` |
| `thesis-enhanced.jpg` (40,277 bytes) | `b6cda60254fdf35f68613be57b1f1fcfc656d1a2c47846e17d90d3e522fee2de` |
| Source poster `image83.png` (820,287 bytes) | `596a96f092cbe5fef85ee95ff50a429910fbc35dc6a8045c2210d3dfd6a44a3c` |
| Converted `de1-soc-demo-setup.jpg` (147,474 bytes) | `7aeabaa8fc4dda16bec30a7fe6c65befa5420b6e1a092d55e63254ff4318c245` |
| Source video `media1.mp4` (62,467,165 bytes) | `c7418010a8e41c3e399dab9ccd87384e0163e07f40f01f226e06cb4b05cf60d2` |
| Derived `de1-soc-demo.gif` (5,855,036 bytes) | `09b176764cd49ccdba23534240b6b2247d185883181d41c761f55469217dda41` |

## Resource and timing records

The thesis and defense report the following system resource snapshot. The thesis appendix identifies the device as `5CSEMA5F31C6` and the tool as Quartus Prime 18.1.0 Build 625. **Sources: T, Table 3.1, PDF pp. 41–42 / printed pp. 26–27; Figure B.12, PDF p. 62 / printed p. 37; D, slide 20.**

| Metric | Thesis / defense reported value |
|---|---:|
| Logic utilization | 6,021 / 32,070 ALMs (19%) |
| Registers | 4,851 |
| Block-memory bits | 1,113,192 / 4,065,280 (27%) |
| DSP blocks | 8 / 87 |
| Operating clock | 50 MHz |

The **50 MHz operating clock is not an Fmax measurement**. The manuscript reports a different resource snapshot (6,279 ALMs, 4,875 registers and 1,113,243 memory bits). The exact revision/build mapping between these records has not been established, so their difference is not presented as a measured improvement. **Sources: T, Table 3.1; D, slide 20; [manuscript §4.2, Table 2, lines 103–121](https://github.com/DyDuy/fpga-vision-enhancement/blob/5e287f1821ffd83656033a32633448babdc4a698/paper/article/53_20260916_A_real_time_FPGA_based_vision_enhancement_system_Final_Submission.md#L103-L121).**

The thesis gives the following slack summary, in **nanoseconds**. The defense reproduces the values without explicit units. **Sources: T, Table 3.2, PDF p. 42 / printed p. 27; D, slide 21.**

| Corner | Setup (ns) | Hold (ns) | Recovery (ns) | Removal (ns) |
|---|---:|---:|---:|---:|
| Slow, 1,100 mV, 85°C | 1.730 | 0.143 | 3.375 | 0.470 |
| Slow, 1,100 mV, 0°C | 1.727 | 0.162 | 3.468 | 0.460 |
| Fast, 1,100 mV, 85°C | 2.110 | 0.084 | 3.727 | 0.497 |
| Fast, 1,100 mV, 0°C | 2.110 | 0.077 | 3.825 | 0.473 |

The associated appendix screenshots analyze `hps_sdram_p0` and display **“Design is not fully constrained.”** This context limits interpretation: neither the table nor these screenshots establishes timing closure for the full pixel datapath, and no Fmax is derived here from their slack. **Source: T, Figures B.13–B.14, PDF pp. 63–64 / printed pp. 38–39.**

## Recorded workflow and journal scope

- **Thesis demonstration flow:** the report describes still-image movement from SD card through dehazing, SDRAM and VGA. This is a historical description and can differ from the maintained HPS image loader. **Source: T, PDF p. 49 / printed p. 34; compare [current HPS loader, lines 19–83](https://github.com/DyDuy/fpga-vision-enhancement/blob/5e287f1821ffd83656033a32633448babdc4a698/software/hps/src/vga_simple_display.c#L19-L83).**
- **Image preparation and fixed-point planning:** the journal discusses 640 × 480 images, 24-bit RGB `RRGGBB`/HEX conversion and ModelSim/Quartus work. PSNR and SSIM appear as evaluation goals, without measured values in the reviewed section. **Source: J, PDF/printed pp. 23–26.**
- **Integration discussion:** the later Avalon-ST and system-integration notes include recommendations; they are not treated as proof that every discussed feature was implemented. **Source: J, PDF/printed pp. 27–30.**

## Evidence boundaries

These are historical authored records, not a new compilation, RTL simulation, board run or measurement of the current checkout. Selected technical figures are provided for inspection; full source documents, signatures and administrative/network-setup screenshots are not published. The journal's Linux/programming setup pages are outside the extracts presented here. **Source context: T and D as located above; J, PDF/printed pp. 3–19.**

The thesis's generic local-window discussion is not used to assign a 1×1 or 15×15 variant to its reported build. The maintained source's per-pixel scope is documented separately in [hardware/README.md](../../hardware/README.md).

No numerical speed, image-quality or comparative-performance conclusion is added from the following incomplete evidence:

- The thesis's approximate per-frame processing-time statement lacks sufficient measurement conditions for a reproducible throughput claim. **Source: T, PDF p. 49 / printed p. 34.**
- Thesis image-quality tables are not promoted as PSNR/SSIM measurements or used for new comparisons. **Source: T, Tables 3.3–3.6, PDF pp. 44–47 / printed pp. 29–32; journal evaluation goals: J, PDF/printed pp. 23–26.**

Current-commit bitstream identification, raw fit/timing reports with reviewed constraints, fixed-point reference vectors and RTL/board regression remain necessary to connect the source tree to a reproducible hardware result. See the [verification plan](../../docs/development/verification.md).
