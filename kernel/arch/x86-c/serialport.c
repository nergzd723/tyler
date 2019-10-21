#include "serial_port.h"
#include "io.h"
#include "types.h"

#define SERIAL_DATA_PORT(base)          (base)
#define SERIAL_FIFO_COMMAND_PORT(base)  (base + 2)
#define SERIAL_LINE_COMMAND_PORT(base)  (base + 3)
#define SERIAL_MODEM_COMMAND_PORT(base) (base + 4)
#define SERIAL_LINE_STATUS_PORT(base)   (base + 5)
#define SERIAL_LINE_ENABLE_DLAB         0x80

void serial_write_byte(unsigned char b) {
    // Block until buffer is not full
    while (!serial_is_transmit_fifo_empty(SERIAL_COM1_BASE)) {}
    outb(SERIAL_DATA_PORT(SERIAL_COM1_BASE), b);
}

void serial_configure_baud_rate(unsigned short com, unsigned short divisor)
{
    outb(SERIAL_LINE_COMMAND_PORT(com),
         SERIAL_LINE_ENABLE_DLAB);
    outb(SERIAL_DATA_PORT(com),
         (divisor >> 8) & 0x00FF);
    outb(SERIAL_DATA_PORT(com),
         divisor & 0x00FF);
}

void serial_configure_line(int16 com)
{
    outb(SERIAL_LINE_COMMAND_PORT(com), 0x03);
}

void serial_configure_fifo(int16 com)
{
    outb(SERIAL_FIFO_COMMAND_PORT(com), 0xC7);
}

void serial_configure_modem(int16 com)
{
    outb(SERIAL_MODEM_COMMAND_PORT(com), 0x03);
}

void serial_init(int16 com) {
    serial_configure_baud_rate(com, 2);
    serial_configure_line(com);
    serial_configure_fifo(com);
    serial_configure_modem(com);
}

void serial_write(int16 com, char * s) {
    int i = 0;
    while (s[i]) {
        // Block until buffer is not full
        while (!inb(SERIAL_LINE_STATUS_PORT(com)) & 0x20) {}
        outb(SERIAL_DATA_PORT(com), s[i]);
        i++;
    }
}
