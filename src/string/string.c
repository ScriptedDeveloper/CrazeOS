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

