#include "irq.h"
#include "fbh.h"
void interrupt_handler(struct cpu_state cpu, struct stack_state stack, uint32_t interrupt)
{
  log("interrupt_handler()\n");
  return;
} 