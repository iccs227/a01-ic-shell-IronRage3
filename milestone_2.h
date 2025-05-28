#ifndef MILESTONE_2_H
#define MILESTONE_2_H

#include "stdio.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "command_check.h"
#include "milestone_1.h"

#define MAX_CMD_BUFFER 255

extern char previous_buffer[MAX_CMD_BUFFER];
extern int check_valid;
extern int check_empty;

void script_mode(int argc, char *argv[]);
void iterate_input(int argc, char *argv[]);


#endif