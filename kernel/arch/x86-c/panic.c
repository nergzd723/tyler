#include "usercomm.h"
#include "fbh.h"
void panic(char* panicmessage){
    fill_screen(FB_LIGHT_BLUE);
    write(SCREEN, "\n\n\n\n\nPanicked successfully!\n\n\n");
    write(LOG, "Panicked! Error message: ");
    write(LOG, panicmessage);
    write(LOG, "\n");
    write(SCREEN, panicmessage);
    halt();
}