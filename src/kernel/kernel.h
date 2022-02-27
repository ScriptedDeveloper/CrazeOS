#pragma once
#ifndef KERNEL_H_INCLUDED
#define KERNEL_H_INCLUDED
#include <stdint.h>
#include <stddef.h>
#include "keyboard/keyboard.h"
#include "video/video.h"
#include "shell/shell.h"
#include "string/string.h"



int kmain();
int kcharlen(char *c);
long khash(char* string);
#endif
