#include "irq.h"
#include "fbh.h"
#include "io.h"
#include "pic.h"
#include "kb.h"

void interrupt_handler(struct cpu_state cpu, struct stack_state stack, uint32_t interrupt_number)
{
  log("interrupt_handler()\n");
  if (cpu.eax) {}; // Avoid unused parameter error
  switch(interrupt_number) {
    case(0x00000009):
      consume_scan_code();
      pic_acknowledge(interrupt_number);
      break;
    default:
      log("Unhandled Interrupt: ");
      print_uint32(LOG, interrupt_number);
      log("\n");
      break;
  }
} 

void enable_keyboard_interrupts() {
  outb(0x21,0xfd);
  outb(0xa1,0xff);
  enable_hardware_interrupts();
}