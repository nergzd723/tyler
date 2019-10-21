#include "fbh.h"
#include "io.h"
#include "serial_port.h"
#include "types.h"

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

uint16_t cursor_pos = 0;

write_byte_t write_byte_function(FILE stream) {
  switch (stream) {
    case (SCREEN):
      return fb_write_byte;
    case (LOG):
      return serial_write_byte;
  }
}

//writes fb cell
void fb_write_cell(unsigned int cell, char c, unsigned char fg, unsigned char bg)
{
    int i = cell*2;
    fb[i] = c;
    fb[i + 1] = ((fg & 0x0F) << 4) | (bg & 0x0F);
}

//fills screen in beautiful way
void checkmate(unsigned short color, unsigned short color2){
    int i = 0;
    int n = 0;
    while(i < FB_CELLS)
    {
        if (n == FB_COLS){
            n = 0;
            i++;
        }
        fb_write_cell(i, ' ', color, color);
        i++;
        n++;
        fb_write_cell(i, ' ', color2, color2);
        i++;
        n++;
    }
}

//fills screen with some color
void fill_screen(unsigned char color){
    for (int i = 0; i < FB_CELLS; i++){
        fb_write_cell(i, ' ', color, color);
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

void fb_write_byte(uint8_t b) {
  fb_write_cell(cursor_pos, b, FB_WHITE, FB_BLACK);
  cursor_pos++;
  if (cursor_pos < FB_CELLS) {
    move_cursor_to_pos(cursor_pos);
  }
}
void print_int8(FILE stream, uint8_t data) {
  write_byte_t write_byte = write_byte_function(stream);
  uint8_t half_byte;
  write_byte('0');
  write_byte('x');
  for (int i = 1; i >=0; i--) {
    half_byte = (data >> (4*i)) & 0x0F;
    print_half_byte(write_byte, half_byte);
  }
}
//clears screen
void clear_screen(void)
{
    fill_screen(FB_BLACK);
}

//more dedicated cursor move, to specific row and column
void move_cursor(unsigned short row, unsigned short col) {
  move_cursor_to_pos(row*FB_COLS + col);
}

//prints something to framebuffer
void fb_write(char* s){
    int i = 0;
    while(s[i]){
        fb_write_byte(s[i]);
        i++;
    }
}
typedef void (*write_byte_t)(uint8_t);

int fprintf (FILE stream, const char * format, ...) {
  write_byte_t write_byte = write_byte_function(stream);
  int i = 0;
  while (format[i]) {
    write_byte(format[i]);
    i++;
  }
  return i;
}

void print_half_byte(write_byte_t write_byte, uint8_t half_byte)
{
    switch (half_byte) {
      case 0x0:
        write_byte('0');
        break;
      case 0x1:
        write_byte('1');
        break;
      case 0x2:
        write_byte('2');
        break;
      case 0x3:
        write_byte('3');
        break;
      case 0x4:
        write_byte('4');
        break;
      case 0x5:
        write_byte('5');
        break;
      case 0x6:
        write_byte('6');
        break;
      case 0x7:
        write_byte('7');
        break;
      case 0x8:
        write_byte('8');
        break;
      case 0x9:
        write_byte('9');
        break;
      case 0xA:
        write_byte('A');
        break;
      case 0xB:
        write_byte('B');
        break;
      case 0xC:
        write_byte('C');
        break;
      case 0xD:
        write_byte('D');
        break;
      case 0xE:
        write_byte('E');
        break;
      case 0xF:
        write_byte('F');
        break;
    }
}

void print_uint32(FILE stream, uint32_t data) 
{
  write_byte_t write_byte = write_byte_function(stream);
  uint8_t half_byte;
  write_byte('0');
  write_byte('x');
  for (int i = 7; i >=0; i--) {
    half_byte = (data >> (4*i)) & 0x0F;
    print_half_byte(write_byte, half_byte);
  }
}

