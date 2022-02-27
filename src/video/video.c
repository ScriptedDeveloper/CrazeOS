#include "video.h"
#define VGA_WIDTH 25
#define VGA_HEIGHT 80

char* vgaBuffer = (char*) 0xb8000; // screen buffer (VGA Text Mode)
int vgaBufferInt = 8000; // to change newlines
int term_height = 0;
int term_width = 0;

void print(char *string){
	for(long i = 0; string[i] != '\0'; i++){
		const int id = (VGA_HEIGHT * term_width) + term_height;
		term_height++;
		if(string[i] == '\n'){
 			term_height = 0;
 			term_width++; term_width++;
		}
		else if(string[i] == '\e'){
			terminal_clear_screen();
			print("CrazeOS > ");
		}
		else{
		vgaBuffer[id] = string[i];
		term_height++;
		vgaBuffer[id + 1] = 15;
		}
	}
	return;
}


void terminal_clear_screen(){
	term_height = 0;
	term_width = 0;
	int limit = (VGA_WIDTH * 2) * (VGA_HEIGHT); 
	for (int i = 0; i < limit; ++i) {
		vgaBuffer[i] = 0;
	}
	return;
}
