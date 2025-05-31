#ifndef MILESTONE_4_H
#define MILESTONE_4_H

#include "stdio.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "start_art.h"
#include "command_check.h"

#include "milestone_1.h"
#include "milestone_3.h"



#define MAX_CMD_BUFFER 255

// Global variables from icsh.c
extern char previous_buffer[MAX_CMD_BUFFER];
extern int check_invalid;
extern int check_empty;


extern volatile pid_t foreground_pid;

void sigint_handler(int sig);
void sigtstp_handler(int sig);
void setup_signal_handlers();



#endif