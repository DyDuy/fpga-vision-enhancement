`timescale 1ns/1ps
module tb_dehazing;
    reg clk=0;
    always #5 clk=~clk;
    reg rst_n=0, sw_bypass=0, snk_valid=0, snk_sop=0, snk_eop=0, src_ready=0;
    reg [29:0] snk_data=0;
    wire snk_ready, src_valid, src_sop, src_eop;
    wire [29:0] src_data;
    dehazing_system_top dut(.*);

    // Independent transaction model: no DUT internal datapath is consulted.
    reg [7:0] gamma_rom[0:255];
    reg [9:0] transmission_rom[0:65535];
    bit ev[0:10], es[0:10], ee[0:10];
    reg [29:0] ed[0:10];
    bit meta=0, sync_mode=0, frame_mode=0;
    integer atmosphere=220, maximum=0;
    integer checks=0, accepted=0, seed=0;
    reg [31:0] rng;
    reg [32:0] last_output;
    bit last_reset=0;

    function automatic [31:0] next_random(input [31:0] x);
        next_random=x*32'd1664525+32'd1013904223;
    endfunction

    function automatic integer clamp(input integer value);
        if (value<0) clamp=0;
        else if (value>255) clamp=255;
        else clamp=value;
    endfunction

    task automatic fail(input string reason);
        $display("CHECK_FAIL seed=%0d accepted=%0d checks=%0d: %s",seed,accepted,checks,reason);
        $fatal(1,"scoreboard failure");
    endtask

    task automatic tick(input bit ready_i, valid_i, sop_i, eop_i, mode_i,
                        input [29:0] pixel_i, input bit reset_i);
        integer i,r,g,b,hi,lo,t,inv,a_used,jr,jg,jb;
        reg [7:0] gr,gg,gb;
        reg [29:0] processed;
        bit selected;
        begin
            @(negedge clk);
            src_ready=ready_i; snk_valid=valid_i; snk_sop=sop_i;
            snk_eop=eop_i; snk_data=pixel_i; sw_bypass=mode_i; rst_n=reset_i;
            @(posedge clk);
            if (!reset_i) begin
                for(i=0;i<11;i=i+1) begin ev[i]=0;es[i]=0;ee[i]=0;ed[i]=0;end
                meta=0;sync_mode=0;frame_mode=0;atmosphere=220;maximum=0;
            end else begin
                if (ready_i) begin
                    for(i=10;i>0;i=i-1) begin
                        ev[i]=ev[i-1];es[i]=es[i-1];ee[i]=ee[i-1];ed[i]=ed[i-1];
                    end
                    ev[0]=valid_i; es[0]=valid_i&&sop_i; ee[0]=valid_i&&eop_i;
                    ed[0]=0;
                    if(valid_i) begin
                        accepted=accepted+1;
                        selected=sop_i?sync_mode:frame_mode;
                        if(sop_i) frame_mode=sync_mode;
                        r=pixel_i[29:22];g=pixel_i[19:12];b=pixel_i[9:2];
                        hi=(r>g)?((r>b)?r:b):((g>b)?g:b);
                        lo=(r<g)?((r<b)?r:b):((g<b)?g:b);
                        t=transmission_rom[(hi<<8)|lo];
                        // Preserve the existing 18-bit product and 10-bit slice.
                        t=((t*256)&18'h3ffff)>>8;
                        if(t<102) t=102;
                        inv=(t<100)?10240:(1048576/t);
                        inv=inv&14'h3fff;
                        a_used=atmosphere;
                        jr=clamp((((r-a_used)*inv)>>>10)+a_used);
                        jg=clamp((((g-a_used)*inv)>>>10)+a_used);
                        jb=clamp((((b-a_used)*inv)>>>10)+a_used);
                        gr=gamma_rom[jr];gg=gamma_rom[jg];gb=gamma_rom[jb];
                        processed={gr,gr[7:6],gg,gg[7:6],gb,gb[7:6]};
                        ed[0]=selected?processed:pixel_i;
                        // Same-edge restoration consumes OLD A; SOP is excluded.
                        if(sop_i) begin
                            if(maximum>50) atmosphere=(15*atmosphere+maximum)>>4;
                            maximum=0;
                        end else if(t<220 && hi>maximum) maximum=hi;
                    end
                end
                // Two free-running synchronizer flops, independent of ready.
                sync_mode=meta;meta=mode_i;
            end
            #1;
            if(snk_ready!==src_ready) fail("ready contract");
            if(src_valid!==ev[10]) fail("11 enabled-stage valid/reset/bubble timing");
            if(src_sop!==es[10] || src_eop!==ee[10]) fail("ordered SOP/EOP");
            if(ev[10] && src_data!==ed[10]) begin
                $display("expected=%h actual=%h",ed[10],src_data);
                fail("ordered raw/processed pixel or frame mode");
            end
            if(reset_i && last_reset && !ready_i &&
               {src_valid,src_sop,src_eop,src_data}!==last_output)
                fail("output changed while stalled (including mode changes)");
            last_output={src_valid,src_sop,src_eop,src_data};last_reset=reset_i;
            checks=checks+1;
        end
    endtask

    // Direct estimator cases reach the preserved threshold even if the supplied
    // transmission ROM never does. This is separate from the transaction model.
    reg av=0, aso=0, ae=1, ar=0;
    reg [23:0] ap=0;
    reg [9:0] at=100;
    wire [7:0] aa;
    atmospheric_light_est probe(clk,ar,ae,av,aso,ap,at,aa);
    task automatic estimator_case(input bit valid_i,sof_i,en_i,
                                  input [23:0] pixel_i,input integer expected);
        @(negedge clk); av=valid_i;aso=sof_i;ae=en_i;ap=pixel_i;
        @(posedge clk);#1;
        if(aa!==expected[7:0]) fail("atmospheric valid SOF / old-A convention");
    endtask

    integer frame,pixel,stall,i;
    reg [29:0] value;
    bit mode_value,bubble;
    initial begin
        $readmemh("gamma_lut_data.hex",gamma_rom);
        $readmemh("transmission_lut_data.hex",transmission_rom);
        if(!$value$plusargs("SEED=%d",seed)) seed=0;
        rng=32'h12345678+seed;
        tick(0,0,0,0,0,0,0);tick(1,0,0,0,0,0,0);
        for(i=0;i<4;i=i+1) tick(1,0,1,1,1,0,1);
        for(frame=0;frame<16;frame=frame+1) begin
            // Let switch settle before SOP; subsequent changes must not alter
            // this frame, including an output held during backpressure.
            mode_value=frame[0];
            for(i=0;i<3;i=i+1) tick(1,0,1,0,mode_value,0,1);
            for(pixel=0;pixel<23;pixel=pixel+1) begin
                rng=next_random(rng);value=rng[29:0];
                stall=(rng>>28)&7;
                for(i=0;i<stall;i=i+1)
                    tick(0,1,pixel==0,pixel==22,i[0],value,1);
                tick(1,1,pixel==0,pixel==22,mode_value,value,1);
                rng=next_random(rng);bubble=rng[3];
                if(bubble) tick(1,0,1,1,!mode_value,~value,1);
            end
        end
        // Reset a populated pipeline while backpressured; then inject no SOP
        // requirement: a valid non-SOP pixel after reset must still pass.
        tick(0,1,1,0,1,30'h3fffffff,0);
        tick(0,0,0,0,0,0,1);
        tick(1,1,0,0,0,30'h12345678,1);
        for(i=0;i<14;i=i+1) tick(1,0,1,1,1,0,1);
        // Adjacent one-pixel frames, with no blanking assumed by the core.
        for(i=0;i<12;i=i+1) tick(1,1,1,1,i[0],i*30'h1020304,1);
        for(i=0;i<14;i=i+1) tick(1,0,0,0,0,0,1);
        @(negedge clk);ar=0;@(posedge clk);#1;ar=1;
        estimator_case(1,0,1,24'hc86432,220); // collect max200
        estimator_case(0,1,1,24'hffffff,220); // invalid SOP cannot commit
        estimator_case(1,1,0,24'hffffff,220); // stalled SOP cannot commit
        estimator_case(1,1,1,24'hffffff,218); // (220*15+200)>>4
        estimator_case(1,1,1,24'hffffff,218); // previous SOP excluded
        estimator_case(1,0,1,24'h283214,218); // max50 below strict >50
        estimator_case(1,1,1,24'hffffff,218);
        $display("CORE_PASS seed=%0d accepted=%0d edge_checks=%0d",seed,accepted,checks);
        $finish;
    end
endmodule
