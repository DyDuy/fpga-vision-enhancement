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

    // UD_DELAY = so chu ky tu dau vao den v4 (st1..st4), da +1 vi
    // transmission_engine (st3) gio la 2 chu ky (pipeline ROM 65536-entry
    // de fix timing) thay vi 1: 1(st1)+1(st2)+2(st3)+1(st4) = 5
    localparam UD_DELAY    = 5;

    // TONG TRE: UD_DELAY(5) + Khoi phuc st5(4) + Gamma st6(2) = 11
    localparam TOTAL_DELAY = 11;

    // 1. Đồng bộ luồng điều khiển khung hình tổng (SOP/EOP/Valid)
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
    common_delay_line #(1, UD_DELAY) sof_delay (
        .clk(clk),
        .rst_n(rst_n),
        .i_en(i_en),
        .i_v(snk_sop),
        .i_data(snk_sop),
        .o_data(sof_sync)
    );

    // --- KHAI BÁO CÁC TÍN HIỆU KẾT NỐI NỘI BỘ ---
    // Đã xóa v_sharp và p_sharp
    wire v1, v2, v3, v4, v5, v6;
    wire [7:0] cmax_st1, cmin_st1;
    wire [7:0] cmax_st2, cmin_st2;
    wire [9:0] t_raw, t_ref;
    wire [7:0] auto_Ag;
    wire [23:0] p_sync, p_dehazed, p_gamma;

    // --- PIPELINE XỬ LÝ SỐ TÍN HIỆU ẢNH ---

    // Stage 1: Trích xuất cả Cmax và Cmin
    feature_extraction_soc st1 (
        .clk(clk), .rst_n(rst_n), .i_en(i_en), .i_valid(snk_valid),
        .i_r(ir), .i_g(ig), .i_b(ib),
        .o_valid(v1), .o_Cmax(cmax_st1), .o_Cmin(cmin_st1)
    );

    // Stage 2: Thanh ghi đồng bộ trễ 1 nhịp cho Cmax và Cmin
    dark_channel_1x1 st2 (
        .clk(clk), .rst_n(rst_n), .i_en(i_en), .i_valid(v1),
        .i_cmax(cmax_st1), .i_cmin(cmin_st1),
        .o_valid(v2), .o_cmax_reg(cmax_st2), .o_cmin_reg(cmin_st2)
    );

    // Stage 3: Khối tính toán truyền dẫn sử dụng 2D LUT (M10K ROM)
    transmission_engine st3 (
        .clk(clk), .rst_n(rst_n), .i_en(i_en), .i_valid(v2),
        .i_cmax(cmax_st2), .i_cmin(cmin_st2),
        .o_valid(v3), .o_t(t_raw)
    );

    // Pixel Sync Buffer: Khóa dữ liệu RGB gốc đúng 4 nhịp chờ bản đồ truyền dẫn
    common_delay_line #(24, UD_DELAY) ud_inst (
        .clk(clk), .rst_n(rst_n), .i_en(i_en), .i_v(snk_valid),
        .i_data({ir, ig, ib}), .o_data(p_sync)
    );

    // Stage 4: Buffer bản đồ truyền dẫn
    // Tang do sau khu suong: giam STRENGTH xuong duoi 256 (vd 230 de
    // khu manh hon ~10%, hoac 205 cho ~20%). Giu 256 = hanh vi cu, khong doi.
    refinement_1x1 #(.STRENGTH(256), .T_FLOOR(102)) st4 (
        .clk(clk), .rst_n(rst_n), .i_en(i_en), .i_valid(v3),
        .i_t_raw(t_raw),
        .o_valid(v4), .o_t_refined(t_ref)
    );

    // Khối ước lượng ánh sáng khí quyển
    atmospheric_light_est st_ag (
        .clk(clk), .rst_n(rst_n), .i_en(i_en), .i_valid(v4),
        .i_sof(sof_sync), .i_pixel(p_sync), .i_t(t_ref),
        .o_Ag(auto_Ag)
    );

    // Stage 5: Khôi phục ảnh gốc
    image_restoration_soc st5 (
        .clk(clk), .rst_n(rst_n), .i_en(i_en), .i_valid(v4),
        .i_pixel_sync(p_sync), .i_t_refined(t_ref), .i_A(auto_Ag),
        .o_valid(v5), .o_pixel_dehazed(p_dehazed)
    );

    // Stage 6: Bù sáng Gamma (Nhận trực tiếp đầu vào từ khối khôi phục st5)
    gamma_correction_soc st6 (
        .clk(clk), .rst_n(rst_n), .i_en(i_en), .i_valid(v5),
        .i_pixel(p_dehazed),
        .o_valid(v6), .o_pixel_gamma(p_gamma)
    );

    // --- ĐẦU RA MẠCH MUX ĐỒNG BỘ ---
    assign {src_sop, src_eop, src_valid} = {p_out[32], p_out[31], p_out[30]};
    wire [29:0] raw_data_delayed = p_out[29:0];
    wire [29:0] processed_data = {
        p_gamma[23:16], p_gamma[23:22],
        p_gamma[15:8],  p_gamma[15:14],
        p_gamma[7:0],   p_gamma[7:6]
    };

    assign src_data = sw_bypass ? processed_data : raw_data_delayed;

endmodule


// =======================================================================
// MODULE GAMMA CORRECTION SOC (LÀM TỐI ẢNH - TRỄ 2 CHU KỲ CLOCK)
// =======================================================================
module gamma_correction_soc (
    input  wire        clk, rst_n, i_en, i_valid,
    input  wire [23:0] i_pixel,
    output reg         o_valid,
    output reg  [23:0] o_pixel_gamma
);
    wire [7:0] g_r, g_g, g_b;
    reg v_r1;

    gamma_lut lut_r (.clk(clk), .addr(i_pixel[23:16]), .q(g_r));
    gamma_lut lut_g (.clk(clk), .addr(i_pixel[15:8]),  .q(g_g));
    gamma_lut lut_b (.clk(clk), .addr(i_pixel[7:0]),   .q(g_b));

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            v_r1          <= 1'b0;
            o_valid       <= 1'b0;
            o_pixel_gamma <= 24'd0;
        end
        else if (i_en) begin
            v_r1    <= i_valid; // Chu kỳ trễ thứ nhất đồng bộ với ngõ ra của ROM M10K
            o_valid <= v_r1;    // Chu kỳ trễ thứ hai đồng bộ với thanh ghi gán dữ liệu màu
            if (v_r1) o_pixel_gamma <= {g_r, g_g, g_b};
        end
    end
endmodule

module gamma_lut (
    input  wire       clk,
    input  wire [7:0] addr,
    output reg  [7:0] q
);
    (* ramstyle = "M10K" *) reg [7:0] rom [0:255];

    initial begin
        $readmemh("gamma_lut_data.hex", rom);
    end

    always @(posedge clk) begin
        q <= rom[addr];
    end
endmodule

// =======================================================================
// KHỐI ĐỆM DÒNG RAM & ĐƯỜNG DELAY ĐIỀU KHIỂN
// =======================================================================
module common_delay_line #(parameter WIDTH=8, DELAY=640) (
    input  wire             clk, rst_n, i_en, i_v,
    input  wire [WIDTH-1:0] i_data,
    output reg  [WIDTH-1:0] o_data
);
    (* ramstyle = "M10K" *) reg [WIDTH-1:0] mem [0:DELAY-1];
    reg [$clog2(DELAY)-1:0] addr;
    always @(posedge clk) begin
        if (!rst_n) begin
            addr <= 0;
            o_data <= 0;
        end
        else if (i_en) begin
            mem[addr] <= i_data;
            o_data    <= mem[addr];
            addr      <= (addr >= DELAY-1) ? 0 : addr + 1;
        end
    end
endmodule

module valid_delay_line #(parameter DELAY=10) (
    input wire clk, rst_n, i_en, i_v,
    output wire o_v
);
    generate
        if (DELAY <= 0) begin : d0
            assign o_v = i_v;
        end
        else if (DELAY == 1) begin : d1
            reg delay_reg;
            always @(posedge clk or negedge rst_n) begin
                if (!rst_n) delay_reg <= 1'b0;
                else if (i_en) delay_reg <= i_v;
            end
            assign o_v = delay_reg;
        end
        else begin : dN
            reg [DELAY-1:0] delay_reg;
            always @(posedge clk or negedge rst_n) begin
                if (!rst_n) begin
                    delay_reg <= {DELAY{1'b0}};
                end
                else if (i_en) begin
                    delay_reg <= {delay_reg[DELAY-2:0], i_v};
                end
            end
            assign o_v = delay_reg[DELAY-1];
        end
    endgenerate
endmodule

// =======================================================================
// CÁC MODULE PIPELINE XỬ LÝ ẢNH DEHAZING
// =======================================================================
module feature_extraction_soc (
    input  wire        clk, rst_n, i_en, i_valid,
    input  wire [7:0]  i_r, i_g, i_b,
    output reg         o_valid,
    output reg  [7:0]  o_Cmax,
    output reg  [7:0]  o_Cmin
);
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            o_valid <= 1'b0;
            o_Cmax   <= 8'd0;
            o_Cmin   <= 8'd0;
        end
        else if (i_en) begin
            o_valid <= i_valid;
            // Tìm Max(R,G,B)
            o_Cmax  <= (i_r > i_g) ? ((i_r > i_b) ? i_r : i_b) : ((i_g > i_b) ? i_g : i_b);
            // Tìm Min(R,G,B)
            o_Cmin  <= (i_r < i_g) ? ((i_r < i_b) ? i_r : i_b) : ((i_g < i_b) ? i_g : i_b);
        end
    end
endmodule

module dark_channel_1x1 (
    input wire clk, rst_n, i_en, i_valid,
    input wire [7:0] i_cmax,
    input wire [7:0] i_cmin,
    output wire o_valid,
    output reg [7:0] o_cmax_reg,
    output reg [7:0] o_cmin_reg
);
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            o_cmax_reg <= 8'd0;
            o_cmin_reg <= 8'd0;
        end
        else if (i_en) begin
            o_cmax_reg <= i_cmax;
            o_cmin_reg <= i_cmin;
        end
    end
    valid_delay_line #(1) vd (clk, rst_n, i_en, i_valid, o_valid);
endmodule

module transmission_engine (
    input  wire        clk, rst_n, i_en, i_valid,
    input  wire [7:0]  i_cmax,
    input  wire [7:0]  i_cmin,
    output reg         o_valid,
    output reg  [9:0]  o_t
);

    (* ramstyle = "M10K" *) reg [9:0] transmission_lut [0:65535];
    wire [15:0] rom_addr = {i_cmax, i_cmin};

    initial begin
        $readmemh("transmission_lut_data.hex", transmission_lut);
    end

    // Stage A: doc tho tu ROM (co the con chua duong mux chon khoi M10K)
    reg [9:0] rom_q;
    reg       v_a;
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            rom_q <= 10'd1023;
            v_a   <= 1'b0;
        end
        else if (i_en) begin
            rom_q <= transmission_lut[rom_addr];
            v_a   <= i_valid;
        end
    end

    // Stage B: dem output rieng 1 chu ky, dam bao khong con to hop dai
    // truoc thanh ghi cuoi cung o_t
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            o_valid <= 1'b0;
            o_t     <= 10'd1023;
        end
        else if (i_en) begin
            o_t     <= rom_q;
            o_valid <= v_a;
        end
    end
endmodule

module refinement_1x1 #(
    // STRENGTH: he so thu nho transmission t (dang fixed-point Q1.8,
    // 256 = x1.00 khong doi). Giam STRENGTH -> t nho hon -> khu suong
    // SAU hon (tuong duong tang omega trong cong thuc DCP goc).
    // Vi du:
    //   256 = giu nguyen (mac dinh, khop voi .hex hien tai)
    //   230 = t *= 0.90  -> khu suong manh hon ~10%
    //   205 = t *= 0.80  -> khu suong manh hon ~20% (de bat dau xuat hien
    //                       nhieu/artifact o vung it suong, can theo doi)
    // T_FLOOR: gia tri san toi thieu cua t sau khi thu nho, tranh chia
    // cho so qua nho gay khuech dai nhieu qua muc (DCP goc khuyen nghi
    // t0 ~ 0.1, tuc ~102/1023 theo thang 10-bit dang dung o day).
    parameter STRENGTH = 256,
    parameter T_FLOOR   = 102
)(
    input wire clk, rst_n, i_en, i_valid,
    input wire [9:0] i_t_raw,
    output wire o_valid,
    output reg [9:0] o_t_refined
);
    wire [17:0] t_scaled_w = i_t_raw * STRENGTH;   // Q1.8 -> can >>8
    wire [9:0]  t_scaled   = t_scaled_w[17:8];
    wire [9:0]  t_clamped  = (t_scaled < T_FLOOR) ? T_FLOOR : t_scaled;

    always @(posedge clk) begin
        if (!rst_n) o_t_refined <= 0;
        else if (i_en) o_t_refined <= t_clamped;
    end
    valid_delay_line #(1) vd_st4 (clk, rst_n, i_en, i_valid, o_valid);
endmodule

// =======================================================================
// MODULE RESTORATION - PIPELINED (4 STAGES) ĐỂ FIX LỖI SETUP SLACK -12ns
// =======================================================================
module image_restoration_soc (
    input  wire        clk, rst_n, i_en, i_valid,
    input  wire [23:0] i_pixel_sync,
    input  wire [9:0]  i_t_refined,
    input  wire [7:0]  i_A,
    output reg         o_valid,
    output reg  [23:0] o_pixel_dehazed
);
    // --- STAGE 1: Tính hiệu (Pixel - A) và Yêu cầu tra bảng ROM ---
    wire [13:0] inv_t;
    inverse_t_lut uinv (.address(i_t_refined), .clk(clk), .q(inv_t));

    reg signed [17:0] r_d, g_d, b_d;
    reg [7:0] a_st1;
    reg v_st1;

    always @(posedge clk) begin
        if (!rst_n) begin
            r_d <= 0; g_d <= 0; b_d <= 0; a_st1 <= 0; v_st1 <= 1'b0;
        end
        else if (i_en) begin
            // Trừ đi ánh sáng khí quyển A (Có dấu)
            r_d   <= $signed({1'b0, i_pixel_sync[23:16]}) - $signed({1'b0, i_A});
            g_d   <= $signed({1'b0, i_pixel_sync[15:8]})  - $signed({1'b0, i_A});
            b_d   <= $signed({1'b0, i_pixel_sync[7:0]})   - $signed({1'b0, i_A});
            a_st1 <= i_A;
            v_st1 <= i_valid;
        end
    end

    // --- STAGE 2: Khối Phép Nhân (Multiplier / DSP Blocks) ---
    // Dữ liệu inv_t từ ROM sẽ sẵn sàng ở chu kỳ này
    reg signed [31:0] r_mult, g_mult, b_mult;
    reg [7:0] a_st2;
    reg v_st2;

    always @(posedge clk) begin
        if (!rst_n) begin
            r_mult <= 0; g_mult <= 0; b_mult <= 0; a_st2 <= 0; v_st2 <= 1'b0;
        end
        else if (i_en) begin
            r_mult <= r_d * $signed({1'b0, inv_t});
            g_mult <= g_d * $signed({1'b0, inv_t});
            b_mult <= b_d * $signed({1'b0, inv_t});
            a_st2  <= a_st1;
            v_st2  <= v_st1;
        end
    end

    // --- STAGE 3: Dịch bit (Chia) và Cộng bù A ---
    reg signed [31:0] r_add, g_add, b_add;
    reg v_st3;

    always @(posedge clk) begin
        if (!rst_n) begin
            r_add <= 0; g_add <= 0; b_add <= 0; v_st3 <= 1'b0;
        end
        else if (i_en) begin
            r_add <= (r_mult >>> 10) + $signed({1'b0, a_st2});
            g_add <= (g_mult >>> 10) + $signed({1'b0, a_st2});
            b_add <= (b_mult >>> 10) + $signed({1'b0, a_st2});
            v_st3 <= v_st2;
        end
    end

    // --- STAGE 4: Cắt giới hạn (Clipping 0 - 255) và Xuất Output ---
    always @(posedge clk) begin
        if (!rst_n) begin
            o_valid <= 1'b0;
            o_pixel_dehazed <= 24'd0;
        end
        else if (i_en) begin
            o_valid <= v_st3;
            if (v_st3) begin
                // Clipping RGB trực tiếp không dùng function để Quartus tổng hợp nhanh nhất
                o_pixel_dehazed[23:16] <= (r_add > 255) ? 8'd255 : ((r_add < 0) ? 8'd0 : r_add[7:0]);
                o_pixel_dehazed[15:8]  <= (g_add > 255) ? 8'd255 : ((g_add < 0) ? 8'd0 : g_add[7:0]);
                o_pixel_dehazed[7:0]   <= (b_add > 255) ? 8'd255 : ((b_add < 0) ? 8'd0 : b_add[7:0]);
            end
        end
    end
endmodule
module inverse_t_lut (
    input  wire [9:0] address,
    input  wire       clk,
    output reg  [13:0] q
);
    (* ramstyle = "M10K" *) reg [13:0] rom [0:1023];
    integer i;
    initial for (i=0; i<1024; i=i+1) rom[i] = (i < 100) ? 10240 : (1048576 / i);
    always @(posedge clk) q <= rom[address];
endmodule

module atmospheric_light_est (
    input  wire        clk, rst_n, i_en, i_valid, i_sof,
    input  wire [23:0] i_pixel,
    input  wire [9:0]  i_t,
    output reg  [7:0]  o_Ag
);
    reg [7:0] max_r;
    wire [7:0] p_m = (i_pixel[23:16]>i_pixel[15:8])?((i_pixel[23:16]>i_pixel[7:0])?i_pixel[23:16]:i_pixel[7:0]):((i_pixel[15:8]>i_pixel[7:0])?i_pixel[15:8]:i_pixel[7:0]);

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            max_r <= 0;
            o_Ag  <= 220;
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