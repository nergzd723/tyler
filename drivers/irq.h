#ifndef INCLUDE_IRQ_H
#define INCLUDE_IRQ_H
#include "types.h"

struct cpu_state {
  uint32_t eax;
  uint32_t ebx;
  uint32_t ecx;
  uint32_t edx;
  uint32_t esi;
  uint32_t edi;
  uint32_t esp;
  uint32_t ebp;
} __attribute__((packed));

struct stack_state {
  uint32_t error_code;
  uint32_t eip;
  uint32_t cs;
  uint32_t eflags;
} __attribute__((packed));

void interrupt_handler(struct cpu_state cpu, struct stack_state stack, uint32_t interrupt);
void interrupt_handler_49();
void enable_keyboard_interrupts();
#endif