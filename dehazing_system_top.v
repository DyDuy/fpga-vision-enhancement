`timescale 1ns / 1ps


module dehazing_system_top (
    input  wire        clk,
    input  wire        rst_n,
    input  wire        sw_bypass, // 0: Original (delayed), 1: Processed

    // Avalon-ST Sink Interface (Input từ DMA)
    input  wire [29:0] snk_data,
    input  wire        snk_valid,
    output wire        snk_ready,
    input  wire        snk_sop,
    input  wire        snk_eop,

    // Avalon-ST Source Interface (Output ra VGA)
    output wire [29:0] src_data,
    output wire        src_valid,
    input  wire        src_ready,
    output wire        src_sop,
    output wire        src_eop
);

    // Backpressure: Ép toàn bộ Pipeline dừng khi màn hình chưa sẵn sàng
    assign snk_ready = src_ready;
    wire i_en = src_ready; 

    // --- TRÍCH XUẤT 24-BIT MSB CHO TÍNH TOÁN ---
    wire [7:0] ir = snk_data[29:22]; 
    wire [7:0] ig = snk_data[19:12];
    wire [7:0] ib = snk_data[9:2];

    localparam UD_DELAY    = 3;   
    localparam TOTAL_DELAY = 649; 

    // 1. Đồng bộ luồng điều khiển khung hình (SOP/EOP/Valid)
    wire [32:0] p_out;
    common_delay_line #(33, TOTAL_DELAY) global_sync (
        .clk(clk), 
		  .rst_n(rst_n), 
		  .i_en(i_en), 
		  .i_v(snk_valid),
        .i_data({snk_sop, snk_eop, snk_valid, snk_data}), 
        .o_data(p_out)
    );

    // 2. Đồng bộ SOP nội bộ cho Atmospheric Light Estimation
    wire sof_sync;
    common_delay_line #(1, UD_DELAY) sof_delay 
	 (
        .clk(clk), 
		  .rst_n(rst_n), 
		  .i_en(i_en), 
		  .i_v(snk_valid),
        .i_data(snk_sop),
        .o_data(sof_sync)
    );

    wire v1, v2, v3, v4, v5, v6;
    wire [9:0] t_raw, t_ref; 
    wire [7:0] Cmin, d_raw, auto_Ag; 
    wire [23:0] p_sync, p_dehazed, p_sharp;

    // --- PIPELINE XỬ LÝ TỐI ƯU ---
    feature_extraction_soc st1 (
        .clk(clk), 
		  .rst_n(rst_n), 
		  .i_en(i_en), 
		  .i_valid(snk_valid), 
        .i_r(ir), 
		  .i_g(ig), 
		  .i_b(ib), 
        .o_valid(v1), 
		  .o_Cmin(Cmin)
    );
    
    dark_channel_1x1 st2 
	 (
        .clk(clk), 
		  .rst_n(rst_n), 
		  .i_en(i_en), 
		  .i_valid(v1), 
        .i_cmin(Cmin), 
		  .o_valid(v2), 
		  .o_dark(d_raw)
    );
    
    transmission_engine st3 
	 (
        .clk(clk), 
		  .rst_n(rst_n), 
		  .i_en(i_en), 
		  .i_valid(v2), 
        .i_dark(d_raw),
		  .o_valid(v3), 
		  .o_t(t_raw)
    );
    
    // Pixel Sync Buffer: Khóa p_sync đúng 4 nhịp (3+1)
    common_delay_line #(24, UD_DELAY) ud_inst (
        .clk(clk), 
		  .rst_n(rst_n), 
		  .i_en(i_en), 
		  .i_v(snk_valid),
        .i_data({ir, ig, ib}), 
		  .o_data(p_sync)
    );

    refinement_1x1 st4 
	 (
        .clk(clk), 
		  .rst_n(rst_n), 
		  .i_en(i_en), 
		  .i_valid(v3), 
        .i_t_raw(t_raw), 
		  .o_valid(v4), 
		  .o_t_refined(t_ref)
    );
    
    atmospheric_light_est st_ag (
        .clk(clk), 
		  .rst_n(rst_n), 
		  .i_en(i_en), 
		  .i_valid(v4), 
        .i_sof(sof_sync), 
		  .i_pixel(p_sync), 
		  .i_t(t_ref), 
        .o_Ag(auto_Ag)
    );
    
    image_restoration_soc st5 (
        .clk(clk), 
		  .rst_n(rst_n), 
		  .i_en(i_en), 
		  .i_valid(v4), 
        .i_pixel_sync(p_sync), .i_t_refined(t_ref), .i_A(auto_Ag), 
        .o_valid(v5), .o_pixel_dehazed(p_dehazed)
    );
    
    
    image_sharpening_soc st6 (
        .clk(clk), 
		  .rst_n(rst_n), 
		  .i_en(i_en), 
		  .i_valid(v5), 
        .i_pixel(p_dehazed), .i_k(4'd2), 
        .o_valid(v6), .o_pixel_sharp(p_sharp)
    );

    assign {src_sop, src_eop, src_valid} = {p_out[32], p_out[31], p_out[30]};
    wire [29:0] raw_data_delayed = p_out[29:0];
    wire [29:0] processed_data = {
        p_sharp[23:16], p_sharp[23:22], 
        p_sharp[15:8],  p_sharp[15:14], 
        p_sharp[7:0],   p_sharp[7:6]
    };

    assign src_data = sw_bypass ? processed_data : raw_data_delayed;

endmodule


module common_delay_line #(parameter WIDTH=8, DELAY=640) (
    input  wire             clk, rst_n, i_en, i_v,
    input  wire [WIDTH-1:0] i_data,
    output reg  [WIDTH-1:0] o_data
);
    (* ramstyle = "M10K" *) reg [WIDTH-1:0] mem [0:DELAY-1];
    reg [$clog2(DELAY)-1:0] addr;
    always @(posedge clk) begin
        if (!rst_n) begin addr <= 0; o_data <= 0; end
        else if (i_en && i_v) begin 
            mem[addr] <= i_data; 
            o_data <= mem[addr]; 
            addr <= (addr >= DELAY-1) ? 0 : addr + 1; 
        end
    end
endmodule

module dark_channel_1x1 
(
    input wire clk, rst_n, i_en, i_valid, 
	 input wire [7:0] i_cmin, 
	 output wire o_valid, 
	 output reg [7:0] o_dark
);
    always @(posedge clk) begin 
	 if (!rst_n) o_dark <= 0; 
	 else if (i_en && i_valid) o_dark <= i_cmin; end
    valid_delay_line #(1) vd (clk, rst_n, i_en, i_valid, o_valid);
endmodule

module refinement_1x1 
(
    input wire clk, rst_n, i_en, i_valid, 
	 input wire [9:0] i_t_raw, 
	 output wire o_valid, 
	 output reg [9:0] o_t_refined
);
    always @(posedge clk) begin 
	 if (!rst_n) o_t_refined <= 0; 
	 else 
	 if (i_en && i_valid) o_t_refined <= i_t_raw; end
    valid_delay_line #(1) vd_st4 (clk, rst_n, i_en, i_valid, o_valid);
endmodule

module feature_extraction_soc (
    input  wire        clk, rst_n, i_en, i_valid,
    input  wire [7:0]  i_r, i_g, i_b, 
    output reg         o_valid, 
    output reg  [7:0]  o_Cmin
);
    always @(posedge clk) begin 
        if (!rst_n) o_valid <= 1'b0;
        else if (i_en && i_valid) begin 
            o_Cmin <= (i_r < i_g) ? ((i_r < i_b) ? i_r : i_b) : ((i_g < i_b) ? i_g : i_b); 
            o_valid <= 1'b1; 
        end
        else if (i_en) o_valid <= 1'b0;
    end
endmodule

module transmission_engine (
    input  wire        clk, rst_n, i_en, i_valid,
    input  wire [7:0]  i_dark,
    output reg         o_valid,
    output reg  [9:0]  o_t
);
    
    wire [17:0] product = i_dark * 10'd794; 
    wire [9:0]  sub_val = product[17:8];    

    wire [10:0] t_calc = 11'd1023 - {1'b0, sub_val};

    always @(posedge clk) begin
        if (!rst_n) begin
            o_valid <= 1'b0;
            o_t     <= 10'd0;
        end
        else if (i_en && i_valid) begin
            if (t_calc < 11'd100)
                o_t <= 10'd100;
            else
                o_t <= t_calc[9:0];

            o_valid <= 1'b1;
        end
        else if (i_en) begin
            o_valid <= 1'b0;
        end
    end
endmodule

module image_restoration_soc 
(
    input  wire        clk, rst_n, i_en, i_valid,
    input  wire [23:0] i_pixel_sync, 
    input  wire [9:0]  i_t_refined, 
    input  wire [7:0]  i_A, 
    output reg         o_valid, 
    output reg  [23:0] o_pixel_dehazed
);
    wire [13:0] inv_t; inverse_t_lut uinv (.address(i_t_refined), .clk(clk), .q(inv_t));
    reg signed [17:0] r_d, g_d, b_d; reg [7:0] a_r; reg v_r1;
    
    always @(posedge clk) if (i_en && i_valid) begin 
        r_d <= $signed({1'b0, i_pixel_sync[23:16]}) - $signed({1'b0, i_A}); 
        g_d <= $signed({1'b0, i_pixel_sync[15:8]}) - $signed({1'b0, i_A}); 
        b_d <= $signed({1'b0, i_pixel_sync[7:0]}) - $signed({1'b0, i_A}); 
        a_r <= i_A; 
        v_r1 <= 1'b1;
    end else if (i_en) v_r1 <= 1'b0;

    always @(posedge clk) begin
        if (!rst_n) o_valid <= 1'b0;
        else if (i_en) begin 
            o_valid <= v_r1;
            if (v_r1) begin
                o_pixel_dehazed[23:16] <= clp((r_d * $signed({1'b0, inv_t})) >>> 10, a_r);
                o_pixel_dehazed[15:8]  <= clp((g_d * $signed({1'b0, inv_t})) >>> 10, a_r);
                o_pixel_dehazed[7:0]   <= clp((b_d * $signed({1'b0, inv_t})) >>> 10, a_r);
            end
        end
    end
    function [7:0] clp(input signed [31:0] v, input [7:0] a); reg signed [31:0] res; begin res = v + $signed({1'b0, a}); if (res > 255) clp = 255; else if (res < 0) clp = 0; else clp = res[7:0]; end endfunction
endmodule

module image_sharpening_soc (
    input  wire        clk, rst_n, i_en, i_valid, 
    input  wire [23:0] i_pixel, 
    input  wire [3:0]  i_k, 
    output wire        o_valid, 
    output reg  [23:0] o_pixel_sharp
);
    wire [7:0] r_t[0:2], g_t[0:2], b_t[0:2]; 
	 integer i; 
	 reg [7:0] wr [0:2][0:2], wg [0:2][0:2], wb [0:2][0:2];
    line_buffer_3tap lb_r (clk, rst_n, i_en, i_valid, i_pixel[23:16], r_t[0], r_t[1], r_t[2]);
    line_buffer_3tap lb_g (clk, rst_n, i_en, i_valid, i_pixel[15:8],  g_t[0], g_t[1], g_t[2]);
    line_buffer_3tap lb_b (clk, rst_n, i_en, i_valid, i_pixel[7:0],   b_t[0], b_t[1], b_t[2]);
    
    always @(posedge clk) 
	 if (i_en && i_valid) for(i=0; i<3; i=i+1) begin 
        wr[i][0]<=r_t[i]; wr[i][1]<=wr[i][0]; wr[i][2]<=wr[i][1]; 
        wg[i][0]<=g_t[i]; wg[i][1]<=wg[i][0]; wg[i][2]<=wg[i][1]; 
        wb[i][0]<=b_t[i]; wb[i][1]<=wb[i][0]; wb[i][2]<=wb[i][1]; 
    end
    
    function signed [11:0] lap(input [7:0] p01, p10, p11, p12, p21); lap = ($signed({4'b0, p11}) << 2) - $signed({4'b0, p01}) - $signed({4'b0, p21}) - $signed({4'b0, p10}) - $signed({4'b0, p12}); endfunction
    wire signed [15:0] sr = $signed({8'b0, wr[1][1]}) + ($signed({12'b0, i_k}) * lap(wr[0][1], wr[1][0], wr[1][1], wr[1][2], wr[2][1]) / 4);
    wire signed [15:0] sg = $signed({8'b0, wg[1][1]}) + ($signed({12'b0, i_k}) * lap(wg[0][1], wg[1][0], wg[1][1], wg[1][2], wg[2][1]) / 4);
    wire signed [15:0] sb = $signed({8'b0, wb[1][1]}) + ($signed({12'b0, i_k}) * lap(wb[0][1], wb[1][0], wb[1][1], wb[1][2], wb[2][1]) / 4);
    
    always @(posedge clk) 
	 if (i_en && i_valid) begin 
        o_pixel_sharp[23:16] <= (sr>255)?255:(sr<0?0:sr[7:0]); 
        o_pixel_sharp[15:8]  <= (sg>255)?255:(sg<0?0:sg[7:0]); 
        o_pixel_sharp[7:0]   <= (sb>255)?255:(sb<0?0:sb[7:0]); 
    end
    
    valid_delay_line #(644) vd_st6 (clk, rst_n, i_en, i_valid, o_valid);
endmodule

module line_buffer_3tap (
    input  wire        clk, rst_n, i_en, i_valid, 
    input  wire [7:0]  i_data, 
    output wire [7:0]  tap0, tap1, tap2
);
    wire [7:0] c1, c2; 
    common_delay_line #(8, 640) u1 (clk, rst_n, i_en, i_valid, i_data, c1); 
    common_delay_line #(8, 640) u2 (clk, rst_n, i_en, i_valid, c1, c2);
    assign tap0 = i_data; 
	 assign tap1 = c1; 
	 assign tap2 = c2;
endmodule

module inverse_t_lut 
(
    input wire [9:0] address, 
	 input wire clk, 
	 output reg [13:0] q
);
    (* ramstyle = "M10K" *) reg [13:0] rom [0:1023]; 
	 integer i; 
	 initial for (i=0; i<1024; i=i+1) rom[i] = (i < 100) ? 10240 : (1048576 / i);
    always @(posedge clk) q <= rom[address];
endmodule

module atmospheric_light_est 
(
    input  wire        clk, rst_n, i_en, i_valid, i_sof,
    input  wire [23:0] i_pixel,
    input  wire [9:0]  i_t,
    output reg  [7:0]  o_Ag
);
    reg [7:0] max_r;
    wire [7:0] p_m =
      (i_pixel[23:16]>i_pixel[15:8])?((i_pixel[23:16]>i_pixel[7:0])?i_pixel[23:16]:i_pixel[7:0]):((i_pixel[15:8]>i_pixel[7:0])?i_pixel[15:8]:i_pixel[7:0]);

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            max_r <= 0;
            o_Ag <= 220; 
        end
        else if (i_en) begin
            if (i_sof) begin
                if (max_r > 50)
                    o_Ag <= (o_Ag * 15 + max_r) >> 4;
                max_r <= 0;
            end
            else if (i_valid) begin
                if (i_t < 220 && p_m > max_r) max_r <= p_m;
            end
        end
    end
endmodule

module valid_delay_line #(parameter DELAY=10) (
    input wire clk, rst_n, i_en, i_v,
    output wire o_v
);
    generate
        if (DELAY <= 0) begin : d0
            // Trường hợp không delay
            assign o_v = i_v;
        end
        else if (DELAY == 1) begin : d1
            // Trường hợp delay đúng 1 nhịp 
            reg delay_reg;
            always @(posedge clk or negedge rst_n) begin
                if (!rst_n) delay_reg <= 1'b0;
                else if (i_en) delay_reg <= i_v;
            end
            assign o_v = delay_reg;
        end
        else begin : dN
            // Trường hợp delay > 1 nhịp
            reg [DELAY-1:0] delay_reg;
            always @(posedge clk or negedge rst_n) begin
                if (!rst_n) delay_reg <= {DELAY{1'b0}};
                else if (i_en && i_v) delay_reg <= {delay_reg[DELAY-2:0], i_v};
                else if (i_en && !i_v) delay_reg <= delay_reg; // Giữ nguyên khi blanking
            end
            assign o_v = delay_reg[DELAY-1] && i_v;
        end
    endgenerate
endmodule
