#ifndef MILESTONE_1_H
#define MILESTONE_1_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "start_art.h"
#include "command_check.h"

#define MAX_CMD_BUFFER 255

extern char previous_buffer[MAX_CMD_BUFFER];
extern int check_valid;

void replace_previous_buffer(char *buffer);
void echo_command(char *buffer);
void shebang_command(char *buffer);
void exit_command(char *buffer);


#endif
