// Tyler`s kernel
// Copyright nergzd723, 2019
#include "fb.h"
#include "communication.h"
#include "serial.h"

int kernel_main(){
    clear_screen();
    serial_init(SERIAL_COM1_BASE);
    fb_write("Tyler has been booted", FB_LIGHT_BLUE, FB_LIGHT_GREY);
    move_cursor(15, 0);
    fb_write("This text should be on row 15", FB_LIGHT_RED, FB_MAGENTA);
    move_cursor(16, 0);
    fb_write("Yes i know that the colorpalette is awful", FB_LIGHT_RED, FB_MAGENTA);
    move_cursor(17, 0);
    write(LOG, "Serial log?");
    while(1) {}
}