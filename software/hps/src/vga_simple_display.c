#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stdint.h>
#include "hps_fpga_addresses.h"

int main(int argc, char **argv) 
{
    int fd;
    int x, y;
    void *h2f_virtual, *lw_virtual;
    volatile uint32_t *vga_dma_ctrl;
    uint32_t *sdram_ptr;
    FILE *fp;
    uint32_t hex_val;
    char *filename = (argc > 1) ? argv[1] : "input_image.hex";
    if( ( fd = open( "/dev/mem", ( O_RDWR | O_SYNC ) ) ) == -1 ) 
    {
        printf( "ERROR: could not open \"/dev/mem\"...\n" );
        return( 1 );
    }
    h2f_virtual = mmap( NULL, HPS_TO_FPGA_SPAN, ( PROT_READ | PROT_WRITE ), MAP_SHARED, fd, HPS_TO_FPGA_BASE );
    lw_virtual  = mmap( NULL, LWHPS_SPAN, ( PROT_READ | PROT_WRITE ), MAP_SHARED, fd, LWHPS_BASE );
    if( h2f_virtual == MAP_FAILED || lw_virtual == MAP_FAILED ) 
    {
        printf( "ERROR: mmap failed\n" ); close( fd ); return( 1 );
    }
    sdram_ptr    = (uint32_t *)(h2f_virtual + SDRAM_BASE);
    vga_dma_ctrl = (uint32_t *)(lw_virtual  + PIXEL_DMA_CTRL_BASE);
    printf("Cleaning SDRAM buffer...\n");
    for (y = 0; y < 480; y++)
    {
        for (x = 0; x < 640; x++) 
        {
            sdram_ptr[(y << 10) + x] = 0;
        }
    }
    fp = fopen(filename, "r");
    if (!fp) { printf("ERROR: File %s missing!\n", filename); goto cleanup; }
    printf("Step 1: Loading %s and sending to Inline Pipeline...\n", filename);
    for (y = 0; y < 480; y++) 
    {
        for (x = 0; x < 640; x++) 
        {
            if (fscanf(fp, "%x", &hex_val) != EOF) 
            {
                sdram_ptr[(y << 10) + x] = hex_val;
            }
        }
    }
    fclose(fp);
    printf("Image loaded successfully into SDRAM.\n");
  
    printf("Step 2: Activating VGA Pixel DMA at 0x3020...\n");

    vga_dma_ctrl[1] = 0x00000000; 
    vga_dma_ctrl[0] = 1;          
    printf("--- SYSTEM ONLINE ---\n");
    printf("The image is flowing through: DMA -> Resampler -> Dehazing -> VGA\n");
    while(1) 
    {
        sleep(60);
    }
cleanup:
    munmap(h2f_virtual, HPS_TO_FPGA_SPAN);
    munmap(lw_virtual, LWHPS_SPAN);
    close(fd);
    return 0;
}
