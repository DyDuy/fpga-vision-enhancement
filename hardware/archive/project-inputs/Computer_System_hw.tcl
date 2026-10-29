# _hw.tcl file for Computer_System
package require -exact qsys 14.0

# module properties
set_module_property NAME {Computer_System_export}
set_module_property DISPLAY_NAME {Computer_System_export_display}

# default module properties
set_module_property VERSION {1.0}
set_module_property GROUP {default group}
set_module_property DESCRIPTION {default description}
set_module_property AUTHOR {author}

set_module_property COMPOSITION_CALLBACK compose
set_module_property opaque_address_map false

proc compose { } {
    # Instances and instance parameters
    # (disabled instances are intentionally culled)
    add_instance ARM_A9_HPS altera_hps 18.1
    set_instance_parameter_value ARM_A9_HPS {ABSTRACT_REAL_COMPARE_TEST} {0}
    set_instance_parameter_value ARM_A9_HPS {ABS_RAM_MEM_INIT_FILENAME} {meminit}
    set_instance_parameter_value ARM_A9_HPS {ACV_PHY_CLK_ADD_FR_PHASE} {0.0}
    set_instance_parameter_value ARM_A9_HPS {AC_PACKAGE_DESKEW} {0}
    set_instance_parameter_value ARM_A9_HPS {AC_ROM_USER_ADD_0} {0_0000_0000_0000}
    set_instance_parameter_value ARM_A9_HPS {AC_ROM_USER_ADD_1} {0_0000_0000_1000}
    set_instance_parameter_value ARM_A9_HPS {ADDR_ORDER} {0}
    set_instance_parameter_value ARM_A9_HPS {ADD_EFFICIENCY_MONITOR} {0}
    set_instance_parameter_value ARM_A9_HPS {ADD_EXTERNAL_SEQ_DEBUG_NIOS} {0}
    set_instance_parameter_value ARM_A9_HPS {ADVANCED_CK_PHASES} {0}
    set_instance_parameter_value ARM_A9_HPS {ADVERTIZE_SEQUENCER_SW_BUILD_FILES} {0}
    set_instance_parameter_value ARM_A9_HPS {AFI_DEBUG_INFO_WIDTH} {32}
    set_instance_parameter_value ARM_A9_HPS {ALTMEMPHY_COMPATIBLE_MODE} {0}
    set_instance_parameter_value ARM_A9_HPS {AP_MODE} {0}
    set_instance_parameter_value ARM_A9_HPS {AP_MODE_EN} {0}
    set_instance_parameter_value ARM_A9_HPS {AUTO_PD_CYCLES} {0}
    set_instance_parameter_value ARM_A9_HPS {AUTO_POWERDN_EN} {0}
    set_instance_parameter_value ARM_A9_HPS {AVL_DATA_WIDTH_PORT} {32 32 32 32 32 32}
    set_instance_parameter_value ARM_A9_HPS {AVL_MAX_SIZE} {4}
    set_instance_parameter_value ARM_A9_HPS {BONDING_OUT_ENABLED} {0}
    set_instance_parameter_value ARM_A9_HPS {BOOTFROMFPGA_Enable} {0}
    set_instance_parameter_value ARM_A9_HPS {BSEL} {1}
    set_instance_parameter_value ARM_A9_HPS {BSEL_EN} {0}
    set_instance_parameter_value ARM_A9_HPS {BYTE_ENABLE} {1}
    set_instance_parameter_value ARM_A9_HPS {C2P_WRITE_CLOCK_ADD_PHASE} {0.0}
    set_instance_parameter_value ARM_A9_HPS {CALIBRATION_MODE} {Skip}
    set_instance_parameter_value ARM_A9_HPS {CALIB_REG_WIDTH} {8}
    set_instance_parameter_value ARM_A9_HPS {CAN0_Mode} {N/A}
    set_instance_parameter_value ARM_A9_HPS {CAN0_PinMuxing} {Unused}
    set_instance_parameter_value ARM_A9_HPS {CAN1_Mode} {N/A}
    set_instance_parameter_value ARM_A9_HPS {CAN1_PinMuxing} {Unused}
    set_instance_parameter_value ARM_A9_HPS {CFG_DATA_REORDERING_TYPE} {INTER_BANK}
    set_instance_parameter_value ARM_A9_HPS {CFG_REORDER_DATA} {1}
    set_instance_parameter_value ARM_A9_HPS {CFG_TCCD_NS} {2.5}
    set_instance_parameter_value ARM_A9_HPS {COMMAND_PHASE} {0.0}
    set_instance_parameter_value ARM_A9_HPS {CONTROLLER_LATENCY} {5}
    set_instance_parameter_value ARM_A9_HPS {CORE_DEBUG_CONNECTION} {EXPORT}
    set_instance_parameter_value ARM_A9_HPS {CPORT_TYPE_PORT} {Bidirectional Bidirectional Bidirectional Bidirectional Bidirectional Bidirectional}
    set_instance_parameter_value ARM_A9_HPS {CSEL} {0}
    set_instance_parameter_value ARM_A9_HPS {CSEL_EN} {0}
    set_instance_parameter_value ARM_A9_HPS {CTI_Enable} {0}
    set_instance_parameter_value ARM_A9_HPS {CTL_AUTOPCH_EN} {0}
    set_instance_parameter_value ARM_A9_HPS {CTL_CMD_QUEUE_DEPTH} {8}
    set_instance_parameter_value ARM_A9_HPS {CTL_CSR_CONNECTION} {INTERNAL_JTAG}
    set_instance_parameter_value ARM_A9_HPS {CTL_CSR_ENABLED} {0}
    set_instance_parameter_value ARM_A9_HPS {CTL_CSR_READ_ONLY} {1}
    set_instance_parameter_value ARM_A9_HPS {CTL_DEEP_POWERDN_EN} {0}
    set_instance_parameter_value ARM_A9_HPS {CTL_DYNAMIC_BANK_ALLOCATION} {0}
    set_instance_parameter_value ARM_A9_HPS {CTL_DYNAMIC_BANK_NUM} {4}
    set_instance_parameter_value ARM_A9_HPS {CTL_ECC_AUTO_CORRECTION_ENABLED} {0}
    set_instance_parameter_value ARM_A9_HPS {CTL_ECC_ENABLED} {0}
    set_instance_parameter_value ARM_A9_HPS {CTL_ENABLE_BURST_INTERRUPT} {0}
    set_instance_parameter_value ARM_A9_HPS {CTL_ENABLE_BURST_TERMINATE} {0}
    set_instance_parameter_value ARM_A9_HPS {CTL_HRB_ENABLED} {0}
    set_instance_parameter_value ARM_A9_HPS {CTL_LOOK_AHEAD_DEPTH} {4}
    set_instance_parameter_value ARM_A9_HPS {CTL_SELF_REFRESH_EN} {0}
    set_instance_parameter_value ARM_A9_HPS {CTL_USR_REFRESH_EN} {0}
    set_instance_parameter_value ARM_A9_HPS {CTL_ZQCAL_EN} {0}
    set_instance_parameter_value ARM_A9_HPS {CUT_NEW_FAMILY_TIMING} {1}
    set_instance_parameter_value ARM_A9_HPS {DAT_DATA_WIDTH} {32}
    set_instance_parameter_value ARM_A9_HPS {DEBUGAPB_Enable} {0}
    set_instance_parameter_value ARM_A9_HPS {DEBUG_MODE} {0}
    set_instance_parameter_value ARM_A9_HPS {DEVICE_DEPTH} {1}
    set_instance_parameter_value ARM_A9_HPS {DEVICE_FAMILY_PARAM} {}
    set_instance_parameter_value ARM_A9_HPS {DISABLE_CHILD_MESSAGING} {0}
    set_instance_parameter_value ARM_A9_HPS {DISCRETE_FLY_BY} {1}
    set_instance_parameter_value ARM_A9_HPS {DLL_SHARING_MODE} {None}
    set_instance_parameter_value ARM_A9_HPS {DMA_Enable} {No No No No No No No No}
    set_instance_parameter_value ARM_A9_HPS {DQS_DQSN_MODE} {DIFFERENTIAL}
    set_instance_parameter_value ARM_A9_HPS {DQ_INPUT_REG_USE_CLKN} {0}
    set_instance_parameter_value ARM_A9_HPS {DUPLICATE_AC} {0}
    set_instance_parameter_value ARM_A9_HPS {ED_EXPORT_SEQ_DEBUG} {0}
    set_instance_parameter_value ARM_A9_HPS {EMAC0_Mode} {N/A}
    set_instance_parameter_value ARM_A9_HPS {EMAC0_PTP} {0}
    set_instance_parameter_value ARM_A9_HPS {EMAC0_PinMuxing} {Unused}
    set_instance_parameter_value ARM_A9_HPS {EMAC1_Mode} {RGMII}
    set_instance_parameter_value ARM_A9_HPS {EMAC1_PTP} {0}
    set_instance_parameter_value ARM_A9_HPS {EMAC1_PinMuxing} {HPS I/O Set 0}
    set_instance_parameter_value ARM_A9_HPS {ENABLE_ABS_RAM_MEM_INIT} {0}
    set_instance_parameter_value ARM_A9_HPS {ENABLE_BONDING} {0}
    set_instance_parameter_value ARM_A9_HPS {ENABLE_BURST_MERGE} {0}
    set_instance_parameter_value ARM_A9_HPS {ENABLE_CTRL_AVALON_INTERFACE} {1}
    set_instance_parameter_value ARM_A9_HPS {ENABLE_DELAY_CHAIN_WRITE} {0}
    set_instance_parameter_value ARM_A9_HPS {ENABLE_EMIT_BFM_MASTER} {0}
    set_instance_parameter_value ARM_A9_HPS {ENABLE_EXPORT_SEQ_DEBUG_BRIDGE} {0}
    set_instance_parameter_value ARM_A9_HPS {ENABLE_EXTRA_REPORTING} {0}
    set_instance_parameter_value ARM_A9_HPS {ENABLE_ISS_PROBES} {0}
    set_instance_parameter_value ARM_A9_HPS {ENABLE_NON_DESTRUCTIVE_CALIB} {0}
    set_instance_parameter_value ARM_A9_HPS {ENABLE_NON_DES_CAL} {0}
    set_instance_parameter_value ARM_A9_HPS {ENABLE_NON_DES_CAL_TEST} {0}
    set_instance_parameter_value ARM_A9_HPS {ENABLE_SEQUENCER_MARGINING_ON_BY_DEFAULT} {0}
    set_instance_parameter_value ARM_A9_HPS {ENABLE_USER_ECC} {0}
    set_instance_parameter_value ARM_A9_HPS {EXPORT_AFI_HALF_CLK} {0}
    set_instance_parameter_value ARM_A9_HPS {EXTRA_SETTINGS} {}
    set_instance_parameter_value ARM_A9_HPS {F2SCLK_COLDRST_Enable} {0}
    set_instance_parameter_value ARM_A9_HPS {F2SCLK_DBGRST_Enable} {0}
    set_instance_parameter_value ARM_A9_HPS {F2SCLK_PERIPHCLK_Enable} {0}
    set_instance_parameter_value ARM_A9_HPS {F2SCLK_SDRAMCLK_Enable} {0}
    set_instance_parameter_value ARM_A9_HPS {F2SCLK_WARMRST_Enable} {0}
    set_instance_parameter_value ARM_A9_HPS {F2SDRAM_Type} {}
    set_instance_parameter_value ARM_A9_HPS {F2SDRAM_Width} {}
    set_instance_parameter_value ARM_A9_HPS {F2SINTERRUPT_Enable} {1}
    set_instance_parameter_value ARM_A9_HPS {F2S_Width} {2}
    set_instance_parameter_value ARM_A9_HPS {FIX_READ_LATENCY} {8}
    set_instance_parameter_value ARM_A9_HPS {FORCED_NON_LDC_ADDR_CMD_MEM_CK_INVERT} {0}
    set_instance_parameter_value ARM_A9_HPS {FORCED_NUM_WRITE_FR_CYCLE_SHIFTS} {0}
    set_instance_parameter_value ARM_A9_HPS {FORCE_DQS_TRACKING} {AUTO}
    set_instance_parameter_value ARM_A9_HPS {FORCE_MAX_LATENCY_COUNT_WIDTH} {0}
    set_instance_parameter_value ARM_A9_HPS {FORCE_SEQUENCER_TCL_DEBUG_MODE} {0}
    set_instance_parameter_value ARM_A9_HPS {FORCE_SHADOW_REGS} {AUTO}
    set_instance_parameter_value ARM_A9_HPS {FORCE_SYNTHESIS_LANGUAGE} {}
    set_instance_parameter_value ARM_A9_HPS {FPGA_PERIPHERAL_OUTPUT_CLOCK_FREQ_EMAC0_GTX_CLK} {125}
    set_instance_parameter_value ARM_A9_HPS {FPGA_PERIPHERAL_OUTPUT_CLOCK_FREQ_EMAC0_MD_CLK} {100.0}
    set_instance_parameter_value ARM_A9_HPS {FPGA_PERIPHERAL_OUTPUT_CLOCK_FREQ_EMAC1_GTX_CLK} {125}
    set_instance_parameter_value ARM_A9_HPS {FPGA_PERIPHERAL_OUTPUT_CLOCK_FREQ_EMAC1_MD_CLK} {100.0}
    set_instance_parameter_value ARM_A9_HPS {FPGA_PERIPHERAL_OUTPUT_CLOCK_FREQ_I2C0_CLK} {100}
    set_instance_parameter_value ARM_A9_HPS {FPGA_PERIPHERAL_OUTPUT_CLOCK_FREQ_I2C1_CLK} {100}
    set_instance_parameter_value ARM_A9_HPS {FPGA_PERIPHERAL_OUTPUT_CLOCK_FREQ_I2C2_CLK} {100}
    set_instance_parameter_value ARM_A9_HPS {FPGA_PERIPHERAL_OUTPUT_CLOCK_FREQ_I2C3_CLK} {100}
    set_instance_parameter_value ARM_A9_HPS {FPGA_PERIPHERAL_OUTPUT_CLOCK_FREQ_QSPI_SCLK_OUT} {100}
    set_instance_parameter_value ARM_A9_HPS {FPGA_PERIPHERAL_OUTPUT_CLOCK_FREQ_SDIO_CCLK} {100}
    set_instance_parameter_value ARM_A9_HPS {FPGA_PERIPHERAL_OUTPUT_CLOCK_FREQ_SPIM0_SCLK_OUT} {100}
    set_instance_parameter_value ARM_A9_HPS {FPGA_PERIPHERAL_OUTPUT_CLOCK_FREQ_SPIM1_SCLK_OUT} {100}
    set_instance_parameter_value ARM_A9_HPS {GPIO_Enable} {No No No No No No No No No Yes No No No No No No No No No No No No No No No No No No No No No No No No No Yes No No No No Yes Yes No No No No No No Yes No No No No Yes Yes No No No No No No Yes No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No}
    set_instance_parameter_value ARM_A9_HPS {GP_Enable} {0}
    set_instance_parameter_value ARM_A9_HPS {HARD_EMIF} {1}
    set_instance_parameter_value ARM_A9_HPS {HCX_COMPAT_MODE} {0}
    set_instance_parameter_value ARM_A9_HPS {HHP_HPS} {1}
    set_instance_parameter_value ARM_A9_HPS {HHP_HPS_SIMULATION} {0}
    set_instance_parameter_value ARM_A9_HPS {HHP_HPS_VERIFICATION} {0}
    set_instance_parameter_value ARM_A9_HPS {HLGPI_Enable} {0}
    set_instance_parameter_value ARM_A9_HPS {HPS_PROTOCOL} {DDR3}
    set_instance_parameter_value ARM_A9_HPS {I2C0_Mode} {I2C}
    set_instance_parameter_value ARM_A9_HPS {I2C0_PinMuxing} {HPS I/O Set 0}
    set_instance_parameter_value ARM_A9_HPS {I2C1_Mode} {I2C}
    set_instance_parameter_value ARM_A9_HPS {I2C1_PinMuxing} {HPS I/O Set 0}
    set_instance_parameter_value ARM_A9_HPS {I2C2_Mode} {N/A}
    set_instance_parameter_value ARM_A9_HPS {I2C2_PinMuxing} {Unused}
    set_instance_parameter_value ARM_A9_HPS {I2C3_Mode} {N/A}
    set_instance_parameter_value ARM_A9_HPS {I2C3_PinMuxing} {Unused}
    set_instance_parameter_value ARM_A9_HPS {INCLUDE_BOARD_DELAY_MODEL} {0}
    set_instance_parameter_value ARM_A9_HPS {INCLUDE_MULTIRANK_BOARD_DELAY_MODEL} {0}
    set_instance_parameter_value ARM_A9_HPS {IS_ES_DEVICE} {0}
    set_instance_parameter_value ARM_A9_HPS {LOANIO_Enable} {No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No No}
    set_instance_parameter_value ARM_A9_HPS {LOCAL_ID_WIDTH} {8}
    set_instance_parameter_value ARM_A9_HPS {LRDIMM_EXTENDED_CONFIG} {0x000000000000000000}
    set_instance_parameter_value ARM_A9_HPS {LWH2F_Enable} {true}
    set_instance_parameter_value ARM_A9_HPS {MARGIN_VARIATION_TEST} {0}
    set_instance_parameter_value ARM_A9_HPS {MAX_PENDING_RD_CMD} {32}
    set_instance_parameter_value ARM_A9_HPS {MAX_PENDING_WR_CMD} {16}
    set_instance_parameter_value ARM_A9_HPS {MEM_ASR} {Manual}
    set_instance_parameter_value ARM_A9_HPS {MEM_ATCL} {Disabled}
    set_instance_parameter_value ARM_A9_HPS {MEM_AUTO_LEVELING_MODE} {1}
    set_instance_parameter_value ARM_A9_HPS {MEM_BANKADDR_WIDTH} {3}
    set_instance_parameter_value ARM_A9_HPS {MEM_BL} {OTF}
    set_instance_parameter_value ARM_A9_HPS {MEM_BT} {Sequential}
    set_instance_parameter_value ARM_A9_HPS {MEM_CK_PHASE} {0.0}
    set_instance_parameter_value ARM_A9_HPS {MEM_CK_WIDTH} {1}
    set_instance_parameter_value ARM_A9_HPS {MEM_CLK_EN_WIDTH} {1}
    set_instance_parameter_value ARM_A9_HPS {MEM_CLK_FREQ} {400.0}
    set_instance_parameter_value ARM_A9_HPS {MEM_CLK_FREQ_MAX} {800.0}
    set_instance_parameter_value ARM_A9_HPS {MEM_COL_ADDR_WIDTH} {10}
    set_instance_parameter_value ARM_A9_HPS {MEM_CS_WIDTH} {1}
    set_instance_parameter_value ARM_A9_HPS {MEM_DEVICE} {MISSING_MODEL}
    set_instance_parameter_value ARM_A9_HPS {MEM_DLL_EN} {1}
    set_instance_parameter_value ARM_A9_HPS {MEM_DQ_PER_DQS} {8}
    set_instance_parameter_value ARM_A9_HPS {MEM_DQ_WIDTH} {32}
    set_instance_parameter_value ARM_A9_HPS {MEM_DRV_STR} {RZQ/7}
    set_instance_parameter_value ARM_A9_HPS {MEM_FORMAT} {DISCRETE}
    set_instance_parameter_value ARM_A9_HPS {MEM_GUARANTEED_WRITE_INIT} {0}
    set_instance_parameter_value ARM_A9_HPS {MEM_IF_BOARD_BASE_DELAY} {10}
    set_instance_parameter_value ARM_A9_HPS {MEM_IF_DM_PINS_EN} {1}
    set_instance_parameter_value ARM_A9_HPS {MEM_IF_DQSN_EN} {1}
    set_instance_parameter_value ARM_A9_HPS {MEM_IF_SIM_VALID_WINDOW} {0}
    set_instance_parameter_value ARM_A9_HPS {MEM_INIT_EN} {0}
    set_instance_parameter_value ARM_A9_HPS {MEM_INIT_FILE} {}
    set_instance_parameter_value ARM_A9_HPS {MEM_MIRROR_ADDRESSING} {0}
    set_instance_parameter_value ARM_A9_HPS {MEM_NUMBER_OF_DIMMS} {1}
    set_instance_parameter_value ARM_A9_HPS {MEM_NUMBER_OF_RANKS_PER_DEVICE} {1}
    set_instance_parameter_value ARM_A9_HPS {MEM_NUMBER_OF_RANKS_PER_DIMM} {1}
    set_instance_parameter_value ARM_A9_HPS {MEM_PD} {DLL off}
    set_instance_parameter_value ARM_A9_HPS {MEM_RANK_MULTIPLICATION_FACTOR} {1}
    set_instance_parameter_value ARM_A9_HPS {MEM_ROW_ADDR_WIDTH} {15}
    set_instance_parameter_value ARM_A9_HPS {MEM_RTT_NOM} {RZQ/4}
    set_instance_parameter_value ARM_A9_HPS {MEM_RTT_WR} {RZQ/4}
    set_instance_parameter_value ARM_A9_HPS {MEM_SRT} {Normal}
    set_instance_parameter_value ARM_A9_HPS {MEM_TCL} {11}
    set_instance_parameter_value ARM_A9_HPS {MEM_TFAW_NS} {30.0}
    set_instance_parameter_value ARM_A9_HPS {MEM_TINIT_US} {500}
    set_instance_parameter_value ARM_A9_HPS {MEM_TMRD_CK} {4}
    set_instance_parameter_value ARM_A9_HPS {MEM_TRAS_NS} {35.0}
    set_instance_parameter_value ARM_A9_HPS {MEM_TRCD_NS} {13.75}
    set_instance_parameter_value ARM_A9_HPS {MEM_TREFI_US} {7.8}
    set_instance_parameter_value ARM_A9_HPS {MEM_TRFC_NS} {260.0}
    set_instance_parameter_value ARM_A9_HPS {MEM_TRP_NS} {13.75}
    set_instance_parameter_value ARM_A9_HPS {MEM_TRRD_NS} {7.5}
    set_instance_parameter_value ARM_A9_HPS {MEM_TRTP_NS} {7.5}
    set_instance_parameter_value ARM_A9_HPS {MEM_TWR_NS} {15.0}
    set_instance_parameter_value ARM_A9_HPS {MEM_TWTR} {4}
    set_instance_parameter_value ARM_A9_HPS {MEM_USER_LEVELING_MODE} {Leveling}
    set_instance_parameter_value ARM_A9_HPS {MEM_VENDOR} {JEDEC}
    set_instance_parameter_value ARM_A9_HPS {MEM_VERBOSE} {1}
    set_instance_parameter_value ARM_A9_HPS {MEM_VOLTAGE} {1.5V DDR3}
    set_instance_parameter_value ARM_A9_HPS {MEM_WTCL} {8}
    set_instance_parameter_value ARM_A9_HPS {MPU_EVENTS_Enable} {0}
    set_instance_parameter_value ARM_A9_HPS {MRS_MIRROR_PING_PONG_ATSO} {0}
    set_instance_parameter_value ARM_A9_HPS {MULTICAST_EN} {0}
    set_instance_parameter_value ARM_A9_HPS {NAND_Mode} {N/A}
    set_instance_parameter_value ARM_A9_HPS {NAND_PinMuxing} {Unused}
    set_instance_parameter_value ARM_A9_HPS {NEXTGEN} {1}
    set_instance_parameter_value ARM_A9_HPS {NIOS_ROM_DATA_WIDTH} {32}
    set_instance_parameter_value ARM_A9_HPS {NUM_DLL_SHARING_INTERFACES} {1}
    set_instance_parameter_value ARM_A9_HPS {NUM_EXTRA_REPORT_PATH} {10}
    set_instance_parameter_value ARM_A9_HPS {NUM_OCT_SHARING_INTERFACES} {1}
    set_instance_parameter_value ARM_A9_HPS {NUM_OF_PORTS} {1}
    set_instance_parameter_value ARM_A9_HPS {NUM_PLL_SHARING_INTERFACES} {1}
    set_instance_parameter_value ARM_A9_HPS {OCT_SHARING_MODE} {None}
    set_instance_parameter_value ARM_A9_HPS {P2C_READ_CLOCK_ADD_PHASE} {0.0}
    set_instance_parameter_value ARM_A9_HPS {PACKAGE_DESKEW} {0}
    set_instance_parameter_value ARM_A9_HPS {PARSE_FRIENDLY_DEVICE_FAMILY_PARAM} {}
    set_instance_parameter_value ARM_A9_HPS {PARSE_FRIENDLY_DEVICE_FAMILY_PARAM_VALID} {0}
    set_instance_parameter_value ARM_A9_HPS {PHY_CSR_CONNECTION} {INTERNAL_JTAG}
    set_instance_parameter_value ARM_A9_HPS {PHY_CSR_ENABLED} {0}
    set_instance_parameter_value ARM_A9_HPS {PHY_ONLY} {0}
    set_instance_parameter_value ARM_A9_HPS {PINGPONGPHY_EN} {0}
    set_instance_parameter_value ARM_A9_HPS {PLL_ADDR_CMD_CLK_DIV_PARAM} {0}
    set_instance_parameter_value ARM_A9_HPS {PLL_ADDR_CMD_CLK_FREQ_PARAM} {0.0}
    set_instance_parameter_value ARM_A9_HPS {PLL_ADDR_CMD_CLK_FREQ_SIM_STR_PARAM} {}
    set_instance_parameter_value ARM_A9_HPS {PLL_ADDR_CMD_CLK_MULT_PARAM} {0}
    set_instance_parameter_value ARM_A9_HPS {PLL_ADDR_CMD_CLK_PHASE_PS_PARAM} {0}
    set_instance_parameter_value ARM_A9_HPS {PLL_ADDR_CMD_CLK_PHASE_PS_SIM_STR_PARAM} {}
    set_instance_parameter_value ARM_A9_HPS {PLL_AFI_CLK_DIV_PARAM} {0}
    set_instance_parameter_value ARM_A9_HPS {PLL_AFI_CLK_FREQ_PARAM} {0.0}
    set_instance_parameter_value ARM_A9_HPS {PLL_AFI_CLK_FREQ_SIM_STR_PARAM} {}
    set_instance_parameter_value ARM_A9_HPS {PLL_AFI_CLK_MULT_PARAM} {0}
    set_instance_parameter_value ARM_A9_HPS {PLL_AFI_CLK_PHASE_PS_PARAM} {0}
    set_instance_parameter_value ARM_A9_HPS {PLL_AFI_CLK_PHASE_PS_SIM_STR_PARAM} {}
    set_instance_parameter_value ARM_A9_HPS {PLL_AFI_HALF_CLK_DIV_PARAM} {0}
    set_instance_parameter_value ARM_A9_HPS {PLL_AFI_HALF_CLK_FREQ_PARAM} {0.0}
    set_instance_parameter_value ARM_A9_HPS {PLL_AFI_HALF_CLK_FREQ_SIM_STR_PARAM} {}
    set_instance_parameter_value ARM_A9_HPS {PLL_AFI_HALF_CLK_MULT_PARAM} {0}
    set_instance_parameter_value ARM_A9_HPS {PLL_AFI_HALF_CLK_PHASE_PS_PARAM} {0}
    set_instance_parameter_value ARM_A9_HPS {PLL_AFI_HALF_CLK_PHASE_PS_SIM_STR_PARAM} {}
    set_instance_parameter_value ARM_A9_HPS {PLL_AFI_PHY_CLK_DIV_PARAM} {0}
    set_instance_parameter_value ARM_A9_HPS {PLL_AFI_PHY_CLK_FREQ_PARAM} {0.0}
    set_instance_parameter_value ARM_A9_HPS {PLL_AFI_PHY_CLK_FREQ_SIM_STR_PARAM} {}
    set_instance_parameter_value ARM_A9_HPS {PLL_AFI_PHY_CLK_MULT_PARAM} {0}
    set_instance_parameter_value ARM_A9_HPS {PLL_AFI_PHY_CLK_PHASE_PS_PARAM} {0}
    set_instance_parameter_value ARM_A9_HPS {PLL_AFI_PHY_CLK_PHASE_PS_SIM_STR_PARAM} {}
    set_instance_parameter_value ARM_A9_HPS {PLL_C2P_WRITE_CLK_DIV_PARAM} {0}
    set_instance_parameter_value ARM_A9_HPS {PLL_C2P_WRITE_CLK_FREQ_PARAM} {0.0}
    set_instance_parameter_value ARM_A9_HPS {PLL_C2P_WRITE_CLK_FREQ_SIM_STR_PARAM} {}
    set_instance_parameter_value ARM_A9_HPS {PLL_C2P_WRITE_CLK_MULT_PARAM} {0}
    set_instance_parameter_value ARM_A9_HPS {PLL_C2P_WRITE_CLK_PHASE_PS_PARAM} {0}
    set_instance_parameter_value ARM_A9_HPS {PLL_C2P_WRITE_CLK_PHASE_PS_SIM_STR_PARAM} {}
    set_instance_parameter_value ARM_A9_HPS {PLL_CLK_PARAM_VALID} {0}
    set_instance_parameter_value ARM_A9_HPS {PLL_CONFIG_CLK_DIV_PARAM} {0}
    set_instance_parameter_value ARM_A9_HPS {PLL_CONFIG_CLK_FREQ_PARAM} {0.0}
    set_instance_parameter_value ARM_A9_HPS {PLL_CONFIG_CLK_FREQ_SIM_STR_PARAM} {}
    set_instance_parameter_value ARM_A9_HPS {PLL_CONFIG_CLK_MULT_PARAM} {0}
    set_instance_parameter_value ARM_A9_HPS {PLL_CONFIG_CLK_PHASE_PS_PARAM} {0}
    set_instance_parameter_value ARM_A9_HPS {PLL_CONFIG_CLK_PHASE_PS_SIM_STR_PARAM} {}
    set_instance_parameter_value ARM_A9_HPS {PLL_DR_CLK_DIV_PARAM} {0}
    set_instance_parameter_value ARM_A9_HPS {PLL_DR_CLK_FREQ_PARAM} {0.0}
    set_instance_parameter_value ARM_A9_HPS {PLL_DR_CLK_FREQ_SIM_STR_PARAM} {}
    set_instance_parameter_value ARM_A9_HPS {PLL_DR_CLK_MULT_PARAM} {0}
    set_instance_parameter_value ARM_A9_HPS {PLL_DR_CLK_PHASE_PS_PARAM} {0}
    set_instance_parameter_value ARM_A9_HPS {PLL_DR_CLK_PHASE_PS_SIM_STR_PARAM} {}
    set_instance_parameter_value ARM_A9_HPS {PLL_HR_CLK_DIV_PARAM} {0}
    set_instance_parameter_value ARM_A9_HPS {PLL_HR_CLK_FREQ_PARAM} {0.0}
    set_instance_parameter_value ARM_A9_HPS {PLL_HR_CLK_FREQ_SIM_STR_PARAM} {}
    set_instance_parameter_value ARM_A9_HPS {PLL_HR_CLK_MULT_PARAM} {0}
    set_instance_parameter_value ARM_A9_HPS {PLL_HR_CLK_PHASE_PS_PARAM} {0}
    set_instance_parameter_value ARM_A9_HPS {PLL_HR_CLK_PHASE_PS_SIM_STR_PARAM} {}
    set_instance_parameter_value ARM_A9_HPS {PLL_LOCATION} {Top_Bottom}
    set_instance_parameter_value ARM_A9_HPS {PLL_MEM_CLK_DIV_PARAM} {0}
    set_instance_parameter_value ARM_A9_HPS {PLL_MEM_CLK_FREQ_PARAM} {0.0}
    set_instance_parameter_value ARM_A9_HPS {PLL_MEM_CLK_FREQ_SIM_STR_PARAM} {}
    set_instance_parameter_value ARM_A9_HPS {PLL_MEM_CLK_MULT_PARAM} {0}
    set_instance_parameter_value ARM_A9_HPS {PLL_MEM_CLK_PHASE_PS_PARAM} {0}
    set_instance_parameter_value ARM_A9_HPS {PLL_MEM_CLK_PHASE_PS_SIM_STR_PARAM} {}
    set_instance_parameter_value ARM_A9_HPS {PLL_NIOS_CLK_DIV_PARAM} {0}
    set_instance_parameter_value ARM_A9_HPS {PLL_NIOS_CLK_FREQ_PARAM} {0.0}
    set_instance_parameter_value ARM_A9_HPS {PLL_NIOS_CLK_FREQ_SIM_STR_PARAM} {}
    set_instance_parameter_value ARM_A9_HPS {PLL_NIOS_CLK_MULT_PARAM} {0}
    set_instance_parameter_value ARM_A9_HPS {PLL_NIOS_CLK_PHASE_PS_PARAM} {0}
    set_instance_parameter_value ARM_A9_HPS {PLL_NIOS_CLK_PHASE_PS_SIM_STR_PARAM} {}
    set_instance_parameter_value ARM_A9_HPS {PLL_P2C_READ_CLK_DIV_PARAM} {0}
    set_instance_parameter_value ARM_A9_HPS {PLL_P2C_READ_CLK_FREQ_PARAM} {0.0}
    set_instance_parameter_value ARM_A9_HPS {PLL_P2C_READ_CLK_FREQ_SIM_STR_PARAM} {}
    set_instance_parameter_value ARM_A9_HPS {PLL_P2C_READ_CLK_MULT_PARAM} {0}
    set_instance_parameter_value ARM_A9_HPS {PLL_P2C_READ_CLK_PHASE_PS_PARAM} {0}
    set_instance_parameter_value ARM_A9_HPS {PLL_P2C_READ_CLK_PHASE_PS_SIM_STR_PARAM} {}
    set_instance_parameter_value ARM_A9_HPS {PLL_SHARING_MODE} {None}
    set_instance_parameter_value ARM_A9_HPS {PLL_WRITE_CLK_DIV_PARAM} {0}
    set_instance_parameter_value ARM_A9_HPS {PLL_WRITE_CLK_FREQ_PARAM} {0.0}
    set_instance_parameter_value ARM_A9_HPS {PLL_WRITE_CLK_FREQ_SIM_STR_PARAM} {}
    set_instance_parameter_value ARM_A9_HPS {PLL_WRITE_CLK_MULT_PARAM} {0}
    set_instance_parameter_value ARM_A9_HPS {PLL_WRITE_CLK_PHASE_PS_PARAM} {0}
    set_instance_parameter_value ARM_A9_HPS {PLL_WRITE_CLK_PHASE_PS_SIM_STR_PARAM} {}
    set_instance_parameter_value ARM_A9_HPS {POWER_OF_TWO_BUS} {0}
    set_instance_parameter_value ARM_A9_HPS {PRIORITY_PORT} {1 1 1 1 1 1}
    set_instance_parameter_value ARM_A9_HPS {QSPI_Mode} {1 SS}
    set_instance_parameter_value ARM_A9_HPS {QSPI_PinMuxing} {HPS I/O Set 0}
    set_instance_parameter_value ARM_A9_HPS {RATE} {Full}
    set_instance_parameter_value ARM_A9_HPS {RDIMM_CONFIG} {0000000000000000}
    set_instance_parameter_value ARM_A9_HPS {READ_DQ_DQS_CLOCK_SOURCE} {INVERTED_DQS_BUS}
    set_instance_parameter_value ARM_A9_HPS {READ_FIFO_SIZE} {8}
    set_instance_parameter_value ARM_A9_HPS {REFRESH_BURST_VALIDATION} {0}
    set_instance_parameter_value ARM_A9_HPS {REFRESH_INTERVAL} {15000}
    set_instance_parameter_value ARM_A9_HPS {REF_CLK_FREQ} {25.0}
    set_instance_parameter_value ARM_A9_HPS {REF_CLK_FREQ_MAX_PARAM} {0.0}
    set_instance_parameter_value ARM_A9_HPS {REF_CLK_FREQ_MIN_PARAM} {0.0}
    set_instance_parameter_value ARM_A9_HPS {REF_CLK_FREQ_PARAM_VALID} {0}
    set_instance_parameter_value ARM_A9_HPS {S2FCLK_COLDRST_Enable} {0}
    set_instance_parameter_value ARM_A9_HPS {S2FCLK_PENDINGRST_Enable} {0}
    set_instance_parameter_value ARM_A9_HPS {S2FCLK_USER0CLK_Enable} {0}
    set_instance_parameter_value ARM_A9_HPS {S2FCLK_USER1CLK_Enable} {0}
    set_instance_parameter_value ARM_A9_HPS {S2FCLK_USER1CLK_FREQ} {100.0}
    set_instance_parameter_value ARM_A9_HPS {S2FCLK_USER2CLK} {5}
    set_instance_parameter_value ARM_A9_HPS {S2FCLK_USER2CLK_Enable} {0}
    set_instance_parameter_value ARM_A9_HPS {S2FCLK_USER2CLK_FREQ} {100.0}
    set_instance_parameter_value ARM_A9_HPS {S2FINTERRUPT_CAN_Enable} {0}
    set_instance_parameter_value ARM_A9_HPS {S2FINTERRUPT_CLOCKPERIPHERAL_Enable} {0}
    set_instance_parameter_value ARM_A9_HPS {S2FINTERRUPT_CTI_Enable} {0}
    set_instance_parameter_value ARM_A9_HPS {S2FINTERRUPT_DMA_Enable} {0}
    set_instance_parameter_value ARM_A9_HPS {S2FINTERRUPT_EMAC_Enable} {0}
    set_instance_parameter_value ARM_A9_HPS {S2FINTERRUPT_FPGAMANAGER_Enable} {0}
    set_instance_parameter_value ARM_A9_HPS {S2FINTERRUPT_GPIO_Enable} {0}
    set_instance_parameter_value ARM_A9_HPS {S2FINTERRUPT_I2CEMAC_Enable} {0}
    set_instance_parameter_value ARM_A9_HPS {S2FINTERRUPT_I2CPERIPHERAL_Enable} {0}
    set_instance_parameter_value ARM_A9_HPS {S2FINTERRUPT_L4TIMER_Enable} {0}
    set_instance_parameter_value ARM_A9_HPS {S2FINTERRUPT_NAND_Enable} {0}
    set_instance_parameter_value ARM_A9_HPS {S2FINTERRUPT_OSCTIMER_Enable} {0}
    set_instance_parameter_value ARM_A9_HPS {S2FINTERRUPT_QSPI_Enable} {0}
    set_instance_parameter_value ARM_A9_HPS {S2FINTERRUPT_SDMMC_Enable} {0}
    set_instance_parameter_value ARM_A9_HPS {S2FINTERRUPT_SPIMASTER_Enable} {0}
    set_instance_parameter_value ARM_A9_HPS {S2FINTERRUPT_SPISLAVE_Enable} {0}
    set_instance_parameter_value ARM_A9_HPS {S2FINTERRUPT_UART_Enable} {0}
    set_instance_parameter_value ARM_A9_HPS {S2FINTERRUPT_USB_Enable} {0}
    set_instance_parameter_value ARM_A9_HPS {S2FINTERRUPT_WATCHDOG_Enable} {0}
    set_instance_parameter_value ARM_A9_HPS {S2F_Width} {3}
    set_instance_parameter_value ARM_A9_HPS {SDIO_Mode} {4-bit Data}
    set_instance_parameter_value ARM_A9_HPS {SDIO_PinMuxing} {HPS I/O Set 0}
    set_instance_parameter_value ARM_A9_HPS {SEQUENCER_TYPE} {NIOS}
    set_instance_parameter_value ARM_A9_HPS {SEQ_MODE} {0}
    set_instance_parameter_value ARM_A9_HPS {SKIP_MEM_INIT} {1}
    set_instance_parameter_value ARM_A9_HPS {SOPC_COMPAT_RESET} {0}
    set_instance_parameter_value ARM_A9_HPS {SPEED_GRADE} {7}
    set_instance_parameter_value ARM_A9_HPS {SPIM0_Mode} {N/A}
    set_instance_parameter_value ARM_A9_HPS {SPIM0_PinMuxing} {Unused}
    set_instance_parameter_value ARM_A9_HPS {SPIM1_Mode} {Single Slave Select}
    set_instance_parameter_value ARM_A9_HPS {SPIM1_PinMuxing} {HPS I/O Set 0}
    set_instance_parameter_value ARM_A9_HPS {SPIS0_Mode} {N/A}
    set_instance_parameter_value ARM_A9_HPS {SPIS0_PinMuxing} {Unused}
    set_instance_parameter_value ARM_A9_HPS {SPIS1_Mode} {N/A}
    set_instance_parameter_value ARM_A9_HPS {SPIS1_PinMuxing} {Unused}
    set_instance_parameter_value ARM_A9_HPS {STARVE_LIMIT} {10}
    set_instance_parameter_value ARM_A9_HPS {STM_Enable} {0}
    set_instance_parameter_value ARM_A9_HPS {TEST_Enable} {0}
    set_instance_parameter_value ARM_A9_HPS {TIMING_BOARD_AC_EYE_REDUCTION_H} {0.0}
    set_instance_parameter_value ARM_A9_HPS {TIMING_BOARD_AC_EYE_REDUCTION_SU} {0.0}
    set_instance_parameter_value ARM_A9_HPS {TIMING_BOARD_AC_SKEW} {0.03}
    set_instance_parameter_value ARM_A9_HPS {TIMING_BOARD_AC_SLEW_RATE} {1.0}
    set_instance_parameter_value ARM_A9_HPS {TIMING_BOARD_AC_TO_CK_SKEW} {0.0}
    set_instance_parameter_value ARM_A9_HPS {TIMING_BOARD_CK_CKN_SLEW_RATE} {2.0}
    set_instance_parameter_value ARM_A9_HPS {TIMING_BOARD_DELTA_DQS_ARRIVAL_TIME} {0.0}
    set_instance_parameter_value ARM_A9_HPS {TIMING_BOARD_DELTA_READ_DQS_ARRIVAL_TIME} {0.0}
    set_instance_parameter_value ARM_A9_HPS {TIMING_BOARD_DERATE_METHOD} {AUTO}
    set_instance_parameter_value ARM_A9_HPS {TIMING_BOARD_DQS_DQSN_SLEW_RATE} {2.0}
    set_instance_parameter_value ARM_A9_HPS {TIMING_BOARD_DQ_EYE_REDUCTION} {0.0}
    set_instance_parameter_value ARM_A9_HPS {TIMING_BOARD_DQ_SLEW_RATE} {1.0}
    set_instance_parameter_value ARM_A9_HPS {TIMING_BOARD_DQ_TO_DQS_SKEW} {0.0}
    set_instance_parameter_value ARM_A9_HPS {TIMING_BOARD_ISI_METHOD} {AUTO}
    set_instance_parameter_value ARM_A9_HPS {TIMING_BOARD_MAX_CK_DELAY} {0.03}
    set_instance_parameter_value ARM_A9_HPS {TIMING_BOARD_MAX_DQS_DELAY} {0.02}
    set_instance_parameter_value ARM_A9_HPS {TIMING_BOARD_READ_DQ_EYE_REDUCTION} {0.0}
    set_instance_parameter_value ARM_A9_HPS {TIMING_BOARD_SKEW_BETWEEN_DIMMS} {0.05}
    set_instance_parameter_value ARM_A9_HPS {TIMING_BOARD_SKEW_BETWEEN_DQS} {0.08}
    set_instance_parameter_value ARM_A9_HPS {TIMING_BOARD_SKEW_CKDQS_DIMM_MAX} {0.16}
    set_instance_parameter_value ARM_A9_HPS {TIMING_BOARD_SKEW_CKDQS_DIMM_MIN} {0.09}
    set_instance_parameter_value ARM_A9_HPS {TIMING_BOARD_SKEW_WITHIN_DQS} {0.01}
    set_instance_parameter_value ARM_A9_HPS {TIMING_BOARD_TDH} {0.0}
    set_instance_parameter_value ARM_A9_HPS {TIMING_BOARD_TDS} {0.0}
    set_instance_parameter_value ARM_A9_HPS {TIMING_BOARD_TIH} {0.0}
    set_instance_parameter_value ARM_A9_HPS {TIMING_BOARD_TIS} {0.0}
    set_instance_parameter_value ARM_A9_HPS {TIMING_TDH} {65}
    set_instance_parameter_value ARM_A9_HPS {TIMING_TDQSCK} {255}
    set_instance_parameter_value ARM_A9_HPS {TIMING_TDQSCKDL} {1200}
    set_instance_parameter_value ARM_A9_HPS {TIMING_TDQSCKDM} {900}
    set_instance_parameter_value ARM_A9_HPS {TIMING_TDQSCKDS} {450}
    set_instance_parameter_value ARM_A9_HPS {TIMING_TDQSH} {0.35}
    set_instance_parameter_value ARM_A9_HPS {TIMING_TDQSQ} {125}
    set_instance_parameter_value ARM_A9_HPS {TIMING_TDQSS} {0.25}
    set_instance_parameter_value ARM_A9_HPS {TIMING_TDS} {30}
    set_instance_parameter_value ARM_A9_HPS {TIMING_TDSH} {0.2}
    set_instance_parameter_value ARM_A9_HPS {TIMING_TDSS} {0.2}
    set_instance_parameter_value ARM_A9_HPS {TIMING_TIH} {140}
    set_instance_parameter_value ARM_A9_HPS {TIMING_TIS} {180}
    set_instance_parameter_value ARM_A9_HPS {TIMING_TQH} {0.38}
    set_instance_parameter_value ARM_A9_HPS {TIMING_TQHS} {300}
    set_instance_parameter_value ARM_A9_HPS {TIMING_TQSH} {0.4}
    set_instance_parameter_value ARM_A9_HPS {TPIUFPGA_Enable} {0}
    set_instance_parameter_value ARM_A9_HPS {TPIUFPGA_alt} {0}
    set_instance_parameter_value ARM_A9_HPS {TRACE_Mode} {N/A}
    set_instance_parameter_value ARM_A9_HPS {TRACE_PinMuxing} {Unused}
    set_instance_parameter_value ARM_A9_HPS {TRACKING_ERROR_TEST} {0}
    set_instance_parameter_value ARM_A9_HPS {TRACKING_WATCH_TEST} {0}
    set_instance_parameter_value ARM_A9_HPS {TREFI} {35100}
    set_instance_parameter_value ARM_A9_HPS {TRFC} {350}
    set_instance_parameter_value ARM_A9_HPS {UART0_Mode} {No Flow Control}
    set_instance_parameter_value ARM_A9_HPS {UART0_PinMuxing} {HPS I/O Set 0}
    set_instance_parameter_value ARM_A9_HPS {UART1_Mode} {N/A}
    set_instance_parameter_value ARM_A9_HPS {UART1_PinMuxing} {Unused}
    set_instance_parameter_value ARM_A9_HPS {USB0_Mode} {N/A}
    set_instance_parameter_value ARM_A9_HPS {USB0_PinMuxing} {Unused}
    set_instance_parameter_value ARM_A9_HPS {USB1_Mode} {SDR}
    set_instance_parameter_value ARM_A9_HPS {USB1_PinMuxing} {HPS I/O Set 0}
    set_instance_parameter_value ARM_A9_HPS {USER_DEBUG_LEVEL} {1}
    set_instance_parameter_value ARM_A9_HPS {USE_AXI_ADAPTOR} {0}
    set_instance_parameter_value ARM_A9_HPS {USE_FAKE_PHY} {0}
    set_instance_parameter_value ARM_A9_HPS {USE_MEM_CLK_FREQ} {0}
    set_instance_parameter_value ARM_A9_HPS {USE_MM_ADAPTOR} {1}
    set_instance_parameter_value ARM_A9_HPS {USE_SEQUENCER_BFM} {0}
    set_instance_parameter_value ARM_A9_HPS {WEIGHT_PORT} {0 0 0 0 0 0}
    set_instance_parameter_value ARM_A9_HPS {WRBUFFER_ADDR_WIDTH} {6}
    set_instance_parameter_value ARM_A9_HPS {can0_clk_div} {1}
    set_instance_parameter_value ARM_A9_HPS {can1_clk_div} {1}
    set_instance_parameter_value ARM_A9_HPS {configure_advanced_parameters} {0}
    set_instance_parameter_value ARM_A9_HPS {customize_device_pll_info} {0}
    set_instance_parameter_value ARM_A9_HPS {dbctrl_stayosc1} {1}
    set_instance_parameter_value ARM_A9_HPS {dbg_at_clk_div} {0}
    set_instance_parameter_value ARM_A9_HPS {dbg_clk_div} {1}
    set_instance_parameter_value ARM_A9_HPS {dbg_trace_clk_div} {0}
    set_instance_parameter_value ARM_A9_HPS {desired_can0_clk_mhz} {100.0}
    set_instance_parameter_value ARM_A9_HPS {desired_can1_clk_mhz} {100.0}
    set_instance_parameter_value ARM_A9_HPS {desired_cfg_clk_mhz} {100.0}
    set_instance_parameter_value ARM_A9_HPS {desired_emac0_clk_mhz} {250.0}
    set_instance_parameter_value ARM_A9_HPS {desired_emac1_clk_mhz} {250.0}
    set_instance_parameter_value ARM_A9_HPS {desired_gpio_db_clk_hz} {32000}
    set_instance_parameter_value ARM_A9_HPS {desired_l4_mp_clk_mhz} {100.0}
    set_instance_parameter_value ARM_A9_HPS {desired_l4_sp_clk_mhz} {100.0}
    set_instance_parameter_value ARM_A9_HPS {desired_mpu_clk_mhz} {800.0}
    set_instance_parameter_value ARM_A9_HPS {desired_nand_clk_mhz} {12.5}
    set_instance_parameter_value ARM_A9_HPS {desired_qspi_clk_mhz} {400.0}
    set_instance_parameter_value ARM_A9_HPS {desired_sdmmc_clk_mhz} {200.0}
    set_instance_parameter_value ARM_A9_HPS {desired_spi_m_clk_mhz} {200.0}
    set_instance_parameter_value ARM_A9_HPS {desired_usb_mp_clk_mhz} {200.0}
    set_instance_parameter_value ARM_A9_HPS {device_pll_info_manual} {{320000000 1600000000} {320000000 1000000000} {800000000 400000000 400000000}}
    set_instance_parameter_value ARM_A9_HPS {eosc1_clk_mhz} {25.0}
    set_instance_parameter_value ARM_A9_HPS {eosc2_clk_mhz} {25.0}
    set_instance_parameter_value ARM_A9_HPS {gpio_db_clk_div} {6249}
    set_instance_parameter_value ARM_A9_HPS {l3_mp_clk_div} {1}
    set_instance_parameter_value ARM_A9_HPS {l3_sp_clk_div} {1}
    set_instance_parameter_value ARM_A9_HPS {l4_mp_clk_div} {1}
    set_instance_parameter_value ARM_A9_HPS {l4_mp_clk_source} {1}
    set_instance_parameter_value ARM_A9_HPS {l4_sp_clk_div} {1}
    set_instance_parameter_value ARM_A9_HPS {l4_sp_clk_source} {1}
    set_instance_parameter_value ARM_A9_HPS {main_pll_c3} {3}
    set_instance_parameter_value ARM_A9_HPS {main_pll_c4} {3}
    set_instance_parameter_value ARM_A9_HPS {main_pll_c5} {15}
    set_instance_parameter_value ARM_A9_HPS {main_pll_m} {63}
    set_instance_parameter_value ARM_A9_HPS {main_pll_n} {0}
    set_instance_parameter_value ARM_A9_HPS {nand_clk_source} {2}
    set_instance_parameter_value ARM_A9_HPS {periph_pll_c0} {3}
    set_instance_parameter_value ARM_A9_HPS {periph_pll_c1} {3}
    set_instance_parameter_value ARM_A9_HPS {periph_pll_c2} {1}
    set_instance_parameter_value ARM_A9_HPS {periph_pll_c3} {19}
    set_instance_parameter_value ARM_A9_HPS {periph_pll_c4} {4}
    set_instance_parameter_value ARM_A9_HPS {periph_pll_c5} {9}
    set_instance_parameter_value ARM_A9_HPS {periph_pll_m} {79}
    set_instance_parameter_value ARM_A9_HPS {periph_pll_n} {1}
    set_instance_parameter_value ARM_A9_HPS {periph_pll_source} {0}
    set_instance_parameter_value ARM_A9_HPS {qspi_clk_source} {1}
    set_instance_parameter_value ARM_A9_HPS {sdmmc_clk_source} {2}
    set_instance_parameter_value ARM_A9_HPS {show_advanced_parameters} {0}
    set_instance_parameter_value ARM_A9_HPS {show_debug_info_as_warning_msg} {0}
    set_instance_parameter_value ARM_A9_HPS {show_warning_as_error_msg} {0}
    set_instance_parameter_value ARM_A9_HPS {spi_m_clk_div} {0}
    set_instance_parameter_value ARM_A9_HPS {usb_mp_clk_div} {0}
    set_instance_parameter_value ARM_A9_HPS {use_default_mpu_clk} {1}

    add_instance AV_Config altera_up_avalon_audio_and_video_config 18.0
    set_instance_parameter_value AV_Config {audio_in} {Microphone to ADC}
    set_instance_parameter_value AV_Config {bit_length} {32}
    set_instance_parameter_value AV_Config {board} {DE1-SoC}
    set_instance_parameter_value AV_Config {d5m_resolution} {2592 x 1944}
    set_instance_parameter_value AV_Config {dac_enable} {1}
    set_instance_parameter_value AV_Config {data_format} {Left Justified}
    set_instance_parameter_value AV_Config {device} {On-Board Peripherals}
    set_instance_parameter_value AV_Config {eai} {1}
    set_instance_parameter_value AV_Config {exposure} {0}
    set_instance_parameter_value AV_Config {line_in_bypass} {1}
    set_instance_parameter_value AV_Config {mic_attenuation} {-6dB}
    set_instance_parameter_value AV_Config {mic_bypass} {0}
    set_instance_parameter_value AV_Config {sampling_rate} {48 kHz}
    set_instance_parameter_value AV_Config {video_format} {NTSC}

    add_instance F2H_Mem_Window_00000000 altera_address_span_extender 18.1
    set_instance_parameter_value F2H_Mem_Window_00000000 {BURSTCOUNT_WIDTH} {1}
    set_instance_parameter_value F2H_Mem_Window_00000000 {DATA_WIDTH} {32}
    set_instance_parameter_value F2H_Mem_Window_00000000 {ENABLE_SLAVE_PORT} {0}
    set_instance_parameter_value F2H_Mem_Window_00000000 {MASTER_ADDRESS_DEF} {0}
    set_instance_parameter_value F2H_Mem_Window_00000000 {MASTER_ADDRESS_WIDTH} {32}
    set_instance_parameter_value F2H_Mem_Window_00000000 {MAX_PENDING_READS} {1}
    set_instance_parameter_value F2H_Mem_Window_00000000 {SLAVE_ADDRESS_WIDTH} {28}
    set_instance_parameter_value F2H_Mem_Window_00000000 {SUB_WINDOW_COUNT} {1}

    add_instance F2H_Mem_Window_FF600000 altera_address_span_extender 18.1
    set_instance_parameter_value F2H_Mem_Window_FF600000 {BURSTCOUNT_WIDTH} {1}
    set_instance_parameter_value F2H_Mem_Window_FF600000 {DATA_WIDTH} {32}
    set_instance_parameter_value F2H_Mem_Window_FF600000 {ENABLE_SLAVE_PORT} {0}
    set_instance_parameter_value F2H_Mem_Window_FF600000 {MASTER_ADDRESS_DEF} {4284481536}
    set_instance_parameter_value F2H_Mem_Window_FF600000 {MASTER_ADDRESS_WIDTH} {32}
    set_instance_parameter_value F2H_Mem_Window_FF600000 {MAX_PENDING_READS} {1}
    set_instance_parameter_value F2H_Mem_Window_FF600000 {SLAVE_ADDRESS_WIDTH} {19}
    set_instance_parameter_value F2H_Mem_Window_FF600000 {SUB_WINDOW_COUNT} {1}

    add_instance F2H_Mem_Window_FF800000 altera_address_span_extender 18.1
    set_instance_parameter_value F2H_Mem_Window_FF800000 {BURSTCOUNT_WIDTH} {1}
    set_instance_parameter_value F2H_Mem_Window_FF800000 {DATA_WIDTH} {32}
    set_instance_parameter_value F2H_Mem_Window_FF800000 {ENABLE_SLAVE_PORT} {0}
    set_instance_parameter_value F2H_Mem_Window_FF800000 {MASTER_ADDRESS_DEF} {4286578688}
    set_instance_parameter_value F2H_Mem_Window_FF800000 {MASTER_ADDRESS_WIDTH} {32}
    set_instance_parameter_value F2H_Mem_Window_FF800000 {MAX_PENDING_READS} {1}
    set_instance_parameter_value F2H_Mem_Window_FF800000 {SLAVE_ADDRESS_WIDTH} {21}
    set_instance_parameter_value F2H_Mem_Window_FF800000 {SUB_WINDOW_COUNT} {1}

    add_instance Onchip_SRAM altera_avalon_onchip_memory2 18.1
    set_instance_parameter_value Onchip_SRAM {allowInSystemMemoryContentEditor} {0}
    set_instance_parameter_value Onchip_SRAM {blockType} {AUTO}
    set_instance_parameter_value Onchip_SRAM {copyInitFile} {0}
    set_instance_parameter_value Onchip_SRAM {dataWidth} {8}
    set_instance_parameter_value Onchip_SRAM {dataWidth2} {32}
    set_instance_parameter_value Onchip_SRAM {dualPort} {1}
    set_instance_parameter_value Onchip_SRAM {ecc_enabled} {0}
    set_instance_parameter_value Onchip_SRAM {enPRInitMode} {0}
    set_instance_parameter_value Onchip_SRAM {enableDiffWidth} {0}
    set_instance_parameter_value Onchip_SRAM {initMemContent} {0}
    set_instance_parameter_value Onchip_SRAM {initializationFileName} {onchip_mem.hex}
    set_instance_parameter_value Onchip_SRAM {instanceID} {NONE}
    set_instance_parameter_value Onchip_SRAM {memorySize} {131072.0}
    set_instance_parameter_value Onchip_SRAM {readDuringWriteMode} {DONT_CARE}
    set_instance_parameter_value Onchip_SRAM {resetrequest_enabled} {1}
    set_instance_parameter_value Onchip_SRAM {simAllowMRAMContentsFile} {0}
    set_instance_parameter_value Onchip_SRAM {simMemInitOnlyFilename} {0}
    set_instance_parameter_value Onchip_SRAM {singleClockOperation} {1}
    set_instance_parameter_value Onchip_SRAM {slave1Latency} {1}
    set_instance_parameter_value Onchip_SRAM {slave2Latency} {1}
    set_instance_parameter_value Onchip_SRAM {useNonDefaultInitFile} {0}
    set_instance_parameter_value Onchip_SRAM {useShallowMemBlocks} {0}
    set_instance_parameter_value Onchip_SRAM {writable} {1}

    add_instance Pixel_DMA_Addr_Translation altera_up_avalon_video_dma_ctrl_addr_trans 18.0
    set_instance_parameter_value Pixel_DMA_Addr_Translation {ADDRESS_TRANSLATION_MASK} {3221225472}

    add_instance Pushbuttons altera_avalon_pio 18.1
    set_instance_parameter_value Pushbuttons {bitClearingEdgeCapReg} {1}
    set_instance_parameter_value Pushbuttons {bitModifyingOutReg} {0}
    set_instance_parameter_value Pushbuttons {captureEdge} {1}
    set_instance_parameter_value Pushbuttons {direction} {Input}
    set_instance_parameter_value Pushbuttons {edgeType} {FALLING}
    set_instance_parameter_value Pushbuttons {generateIRQ} {1}
    set_instance_parameter_value Pushbuttons {irqType} {EDGE}
    set_instance_parameter_value Pushbuttons {resetValue} {0.0}
    set_instance_parameter_value Pushbuttons {simDoTestBenchWiring} {1}
    set_instance_parameter_value Pushbuttons {simDrivenValue} {0.0}
    set_instance_parameter_value Pushbuttons {width} {4}

    add_instance SDRAM altera_avalon_new_sdram_controller 18.1
    set_instance_parameter_value SDRAM {TAC} {5.5}
    set_instance_parameter_value SDRAM {TMRD} {3.0}
    set_instance_parameter_value SDRAM {TRCD} {20.0}
    set_instance_parameter_value SDRAM {TRFC} {70.0}
    set_instance_parameter_value SDRAM {TRP} {20.0}
    set_instance_parameter_value SDRAM {TWR} {14.0}
    set_instance_parameter_value SDRAM {casLatency} {3}
    set_instance_parameter_value SDRAM {columnWidth} {10}
    set_instance_parameter_value SDRAM {dataWidth} {16}
    set_instance_parameter_value SDRAM {generateSimulationModel} {1}
    set_instance_parameter_value SDRAM {initNOPDelay} {0.0}
    set_instance_parameter_value SDRAM {initRefreshCommands} {2}
    set_instance_parameter_value SDRAM {masteredTristateBridgeSlave} {0}
    set_instance_parameter_value SDRAM {model} {single_Micron_MT48LC4M32B2_7_chip}
    set_instance_parameter_value SDRAM {numberOfBanks} {4}
    set_instance_parameter_value SDRAM {numberOfChipSelects} {1}
    set_instance_parameter_value SDRAM {pinsSharedViaTriState} {0}
    set_instance_parameter_value SDRAM {powerUpDelay} {100.0}
    set_instance_parameter_value SDRAM {refreshPeriod} {15.625}
    set_instance_parameter_value SDRAM {registerDataIn} {1}
    set_instance_parameter_value SDRAM {rowWidth} {13}

    add_instance Slider_Switches altera_avalon_pio 18.1
    set_instance_parameter_value Slider_Switches {bitClearingEdgeCapReg} {0}
    set_instance_parameter_value Slider_Switches {bitModifyingOutReg} {0}
    set_instance_parameter_value Slider_Switches {captureEdge} {0}
    set_instance_parameter_value Slider_Switches {direction} {Input}
    set_instance_parameter_value Slider_Switches {edgeType} {RISING}
    set_instance_parameter_value Slider_Switches {generateIRQ} {0}
    set_instance_parameter_value Slider_Switches {irqType} {LEVEL}
    set_instance_parameter_value Slider_Switches {resetValue} {0.0}
    set_instance_parameter_value Slider_Switches {simDoTestBenchWiring} {1}
    set_instance_parameter_value Slider_Switches {simDrivenValue} {0.0}
    set_instance_parameter_value Slider_Switches {width} {10}

    add_instance SysID altera_avalon_sysid_qsys 18.1
    set_instance_parameter_value SysID {id} {0}

    add_instance System_PLL altera_up_avalon_sys_sdram_pll 18.0
    set_instance_parameter_value System_PLL {CIII_boards} {DE0}
    set_instance_parameter_value System_PLL {CIV_boards} {DE2-115}
    set_instance_parameter_value System_PLL {CV_boards} {DE1-SoC}
    set_instance_parameter_value System_PLL {MAX10_boards} {DE10-Lite}
    set_instance_parameter_value System_PLL {gui_outclk} {100.0}
    set_instance_parameter_value System_PLL {gui_refclk} {50.0}
    set_instance_parameter_value System_PLL {other_boards} {None}

    add_instance VGA_Subsystem VGA_Subsystem 1.0

    add_instance Video_In_DMA_Addr_Translation altera_up_avalon_video_dma_ctrl_addr_trans 18.0
    set_instance_parameter_value Video_In_DMA_Addr_Translation {ADDRESS_TRANSLATION_MASK} {3221225472}

    add_instance dehazing_system_0 dehazing_system 1.0

    # connections and connection parameters
    add_connection ARM_A9_HPS.f2h_irq0 Pushbuttons.irq interrupt
    set_connection_parameter_value ARM_A9_HPS.f2h_irq0/Pushbuttons.irq irqNumber {1}

    add_connection ARM_A9_HPS.h2f_axi_master Onchip_SRAM.s2 avalon
    set_connection_parameter_value ARM_A9_HPS.h2f_axi_master/Onchip_SRAM.s2 arbitrationPriority {1}
    set_connection_parameter_value ARM_A9_HPS.h2f_axi_master/Onchip_SRAM.s2 baseAddress {0x08000000}
    set_connection_parameter_value ARM_A9_HPS.h2f_axi_master/Onchip_SRAM.s2 defaultConnection {0}

    add_connection ARM_A9_HPS.h2f_axi_master SDRAM.s1 avalon
    set_connection_parameter_value ARM_A9_HPS.h2f_axi_master/SDRAM.s1 arbitrationPriority {1}
    set_connection_parameter_value ARM_A9_HPS.h2f_axi_master/SDRAM.s1 baseAddress {0x0000}
    set_connection_parameter_value ARM_A9_HPS.h2f_axi_master/SDRAM.s1 defaultConnection {0}

    add_connection ARM_A9_HPS.h2f_lw_axi_master AV_Config.avalon_av_config_slave avalon
    set_connection_parameter_value ARM_A9_HPS.h2f_lw_axi_master/AV_Config.avalon_av_config_slave arbitrationPriority {1}
    set_connection_parameter_value ARM_A9_HPS.h2f_lw_axi_master/AV_Config.avalon_av_config_slave baseAddress {0x3000}
    set_connection_parameter_value ARM_A9_HPS.h2f_lw_axi_master/AV_Config.avalon_av_config_slave defaultConnection {0}

    add_connection ARM_A9_HPS.h2f_lw_axi_master Pixel_DMA_Addr_Translation.slave avalon
    set_connection_parameter_value ARM_A9_HPS.h2f_lw_axi_master/Pixel_DMA_Addr_Translation.slave arbitrationPriority {1}
    set_connection_parameter_value ARM_A9_HPS.h2f_lw_axi_master/Pixel_DMA_Addr_Translation.slave baseAddress {0x3020}
    set_connection_parameter_value ARM_A9_HPS.h2f_lw_axi_master/Pixel_DMA_Addr_Translation.slave defaultConnection {0}

    add_connection ARM_A9_HPS.h2f_lw_axi_master Pushbuttons.s1 avalon
    set_connection_parameter_value ARM_A9_HPS.h2f_lw_axi_master/Pushbuttons.s1 arbitrationPriority {1}
    set_connection_parameter_value ARM_A9_HPS.h2f_lw_axi_master/Pushbuttons.s1 baseAddress {0x0050}
    set_connection_parameter_value ARM_A9_HPS.h2f_lw_axi_master/Pushbuttons.s1 defaultConnection {0}

    add_connection ARM_A9_HPS.h2f_lw_axi_master Slider_Switches.s1 avalon
    set_connection_parameter_value ARM_A9_HPS.h2f_lw_axi_master/Slider_Switches.s1 arbitrationPriority {1}
    set_connection_parameter_value ARM_A9_HPS.h2f_lw_axi_master/Slider_Switches.s1 baseAddress {0x0040}
    set_connection_parameter_value ARM_A9_HPS.h2f_lw_axi_master/Slider_Switches.s1 defaultConnection {0}

    add_connection ARM_A9_HPS.h2f_lw_axi_master SysID.control_slave avalon
    set_connection_parameter_value ARM_A9_HPS.h2f_lw_axi_master/SysID.control_slave arbitrationPriority {1}
    set_connection_parameter_value ARM_A9_HPS.h2f_lw_axi_master/SysID.control_slave baseAddress {0x2040}
    set_connection_parameter_value ARM_A9_HPS.h2f_lw_axi_master/SysID.control_slave defaultConnection {0}

    add_connection ARM_A9_HPS.h2f_lw_axi_master Video_In_DMA_Addr_Translation.slave avalon
    set_connection_parameter_value ARM_A9_HPS.h2f_lw_axi_master/Video_In_DMA_Addr_Translation.slave arbitrationPriority {1}
    set_connection_parameter_value ARM_A9_HPS.h2f_lw_axi_master/Video_In_DMA_Addr_Translation.slave baseAddress {0x3060}
    set_connection_parameter_value ARM_A9_HPS.h2f_lw_axi_master/Video_In_DMA_Addr_Translation.slave defaultConnection {0}

    add_connection ARM_A9_HPS.h2f_reset AV_Config.reset reset

    add_connection ARM_A9_HPS.h2f_reset F2H_Mem_Window_00000000.reset reset

    add_connection ARM_A9_HPS.h2f_reset F2H_Mem_Window_FF600000.reset reset

    add_connection ARM_A9_HPS.h2f_reset F2H_Mem_Window_FF800000.reset reset

    add_connection ARM_A9_HPS.h2f_reset Onchip_SRAM.reset1 reset

    add_connection ARM_A9_HPS.h2f_reset Pixel_DMA_Addr_Translation.reset reset

    add_connection ARM_A9_HPS.h2f_reset Pushbuttons.reset reset

    add_connection ARM_A9_HPS.h2f_reset SDRAM.reset reset

    add_connection ARM_A9_HPS.h2f_reset Slider_Switches.reset reset

    add_connection ARM_A9_HPS.h2f_reset SysID.reset reset

    add_connection ARM_A9_HPS.h2f_reset VGA_Subsystem.sys_reset reset

    add_connection ARM_A9_HPS.h2f_reset Video_In_DMA_Addr_Translation.reset reset

    add_connection F2H_Mem_Window_00000000.expanded_master ARM_A9_HPS.f2h_axi_slave avalon
    set_connection_parameter_value F2H_Mem_Window_00000000.expanded_master/ARM_A9_HPS.f2h_axi_slave arbitrationPriority {1}
    set_connection_parameter_value F2H_Mem_Window_00000000.expanded_master/ARM_A9_HPS.f2h_axi_slave baseAddress {0x0000}
    set_connection_parameter_value F2H_Mem_Window_00000000.expanded_master/ARM_A9_HPS.f2h_axi_slave defaultConnection {0}

    add_connection F2H_Mem_Window_FF600000.expanded_master ARM_A9_HPS.f2h_axi_slave avalon
    set_connection_parameter_value F2H_Mem_Window_FF600000.expanded_master/ARM_A9_HPS.f2h_axi_slave arbitrationPriority {1}
    set_connection_parameter_value F2H_Mem_Window_FF600000.expanded_master/ARM_A9_HPS.f2h_axi_slave baseAddress {0x0000}
    set_connection_parameter_value F2H_Mem_Window_FF600000.expanded_master/ARM_A9_HPS.f2h_axi_slave defaultConnection {0}

    add_connection F2H_Mem_Window_FF800000.expanded_master ARM_A9_HPS.f2h_axi_slave avalon
    set_connection_parameter_value F2H_Mem_Window_FF800000.expanded_master/ARM_A9_HPS.f2h_axi_slave arbitrationPriority {1}
    set_connection_parameter_value F2H_Mem_Window_FF800000.expanded_master/ARM_A9_HPS.f2h_axi_slave baseAddress {0x0000}
    set_connection_parameter_value F2H_Mem_Window_FF800000.expanded_master/ARM_A9_HPS.f2h_axi_slave defaultConnection {0}

    add_connection Pixel_DMA_Addr_Translation.master VGA_Subsystem.pixel_dma_control_slave avalon
    set_connection_parameter_value Pixel_DMA_Addr_Translation.master/VGA_Subsystem.pixel_dma_control_slave arbitrationPriority {1}
    set_connection_parameter_value Pixel_DMA_Addr_Translation.master/VGA_Subsystem.pixel_dma_control_slave baseAddress {0x0000}
    set_connection_parameter_value Pixel_DMA_Addr_Translation.master/VGA_Subsystem.pixel_dma_control_slave defaultConnection {0}

    add_connection System_PLL.reset_source AV_Config.reset reset

    add_connection System_PLL.reset_source F2H_Mem_Window_00000000.reset reset

    add_connection System_PLL.reset_source F2H_Mem_Window_FF600000.reset reset

    add_connection System_PLL.reset_source F2H_Mem_Window_FF800000.reset reset

    add_connection System_PLL.reset_source Onchip_SRAM.reset1 reset

    add_connection System_PLL.reset_source Pixel_DMA_Addr_Translation.reset reset

    add_connection System_PLL.reset_source Pushbuttons.reset reset

    add_connection System_PLL.reset_source SDRAM.reset reset

    add_connection System_PLL.reset_source Slider_Switches.reset reset

    add_connection System_PLL.reset_source SysID.reset reset

    add_connection System_PLL.reset_source VGA_Subsystem.sys_reset reset

    add_connection System_PLL.reset_source Video_In_DMA_Addr_Translation.reset reset

    add_connection System_PLL.reset_source dehazing_system_0.reset_sink reset

    add_connection System_PLL.sys_clk ARM_A9_HPS.f2h_axi_clock clock

    add_connection System_PLL.sys_clk ARM_A9_HPS.h2f_axi_clock clock

    add_connection System_PLL.sys_clk ARM_A9_HPS.h2f_lw_axi_clock clock

    add_connection System_PLL.sys_clk AV_Config.clk clock

    add_connection System_PLL.sys_clk F2H_Mem_Window_00000000.clock clock

    add_connection System_PLL.sys_clk F2H_Mem_Window_FF600000.clock clock

    add_connection System_PLL.sys_clk F2H_Mem_Window_FF800000.clock clock

    add_connection System_PLL.sys_clk Onchip_SRAM.clk1 clock

    add_connection System_PLL.sys_clk Pixel_DMA_Addr_Translation.clock clock

    add_connection System_PLL.sys_clk Pushbuttons.clk clock

    add_connection System_PLL.sys_clk SDRAM.clk clock

    add_connection System_PLL.sys_clk Slider_Switches.clk clock

    add_connection System_PLL.sys_clk SysID.clk clock

    add_connection System_PLL.sys_clk VGA_Subsystem.sys_clk clock

    add_connection System_PLL.sys_clk Video_In_DMA_Addr_Translation.clock clock

    add_connection System_PLL.sys_clk dehazing_system_0.clock clock

    add_connection VGA_Subsystem.pixel_dma_master SDRAM.s1 avalon
    set_connection_parameter_value VGA_Subsystem.pixel_dma_master/SDRAM.s1 arbitrationPriority {1}
    set_connection_parameter_value VGA_Subsystem.pixel_dma_master/SDRAM.s1 baseAddress {0x0000}
    set_connection_parameter_value VGA_Subsystem.pixel_dma_master/SDRAM.s1 defaultConnection {0}

    add_connection VGA_Subsystem.snk dehazing_system_0.snk avalon_streaming

    add_connection dehazing_system_0.src VGA_Subsystem.src avalon_streaming

    # exported interfaces
    add_interface av_config conduit end
    set_interface_property av_config EXPORT_OF AV_Config.external_interface
    add_interface hps_io conduit end
    set_interface_property hps_io EXPORT_OF ARM_A9_HPS.hps_io
    add_interface memory conduit end
    set_interface_property memory EXPORT_OF ARM_A9_HPS.memory
    add_interface pushbuttons conduit end
    set_interface_property pushbuttons EXPORT_OF Pushbuttons.external_connection
    add_interface sdram conduit end
    set_interface_property sdram EXPORT_OF SDRAM.wire
    add_interface sdram_clk clock source
    set_interface_property sdram_clk EXPORT_OF System_PLL.sdram_clk
    add_interface slider_switches conduit end
    set_interface_property slider_switches EXPORT_OF Slider_Switches.external_connection
    add_interface system_pll_ref_clk clock sink
    set_interface_property system_pll_ref_clk EXPORT_OF System_PLL.ref_clk
    add_interface system_pll_ref_reset reset sink
    set_interface_property system_pll_ref_reset EXPORT_OF System_PLL.ref_reset
    add_interface vga conduit end
    set_interface_property vga EXPORT_OF VGA_Subsystem.vga
    add_interface vga_pll_ref_clk clock sink
    set_interface_property vga_pll_ref_clk EXPORT_OF VGA_Subsystem.vga_pll_ref_clk
    add_interface vga_pll_ref_reset reset sink
    set_interface_property vga_pll_ref_reset EXPORT_OF VGA_Subsystem.vga_pll_ref_reset

    # interconnect requirements
    set_interconnect_requirement {$system} {qsys_mm.clockCrossingAdapter} {HANDSHAKE}
    set_interconnect_requirement {$system} {qsys_mm.enableEccProtection} {FALSE}
    set_interconnect_requirement {$system} {qsys_mm.insertDefaultSlave} {FALSE}
    set_interconnect_requirement {$system} {qsys_mm.maxAdditionalLatency} {1}
}
