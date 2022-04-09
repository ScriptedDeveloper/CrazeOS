#include "shell.h"

multiboot_info_t *mbd_shell;

void command_line(){
    print("\n\nCrazeOS > ");
}

void exception_invalid_usage(){
    print("\nERROR, WRONG USAGE!");
    command_line();
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

void shell_print_mmap() {
    for(int i = 0; i < mbd_shell->mmap_length; i += sizeof(multiboot_memory_map_t)) {
    	multiboot_memory_map_t *mmmt = (multiboot_memory_map_t*) (mbd_shell->mmap_addr + i);
    	printf("%s%x", "\nSTART ADDR : " ,mmmt->addr);
	printf("%s%x", " LEN : ", mmmt->len);
	printf("%s%d", " TYPE : ", mmmt->type);
 	printf("%s%x", " SIZE : ", mmmt->size);
    }
    command_line();
}

void shell_init(multiboot_info_t *mbd_) {
    char *command_input = keyboard_handler(true);
    char *commands[] = {"HELP", "ECHO", "ABOUT", "CLEAR", "TOTALMEM", "MMAP"};
    mbd_shell = mbd_;
    if(strcmp(command_input, commands[0]) == 0) {
        print("\nECHO <STRING> - STRING OUTPUT TO CONSOLE\nHELP - STRING OUTPUT TO HELP\nABOUT - PROJECT INFO\nCLEAR - RESETS VGA BUFFER TO DEFAULT\nTOTALMEM - PRINTS TOTAL AVAILABLE MEMORY\nMMAP - PRINTS ENTIRE MEMORY MAP");
        command_line();
    }

    else if(strncmp(commands[1], command_input, 4) == 0){
        if(kcharlen(command_input) < 5){
            exception_invalid_usage();
        }
        else{
            shell_echo(command_input);
        }
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

    else if(strcmp(command_input, commands[5]) == 0) {
	shell_print_mmap();	    
    }

    else if(strcmp(command_input, "\0") == 0){

    }

    else {
        print("\nCommand not found!\n");
        command_input = "\0";
        command_line();
    }
}
