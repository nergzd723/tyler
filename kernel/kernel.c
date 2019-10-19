// Tyler`s kernel
// Copyright nergzd723, 2019
#include "fb.h"
int kernel_main(){
    fb_clear_screen();
    fb_write_cell(0, 'T', FB_GREEN, FB_DARK_GREY);
    fb_write_cell(1, 'Y', FB_GREEN, FB_DARK_GREY);
    fb_write_cell(2, 'L', FB_GREEN, FB_DARK_GREY);
    fb_write_cell(3, 'E', FB_GREEN, FB_DARK_GREY);
    fb_write_cell(4, 'R', FB_GREEN, FB_DARK_GREY);
    while(1) {}
}