#include "shell.h"

/**
 * hsh_cd - Change directory
 *
 * @args: Array of tokens
 * @input_stdin: Input from stdin
 * @exit_status: Exit status
 *
 * Return: Always 1 (success)
 */
int hsh_cd(char **args, char *input_stdin, int *exit_status)
{
	int status; /* store return value of chdir() syscall */
	char cwd[128]; /* used to store the cwd */

	/* get the cwd, and save it in s */
	getcwd(cwd, sizeof(cwd));

	(void)input_stdin;
	(void)exit_status;

	/* cd input w/o any args should change to HOME dir */
	if (args[1] == NULL)
		status = chdir(getenv("HOME"));
	/* user inputs cd - */
	else if (strcmp(args[1], "-") == 0)
		/* change to previous directory */
		status = chdir(getenv("OLDPWD"));
	/* user inputs cd ~ */
	else if (strcmp(args[1], "~") == 0)
		/* change to home directory */
		status = chdir(getenv("HOME"));
	else /* change to the specific path given (absolute or relative) */
		status = chdir(args[1]);

	/* check if any chdir() syscall had an error */
	if (status == -1)
		perror("cd: error");

	/* set the env variable "OLDPWD" to value of the cwd */
	/* the parameter 1 indicates if "OLDPWD" already exist to overwrite it */
	setenv("OLDPWD", cwd, 1);

	/* set the env variable "PWD" also to the value of cwd */
	/* the parameter 1 indicates if "PWD" already exist to overwrite it */
	setenv("PWD", getcwd(cwd, sizeof(cwd)), 1);
	return (1);
}

/**
 * hsh_setenv - Adds or changes an environment variable
 *
 * @args: Array of tokens from input
 * @input_stdin: Input from stdin
 * @exit_status: Exit status
 *
 * Return: Always 1 (success)
 */
int hsh_setenv(char **args,  char *input_stdin, int *exit_status)
{
	int n_tokens = 0; /* used to count # of tokens in CLI (same as argc) */

	(void)input_stdin;
	(void)exit_status;

	/* count # of tokens in CLI (same as argc) */
	while (args[n_tokens] != NULL)
	{
		n_tokens++;
	}

	/* user must supply setenv command along with two args */
	if (n_tokens == 3)
		/* In the array of tokens, args[0] is equivilant to "setenv" command, */
		/* args[1] is added to the environment, its value is set to args[2], */
		/* the parameter 1 indicates if "args[1]" already exist to overwrite it */
		/* with the value of "args[2]" */
		setenv(args[1], args[2], 1);

	/* if user supplied incorrect number of args, print an error */
	else
		fprintf(stderr, "incorrect format, use: \"setenv [KEY] [VALUE]\"\n");

	return (1);
}

/**
 * hsh_unsetenv - Deletes an env var from the environment
 *
 * @args: Array of tokens from input
 * @input_stdin: Input from stdin
 * @exit_status: Exit status
 *
 * Return: Always 1 (success)
 */
int hsh_unsetenv(char **args,  char *input_stdin, int *exit_status)
{
	int n_tokens = 0; /* used to count # of tokens in CLI (same as argc) */

	(void)input_stdin;
	(void)exit_status;

	/* count # of tokens in CLI (same as argc) */
	while (args[n_tokens] != NULL)
	{
		n_tokens++;
	}

	/* user must supply unsetenv command with one argument as var to delete */
	if (n_tokens == 2)
		/* delete the variable args[1] from the environment */
		unsetenv(args[1]);
	/* if user supplied incorrect number of args, print an error */
	else if (n_tokens != 2)
		fprintf(stderr, "incorrect format, use: \"unsetenv [KEY]\"\n");

	return (1);
}

/**
 * hsh_env - Prints enviroment variable of current process
 *
 * @args: arguments
 * @input_stdin: input of stdin
 * @exit_status: exit status
 *
 * Return: Always 1 (success)
 */
int hsh_env(char **args, char *input_stdin, int *exit_status)
{
	int i = 0; /* iterator in for looop */

	(void)args;
	(void)input_stdin;
	(void)exit_status;

	/* check if the environment variables of current process are empty, */
	/* and if they are print an error */
	if (environ[i] == NULL)
	{
		printf("%s\n", "The builtin env is empty");
		return (1);
	}

	/* use a for loop to iterate through array of each environment */
	/* variable being used by current process, and print to stdout */
	for (i = 0; environ[i]; i++)
		printf("%s\n", environ[i]);

	return (1);
}

/**
 * hsh_exit - Function exits the shell
 *
 * @args: arguments
 * @input_stdin: input of stdin
 * @exit_status: exit status
 *
 * Return: 0 on failure otherwise exits and returns
 * the exit status
 */
int hsh_exit(char **args, char *input_stdin, int *exit_status)
{
	int output_exit = 0; /* used to store the exit status */

	(void)args;
	(void)input_stdin;

	/* check for any argurements passed with exit command, */
	/* if not then free memory allocated for shell and exit */
	/* while returning exit status */
	if (args[1] == NULL)
	{
		free(args);
		free(input_stdin);
		exit(*exit_status);
	}

	/* check if user supplied incorrect number of arguements */
	/* for the exit command, if so then print an error and */
	/* return 0 to indicate failure */
	if (args[2] != NULL)
	{
		fprintf(stderr, "exit: too many arguments\n");
		return (0);
	}

	/* is user supplied an arguement to exit command, */
	/* this converts the arguement to an interger value */
	/* to return upon exit, then frees allocated memory */
	/* for shell and exits program returning output_exit */
	/* variable */
	output_exit = atoi(args[1]);
	free(args);
	free(input_stdin);
	exit(output_exit);
}
