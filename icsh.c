/* ICCS227: Project 1: icsh
 * Name: Hardik Vijay
 * StudentID: 6580864
 */

#include "stdio.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "start_art.h"
#include "command_check.h"

// for now as safety, will clean up later
#include "milestone_1.h"

#define MAX_CMD_BUFFER 255

char previous_buffer[MAX_CMD_BUFFER] = "NULL";
int check_valid = 0; // 0 = success, 1 = failure


char current_mode[MAX_CMD_BUFFER] = "NULL";

void start_shell() {
    // Start message for the shell
    printf("Welcome to icsh!\n");
    printf("This is made by Hardik Vijay\n");
    printf("Except the start art\n");
    gogeta_start_art();
    vegito_start_art();
    printf("Art was not made by me, but Uroll Insipred me.\n");
}



int main(int argc, char *argv[]) {

    if (argc > 1) {
        // to implement


        exit(0);
        }
    else {

        char buffer[MAX_CMD_BUFFER];
        start_shell();
        
        while (1) {
            printf("icsh $ ");
            fgets(buffer, 255, stdin);
            is_valid_command(buffer); // allows valid command function to work for both shell mode or script mode
            if (check_valid != 0) {   
                printf("Invalid Command.\n");
            }

        }
    }
            // printf("you said: %s\n", buffer); (starter code)
            // if (strncmp(buffer, "exit", 4) == 0) { 
            //     printf("Exiting icsh. Goodbye!\n");
            //     break;
            // } (starter code)
}
