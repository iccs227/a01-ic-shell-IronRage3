#ifndef MILESTONE_1_H
#define MILESTONE_1_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "start_art.h"
#include "command_check.h"
#include "milestone_3.h"

#define MAX_CMD_BUFFER 255

// Global variables from icsh.c
extern char previous_buffer[MAX_CMD_BUFFER];
extern int check_invalid;
extern int check_empty;


void echo_command(char *buffer, int *tokenized_count);
// void echo_command(char *buffer, char **tokenized_buffer, int *tokenized_count);

void repeat_command(char *buffer);
void exit_command(char *buffer);


#endif
