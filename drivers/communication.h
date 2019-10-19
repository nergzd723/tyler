#include "serial_port.h"
#include "fbh.h"
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

void printf(char * s) {
  write(FRAMEBUFFER, s);
}