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

void is_valid_command(char *buffer) {
    
    int temp = 0;
    while (buffer[temp] == ' ') {
        temp++;
    }
    // to ensure edgecases like "   echo hello world" 
    // counts as "echo hello world" since it works in normal terminal like that
    
    if (strncmp(buffer, "echo", 4) == 0 || strncmp(buffer, "echo ", 5) == 0) {
        echo_command(buffer);
        check_valid = 0;

    } else if (strncmp(buffer, "!!", 2) == 0 || strncmp(buffer, "!! ", 3) == 0) {
        shebang_command(buffer);
        check_valid = 0;

    } else if (strncmp(buffer, "exit", 4) == 0 || strncmp(buffer, "exit ", 5) == 0) {
        exit_command(buffer);
        check_valid = 0;

    } else {
        check_valid = 1;
    }
    
}