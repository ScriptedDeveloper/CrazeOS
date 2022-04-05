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
			print(*args);
			args++;
		}
		args++;
		switch(*args) {
			case 's' :
				s = va_arg(ap, char*);
				args++;
				print(s);
				break;

			case 'c' : 
				c = va_arg(ap, int);
				args++;
				putchar(c);
				break;

			case 'i' :
				i = va_arg(ap, int);
				print(itoa(i, 10));
				args++;
				break;
			
			case 'x' :
				x = va_arg(ap, uint32_t);
				print("0x");
				print(itoa(x, 16));
				args++;
				break;
		}
	}
	va_end(ap);
}
