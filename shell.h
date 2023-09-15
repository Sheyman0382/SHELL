#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

void _printf(char *str);
char *accept_command(void);
char *get_location(char *command);
void execute(char **argv);
void environ_var(void);

#endif
