#pragma once
#include "kernel/kernel.h"
void shell_init();
void command_line();
void shell_clear();
static void exception_invalid_usage(); // static for now
static void shell_about();
static void shell_echo();