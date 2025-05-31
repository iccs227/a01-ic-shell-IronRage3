#ifndef COMMAND_CHECK_H
#define COMMAND_CHECK_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdbool.h>
#include "milestone_1.h"
#include "milestone_3.h"

#define MAX_CMD_BUFFER 255

// Global variables from icsh.c
extern char previous_buffer[MAX_CMD_BUFFER];
extern int check_invalid;
extern int check_empty;

void is_valid_command(char *buffer);
void replace_previous_buffer(char *buffer);
void tokenize_command(char *buffer, char *tokenized_buffer[], int *tokenized_count);


#endif
