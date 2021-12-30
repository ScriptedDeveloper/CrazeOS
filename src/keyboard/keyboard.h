#ifndef KEYBOARD_H_INCLUDED
#define KEYBOARD_H_INCLUDED
#include <stdint.h>
#include "video/video.h"

char* keyboard_handler(bool input);
char* get_ascii(int scancode);
void init_pics(int pic1, int pic2);
unsigned char inportb(unsigned int port);
void outportb(unsigned int port,unsigned char value);
extern char cInput;
extern const char upper_ascii_codes[255];
#endif