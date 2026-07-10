#**************************************************************
# Khóa luận tốt nghiệp: Vision Enhancement System on DE1-SoC
# Target Board: Altera DE1-SoC (Intel Cyclone V)
#**************************************************************

#========================
# Base Clocks
#========================
create_clock -period 20.000 -name clk_50 [get_ports CLOCK_50]
create_clock -period 20.000 -name clk2_50 [get_ports CLOCK2_50]
create_clock -period 20.000 -name clk3_50 [get_ports CLOCK3_50]
create_clock -period 20.000 -name clk4_50 [get_ports CLOCK4_50]

# TV Decoder Clock (27 MHz → 37.037 ns)
create_clock -period 37.037 -name tv_27m [get_ports TD_CLK27]

# DRAM Clock (100 MHz → 10 ns)
create_clock -period 10.000 -name clk_dram [get_ports DRAM_CLK]

# VGA Clock (25.18 MHz → 39.72 ns)
create_clock -period 39.72 -name clk_vga [get_ports VGA_CLK]

# Camera Clock (nếu dùng OV7670/D5M)
# create_clock -period 40.000 -name clk_camera [get_ports CAMERA_PIXCLK]

#========================
# Generated Clocks (PLL)
#========================
derive_pll_clocks
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
set_clock_groups -asynchronous \
    -group {clk_50 clk2_50 clk3_50 clk4_50} \
    -group {clk_dram} \
    -group {clk_vga} \
    -group {tv_27m}

#========================
# False Paths
#========================
# HPS I/O (nếu không dùng)
set_false_path -from [get_ports {HPS_*}] -to *
set_false_path -from * -to [get_ports {HPS_*}]

# Nút bấm, switch
set_false_path -from [get_ports {KEY*}] -to *
set_false_path -from [get_ports {SW*}] -to *

# LED
set_false_path -from * -to [get_ports {LEDR*}]

#========================
# Hold Margin (ép Quartus chèn buffer tránh dữ liệu đến quá sớm)
#========================
set_min_delay 0.5 -from [get_clocks clk_dram] -to [get_clocks clk_dram]
set_min_delay 0.5 -from [get_clocks clk_vga] -to [get_clocks clk_vga]

#========================
# Clock Uncertainty (sửa cú pháp đúng)
#========================
set_clock_uncertainty -setup 0.25 -to [get_clocks clk_dram]
set_clock_uncertainty -hold 0.25 -to [get_clocks clk_dram]

set_clock_uncertainty -setup 0.38 -to [get_clocks clk_vga]
set_clock_uncertainty -hold 0.38 -to [get_clocks clk_vga]

set_clock_uncertainty -setup 0.16 -to [get_clocks tv_27m]
set_clock_uncertainty -hold 0.16 -to [get_clocks tv_27m]
