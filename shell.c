#include "shell.h"

/**
* main - Main loop that parses input from Command Line interface and executes
* @argc: Number of args passed to the program
* @argv: Array of arguments
* Return: Always 0 on success
*/

int main(int argc __attribute__((unused)),
		char *argv[] __attribute__((unused)))
{
	char **args = NULL; /*array of tokens*/
	char *input_stdin = NULL; /* getline manages the memory so we set to NULL */
	int status_return = 1, exit_status = 0;
	size_t size = 0; /* we let getline manage the size of the buffer */
	ssize_t glrv = 0; /* checking getline return value (glrv) and EOF */

	/* checking if we exit the loop*/
	while (status_return && glrv != EOF)
	{
		size = 0; /* setting to 0 for every new input */
		/* return 1 if the file in the argument refers to the terminal */
		status_return = isatty(STDIN_FILENO);
		if (status_return) /* if we are in interactive mode */
			write(STDOUT_FILENO, "$ ", 2); /* print prompt */
		glrv = getline(&input_stdin, &size, stdin);/* get input from stdin */
		if (glrv == -1) /* if we get EOF or any error */
		{
			free(input_stdin);
			break;
		}
		/* if only spaces, tabs and line breaks are inputted */
		if (validate_only_spaces(input_stdin))
		{
			free(input_stdin);
			continue;
		}
		/* split input_stdin string into an array of arguments (tokenize input) */
		args = hsh_tokenizer(input_stdin);
		if (*args[0] == '\0') /* if we get only spaces, tabs and line breaks */
			continue;
		status_return = hsh_execute_builtins(args, input_stdin,
		argv, &exit_status);
		free(input_stdin);
		free(args);
	}
	return (0);
}
