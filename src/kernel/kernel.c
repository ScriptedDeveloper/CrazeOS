#include "kernel/kernel.h"
#include "idt/idt.h"

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
	gdt_init();
	idt_init();
	command_line();
	for(;;){
		shell_init();
	}
	return 0;
}
