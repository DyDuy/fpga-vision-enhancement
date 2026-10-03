#**************************************************************
# Khoa luan tot nghiep: Vision Enhancement System on DE1-SoC
# Target Board: Altera DE1-SoC (Intel Cyclone V)
#
# GHI CHU SUA LOI (so voi ban goc):
#  1) CLOCK_50/2/3/4 la thach anh VAT LY 50 MHz tren board -> phai khai
#     dung period 20.000 ns. Khai 10.000 ns (ep thanh 100 MHz) la SAI,
#     day chinh la nguyen nhan gay slack am -7..-12 ns o MOI corner
#     (Slow/Fast, 85C/0C) trong 4 anh report ban gui.
#  2) Da xoa create_generated_clock placeholder "your_pll|clk[x]"
#     (khong resolve duoc pin that) -> gay warning "PLL cross checking
#     found inconsistent PLL clock settings". derive_pll_clocks da tu
#     dong tao clock cho MOI PLL that trong thiet ke (ke ca PLL noi bo
#     cua HPS), nen khong can khai tay nua.
#  3) Neu ban muon domain 100 MHz that cho dehazing_system_top, phai co
#     1 PLL (ALTPLL/IOPLL trong Qsys/Platform Designer) nhan 50->100MHz,
#     va cong clk cua dehazing_system_top phai lay tu output PLL do
#     (KHONG noi thang CLOCK_50). Sua ten clock "pll_sys_100m" ben duoi
#     cho khop voi ten PLL/pin that trong project cua ban.
#**************************************************************

#========================
# Base Clocks (dung tan so vat ly that: 50 MHz -> 20.000 ns)
#========================
create_clock -period 20.000 -name clk_50  [get_ports CLOCK_50]
create_clock -period 20.000 -name clk2_50 [get_ports CLOCK2_50]
create_clock -period 20.000 -name clk3_50 [get_ports CLOCK3_50]
create_clock -period 20.000 -name clk4_50 [get_ports CLOCK4_50]

# TV Decoder Clock (27 MHz -> 37.037 ns)
create_clock -period 37.037 -name tv_27m [get_ports TD_CLK27]

# Camera Clock (neu dung OV7670/D5M)
# create_clock -period 40.000 -name clk_camera [get_ports CAMERA_PIXCLK]

# GHI CHU QUAN TRONG: KHONG create_clock truc tiep tren VGA_CLK / DRAM_CLK.
# Hai port nay la OUTPUT duoc PLL noi bo (vga_pll, system_pll nhanh sdram_clk)
# LAI TRUC TIEP, tuc la generated clock, khong phai clock nguon. Neu tu
# create_clock ep period len day, se tao 2 dinh nghia clock xung dot tren
# cung 1 mang day (1 dung do derive_pll_clocks tu tinh, 1 sai do ta khai
# tay) -> gay slack am gia tao hang tram ns (da xay ra: clk_vga -12.465,
# clk_dram -3.661 trong report vua roi). Thay vao do dung create_generated_clock
# tro dung ve pin PLL that (lay chinh xac tu report Timing Analyzer):

#========================
# HPS internal toggle-clock pins (khong phai clock dong bo that,
# nhung Quartus nhan dien co pattern clock nen bat buoc phai khai
# de het warning "found without an associated clock assignment").
# Cac pin nay khong duoc dung lam clock cho logic FPGA fabric nen
# duoc coi la async / false path voi tat ca.
#========================
create_clock -name hps_usb_clkout  -period 16.667 [get_ports HPS_USB_CLKOUT] -add
create_clock -name hps_i2c1_sclk   -period 2500.000 [get_ports HPS_I2C1_SCLK] -add
create_clock -name hps_i2c2_sclk   -period 2500.000 [get_ports HPS_I2C2_SCLK] -add

#========================
# Generated Clocks (PLL) - tu dong phat hien MOI PLL that trong thiet ke,
# bao gom ca PLL noi bo cua HPS lan PLL 50->100MHz cua user logic (neu co).
#========================
derive_pll_clocks -create_base_clocks

# Generated clock cho VGA_CLK - nguon la pin PLL that (tu vga_pll, ten pin
# lay tu report Timing Analyzer: The_System|vga_subsystem|vga_pll|video_pll|
# altera_pll_i|general[1].gpll~PLL_OUTPUT_COUNTER|divclk). Neu Quartus doi
# ten node noi bo nay o lan compile khac, mo report_sdc / Timing Analyzer,
# tim dong "PLL_OUTPUT_COUNTER" ung voi VGA_CLK va cap nhat lai duong dan.
create_generated_clock -name clk_vga \
    -source [get_pins {The_System|vga_subsystem|vga_pll|video_pll|altera_pll_i|general[1].gpll~PLL_OUTPUT_COUNTER|divclk}] \
    [get_ports VGA_CLK]

# Generated clock cho DRAM_CLK - nguon la pin PLL that (tu system_pll nhanh
# sdram_clk, lech pha voi sys_clk 100MHz dung cho logic). Ten pin lay tu
# report: The_System|system_pll|sys_pll|altera_pll_i|general[1].gpll~
# PLL_OUTPUT_COUNTER|divclk.
create_generated_clock -name clk_dram \
    -source [get_pins {The_System|system_pll|sys_pll|altera_pll_i|general[1].gpll~PLL_OUTPUT_COUNTER|divclk}] \
    [get_ports DRAM_CLK]

derive_clock_uncertainty

#========================
# Input Delay
#========================
set_input_delay -max -clock clk_dram 0.500 [get_ports DRAM_DQ*]
set_input_delay -min -clock clk_dram -0.500 [get_ports DRAM_DQ*]

set_input_delay -max -clock tv_27m 3.692 [get_ports TD_DATA*]
set_input_delay -min -clock tv_27m 2.492 [get_ports TD_DATA*]

#========================
# Output Delay
#========================
set_output_delay -max -clock clk_dram 1.500 [get_ports DRAM_DQ*]
set_output_delay -min -clock clk_dram -0.800 [get_ports DRAM_DQ*]

set_output_delay -max -clock clk_vga 0.250 [get_ports VGA_R*]
set_output_delay -min -clock clk_vga -1.500 [get_ports VGA_R*]
set_output_delay -max -clock clk_vga 0.250 [get_ports VGA_G*]
set_output_delay -min -clock clk_vga -1.500 [get_ports VGA_G*]
set_output_delay -max -clock clk_vga 0.250 [get_ports VGA_B*]
set_output_delay -min -clock clk_vga -1.500 [get_ports VGA_B*]

#========================
# Clock Groups (Async domains)
#========================
set_clock_groups -exclusive \
    -group {clk_50 clk2_50 clk3_50 clk4_50} \
    -group [get_clocks {The_System|system_pll|sys_pll|altera_pll_i|general[0].gpll~PLL_OUTPUT_COUNTER|divclk}] \
    -group {clk_dram} \
    -group {clk_vga} \
    -group {tv_27m} \
    -group {hps_usb_clkout} \
    -group {hps_i2c1_sclk} \
    -group {hps_i2c2_sclk}

#========================
# False Paths
#========================
# HPS I/O (neu khong dung truc tiep trong fabric)
set_false_path -from [get_ports {HPS_*}] -to *
set_false_path -from * -to [get_ports {HPS_*}]

# Nut bam, switch
set_false_path -from [get_ports {KEY*}] -to *
set_false_path -from [get_ports {SW*}] -to *

# LED
set_false_path -from * -to [get_ports {LEDR*}]

#========================
# Clock Uncertainty
# clk_vga va clk_dram GIO LA generated clock tu PLL (xem phan tren) nen
# derive_clock_uncertainty (da goi o tren) se TU DONG tinh dung uncertainty
# cho chung -> KHONG duoc set tay de lai (de tay se ghi de gia tri dung
# bang gia tri sai, day chinh la 1 nguyen nhan gay slack am gia tao truoc do).
# Chi con tv_27m la clock nguon ngoai that (khong qua PLL) nen van can khai
# tay bo sung uncertainty cho no.
#========================
set_clock_uncertainty -setup 0.18 -to [get_clocks tv_27m]
set_clock_uncertainty -hold  0.18 -to [get_clocks tv_27m]

#========================
# Ghi chu: NEU pipeline dehazing (dehazing_system_top) van con slack am
# NHO sau khi sua clock nhu tren (vi du con -1..-2 ns), nghia la logic to
# hop trong image_restoration_soc (phep nhan 18x14 bit o Stage 2, hoac
# duong dia chi/du lieu cua transmission_lut 64K-entry ROM o Stage 3 cua
# top-level) van chua du nhanh cho 100 MHz thuc. Khi do can pipeline them
# 1 tang thanh ghi cho phep nhan (r_mult/g_mult/b_mult) hoac tach dia chi
# ROM thanh 2 chu ky, KHONG the fix chi bang SDC.
#========================
