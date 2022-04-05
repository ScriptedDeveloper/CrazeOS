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

int kmain(multiboot_info_t *mbd, uint32_t magic){
	terminal_clear_screen();
	if(magic != MULTIBOOT_BOOTLOADER_MAGIC) {
		kpanic("INVALID MAGIC NUMBER!");
	}
	gdt_init();
	idt_init();
	command_line();
	for(;;){
		shell_init(mbd);
	}
	return 0;
}
