#ifndef VIDEO_H_INCLUDED
#define VIDEO_H_INCLUDED
#define bool int
#include <stdbool.h>
#include "keyboard/keyboard.h"
#include "kernel/kernel.h"

extern int vgaBufferInt;
extern int VGA_HEIGHT;
extern int VGA_WIDTH;
extern int term_height;
extern int term_width;
void print(char *string);
void terminal_clear_screen();
#endif