#define SERIAL_COM1_BASE                0x3F8

void serial_init(unsigned short com);
void serial_write(unsigned char com, char * s);
void serial_write_byte(unsigned short b);

