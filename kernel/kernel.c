// Tyler`s kernel
// Copyright nergzd723, 2019
#include "asint.h"
#include "assembly_interface.h"
#include "fbh.h"
#include "pic.h"
#include "serial_port.h"
#include "interrupts.h"
#include "stdio.h"
#include "types.h"
#include "global_descriptor_table.h"
#include "interrupt_descriptor_table.h"

void kernel_main() {
  clear_screen();
  // printf(welcome_string);
  serial_init();
  log("Initialized serial port.\n");
  initialize_gdt();
  log("Loaded global descriptor table.\n");
  initialize_idt();
  log("Loaded interrupt descriptor table.\n");
  log("Returned from test interrupt()\n");
  pic_init();
  log("Initialized PIC\n");
  render_pic();
  // Loop forever
  // User input is accepted asynchronously via interrupts
  while(1){}
}