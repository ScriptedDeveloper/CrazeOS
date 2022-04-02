#include "shell.h"


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
    print(lltoa(mbd->mem_lower + mbd->mem_upper, 10));
    print("KB");
    command_line();
    
}


void shell_init() {
    char *command_input = keyboard_handler(true);
    char *commands[] = {"HELP", "ECHO", "ABOUT", "CLEAR", "TOTALMEM"};
    if(strcmp(command_input, commands[0]) == 0) {
        print("\nECHO <STRING> - STRING OUTPUT TO CONSOLE\nHELP - STRING OUTPUT TO HELP\nABOUT - PROJECT INFO\nCLEAR - RESETS VGA BUFFER TO DEFAULT\nTOTALMEM - PRINTS TOTAL AVAILABLE MEMORY");
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

    else if(strcmp(command_input, "\0") == 0){

    }

    else {
        print("\nCommand not found!\n");
        command_input = "\0";
        command_line();
    }
}
