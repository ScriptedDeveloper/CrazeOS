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

multiboot_info_t *mbd_shell;

void command_line(){
    print("\n\nCrazeOS > ");
}

void exception_invalid_usage(){
    print("\nERROR, WRONG USAGE!");
    command_line();
}

void exception_too_little_args(char *command, int len){
    if(kcharlen(command) < len) {
    	exception_invalid_usage();
    }
}

void shell_about(){
    print("\nTHIS IS A HOBBY OS MAINTAINED BY SCRIPTEDDEV ON GITHUB.\n MORE INFO : https://github.com/ScriptedDeveloper/CrazeOS");
    command_line();
}

void shell_clear(){
    terminal_clear_screen();
    command_line();
}

void shell_echo(char *str){
    str += 5;
    print("\n");
    print(str);
    command_line();
}

void shell_totalmemory() {
    print("\nTOTAL MEMORY AVAILABLE: ");
    print(lltoa(mbd_shell->mem_lower + mbd_shell->mem_upper, 10));
    print("KB");
    command_line();
}

void shell_print_mmap(char *readability) {
    bool available;
    readability += 5;
    if(strncmp("AVAILABLE", readability, 4) == 0) {
    	available = true;
    }
    else if(strncmp("ALL", readability, 2) == 0) {
	available = false;	    
    }
    for(int i = 0; i < mbd_shell->mmap_length; i += sizeof(multiboot_memory_map_t)) {
    	multiboot_memory_map_t *mmmt = (multiboot_memory_map_t*) (mbd_shell->mmap_addr + i);
    	if(available){
		if(mmmt->type == MULTIBOOT_MEMORY_AVAILABLE) {
			printf("%s%x", "\nSTART ADDR : " ,mmmt->addr);
			printf("%s%x", " LEN : ", mmmt->len);
			printf("%s%d", " TYPE : ", mmmt->type);
 			printf("%s%x", " SIZE : ", mmmt->size);
        	}
	} 
	else {
	   	printf("%s%x", "\nSTART ADDR : " ,mmmt->addr);
		printf("%s%x", " LEN : ", mmmt->len);
		printf("%s%d", " TYPE : ", mmmt->type);
 		printf("%s%x", " SIZE : ", mmmt->size);
	}
    }
    command_line();
}

void shell_init(multiboot_info_t *mbd_) {
    char *command_input = keyboard_handler(true);
    char *commands[] = {"HELP", "ECHO", "ABOUT", "CLEAR", "TOTALMEM", "MMAP"};
    mbd_shell = mbd_;
    if(strcmp(command_input, commands[0]) == 0) {
        print("\nECHO <STRING> - STRING OUTPUT TO CONSOLE\nHELP - STRING OUTPUT TO HELP\nABOUT - PROJECT INFO\nCLEAR - RESETS VGA BUFFER TO DEFAULT\nTOTALMEM - PRINTS TOTAL AVAILABLE MEMORY\nMMAP <ALL/AVAILABLE> - PRINTS ENTIRE/USUABLE MEMORY MAP ENTRIES");
        command_line();
    }

    else if(strncmp(commands[1], command_input, 4) == 0){
    	exception_too_little_args(command_input, 5);
	shell_echo(command_input);
    }

    else if(strcmp(command_input, commands[2]) == 0) {
        shell_about();
    }
    
    else if(strcmp(command_input, commands[3]) == 0) {
        shell_clear();
    }

    else if(strcmp(command_input, commands[4]) == 0) {
        shell_totalmemory();
    }

    else if(strncmp(commands[5], command_input, 4) == 0) {
	exception_too_little_args(command_input, 5);
	shell_print_mmap(command_input);
    }

    else if(strcmp(command_input, "\0") == 0){

    }

    else {
        print("\nCommand not found!\n");
        command_input = "\0";
        command_line();
    }
}
