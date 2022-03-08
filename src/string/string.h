#pragma once
#include "kernel/kernel.h"

int strcmp(char *src, char* dest);
int strncmp(char *str1, char* str2, int len);
int kcharlen(char *c);
void* memset(void *bufferptr, int val, size_t size);
