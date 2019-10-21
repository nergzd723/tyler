#ifndef INCLUDE_FBH_H
#define INCLUDE_FBH_H
#define FB_COLS 80
#define FB_ROWS 25

typedef enum output_t {SCREEN, LOG} FILE;

#define FB_CELLS FB_COLS * FB_ROWS

#define FB_BLACK 0
#define FB_BLUE 1
#define FB_GREEN 2
#define FB_CYAN 3
#define FB_RED 4
#define FB_MAGENTA 5
#define FB_BROWN 6
#define FB_LIGHT_GREY 7
#define FB_DARK_GREY 8
#define FB_LIGHT_BLUE 9
#define FB_LIGHT_GREEN 10
#define FB_LIGHT_CYAN 11
#define FB_LIGHT_RED 12
#define FB_LIGHT_MAGENTA 13
#define FB_LIGHT_BROWN 14
#define FB_WHITE 15

void fb_write_cell(unsigned int cell, char c, unsigned char fg, unsigned char bg);
void clear_screen();
void fb_write(char* s);
void move_cursor(unsigned short row, unsigned short col);
void fill_screen(unsigned char color);
void print_int8(FILE stream, unsigned char data);
void print_uint32(FILE stream, unsigned long data);
void checkmate(unsigned short color1, unsigned short color2);

#endif /* INCLUDE_FBH_H */