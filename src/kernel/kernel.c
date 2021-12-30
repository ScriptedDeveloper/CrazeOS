#include "kernel/kernel.h"

int sleep(int sec) {
	int i = 0;
	uint32_t ending;
	do{
	i++;
	ending = i + sec * 3800000000;
	}while(i < ending);
}

kmain(){
	terminal_clear_screen();
	print("CrazeOS > ");
	keyboard_handler(true);
	return 0;
}