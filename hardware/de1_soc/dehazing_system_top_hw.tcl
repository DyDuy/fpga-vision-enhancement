
#
package require -exact qsys 16.1


#
# module dehazing_system
#
set_module_property DESCRIPTION ""
set_module_property NAME dehazing_system
set_module_property VERSION 1.0
set_module_property INTERNAL false
set_module_property OPAQUE_ADDRESS_MAP true
set_module_property GROUP "My system"
set_module_property AUTHOR "Duy Khanh "
set_module_property DISPLAY_NAME "Dehazing Core Pro "
set_module_property INSTANTIATE_IN_SYSTEM_MODULE true
set_module_property EDITABLE true
set_module_property REPORT_TO_TALKBACK false
set_module_property ALLOW_GREYBOX_GENERATION false
set_module_property REPORT_HIERARCHY false


#
# file sets
#
add_fileset QUARTUS_SYNTH QUARTUS_SYNTH "" ""
set_fileset_property QUARTUS_SYNTH TOP_LEVEL dehazing_system_top
set_fileset_property QUARTUS_SYNTH ENABLE_RELATIVE_INCLUDE_PATHS false
set_fileset_property QUARTUS_SYNTH ENABLE_FILE_OVERWRITE_MODE true
add_fileset_file dehazing_system_top.v VERILOG PATH dehazing_system_top.v TOP_LEVEL_FILE


#
# parameters
#


#
# display items
#


#
# connection point clock
#
add_interface clock clock end
set_interface_property clock clockRate 0
set_interface_property clock ENABLED true
set_interface_property clock EXPORT_OF ""
set_interface_property clock PORT_NAME_MAP ""
set_interface_property clock CMSIS_SVD_VARIABLES ""
set_interface_property clock SVD_ADDRESS_GROUP ""

add_interface_port clock clk clk Input 1


#
# connection point reset_sink
#
add_interface reset_sink reset end
set_interface_property reset_sink associatedClock clock
set_interface_property reset_sink synchronousEdges DEASSERT
set_interface_property reset_sink ENABLED true
set_interface_property reset_sink EXPORT_OF ""
set_interface_property reset_sink PORT_NAME_MAP ""
set_interface_property reset_sink CMSIS_SVD_VARIABLES ""
set_interface_property reset_sink SVD_ADDRESS_GROUP ""

add_interface_port reset_sink rst_n reset_n Input 1


#
# connection point snk
#
add_interface snk avalon_streaming end
set_interface_property snk associatedClock clock
set_interface_property snk associatedReset reset_sink
set_interface_property snk dataBitsPerSymbol 10
set_interface_property snk errorDescriptor ""
set_interface_property snk firstSymbolInHighOrderBits true
set_interface_property snk maxChannel 0
set_interface_property snk readyLatency 0
set_interface_property snk symbolsPerBeat 3
set_interface_property snk ENABLED true
set_interface_property snk EXPORT_OF ""
set_interface_property snk PORT_NAME_MAP ""
set_interface_property snk CMSIS_SVD_VARIABLES ""
set_interface_property snk SVD_ADDRESS_GROUP ""

add_interface_port snk snk_data data Input 30
add_interface_port snk snk_valid valid Input 1
add_interface_port snk snk_ready ready Output 1
add_interface_port snk snk_sop startofpacket Input 1
add_interface_port snk snk_eop endofpacket Input 1


#
# connection point src
#
add_interface src avalon_streaming start
set_interface_property src associatedClock clock
set_interface_property src associatedReset reset_sink
set_interface_property src dataBitsPerSymbol 10
set_interface_property src errorDescriptor ""
set_interface_property src firstSymbolInHighOrderBits true
set_interface_property src maxChannel 0
set_interface_property src readyLatency 0
set_interface_property src symbolsPerBeat 3
set_interface_property src ENABLED true
set_interface_property src EXPORT_OF ""
set_interface_property src PORT_NAME_MAP ""
set_interface_property src CMSIS_SVD_VARIABLES ""
set_interface_property src SVD_ADDRESS_GROUP ""

add_interface_port src src_data data Output 30
add_interface_port src src_valid valid Output 1
add_interface_port src src_ready ready Input 1
add_interface_port src src_sop startofpacket Output 1
add_interface_port src src_eop endofpacket Output 1


#
# connection point bypass_switch
#
add_interface bypass_switch conduit end
set_interface_property bypass_switch associatedClock clock
set_interface_property bypass_switch associatedReset reset_sink
set_interface_property bypass_switch ENABLED true
set_interface_property bypass_switch EXPORT_OF ""
set_interface_property bypass_switch PORT_NAME_MAP ""
set_interface_property bypass_switch CMSIS_SVD_VARIABLES ""
set_interface_property bypass_switch SVD_ADDRESS_GROUP ""

add_interface_port bypass_switch sw_bypass sw_bypass Input 1
