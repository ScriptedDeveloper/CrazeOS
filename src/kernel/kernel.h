#define NULL 0
#ifndef KERNEL_H_INCLUDED
#define KERNEL_H_INCLUDED
#include <stdint.h>
#include "keyboard/keyboard.h"
#include "video/video.h"    


int kmain();
int kcharlen(char *c);
int ksleep(int sec);
#endif