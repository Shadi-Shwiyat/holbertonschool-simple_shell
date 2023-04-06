#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib>
#include <unistd.h>
#include <sys/wait.h>

#define BUFSIZE 100 /* constant buffer to use in toekn functions*/
#define DELIM "\t\n" /* delimiters to check */

int hsh_env(char **args, char *input_stdin, int *exit_status);
int hsh_exit(char **args, char *input_stdin, int *exit_status);

#endif