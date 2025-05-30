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


void execute_external_command(char *buffer, char *tokenized_buffer, int *tokenized_count) {


    pid_t pid; = fork(); // Create a new process

    if (pid < 0) {
        perror("Fork failed");
        exit(errno);

    } else if (pid == 0) {
        // Child process
        execvp (tokenized_buffer[0], tokenized_buffer); // Execute the command
        perror("execvp failed"); // If execvp fails, print error - for local testing
        exit(errno);

    }else {
        int *status;
        waitpid(pid, &status, 0); // Parent process waits for child to finish

        int exit_status = WEXITSTATUS(status);
        
        if (exit_status != 0) {
            check_invalid = 1;
        }

    }

}

