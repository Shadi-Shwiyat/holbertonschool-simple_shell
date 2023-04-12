#include "shell.h"

/**
* validate_input - Validates if the PATH exists
* @args: String of Tokens
* @argv: String of arguments from input
* Return: A pointer to an array of the tokenized PATH directories
*/
char *validate_input(char **args, char **argv) /* */
{
	char *new_args, *first, *slash_argument = "/";
	char **tokens_path, holder_env[1024];
	int i = 0;

	if (args[0][0] == '/' || args[0][0] == '.') /* check first element in array if starts with "." or "/" character if so assumes arg is a path or executable file*/
	{
		new_args = args[0]; /* point to the same address */
		if ((access(new_args, F_OK) == -1)) /* check if file exists if not it points to error message */
		{
			fprintf(stderr, "%s: %d: %s: No such file or directory\n", argv[0], __LINE__, args[0]); /* returns this message as error if file or path doesnt exist */
			return ("Fail access");
		}
	}
	else
	{
		strcpy(holder_env, getenv("PATH")); /* get PATH and copy it to holder_env buffer*/
		tokens_path = tokenizer_path(holder_env); /* tokenize holer_env into array of directory PATH environment string */
		while (tokens_path[i])
		{
			/* checkking if file exists if not frees allocated memory for the full path and continues to next directory*/
			first = str_concat(slash_argument, args[0]);
			new_args = str_concat(tokens_path[i], first);
			if ((access(new_args, F_OK) == -1))
			{
				free(new_args);
				free(first);
			}
			else
			{
				free(tokens_path);
				free(first);
				return (new_args);
			}
			i++;
		}
		/*if function has iterated through all directories in tokens_path array and not found executable file prits error message to stderr and returns error*/
		free(tokens_path);
		fprintf(stderr, "%s: %d: %s: No such file or directory\n", argv[0], __LINE__, args[0]);
		return ("Fail access");
	}
	return (new_args);
}

/**
* validate_only_spaces - Checks if input is only spaces
* @input: string from input
* Return: 0 if there are spaces, tabs or line breaks
*/
int validate_only_spaces(char *input)
{
	int i = 0, flag = 1, len = 0;

	len = strlen(input); /* getting the length of the input string */

	while (input[i] == ' ' || input[i] == '\n' || input[i] == '\t') /* iterate through the input string until a non-space/tab/newline character is found*/
		i++;

	if (i != len) /* if "i" is not equal to len it means that there are other characters in the input string besides spaces,tabs,line breaks */
		flag = 0;
	return (flag); /* All we are doing is ensuring that there is something in the input and just not spaces,tabs, or line break*/
}
