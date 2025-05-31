[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/WIXYXthJ)
===========================================================================
# ICSH

Please describe your assumptions and/or implementation here. 

## Milestone 1:
1. Has been refactored to use strtok from while loop manually searching process.  
2. May plan to add more echo related features.  
3. Assumption made is that if user inputs "#" or "##" then it is same as no input given so it gives another prompt for entry.  
4. Another Assumption made is that exit code is either 0 or custom user input only.
5. Echo Assumption - Intentionally leaving "echo      hello world" to print as "      hello world" instead of "hello world" any space or \t is kept as it is.
6. (In milestone 7, I may implement features for echo so it will change for quoted text only)

===========================================================================

## Milestone 2:
1. Script Mode - Assumption made that after all inputs are read, exit back to main terminal not icsh shell.  
2. Another Assumption made is that exit code is 0 after all inputs are read or the exit code inside the file which has exit command.   

===========================================================================

## Milestone 3:
1. Testing Done.
2. Assumption Made, The input given is invalid for:
    - If fork fails.  
    - If execvp fails.  
    - If execvp works but exit_code is not 0.

===========================================================================

## Milestone 4:
1. Assumption Made, When the code exits with any number it updates int last_exit_code.
    - `echo $?` will print last_exit_code.  
    - This exit code is not truncated.  
    - So process will give their own exit code and they will be printed with no modifications.
    - If `echo $?` is the first command given - outputs -1 as no process have run before calling it.
    - If the process has been signal interrupted the command is not saved for !! to run since it failed to execute.

===========================================================================

## Milestone 5:
1. Not Done.

===========================================================================

## Milestone 6:
1. Not Done.

===========================================================================

## Milestone 7:
1. Plan changed - No more echo upgrade
2. Print custom art for launching shell in normal mode
3. if input is exit command - prints custom art

===========================================================================
