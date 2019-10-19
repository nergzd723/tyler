#include "serial_port.h"
#include "fbh.h"
#include "io.h"
enum output_type {FRAMEBUFFER, LOG};

void write(enum output_type output_device, char * s) {
  switch (output_device) {
    case (FRAMEBUFFER):
      fb_write(s, FB_WHITE, FB_BLACK);
      break;
    case (LOG):
      serial_write(SERIAL_COM1_BASE, s);
      break;
  }
}

//printf to screen
void printf(char * s) {
  write(FRAMEBUFFER, s);
}

//output directly to serial
void log(char * s){
    write(LOG, s);
}
