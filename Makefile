CC=gcc
CFLAGS=-Wall -g 
BINARY=icsh

all: icsh

icsh: icsh.c 
	$(CC) -o $(BINARY) $(CFLAGS) icsh.c start_art.c command_check.c milestone_1.c milestone_2.c milestone_3.c milestone_4.c

.PHONY: clean

clean:
	rm -f $(BINARY)
