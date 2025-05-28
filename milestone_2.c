#include "stdio.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "command_check.h"
#include "milestone_1.h"
#include "milestone_2.h"

#define MAX_CMD_BUFFER 255


extern char previous_buffer[MAX_CMD_BUFFER];
extern int check_valid;
extern int check_empty;

void script_mode(int argc, char *argv[]) {
    FILE *file = fopen(argv[argc], "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", argv[argc]);
        exit(1);
    }

    char buffer[MAX_CMD_BUFFER];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        is_valid_command(buffer);
        if (check_empty != 0) {
            check_empty = 0;
        }
        if (check_valid != 0) {
            check_valid = 0; 
            printf("Invalid Command: %s", buffer);
        }
    }

    fclose(file);
}


void iterate_input(int argc, char *argv[]) {
    int input_count = 1;
    while (input_count < argc) { 
        script_mode(input_count, argv);
    }

    exit(0); // Exit after script mode executes - assumption made

}




