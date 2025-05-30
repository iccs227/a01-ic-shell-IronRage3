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


// Global variables from icsh.c
extern char previous_buffer[MAX_CMD_BUFFER];
extern int check_invalid;
extern int check_empty;

// Global variable from (ignore if none added)



// Global variable from command_check.h

void is_valid_command(char *buffer) {
    
    int temp = 0;

    char tokenized_buffer[MAX_CMD_BUFFER];
    int *tokenized_count = 0; // pointer to count tokens across functions - global variable

    tokenize_command(buffer, tokenized_buffer, &tokenized_count);   

    if (tokenized_count == 0) {
        // No tokens = empty command
        check_empty = 1;
        return; // early exit - faster runtime
    }

    char valid_command = tokenized_buffer[0]; // refractored code to have less conditions

    if (strncmp(valid_command, "#", 1) == 0 || strncmp(valid_command, "##", 2) == 0) {
        // comment line, do nothing - tested in terminal, just gives new prompt
        check_empty = 1;
        return; // early exit - faster runtime

    } else if (strncmp(valid_command, "echo", 4) == 0) {

        echo_command(buffer);
        // echo_command(buffer, tokenized_buffer, &tokenized_count); ti be implemented later milestone 

    } else if (strncmp(buffer, "!!", 2) == 0) {
        shebang_command(buffer);

    } else if (strncmp(buffer, "exit", 4) == 0) {
        exit_command(buffer, tokenized_buffer, &tokenized_count);

    } else {
        execute_external_command(buffer, tokenized_buffer, &tokenized_count);
    }

    if (check_invalid == 0) {
        replace_previous_buffer(buffer); // give buffer so it matches the previous command input exactly for external command
    } else {
        printf("bad command.\n"); // bad command from milestone 1 important note
    }
    
}

/*
Replace previous buffer for !! command
*/
void replace_previous_buffer(char *buffer) {
    
    strncpy(previous_buffer, buffer, MAX_CMD_BUFFER);
}


/*
converts given input into array entries seperated by spaces
*/

void tokenize_command(char *buffer, char *tokenized_buffer, int *tokenized_count) {
    int i = 0;
    tokenized_count = 0; // Reset tokenized count
    char *token_arg = strtok(buffer, " ");
    

    while (token_arg != NULL) {
        tokenized_buffer[i] = token_arg;
        i++;
        token_arg = strtok(NULL, " ");
    }
    
    // testing function
    int count = 0;
    while (count <= i) {
        printf("%s\n", tokenized_buffer[count]);
        count++;
    }
}