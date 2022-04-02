#include "kernel/kernel.h"

multiboot_info_t *mbd;

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

void kmain(multiboot_info_t *mbd_, uint32_t magic){
	terminal_clear_screen();
	if(magic != MULTIBOOT_BOOTLOADER_MAGIC) {
		kpanic("INVALID MAGIC NUMBER!");
	}
	mbd = mbd_;
	gdt_init();
	idt_init();
	page_frame_init();
	command_line();
	uint32_t new_frame = frame_allocate();
	print(lltoa(mmap_read(new_frame, MMAP_GET_ADDR), 10));
	for(;;){
		shell_init();
	}
}
