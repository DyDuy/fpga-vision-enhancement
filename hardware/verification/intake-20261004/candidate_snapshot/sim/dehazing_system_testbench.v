`timescale 1ns / 1ps

module dehazing_system_testbench();
    reg clk, rst_n, sw_bypass;

    reg [29:0] snk_data;
    reg snk_valid, snk_sop, snk_eop;
    wire snk_ready;

    wire [29:0] src_data;
    wire src_valid, src_sop, src_eop;
    reg src_ready;

    integer f_in, f_out, status;
    reg [23:0] pix_rgb;
    integer x, y;

    dehazing_system_top dut (
        .clk(clk), .rst_n(rst_n),
        .sw_bypass(sw_bypass),
        .snk_data(snk_data), .snk_valid(snk_valid), .snk_ready(snk_ready),
        .snk_sop(snk_sop), .snk_eop(snk_eop),
        .src_data(src_data), .src_valid(src_valid), .src_ready(src_ready),
        .src_sop(src_sop), .src_eop(src_eop)
    );

    // Tạo xung Clock 100MHz (Chu kỳ 10ns)
    always #5 clk = ~clk;

    initial begin
        clk = 0; rst_n = 0; src_ready = 1;
        sw_bypass = 1; // 1: Xem ảnh đã xử lý khử sương, 0: Xem ảnh gốc bị delay
        snk_valid = 0; snk_data = 0; snk_sop = 0; snk_eop = 0;

        #100 rst_n = 1;
        $display("Starting Simulation: Guided Filter Edition (1943 cycles delay)...");

        f_in = $fopen("input_image.hex", "r");
        f_out = $fopen("output_image.hex", "w");

        if (f_in == 0) begin
            $display("FATAL ERROR: input_image.hex not found!");
            $stop;
        end

        $display("Sending Video Frame (640x480)...");
        for (y = 0; y < 480; y = y + 1) begin
            for (x = 0; x < 640; x = x + 1) begin
                status = $fscanf(f_in, "%x\n", pix_rgb);
                if (status != 1) pix_rgb = 24'h0;

                @(posedge clk);
                // Chờ hệ thống sẵn sàng mới đẩy data (Backpressure support)
                while (!snk_ready) @(posedge clk);

                snk_valid <= 1;
                // Padding 2 bit LSB thành 0 cho chuẩn 10-bit color/channel
                snk_data <= {pix_rgb[23:16], pix_rgb[23:22], pix_rgb[15:8], pix_rgb[15:14], pix_rgb[7:0], pix_rgb[7:6]};
                snk_sop <= (x == 0 && y == 0);
                snk_eop <= (x == 639 && y == 479);
            end
        end

        // Kết thúc luồng dữ liệu vào
        @(posedge clk);
        snk_valid <= 0; snk_sop <= 0; snk_eop <= 0;

                $display("Input stream finished. Flushing pipeline (~1943 cycles)...");
        repeat (1291) @(posedge clk);

        $display("Simulation Finished. Results saved to output_image.hex");
        $fclose(f_in); 
        $fclose(f_out);
        $stop;
    end

    // Khối ghi dữ liệu đầu ra để kiểm tra với Python/MATLAB
    reg recording;
    initial recording = 0;

    always @(posedge clk) begin
        // Bắt đầu ghi khi thấy Start of Packet (SOP)
        if (src_valid && src_sop) recording <= 1;
        // Dừng ghi khi thấy End of Packet (EOP)
        if (src_valid && src_eop) recording <= 0;

        // Trích xuất lại 24-bit RGB (Bỏ 2 bit LSB) để ghi ra file hex
        if (src_valid && (recording || src_sop)) begin
            $fdisplay(f_out, "%06x", {src_data[29:22], src_data[19:12], src_data[9:2]});
        end
    end
endmodule