#define SERIAL_COM1_BASE                0x3F8

void serial_init(unsigned short com);
void serial_write(unsigned short com, char * s);
