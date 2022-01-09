#define CLI_PROMPT "@CrazeOS > "
#include "kernel/kernel.h"
#include "idt/idt.h"

int kcharlen(char *c){
    int i = NULL;
    for(i = 1; c[i] != '\0'; i++){
        i++;
    }
    return i;
}

long khash(char *string){
	int c;
	long hash_val = 5381;
	while(c = *string++){
		hash_val = ((hash_val << 5) + hash_val);
	}
	return hash_val;
}

kmain(){
	terminal_clear_screen();
	//idt_init(); WIP
	print("CrazeOS > ");
	keyboard_handler(false);
	return 0;
}
