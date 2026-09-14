#========================
# Base Clocks (dung tan so vat ly that: 50 MHz -> 20.000 ns)
#========================
create_clock -period 20.000 -name clk_50  [get_ports CLOCK_50]
create_clock -period 20.000 -name clk2_50 [get_ports CLOCK2_50]
create_clock -period 20.000 -name clk3_50 [get_ports CLOCK3_50]
create_clock -period 20.000 -name clk4_50 [get_ports CLOCK4_50]

# TV Decoder Clock (27 MHz -> 37.037 ns)
create_clock -period 37.037 -name tv_27m [get_ports TD_CLK27]

create_clock -name hps_usb_clkout  -period 16.667 [get_ports HPS_USB_CLKOUT] -add
create_clock -name hps_i2c1_sclk   -period 2500.000 [get_ports HPS_I2C1_SCLK] -add
create_clock -name hps_i2c2_sclk   -period 2500.000 [get_ports HPS_I2C2_SCLK] -add


derive_pll_clocks -create_base_clocks


create_generated_clock -name clk_vga \
    -source [get_pins {The_System|vga_subsystem|vga_pll|video_pll|altera_pll_i|general[1].gpll~PLL_OUTPUT_COUNTER|divclk}] \
    [get_ports VGA_CLK]

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


set_clock_uncertainty -setup 0.18 -to [get_clocks tv_27m]
set_clock_uncertainty -hold  0.18 -to [get_clocks tv_27m]


