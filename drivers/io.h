#ifndef INCLUDE_IO_H
#define INCLUDE_IO_H
#include "types.h"
#define FB_COMMAND_PORT         0x3D4
#define FB_DATA_PORT            0x3D5
/* The I/O port commands */
#define FB_HIGH_BYTE_COMMAND    14
#define FB_LOW_BYTE_COMMAND     15
void outb(unsigned short port, unsigned char data);
unsigned char inb(unsigned short port);
//load GDT
void lgdt(void* gdt);
void halt();
void load_idt(void * idt);
void panic(char* panicmessage);
void interrupt(uint32_t interrupt_number);
#endif