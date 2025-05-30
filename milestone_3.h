#ifndef MILESTOENE_3_H
#define MILESTOENE_3_H

#include "stdio.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "command_check.h"
#include "milestone_1.h"
#include "milestone_2.h"

#include <sys/types.h>
#include <sys/wait.h> 
#include <unistd.h> 
#include <errno.h>


// Global variables from icsh.c
extern char previous_buffer[MAX_CMD_BUFFER];
extern int check_invalid;
extern int check_empty;

void execute_external_command(char *buffer, char *tokenized_buffer, int *tokenized_count);







#endif