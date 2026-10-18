`timescale 1ns / 1ps

// ============================================================================
// ĐỒ ÁN TỐT NGHIỆP: HỆ THỐNG KHỬ SƯƠNG MÙ (V11.0 - FINAL OPTIMIZED)
// Tác giả: Duy Khanh
// Đặc điểm: Full Pipeline, Frame-Adaptive Atmospheric Light, Tree-Comparator
// ============================================================================

module dehazing_system_top (
    input  wire        clk, rst_n,
    input  wire        i_sof,      // Tín hiệu Start of Frame (VSync)
    input  wire [23:0] asi_data,   // Dữ liệu vào: [23:16]R, [15:8]G, [7:0]B
    input  wire        asi_valid, 
    output wire        asi_ready,
    output wire [23:0] aso_data, 
    output wire        aso_valid, 
    input  wire        aso_ready,
    output wire [ 4:0] stat_gamma_idx, 
    output wire [ 4:0] stat_sharp_idx
);
    assign asi_ready = 1'b1;
    assign stat_gamma_idx = 5'd6;  // Gamma ~0.8
    assign stat_sharp_idx = 5'd2;  // Sharp k=2

    // --- CÁC ĐƯỜNG TÍN HIỆU PIPELINE ---
    wire v1, v2, v3, v4, v5, v6, v7;
    wire [9:0] V, S, t_raw, t_ref;
    wire [7:0] Cmin, d_raw, auto_Ag;
    wire [23:0] p_sync, p_dehazed, p_sharp, p_final;

    // STAGE 1: Feature Extraction
    feature_extraction_soc st1 (.clk(clk), .rst_n(rst_n), .i_valid(asi_valid), .i_r(asi_data[23:16]), .i_g(asi_data[15:8]), .i_b(asi_data[7:0]), .o_valid(v1), .o_V(V), .o_S(S), .o_Cmin(Cmin));

    // STAGE 2: Dark Channel 15x15
    dark_channel_15x15 st2 (.clk(clk), .rst_n(rst_n), .i_valid(v1), .i_cmin(Cmin), .o_valid(v2), .o_dark(d_raw));

    // STAGE 3: Transmission Engine
    transmission_engine st3 (.clk(clk), .rst_n(rst_n), .i_valid(v2), .i_dark(d_raw), .o_valid(v3), .o_t(t_raw));

    // STAGE 4: Refinement 15x15 (Sync Pixel gốc 17929 cycles)
    refinement_15x15 st4 (.clk(clk), .rst_n(rst_n), .i_valid(v3), .i_pixel_raw(asi_data), .i_t_raw(t_raw), .o_valid(v4), .o_pixel_sync(p_sync), .o_t_refined(t_ref));

    // STAGE 4.5: Atmospheric Light (Adaptive)
    atmospheric_light_est st_ag (.clk(clk), .rst_n(rst_n), .i_valid(v4), .i_sof(i_sof), .i_pixel(p_sync), .i_t(t_ref), .o_Ag(auto_Ag));

    // STAGE 5: Image Restoration
    image_restoration_soc st5 (.clk(clk), .rst_n(rst_n), .i_valid(v4), .i_pixel_sync(p_sync), .i_t_refined(t_ref), .i_A(auto_Ag), .o_valid(v5), .o_pixel_dehazed(p_dehazed));

    // STAGE 6: Sharpening
    image_sharpening_soc st6 (.clk(clk), .rst_n(rst_n), .i_valid(v5), .i_pixel(p_dehazed), .i_k_idx(stat_sharp_idx[3:0]), .o_valid(v6), .o_pixel_sharp(p_sharp));

    // STAGE 7: Gamma Correction
    gamma_correction_soc st7 (.clk(clk), .rst_n(rst_n), .i_valid(v6), .i_pixel(p_sharp), .i_gamma_idx(stat_gamma_idx), .o_valid(v7), .o_pixel_final(p_final));

    assign aso_data  = p_final;
    assign aso_valid = v7;

endmodule

// ============================================================================
// STAGE 1: FEATURE EXTRACTION
// ============================================================================
module feature_extraction_soc (
    input wire clk, rst_n, i_valid, 
    input wire [7:0] i_r, i_g, i_b, 
    output reg o_valid, 
    output reg [9:0] o_V, o_S, 
    output reg [7:0] o_Cmin
);
    reg [7:0] rr, gr, br; reg v0;
    always @(posedge clk) begin rr <= i_r; gr <= i_g; br <= i_b; v0 <= i_valid; end
    reg [7:0] mar, mir; reg v1;
    always @(posedge clk) begin
        mar <= (rr>gr)?((rr>br)?rr:br):((gr>br)?gr:br);
        mir <= (rr<gr)?((rr<br)?rr:br):((gr<br)?gr:br);
        v1 <= v0;
    end
    wire [9:0] im; reciprocal_lut u_inv (.clk(clk), .address(mar), .q(im));
    reg [7:0] dr; reg [9:0] ir; reg [7:0] ms, mis; reg v2;
    always @(posedge clk) begin dr <= mar-mir; ir <= im; ms <= mar; mis <= mir; v2 <= v1; end
    wire [17:0] sp = dr * ir;
    always @(posedge clk or negedge rst_n) if (!rst_n) begin o_valid<=0; o_V<=0; o_S<=0; o_Cmin<=0; end
    else begin o_valid<=v2; o_V<={ms,2'b00}; o_S<=(sp>1023)?1023:sp[9:0]; o_Cmin<=mis; end
endmodule

// ============================================================================
// STAGE 2: DARK CHANNEL 15x15
// ============================================================================
module dark_channel_15x15 (input wire clk, rst_n, i_valid, input wire [7:0] i_cmin, output wire o_valid, output reg [7:0] o_dark);
    reg [7:0] h_s [0:14]; integer i;
    initial for (i=0; i<15; i=i+1) h_s[i] = 8'hFF;
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) for (i=0; i<15; i=i+1) h_s[i] <= 8'hFF;
        else if (i_valid) begin for (i=14; i>0; i=i-1) h_s[i] <= h_s[i-1]; h_s[0] <= i_cmin; end
    end
    function [7:0] m15(input [7:0] d0,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13,d14);
        reg [7:0] res; begin res = d0;
        if(d1<res)res=d1; if(d2<res)res=d2; if(d3<res)res=d3; if(d4<res)res=d4; if(d5<res)res=d5; if(d6<res)res=d6; 
        if(d7<res)res=d7; if(d8<res)res=d8; if(d9<res)res=d9; if(d10<res)res=d10; if(d11<res)res=d11; 
        if(d12<res)res=d12; if(d13<res)res=d13; if(d14<res)res=d14; m15=res; end
    endfunction
    wire [7:0] tp [0:14]; assign tp[0] = m15(h_s[0],h_s[1],h_s[2],h_s[3],h_s[4],h_s[5],h_s[6],h_s[7],h_s[8],h_s[9],h_s[10],h_s[11],h_s[12],h_s[13],h_s[14]);
    genvar k; generate for (k=0; k<14; k=k+1) begin : lb line_delay #(8, 640) u (clk, rst_n, tp[k], tp[k+1]); end endgenerate
    valid_delay_line #(8962) vd (clk, rst_n, i_valid, o_valid);
    always @(posedge clk or negedge rst_n) if (!rst_n) o_dark <= 255; 
    else o_dark <= m15(tp[0],tp[1],tp[2],tp[3],tp[4],tp[5],tp[6],tp[7],tp[8],tp[9],tp[10],tp[11],tp[12],tp[13],tp[14]);
endmodule

// ============================================================================
// STAGE 4: REFINEMENT 15x15
// ============================================================================
module refinement_15x15 (
    input wire clk, rst_n, i_valid, input wire [23:0] i_pixel_raw, input wire [9:0] i_t_raw, 
    output wire o_valid, output reg [23:0] o_pixel_sync, output reg [9:0] o_t_refined
);
    wire [23:0] dp;
    pixel_delay_line_huge #(24, 17942) ud (clk, rst_n, i_pixel_raw, dp);
    wire [9:0] t[0:14];
    line_buffer_15tap #(10, 640) lb_t (clk, rst_n, i_t_raw, t[0],t[1],t[2],t[3],t[4],t[5],t[6],t[7],t[8],t[9],t[10],t[11],t[12],t[13],t[14]);
    reg [13:0] v_sum; always @(posedge clk) v_sum <= t[0]+t[1]+t[2]+t[3]+t[4]+t[5]+t[6]+t[7]+t[8]+t[9]+t[10]+t[11]+t[12]+t[13]+t[14];
    reg [13:0] h_buf [0:14]; integer j;
    always @(posedge clk) begin for (j=14; j>0; j=j-1) h_buf[j] <= h_buf[j-1]; h_buf[0] <= v_sum; end
    reg [17:0] win_sum; always @(posedge clk) win_sum <= h_buf[0]+h_buf[1]+h_buf[2]+h_buf[3]+h_buf[4]+h_buf[5]+h_buf[6]+h_buf[7]+h_buf[8]+h_buf[9]+h_buf[10]+h_buf[11]+h_buf[12]+h_buf[13]+h_buf[14];
    valid_delay_line #(8975) vd_st4 (clk, rst_n, i_valid, o_valid);
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin o_pixel_sync <= 0; o_t_refined <= 1023; end
        else begin o_pixel_sync <= dp; o_t_refined <= (win_sum * 4660) >> 20; end
    end
endmodule

// ============================================================================
// STAGE 4.5: ATMOSPHERIC LIGHT (ADAPTIVE)
// ============================================================================
module atmospheric_light_est (
    input wire clk, rst_n, i_valid, i_sof, 
    input wire [23:0] i_pixel, input wire [9:0] i_t, 
    output reg [7:0] o_Ag
);
    reg [7:0] max_in_frame;
    wire [7:0] p_m = (i_pixel[23:16]>i_pixel[15:8])?((i_pixel[23:16]>i_pixel[7:0])?i_pixel[23:16]:i_pixel[7:0]):((i_pixel[15:8]>i_pixel[7:0])?i_pixel[15:8]:i_pixel[7:0]);
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin max_in_frame <= 220; o_Ag <= 220; end
        else if (i_sof) begin o_Ag <= max_in_frame; max_in_frame <= 0; end
        else if (i_valid) begin
            if (i_t < 102 && p_m > max_in_frame) max_in_frame <= p_m;
        end
    end
endmodule

// ============================================================================
// STAGE 5: IMAGE RESTORATION
// ============================================================================
module image_restoration_soc (
    input wire clk, rst_n, i_valid, 
    input wire [23:0] i_pixel_sync, input wire [9:0] i_t_refined, input wire [7:0] i_A, 
    output reg o_valid, output reg [23:0] o_pixel_dehazed
);
    wire [13:0] inv_t; inverse_t_lut uinv (.address(i_t_refined), .clk(clk), .q(inv_t));
    reg signed [17:0] r_d, g_d, b_d; reg [7:0] a_r; reg v_r;
    always @(posedge clk) begin
        r_d <= $signed({1'b0, i_pixel_sync[23:16]}) - $signed({1'b0, i_A});
        g_d <= $signed({1'b0, i_pixel_sync[15:8]})  - $signed({1'b0, i_A});
        b_d <= $signed({1'b0, i_pixel_sync[7:0]})   - $signed({1'b0, i_A});
        a_r <= i_A; v_r <= i_valid;
    end
    wire signed [31:0] pr = r_d * $signed({1'b0, inv_t});
    wire signed [31:0] pg = g_d * $signed({1'b0, inv_t});
    wire signed [31:0] pb = b_d * $signed({1'b0, inv_t});
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin o_pixel_dehazed <= 0; o_valid <= 0; end
        else begin
            o_valid <= v_r;
            o_pixel_dehazed[23:16] <= clp(pr >>> 10, a_r);
            o_pixel_dehazed[15:8]  <= clp(pg >>> 10, a_r);
            o_pixel_dehazed[7:0]   <= clp(pb >>> 10, a_r);
        end
    end
    function [7:0] clp(input signed [31:0] v, input [7:0] a); 
        reg signed [31:0] res; begin res = v + $signed({1'b0, a});
        if (res > 255) clp = 255; else if (res < 0) clp = 0; else clp = res[7:0]; end
    endfunction
endmodule

// ============================================================================
// HỆ THỐNG MODULE BỔ TRỢ
// ============================================================================
module line_delay #(parameter WIDTH=8, DELAY=640) (input wire clk, rst_n, input wire [WIDTH-1:0] i_data, output wire [WIDTH-1:0] o_data);
    reg [WIDTH-1:0] mem [0:DELAY-1]; reg [11:0] addr; integer i;
    initial begin addr = 0; for (i=0; i<DELAY; i=i+1) mem[i] = 0; end
    assign o_data = mem[addr];
    always @(posedge clk or negedge rst_n) if (!rst_n) addr <= 0; else begin mem[addr] <= i_data; addr <= (addr >= DELAY-1) ? 0 : addr + 1; end
endmodule

module pixel_delay_line_huge #(parameter WIDTH=24, DELAY=18000) (input wire clk, rst_n, input wire [WIDTH-1:0] i_data, output wire [WIDTH-1:0] o_data);
    reg [WIDTH-1:0] mem [0:DELAY-1]; reg [15:0] addr; integer i;
    initial begin addr = 0; for (i=0; i<DELAY; i=i+1) mem[i] = 0; end
    assign o_data = mem[addr];
    always @(posedge clk or negedge rst_n) if (!rst_n) addr <= 0; else begin mem[addr] <= i_data; addr <= (addr >= DELAY-1) ? 0 : addr + 1; end
endmodule

module inverse_t_lut (input wire [9:0] address, input wire clk, output reg [13:0] q);
    reg [13:0] rom [0:1023]; integer i; initial for (i=0; i<1024; i=i+1) rom[i] = (i < 100) ? 10240 : (1048576 / i);
    always @(posedge clk) q <= rom[address];
endmodule

module reciprocal_lut (input wire clk, input wire [7:0] address, output reg [9:0] q);
    reg [9:0] rom [0:255]; integer i; initial begin rom[0]=0; for (i=1; i<256; i=i+1) rom[i] = 1023/i; end
    always @(posedge clk) q <= rom[address];
endmodule

module valid_delay_line #(parameter DELAY=10) (input wire clk, rst_n, i_v, output wire o_v);
    reg [DELAY-1:0] sh; initial sh = 0; always @(posedge clk or negedge rst_n) if (!rst_n) sh <= 0; else sh <= {sh[DELAY-2:0], i_v};
    assign o_v = sh[DELAY-1];
endmodule

module line_buffer_15tap #(parameter WIDTH=8, SIZE=640) (input wire clk, rst_n, input wire [WIDTH-1:0] i_data, output wire [WIDTH-1:0] tap0, tap1, tap2, tap3, tap4, tap5, tap6, tap7, tap8, tap9, tap10, tap11, tap12, tap13, tap14);
    wire [WIDTH-1:0] c [0:14]; assign c[0] = i_data; genvar k;
    generate for (k=0; k<14; k=k+1) begin : tap_gen line_delay #(WIDTH, SIZE) u (clk, rst_n, c[k], c[k+1]); end endgenerate
    assign {tap0,tap1,tap2,tap3,tap4,tap5,tap6,tap7,tap8,tap9,tap10,tap11,tap12,tap13,tap14} = {c[0],c[1],c[2],c[3],c[4],c[5],c[6],c[7],c[8],c[9],c[10],c[11],c[12],c[13],c[14]};
endmodule

module transmission_engine (input wire clk, rst_n, i_valid, input wire [7:0] i_dark, output reg o_valid, output reg [9:0] o_t);
    reg [7:0] dr; reg v1; always @(posedge clk) begin dr <= i_dark; v1 <= i_valid; end
    reg [9:0] tl [0:255]; integer j; initial for (j=0; j<256; j=j+1) tl[j] = 1023 - (j * 3);
    always @(posedge clk or negedge rst_n) if (!rst_n) begin o_t <= 1023; o_valid <= 0; end
    else begin o_t <= tl[dr]; o_valid <= v1; end
endmodule

module image_sharpening_soc (input wire clk, rst_n, i_valid, input wire [23:0] i_pixel, input wire [3:0] i_k_idx, output wire o_valid, output reg [23:0] o_pixel_sharp);
    wire [7:0] r_t[0:2], g_t[0:2], b_t[0:2]; integer i; reg [7:0] wr[0:2][0:2], wg[0:2][0:2], wb[0:2][0:2];
    line_buffer_3tap lb_r (clk, rst_n, i_pixel[23:16], r_t[0], r_t[1], r_t[2]);
    line_buffer_3tap lb_g (clk, rst_n, i_pixel[15:8], g_t[0], g_t[1], g_t[2]);
    line_buffer_3tap lb_b (clk, rst_n, i_pixel[7:0], b_t[0], b_t[1], b_t[2]);
    always @(posedge clk) for(i=0; i<3; i=i+1) begin wr[i][0]<=r_t[i]; wr[i][1]<=wr[i][0]; wr[i][2]<=wr[i][1]; wg[i][0]<=g_t[i]; wg[i][1]<=wg[i][0]; wg[i][2]<=wg[i][1]; wb[i][0]<=b_t[i]; wb[i][1]<=wb[i][0]; wb[i][2]<=wb[i][1]; end
    function signed [11:0] lap(input [7:0] p01, p10, p11, p12, p21); lap = ($signed({4'b0, p11}) << 2) - $signed({4'b0, p01}) - $signed({4'b0, p21}) - $signed({4'b0, p10}) - $signed({4'b0, p12}); endfunction
    wire signed [15:0] sr = $signed({8'b0, wr[1][1]}) + ($signed({12'b0, i_k_idx}) * lap(wr[0][1], wr[1][0], wr[1][1], wr[1][2], wr[2][1]) / 4);
    wire signed [15:0] sg = $signed({8'b0, wg[1][1]}) + ($signed({12'b0, i_k_idx}) * lap(wg[0][1], wg[1][0], wg[1][1], wg[1][2], wg[2][1]) / 4);
    wire signed [15:0] sb = $signed({8'b0, wb[1][1]}) + ($signed({12'b0, i_k_idx}) * lap(wb[0][1], wb[1][0], wb[1][1], wb[1][2], wb[2][1]) / 4);
    valid_delay_line #(643) vd_st6 (clk, rst_n, i_valid, o_valid);
    always @(posedge clk) begin o_pixel_sharp[23:16] <= (sr>255)?255:(sr<0?0:sr[7:0]); o_pixel_sharp[15:8] <= (sg>255)?255:(sg<0?0:sg[7:0]); o_pixel_sharp[7:0] <= (sb>255)?255:(sb<0?0:sb[7:0]); end
endmodule

module line_buffer_3tap (input wire clk, rst_n, input wire [7:0] i_data, output wire [7:0] tap0, tap1, tap2);
    wire [7:0] c1, c2; line_delay #(8, 640) u1 (clk, rst_n, i_data, c1); line_delay #(8, 640) u2 (clk, rst_n, c1, c2);
    assign tap0 = i_data; assign tap1 = c1; assign tap2 = c2;
endmodule

module gamma_correction_soc (input wire clk, rst_n, i_valid, input wire [23:0] i_pixel, input wire [4:0] i_gamma_idx, output reg o_valid, output reg [23:0] o_pixel_final);
    reg [7:0] rom [0:2047]; integer g, p; initial begin for (g=0; g<8; g=g+1) for (p=0; p<256; p=p+1) rom[g*256+p] = p; for (p=0; p<256; p=p+1) rom[6*256+p] = (p == 0) ? 0 : (255 * (p/255.0)**(1.0/0.8)); end
    always @(posedge clk) begin o_valid <= i_valid; o_pixel_final[23:16] <= rom[{i_gamma_idx[2:0], i_pixel[23:16]}]; o_pixel_final[15:8] <= rom[{i_gamma_idx[2:0], i_pixel[15:8]}]; o_pixel_final[7:0] <= rom[{i_gamma_idx[2:0], i_pixel[7:0]}]; end
endmodule