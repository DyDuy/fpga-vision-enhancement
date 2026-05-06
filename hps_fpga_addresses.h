#ifndef HPS_FPGA_ADDRESSES_H
#define HPS_FPGA_ADDRESSES_H

/* === Cyclone V HPS Bridge Bases === */
#define HPS_TO_FPGA_BASE         0xC0000000   // Heavyweight Bridge (64-bit)
#define HPS_TO_FPGA_SPAN         0x10000000   // 256MB
#define LWHPS_BASE               0xFF200000   // Lightweight Bridge (32-bit)
#define LWHPS_SPAN               0x00200000   // 2MB

/* === SDRAM & Peripheral Offsets (Dựa trên filediachi.jpg) === */
#define SDRAM_BASE               0x00000000   // SDRAM vật lý bắt đầu từ 0x0
#define PIXEL_DMA_CTRL_BASE      0x00003020   // Bộ điều khiển VGA Pixel DMA
#define VIDEO_IN_DMA_CTRL_BASE   0x00003060   // Bộ điều khiển Video-In DMA (nếu dùng)

/* === Thông số màn hình & Quét === */
#define SCREEN_WIDTH             640
#define SCREEN_HEIGHT            480
#define DMA_STRIDE               1024         // Bước nhảy dòng 1024 pixels

#endif
