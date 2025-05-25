#include "stdio.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "milestone_1.h"
#include "start_art.h"
#include "command_check.h"

#define MAX_CMD_BUFFER 255

/*
Double checking in case if passed command is a valid command, just to be safe
*/

extern char previous_buffer[MAX_CMD_BUFFER];

void replace_previous_buffer(char *buffer) {
    // Replace previous buffer for !! command
    strncpy(previous_buffer, buffer, MAX_CMD_BUFFER);
}

void echo_command(char *buffer) {
    if (strncmp(buffer, "echo ", 5) == 0) {
        // Store the current command
        // Replace previous buffer for !! command
        replace_previous_buffer(buffer);
        printf("%s", buffer + 5);

    } else {
        printf("Invalid command\n");
    }
}

void shebang_command(char *buffer) {
    if (strncmp(buffer, "!!", 2) == 0 || strncmp(buffer, "!! ", 3) == 0) {
        if (strcmp(previous_buffer, "NULL", 4) == 0) {
        } else {
            printf("%s", previous_buffer);
            is_valid_command(previous_buffer);
        }
    } else {
        printf("Invalid command\n");
    }
}

void exit_command(char *buffer) {
    int count = 5;
    char exit_string[5];
    int temp = 0;

    if (strncmp(buffer, "exit ", count) == 0) {
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

        vegito_start_art();
        gogeta_start_art();
        replace_previous_buffer("NULL"); // fail safe to reset previous buffer if double isch happens (unsure)
        printf("Exiting icsh. Goodbye!\n");
        exit(exit_code); // Exit with the specified exit code
    } else {
        printf("Invalid command\n");
    }
}
