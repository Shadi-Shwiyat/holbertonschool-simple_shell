#include "shell.h"

/**
 * hsh_execute - Fork process and replace the child
 * with a new program
 *
 * @args: String of arguments (tokens)
 * @argv: Array of arguments
 * @exit_status: Exit status
 *
 * Return: Always 1 (success)
 */
int hsh_execute(char **args, char **argv, int *exit_status)
{
	pid_t pid;
	int status; /* this will be used with waitpid syscall */
	char *new_args; /* this will be the path to the executable file */

	/* check if PATH exists and can be accessed, also tokenize PATH */
	new_args = validate_input(args, argv);
	if (strcmp(new_args, "Fail access") == 0)
		return (1);
	pid = fork();
	/* create a duplicate process (child) */
	if (pid == 0) /* current process is child process */
	{
		/* pass execve tokenized command, wait for execution */
		if (execve(new_args, args, environ) == -1)
		{
			perror("execve fail");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0) /* check if fork fails */
	{
		perror("Error forking");
		free(new_args);
		return (1);
	}
	else
	/* safety net if fork() failed to created a child process or execve fails */
	{
		/* equivalent to wait, -1 indicates parent to wait for child to terminate */
		waitpid(-1, &status, 0);
		/* check if the chld terminated normally with macro */
		if (WIFEXITED(status))
		/* set exit status equal to the return child process main */
			*exit_status = WEXITSTATUS(status);
		/* evaluate first element of first token */
		if (args[0][0] != '/' && args[0][0] != '.')
			free(new_args);
		return (1);
	}
	return (1);
}

/**
 * hsh_execute_builtins - Choose from an array of builtin functions
 *
 * @args: String of arguments (tokens)
 * @input_stdin: String from input
 * @argv: Array of arguments
 * @exit_status: Exit status
 *
 * Return: Status to stay or exit the main loop,
 * 1 or 0
 */
int hsh_execute_builtins(char **args, char *input_stdin,
			char **argv, int *exit_status)
{
	int i = 0;

	/* builtin functions array of type 'structure choose_builtin' (see main.h) */
	choose_builtins_t options[] = {
		{"exit", hsh_exit},
		{"env", hsh_env},
		{"cd", hsh_cd},
		{"setenv", hsh_setenv},
		{"unsetenv", hsh_unsetenv},
		{NULL, NULL}
	};

	while (options[i].name_builtin)
	{
		/* compare if args[0] matches the builtin function name */
		if (strcmp(options[i].name_builtin, args[0]) == 0)
		{
			/* return the pointer to function (2nd memeber of array) and execute it */
			return ((int)((*options[i].func_builtin)(args, input_stdin, exit_status)));
		}
		i++;
	}
	/* if no builtin function is encountered execute a process */
	return (hsh_execute(args, argv, exit_status));

}
