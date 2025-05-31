/* ICCS227: Project 1: icsh
 * Name: Hardik Vijay
 * StudentID: 6580864
 */

#include "stdio.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include "start_art.h"
#include "command_check.h"

// for now as safety, will clean up later
#include "milestone_1.h"
#include "milestone_2.h"
#include "milestone_3.h"
#include "milestone_4.h"



#define MAX_CMD_BUFFER 255

char previous_buffer[MAX_CMD_BUFFER] = "NULL";
int check_invalid = 0; // 0 = success, 1 = failed to execute command - print message
int check_empty = 0; // 0 = not empty, 1 = empty or comment line
int last_exit_code = -1; 
// -1 no foreground process or background process. Also -1 = no process has been run after launching icsh.
// any other number = exit code of last process updating this variable

extern volatile pid_t foreground_pid;

// allows valid command function to work for both shell mode or script mode


void start_shell() {
    // Start message for the shell
    printf("Welcome to icsh!\n");
    printf("This is made by Hardik Vijay\n");
    printf("Except the start art\n");
    vegito_start_art();
    printf("Art was not made by me, but Uroll Insipred me.\n");
}



int main(int argc, char *argv[]) {

    setpgid(0, 0);
    tcsetpgrp(STDIN_FILENO, getpid());
    signal(SIGTTOU, SIG_IGN);
    signal(SIGTTIN, SIG_IGN);

    setup_signal_handlers(); // Setup signal handlers for SIGINT and SIGTSTP

    if (argc > 1) {
        iterate_input(argc, argv); // to loop all inputs through script mode
        }
    else {

        char buffer[MAX_CMD_BUFFER];
        start_shell();
        
        while (1) {
            printf("icsh $ ");
            fflush(stdout); // Ensure prompt is printed immediately
            fgets(buffer, 255, stdin);
            if (feof(stdin)) {
                printf("\n");
            } else {

                is_valid_command(buffer);
                if (check_empty != 0) {
                    check_empty = 0; // reset check_empty for next command

                // } else if (check_invalid != 0) {
                //     check_invalid = 0; 
                //     printf("bad command\n");
                }
            }
        }

        // printf("you said: %s\n", buffer); (starter code)
            // if (strncmp(buffer, "exit", 4) == 0) { 
            //     printf("Exiting icsh. Goodbye!\n");
            //     break;
            // } (starter code)  
    }
}         