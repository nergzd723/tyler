#ifndef INCLUDE_KEYBOARD_H
#define INCLUDE_KEYBOARD_H
#include "types.h"

void keyboard_interrupt_handler();
uint8_t consume_scan_code();
#endif /* INCLUDE_KEYBOARD_H */ 