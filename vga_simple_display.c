#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stdint.h>
#include "hps_fpga_addresses.h"

/**
 * CHƯƠNG TRÌNH ĐIỀU KHIỂN LUỒNG VIDEO TÍCH HỢP (V23.0 - INLINE PIPELINE)
 * Tác giả: Duy Khanh & Gemini CLI
 * 
 * LUỒNG DỮ LIỆU:
 * SD Card -> SDRAM -> Pixel_DMA -> RGB_Resampler -> DEHAZING -> VGA
 * 
 * ĐẶC ĐIỂM GIẢI PHẪU:
 * 1. ĐỊA CHỈ: Khớp 100% với filediachi.jpg (DMA tại 0x3020).
 * 2. QUÉT MÀN HÌNH: Cornell Style (y << 10) để tối ưu nhịp quét.
 * 3. ĐÓNG GÓI: Ghi 24-bit RGB chuẩn (0xRRGGBB). Bộ Resampler của Altera 
 *    sẽ tự động "phình" lên 30-bit cho IP Dehazing xử lý.
 */

int main(int argc, char **argv) {
    int fd;
    int x, y;
    void *h2f_virtual, *lw_virtual;
    volatile uint32_t *vga_dma_ctrl;
    uint32_t *sdram_ptr;
    FILE *fp;
    uint32_t hex_val;
    char *filename = (argc > 1) ? argv[1] : "input_image.hex";

    // 1. MỞ BỘ NHỚ HỆ THỐNG
    if( ( fd = open( "/dev/mem", ( O_RDWR | O_SYNC ) ) ) == -1 ) {
        printf( "ERROR: could not open \"/dev/mem\"...\n" );
        return( 1 );
    }

    // Map SDRAM qua cầu Heavyweight (C0000000)
    h2f_virtual = mmap( NULL, HPS_TO_FPGA_SPAN, ( PROT_READ | PROT_WRITE ), MAP_SHARED, fd, HPS_TO_FPGA_BASE );
    // Map IP Control qua cầu Lightweight (FF200000)
    lw_virtual  = mmap( NULL, LWHPS_SPAN, ( PROT_READ | PROT_WRITE ), MAP_SHARED, fd, LWHPS_BASE );

    if( h2f_virtual == MAP_FAILED || lw_virtual == MAP_FAILED ) {
        printf( "ERROR: mmap failed\n" ); close( fd ); return( 1 );
    }

    // Gán con trỏ điều khiển chuẩn theo Qsys
    sdram_ptr    = (uint32_t *)(h2f_virtual + SDRAM_BASE);
    vga_dma_ctrl = (uint32_t *)(lw_virtual  + PIXEL_DMA_CTRL_BASE);

    // 2. BƯỚC 1: XÓA SẠCH SDRAM (Cornell Sanitization)
    // Triệt tiêu rác và vệt đen đáy ngay từ đầu.
    printf("Cleaning SDRAM buffer...\n");
    for (y = 0; y < 480; y++) {
        for (x = 0; x < 640; x++) {
            sdram_ptr[(y << 10) + x] = 0;
        }
    }

    // 3. BƯỚC 2: QUÉT VÀ NẠP ẢNH HEX (Ghi 24-bit chuẩn cho Resampler)
    fp = fopen(filename, "r");
    if (!fp) { printf("ERROR: File %s missing!\n", filename); goto cleanup; }

    printf("Step 1: Loading %s and sending to Inline Pipeline...\n", filename);
    for (y = 0; y < 480; y++) {
        for (x = 0; x < 640; x++) {
            if (fscanf(fp, "%x", &hex_val) != EOF) {
                // Nhịp quét Cornell: (y << 10) + x
                // Giá trị: 0xRRGGBB (Resampler sẽ tự nâng cấp lên 30-bit)
                sdram_ptr[(y << 10) + x] = hex_val;
            }
        }
    }
    fclose(fp);
    printf("Image loaded successfully into SDRAM.\n");

    // 4. BƯỚC 3: KÍCH HOẠT QUÉT PHẦN CỨNG (VGA Display)
    printf("Step 2: Activating VGA Pixel DMA at 0x3020...\n");
    
    // Altera Pixel DMA: Nạp địa chỉ vào Back Buffer [1] rồi Swap [0]
    vga_dma_ctrl[1] = 0x00000000; // Địa chỉ SDRAM vật lý
    vga_dma_ctrl[0] = 1;          // Start/Swap lệnh hiển thị

    printf("--- SYSTEM ONLINE ---\n");
    printf("The image is flowing through: DMA -> Resampler -> Dehazing -> VGA\n");

    // 5. DUY TRÌ HỆ THỐNG
    while(1) {
        sleep(60); 
    }

cleanup:
    munmap(h2f_virtual, HPS_TO_FPGA_SPAN);
    munmap(lw_virtual, LWHPS_SPAN);
    close(fd);
    return 0;
}
