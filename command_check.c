#include "stdio.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "command_check.h"
#include "milestone_1.h"
#include "milestone_3.h"

#define MAX_CMD_BUFFER 255

/*
note for self:
extern is used for variables that are defined in another file. global variable across files
*/


// Global variables from icsh.c
extern char previous_buffer[MAX_CMD_BUFFER];
extern int check_invalid;
extern int check_empty;
extern int last_exit_code;


void is_valid_command(char *buffer) {

    char *tokenized_buffer[MAX_CMD_BUFFER];
    int tokenized_count = 0; // pointer to count tokens across functions - global variable
    
    char *copy_buffer = strdup(buffer); // Create a copy of the buffer to avoid modifying the original
    copy_buffer[strcspn(copy_buffer, "\n")] = 0;
    tokenize_command(copy_buffer, tokenized_buffer, &tokenized_count);
    
    if (tokenized_count == 0) {
        // No tokens = empty command
        check_empty = 1;
        free(copy_buffer);
        return; // early exit - faster runtime
    }

    char *valid_command = tokenized_buffer[0]; // refractored code to have less conditions

    if (strncmp(valid_command, "#", 1) == 0 || strncmp(valid_command, "##", 2) == 0) {
        // comment line, do nothing - tested in terminal, just gives new prompt
        check_empty = 1;
        free(copy_buffer);
        return; // early exit - faster runtime

    } else {
        int check_length = strlen(valid_command);
        bool internal_command = false; // flag to check if command is internal

        if (check_length == 2) {
            if (strncmp(valid_command, "!!", 2) == 0) {
                internal_command = true;
                repeat_command(buffer);
            }
        } else if (check_length == 4) { // ensure cases like echoh or exitlol and more
            if (strncmp(valid_command, "echo", 4) == 0) {
                internal_command = true;
                echo_command(buffer, &tokenized_count);
            } else if (strncmp(valid_command, "exit", 4) == 0) {
                internal_command = true;
                free(copy_buffer);
                exit_command(buffer);
            }
        } 
        if (!internal_command) {
            execute_external_command(buffer, tokenized_buffer);
        }
    }

    free(copy_buffer);
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

void tokenize_command(char *copy_buffer, char *tokenized_buffer[], int *tokenized_count) {
    int i = 0;
    char *saveptr;
    char *token_arg = strtok_r(copy_buffer, " \t\r\n", &saveptr); // Tokenize the input buffer by spaces, tabs, and newlines
    
    if (token_arg == NULL) {
        *tokenized_count = 0; // If no tokens found, set count to 0
        return; // Early exit if no tokens
    } else {
        while (token_arg != NULL && i < MAX_CMD_BUFFER) {
            
            int len = strlen(token_arg);
            while (len > 0 && (token_arg[len - 1] == '\r' || token_arg[len - 1] == '\n')) {
                token_arg[--len] = '\0';
            } // Had to implement this to clean \t \r \n from the string or any input in execvp does not work properly
            
            tokenized_buffer[i] = token_arg;
            i++;
            token_arg = strtok_r(NULL, " ", &saveptr);
        }
    
        *tokenized_count = i; // Update the count of tokens
        tokenized_buffer[i] = NULL;

        // testing tokenizing works as intended
        
        // for (int j = 0; j < i; j++) {
        //     printf("Token %d: '%s' [hex: ", j, tokenized_buffer[j]);
        //     for (int k = 0; tokenized_buffer[j][k]; k++) {
        //         printf("%02x ", (unsigned char)tokenized_buffer[j][k]);
        //     }
        //     printf("]\n");
        // }
    }
}