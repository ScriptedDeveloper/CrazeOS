#include "video.h"
#define VGA_WIDTH 25
#define VGA_HEIGHT 80

char* vgaBuffer = (char*) 0xb8000; // screen buffer (VGA Text Mode)
int vgaBufferInt = 8000; // to change newlines
int term_height = 0;
int term_width = 0;

void putchar(char c);

void print(char *string){
	for(long i = 0; string[i] != '\0'; i++){
		if(string[i] == '\n'){
 			term_height = 0;
 			term_width++; term_width++;
		}
		else if(string[i] == '\e'){
			terminal_clear_screen();
			print("CrazeOS > ");
		}
		else{
			putchar(string[i]);
		}
	}
	return;
}

void putchar(char c){
	const int id = (VGA_HEIGHT * term_width) + term_height;
	term_height++;
	vgaBuffer[id] = c;
	term_height++;
	vgaBuffer[id + 1] = 15;
}

void terminal_clear_screen(){
	term_height = 0;
	term_width = 0;
	int limit = (VGA_WIDTH * 2) * (VGA_HEIGHT); 
	for (int i = 0; i < limit; ++i) {
		vgaBuffer[i] = 0;
	}
}

void printf(char *args, ...){
	va_list ap;
	va_start(ap, args);
	char *s;
	char c;
	int i;
	uint32_t x;
	for(; *args != '\0'; args++) {
		if(*args != '%') {
			args++;
		}
		args++;
		switch(*args) {
			case 's' :
				s = va_arg(ap, char*);
				print(s);
				break;

			case 'c' : 
				c = va_arg(ap, int);
				putchar(c);
				break;

			case 'd' :
				i = va_arg(ap, int);
				print(itoa(i, 10));
				break;
			
			case 'x' :
				x = va_arg(ap, uint32_t);
				print("0x");
				print(itoa(x, 16));
				break;
		}
	}
	va_end(ap);
}
