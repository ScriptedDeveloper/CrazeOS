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

void kpanic(char *msg) {
	terminal_clear_screen();
	print("KERNEL PANIC! ERROR MESSAGE :");
	print(msg);
	__asm__ volatile("cli; hlt");
}

kmain(multiboot_info_t* mbd, uint64_t magic){
	terminal_clear_screen();
	if(magic != MULTIBOOT_HEADER_MAGIC) { // Where the issue is
		print("got   ");
		print(lltoa(magic, 16));
		print(" but need ");
		print(lltoa(MULTIBOOT_BOOTLOADER_MAGIC, 16));
		
			__asm__ volatile("cli; hlt");
	}
	gdt_init();
	idt_init();
	command_line();
	for(;;){
		shell_init();
	}
	return 0;
}
