#pragma once
#define bool int
#include <stdbool.h>
#include "keyboard/keyboard.h"
#include "kernel/kernel.h"
#include "string/string.h"

extern int vgaBufferInt;
extern int VGA_HEIGHT;
extern int VGA_WIDTH;
extern int term_height;
extern int term_width;
void print(char *string);
void terminal_clear_screen();
void printf(char *args, ...);
void putchar(char c);
