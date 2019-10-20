// Tyler`s kernel
// Copyright nergzd723, 2019
#include "fb.h"
#include "communication.h"
#include "serial.h"
#include "dt.h"
#include "panic.h"

int kernel_main(){
    clear_screen();
    serial_init(SERIAL_COM1_BASE);
    fb_write("Yes i know that the colorpalette is awful", FB_LIGHT_RED, FB_MAGENTA);
    initialize_gdt();  
    write(LOG, "GDT init ");
    initialize_idt();
    log("IDT init ");
    checkmate(FB_GREEN, FB_LIGHT_RED);
    while(1) {}
}