#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib>
#include <unistd.h>
#include <sys/wait.h>

#define BUFSIZE 100 /* constant buffer to use in toekn functions*/
#define DELIM "\t\n" /* delimiters to check */

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

/* execute commands */
int hsh_execute(char *args[], char *argv[], int *exit_status);
int hsh_execute_builtins(char *args[], char *input_stdin, char *argv[], int *exit_status);

/* validate inputs */
char *validate_input(char *args[], char *argv[] __attribute__((unused)));
int validate_only_spaces(char *input);

/* tokenizers */
char **hsh_tokenizer(char *input);
char **tokenizer_path(char *input);

/* builting functions */
int hsh_env(char **args, char *input_stdin, int *exit_status);
int hsh_exit(char **args, char *input_stdin, int *exit_status);

#endif
