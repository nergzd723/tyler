#ifndef INCLUDE_ASSEMBLY_INTERFACE_H
#define INCLUDE_ASSEMBLY_INTERFACE_H
#include "types.h"
void outb(unsigned short port, unsigned char data);
unsigned char inb(unsigned short port);
//load GDT
void load_gdt(void* gdt);
void halt();
void load_idt(void * idt);
void panic(char* panicmessage);
void interrupt(uint32_t interrupt_number);
void enterpm();
#endif