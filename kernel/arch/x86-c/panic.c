#include "stdio.h"
#include "assembly_interface.h"
void panic(char* panicmessage){
    printf("\n\n\n\n\nPanicked successfully!\n\n\n");
    printf("Panicked! Error message: ");
    printf(panicmessage);
    printf("\n");
    printf(panicmessage);
}