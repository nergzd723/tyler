#include "fbh.h"
#include "io.h"
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

//writes fb cell
void fb_write_cell(unsigned int cell, char c, unsigned char fg, unsigned char bg)
{
    int i = cell*2;
    fb[i] = c;
    fb[i + 1] = ((fg & 0x0F) << 4) | (bg & 0x0F);
}

//clears screen
void clear_screen()
{
    for (int i = 0; i < FB_CELLS; i++){
        fb_write_cell(i, ' ', FB_BLACK, FB_BLACK);
    }
}

//moves cursor to specific pos, needed for newlines and more
void move_cursor_to_pos(unsigned short pos)
{
    outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
    outb(FB_DATA_PORT,    ((pos >> 8) & 0x00FF));
    outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
    outb(FB_DATA_PORT,    pos & 0x00FF);
}

//more dedicated cursor move, to specific row and column
void move_cursor(unsigned short row, unsigned short col) {
  move_cursor_to_pos(row*FB_COLS + col);
}

//prints something to framebuffer
void fb_write(char* s, unsigned char fg, unsigned char bg){
    int i = 0;
    while(s[i]){
        fb_write_cell(i, s[i], fg, bg);
        i++;
    }
}
