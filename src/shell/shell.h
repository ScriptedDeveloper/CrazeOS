#pragma once
#include "kernel/kernel.h"
void shell_init(multiboot_info_t *mbd);
void command_line();
void shell_clear();
static void exception_invalid_usage(); // static for now
static void shell_about();
static void shell_echo();