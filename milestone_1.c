#include "stdio.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
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

void echo_command(char *buffer, int *tokenized_count) {
    // Store the current command
    // Replace previous buffer for !! command
    replace_previous_buffer(buffer);

    if ((*tokenized_count) == 1) {
        // If no string is provided after "echo", just print a newline
        printf("\n");
    } else {
        int temp = 0;
        while (buffer[temp] == ' ' || buffer[temp] == '\t') {
            temp++;
        }
        printf("%s", buffer + temp + 5);
    }
}



/*

maybe upgrade echo function to handle more complex echo commands in future milestones
putting edge cases answers here

void echo_command(char *buffer, char *tokenized_buffer[], int *tokenized_count) {
    // Store the current command
    // Replace previous buffer for !! command
    replace_previous_buffer(buffer);
    printf("%s", buffer + 5);
}
*/


void repeat_command(char *buffer) { // changed name so it is more readable
    
    if (strncmp(previous_buffer, "NULL", 4) != 0) {
        printf("%s", previous_buffer);
        is_valid_command(previous_buffer);
    }
    
}

void exit_command(char *buffer) {

    char *exit_string = buffer + 5;
    int exit_code = 0; // Default exit code if none is provided

    exit_code = atoi(exit_string);
    exit_code = exit_code & 255;
    exit(exit_code); // Exit with the specified exit code
        
    // if (condition based of terminal size print different art) { // future milestone implementation maybe
    //         // vegito_start_art();
    // } else {
    //         // gogeta_start_art();
    // }

    replace_previous_buffer("NULL"); // fail safe to reset previous buffer if double isch happens (unsure)
    printf("Exiting icsh. Goodbye!\n");
    exit(exit_code);
}
