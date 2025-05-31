#include "stdio.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "command_check.h"
#include "milestone_1.h"

#include "milestone_3.h"
#include <sys/types.h>
#include <sys/wait.h> 
#include <unistd.h>
#include <errno.h>


// Global variables from icsh.c
extern char previous_buffer[MAX_CMD_BUFFER];
extern int check_invalid;
extern int check_empty;


extern int last_exit_code;

extern volatile pid_t foreground_pid;




void execute_external_command(char *buffer, char *tokenized_buffer[]) {

    pid_t pid = fork(); // Create a new process

    if (pid < 0) {
        perror("Fork failed");
        check_invalid = 1; // Set invalid command flag
        return; 
        // Exit the function on fork failure - return early in case code has new entries after if else statements

    } else if (pid == 0) {
        // Child process
        setpgid(pid, pid);
        execvp (tokenized_buffer[0], tokenized_buffer); // Execute the command
        perror("Execution failed"); // If execvp fails, it returns -1 and sets errno
        exit(errno);

    }else {
        setpgid(pid, pid); // Matching Parent process ID with child process ID
        tcsetpgrp(STDIN_FILENO, pid); // Allow child process to work with terminal itself
        foreground_pid = pid;
        int status;
        waitpid(pid, &status, WUNTRACED); // Parent process waits for child to finish
        tcsetpgrp(STDIN_FILENO, getpid()); // Reset terminal control to shell
        foreground_pid = 0; // Reset foreground PID after process completion so other process dont falsely interrupt it
        


        if (WIFEXITED(status)) {
            int exit_status = WEXITSTATUS(status);
            last_exit_code = exit_status; // Update last exit code

            if (exit_status != 0) {
                check_invalid = 1; // to prevent previous buffer from being replaced as this one did not execute successfully
            } else{
                replace_previous_buffer(buffer);
            }
        
        } else if (WIFSTOPPED(status)) {
            //If the child process was terminated by a signal
            
            int stop_sig = WSTOPSIG(status);
            if (stop_sig == SIGTSTP) {
                printf("\nSuspended: %s\n PID: %d \n", buffer, pid);
            }
        }

    }

}

