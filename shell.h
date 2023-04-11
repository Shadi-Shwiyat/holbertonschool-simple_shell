#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <string.h>

#define BUFSIZE 100 /* constant buffer to use in toekn functions*/
#define DELIM " \t\n" /* delimiters to check */

/**
 * struct choose_builtin - Builtin commands struct
 * @name_builtin: Name of builtin command
 * @func_builtin: Pointer to builtin command functions
 */
typedef struct choose_builtin
{
	char *name_builtin;
	int (*func_builtin)(char **, char *, int *);
} choose_builtins_t;

/* global variable to access the enviromment list */
extern char **environ;

/* execute commands */
int hsh_execute(char *args[], char *argv[], int *exit_status);
int hsh_execute_builtins(char *args[], char *input_stdin,
		char *argv[], int *exit_status);

/* validate inputs */
char *validate_input(char *args[], char *argv[] __attribute__((unused)));
int validate_only_spaces(char *input);

/* tokenizers */
char **hsh_tokenizer(char *input);
char **tokenizer_path(char *input);

/* builtin functions */
int hsh_cd(char *args[], char *input_stdin, int *exit_status);
int hsh_setenv(char *args[],  char *input_stdin, int *exit_status);
int hsh_unsetenv(char **args,  char *input_stdin, int *exit_status);
int hsh_env(char **args, char *input_stdin, int *exit_status);
int hsh_exit(char **args, char *input_stdin, int *exit_status);

/* helper functions*/
char *str_concat(char *s1, char *s2);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

#endif
