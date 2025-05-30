#include "stdio.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "milestone_1.h"
#include "start_art.h"
#include "command_check.h"

#define MAX_CMD_BUFFER 255

/*
No more double checking for commands - reduce run time.
*/


// Global variables from icsh.c
extern char previous_buffer[MAX_CMD_BUFFER];
extern int check_invalid;



// moved replace_previous_buffer to command_check.h

void echo_command(char *buffer) {
    // Store the current command
    // Replace previous buffer for !! command
    replace_previous_buffer(buffer);
    printf("%s", buffer + 5);
}

/*

maybe upgrade echo function to handle more complex echo commands in future milestones
putting edge cases answers here

void echo_command(char *buffer, char *tokenized_buffer, int *tokenized_count) {
    // Store the current command
    // Replace previous buffer for !! command
    replace_previous_buffer(buffer);
    printf("%s", buffer + 5);
}
*/


void shebang_command(char *buffer) {
    
    if (strncmp(previous_buffer, "NULL", 4) != 0) {
        printf("%s", previous_buffer);
        is_valid_command(previous_buffer);
    }
    
}

void exit_command(char *buffer, char *tokenized_buffer, int *tokenized_count) {

    char *exit_string;
    int exit_code = 0; // Default exit code if none is provided

    if (tokenized_count > 2) {
        // If more than one argument is given, print error and exit with code 1
        printf("Error: Too many arguments for exit command.\n");
    } else if (tokenized_count == 2) {
        // If one argument is given, check if it's a valid exit code

        exit_string = tokenized_buffer[1];
        exit_code = atoi(exit_string);
        exit_code = exit_code & 255;
        
        printf("Exiting icsh with code %d\n", exit_code);
        exit(exit_code); // Exit with the specified exit code
        
    } else if (tokenized_count == 1) {
        
            // vegito_start_art();
            // gogeta_start_art();

        replace_previous_buffer("NULL"); // fail safe to reset previous buffer if double isch happens (unsure)
        printf("Exiting icsh. Goodbye!\n");
        exit(exit_code);
        
    } else {
        check_invalid = 1; // Set invalid command flag
    }
    
    
    
    
    
    
    
    
    int count = 5;
    char exit_string[5];
    int temp = 0;

    while (buffer[count] == ' ') {
        count++;
        }
    while (buffer[count] != '\n' && buffer[count] != '\0' && buffer[count] != ' ') {
        exit_string[temp] = buffer[count];
        temp++;
        count++;
    }
    exit_string[temp] = '\0'; // Null terminate the exit code string

    int exit_code = 0; // if not exit code given, default is 0
    if (temp > 0) {
        exit_code = atoi(exit_string);
        exit_code = exit_code & 255; 
        // ensures exit code is within 0-255 range (all bits which change are lowest 8 bits rest become 0)
    }


    
}
