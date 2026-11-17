// Protocol template. Bind this checker to a reviewed DUT interface before use.
module dehazing_stream_sva (
  input logic clk, input logic rst_n,
  input logic valid, input logic ready,
  input logic sop, input logic eop,
  input logic [29:0] data
);
  default clocking cb @(posedge clk); endclocking
  property p_payload_stable; valid && !ready |=> valid && $stable({sop,eop,data}); endproperty
  property p_sop_requires_valid; sop |-> valid; endproperty
  property p_eop_requires_valid; eop |-> valid; endproperty
  a_payload_stable: assert property (disable iff (!rst_n) p_payload_stable);
  a_sop_requires_valid: assert property (disable iff (!rst_n) p_sop_requires_valid);
  a_eop_requires_valid: assert property (disable iff (!rst_n) p_eop_requires_valid);
endmodule
