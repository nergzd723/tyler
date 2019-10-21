#include "serial_port.h"
#include "fbh.h"
#include "io.h"

void write(FILE output_device, char * s) {
  switch (output_device) {
    case (SCREEN):
      fb_write(s);
      break;
    case (LOG):
      serial_write(SERIAL_COM1_BASE, s);
      break;
  }
}

//printf to screen
void printf(char * s) {
  write(SCREEN, s);
}

//output directly to serial
void log(char * s){
    write(LOG, s);
}
