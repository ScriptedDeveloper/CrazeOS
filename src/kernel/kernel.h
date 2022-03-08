#pragma once
#include <stdint.h>
#include <stddef.h>
#include "keyboard/keyboard.h"
#include "video/video.h"
#include "shell/shell.h"
#include "string/string.h"
#include "gdt/gdt.h"
#include "idt/idt.h"
#include "idt/isr.h"

static uint8_t stack[8192];
int kmain();
int kcharlen(char *c);
long khash(char* string);
