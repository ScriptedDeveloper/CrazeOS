#pragma once
#ifndef KERNEL_H_INCLUDED
#define NULL 0
#define KERNEL_H_INCLUDED
#include <stdint.h>
#include "keyboard/keyboard.h"
#include "video/video.h"    

static uint8_t stack[8192];
static struct stivale2_header_tag_terminal;
static struct stivale2_header_tag_framebuffer;
static struct stivale2_header;
int kmain();
int kcharlen(char *c);
long khash(char* string);
#endif