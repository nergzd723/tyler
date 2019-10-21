// Tyler`s kernel
// Copyright nergzd723, 2019
#include "fbh.h"
#include "io.h"
#include "serial_port.h"
#include "types.h"
#include "dt.h"
#include "irq.h"

int kernel_main(){
    clear_screen();
    serial_init(SERIAL_COM1_BASE);
    fb_write("Yes i know that the colorpalette is awful");
    initialize_gdt();  
    write(LOG, "GDT init ");
    initialize_idt();
    log("IDT init ");
    enable_keyboard_interrupts();
    checkmate(FB_GREEN, FB_LIGHT_RED);
    while(1) {}
    return 1;
}