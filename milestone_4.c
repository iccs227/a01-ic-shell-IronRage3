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

#include <signal.h>

#define MAX_CMD_BUFFER 255


// Global variables from icsh.c
extern char previous_buffer[MAX_CMD_BUFFER];
extern int check_invalid;
extern int check_empty;


volatile pid_t foreground_pid = 0;

void sigint_handler(int sig) {
    if (foreground_pid > 0) {
        kill(foreground_pid, SIGINT);
    } else {
        // If no foreground process, print a message
        write(STDOUT_FILENO, "\nicsh $ ", 8); // prevent ^CHello cases to happen
    }
}

void sigtstp_handler(int sig) {
    if (foreground_pid > 0) {
        kill(foreground_pid, SIGTSTP);
    } else {
        write(STDOUT_FILENO, "\nicsh $ ", 8); // prevent ^ZHello cases to happen
    }
}

void setup_signal_handlers() {
    struct sigaction sa_int, sa_tstp;

    sa_int.sa_handler = sigint_handler;
    sa_int.sa_flags = SA_RESTART;; // No special flags
    sigemptyset(&sa_int.sa_mask); // No additional signals blocked during handler

    sa_tstp.sa_handler = sigtstp_handler;
    sa_tstp.sa_flags = SA_RESTART;; // No special flags
    sigemptyset(&sa_tstp.sa_mask); // No additional signals blocked during handler

    


    sigaction(SIGINT, &sa_int, NULL);
    sigaction(SIGTSTP, &sa_tstp, NULL);

}

