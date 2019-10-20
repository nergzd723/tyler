#include "irq.h"
void interrupt_handler() {
  log("interrupt_handler()\n");
  while(1){}
} 