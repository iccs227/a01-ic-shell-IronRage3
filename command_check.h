#ifndef COMMAND_CHECK_H
#define COMMAND_CHECK_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdbool.h>
#include "milestone_1.h"

#define MAX_CMD_BUFFER 255

extern char previous_buffer[MAX_CMD_BUFFER];

void is_valid_command(char *buffer);


#endif
