#ifndef INCLUDE_PANIC_H
#define INCLUDE_PANIC_H
#ifndef INCLUDE_COMMUNICATION_H
#include "usercomm.h"
#endif

void panic(char* panicmessage){
    fill_screen(FB_LIGHT_BLUE);
    write(FRAMEBUFFER, "\n\n\n\n\nPanicked successfully!\n\n\n");
    write(LOG, "Panicked! Error message: ");
    write(LOG, panicmessage);
    write(LOG, "\n");
    write(FRAMEBUFFER, panicmessage);
    halt();
}
#endif