#include "fbh.h"
// Start of memory that maps to the fram buffer
char *fb = (char *) 0x000B8000;
/** fb_write_cell:
 *  Writes a character with the given foreground and background to position
 *  in the framebuffer.
 *
 *  @param i  The location in the framebuffer
 *  @param c  The character
 *  @param fg The foreground color
 *  @param bg The background color
 */
void fb_write_cell(unsigned int cell, char c, unsigned char fg, unsigned char bg)
{
    int i = cell*2;
    fb[i] = c;
    fb[i + 1] = ((fg & 0x0F) << 4) | (bg & 0x0F);
}

void fb_clear_screen()
{
    for (int i = 0; i < FB_CELLS; i++){
        fb_write_cell(i, ' ', FB_BLACK, FB_BLACK);
    }
}

void fb_print(char* s, unsigned char fg, unsigned char bg){
    int i = 0;
    while(s[i]){
        fb_write_cell(i, s[i], fg, bg);
        i++;
    }
}
