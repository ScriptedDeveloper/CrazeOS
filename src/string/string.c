/*
CrazeOS, an unix-based, work-in-progess amateurish OS.
Copyright (C) 2022  ScriptedDev

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "string.h"

int strcmp(char *src, char* dest){
	for(int i = 0; i < kcharlen(src); i++){
		for(int i_ = 0; i < kcharlen(dest); i++){
			if(src[i] != dest[i]){
				return 1;
			}
		}
	}
	return 0;
}

int strncmp(char *str1, char* str2, int len){
	if(len > kcharlen(str1) || len > kcharlen(str2)){
		return 2;
	}
	while(len > 0 && *str1 && *str1 == str2){
		len--;
		str2++;
		str1++;
	}
	if(len == 0){
		return 0;
	}
	else{
		return(int) (*str1 - *str2);
	}
}

int kcharlen(char *c){
    int i;
    for(i = 1; c[i] != '\0'; i++){
    }
    return i;
}


void* memset(void *bufferptr, int val, size_t size){
	uint8_t* buffer = (uint8_t*)bufferptr;
	for(size_t i = 0; i < size; i++){
		buffer[i] = (uint8_t)val;
	}
	return bufferptr;
}

char* itoa(int val, int base) {
	static char buffer[32] = {0};
	int i;
	for(i = 30; val && i; i--, val/= base) {
		buffer[i] = "0123456789abcdef"[val % base];
	}
	return &buffer[i+1];
}


char* lltoa(long long val, int base){

    static char buf[64] = {0};

    int i = 62;
    int sign = (val < 0);
    if(sign) val = -val;

    if(val == 0) return "0";

    for(; val && i ; --i, val /= base) {
        buf[i] = "0123456789abcdef"[val % base];
    }

    if(sign) {
        buf[i--] = '-';
    }
    return &buf[i+1];
}

char *strcpy(char *dest, const char *src) {
    char *p = dest;
    while (*src != '\0') {
        *dest++ = *src++;
    }
    *dest = '\0';
    return p;
}
