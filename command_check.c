#include "stdio.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "command_check.h"
#include "milestone_1.h"

#define MAX_CMD_BUFFER 255

/*
note for self:
extern is used for variables that are defined in another file. global variable across files
*/

extern char previous_buffer[MAX_CMD_BUFFER];
extern int check_valid;
extern int check_empty;

void is_valid_command(char *buffer) {
    
    int temp = 0;



    while (buffer[temp] == ' ') {
        temp++;
    }
    // to ensure edgecases like "   echo hello world" 
    // counts as "echo hello world" since it works in normal terminal like that

    if (buffer[temp] == '\n' || buffer[temp] == '\0') {
        check_empty = 1; 
        
    } else if (strncmp(buffer, "#", 1) == 0 || strncmp(buffer, "##", 2) == 0) {
        // comment line, do nothing - tested in terminal, just gives new prompt
        check_empty = 1; 

    } else if (strncmp(buffer, "echo", 4) == 0 || strncmp(buffer, "echo ", 5) == 0) {
        echo_command(buffer);

    } else if (strncmp(buffer, "!!", 2) == 0 || strncmp(buffer, "!! ", 3) == 0) {
        shebang_command(buffer);

    } else if (strncmp(buffer, "exit", 4) == 0 || strncmp(buffer, "exit ", 5) == 0) {
        exit_command(buffer);

    } else {
        check_valid = 1;
    }
    
}