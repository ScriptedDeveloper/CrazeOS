#pragma once
#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>
#include "multiboot/multiboot.h"
#include "keyboard/keyboard.h"
#include "video/video.h"
#include "shell/shell.h"
#include "string/string.h"
#include "../gdt/gdt.h"
#include "../idt/idt.h"
#include "../idt/isr.h"
#include "../paging/paging.h"

int kmain();
int kcharlen(char *c);
long khash(char* string);
void kpanic(char *msg);
extern uintptr_t kernel_start, kernel_end;
