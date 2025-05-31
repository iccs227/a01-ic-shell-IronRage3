#include "stdio.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "command_check.h"
#include "milestone_1.h"
#include "milestone_2.h"

#include "milestone_3.h"
#include <sys/types.h>
#include <sys/wait.h> 
#include <unistd.h>
#include <errno.h>


// Global variables from icsh.c
extern char previous_buffer[MAX_CMD_BUFFER];
extern int check_invalid;
extern int check_empty;


void execute_external_command(char *buffer, char *tokenized_buffer[]) {

    pid_t pid = fork(); // Create a new process

    if (pid < 0) {
        perror("Fork failed");
        check_invalid = 1; // Set invalid command flag
        return; 
        // Exit the function on fork failure - return early in case code has new entries after if else statements

    } else if (pid == 0) {
        // Child process
        execvp (tokenized_buffer[0], tokenized_buffer); // Execute the command
        perror("Execution failed"); // If execvp fails, it returns -1 and sets errno
        exit(errno);

    }else {
        int status;
        waitpid(pid, &status, 0); // Parent process waits for child to finish

        if (WIFEXITED(status)) {
            int exit_status = WEXITSTATUS(status);

            if (exit_status != 0) {
                check_invalid = 1; // to prevent previous buffer from being replaced as this one did not execute successfully
            } else{
                replace_previous_buffer(buffer);
            }
        
        } else {
            check_invalid = 1; // for now process anything exit from "WIFEXITED = false" as invalid command
        }

    }

}

