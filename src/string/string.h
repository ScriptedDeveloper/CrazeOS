#pragma once
#include "kernel/kernel.h"

int strcmp(char *src, char* dest);
int strncmp(char *str1, char* str2, int len);
char *strcpy(char *dest, const char *src);
int kcharlen(char *c);
void* memset(void *bufferptr, int val, size_t size);
char* itoa(int val, int base);
char* lltoa(long long val, int base);
