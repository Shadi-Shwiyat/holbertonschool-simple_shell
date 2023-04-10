#include "shell.h"

/**
 * hsh_tokenizer - Split the input string into a array of arguments (tokens)
 * @input: String from input (main function)
 * Return: Pointer to the array of tokens
 *
 * Overall, this function provides a useful way to tokenize a string into an array of tokens,
 * which can be used for further processing in a shell program
 */
char **hsh_tokenizer(char *input)
{
    int buffer = BUFSIZE, newBuffer = 0, position = 0;
    char **tokens = NULL, *token = NULL;
    char **backup_tokens = NULL;
    char *trimmed_token = NULL;

    tokens = malloc(buffer * sizeof(char *));
    if (tokens == NULL)
    {
        fprintf(stderr, "memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    /* Skip leading spaces */
    while (*input == ' ')
        input++;

    /* Use strsep to tokenize the input string */
    while ((token = strsep(&input, DELIM)) != NULL)
    {
        /* Trim trailing spaces from the token */
        while (strlen(token) > 0 && token[strlen(token) - 1] == ' ')
        {
            token[strlen(token) - 1] = '\0';
        }

        /* Trim leading spaces from the token */
        trimmed_token = token;
        while (*trimmed_token == ' ')
        {
            trimmed_token++;
        }

        if (strlen(trimmed_token) > 0)
        {
            tokens[position] = trimmed_token;
            position++;

            if (position >= buffer)
            {
                newBuffer = BUFSIZE * 2;
                backup_tokens = tokens;
                tokens = realloc(tokens, newBuffer * sizeof(char *));
                if (tokens == NULL)
                {
                    free(backup_tokens);
                    fprintf(stderr, "memory allocation error\n");
                    exit(EXIT_FAILURE);
                }
                buffer = newBuffer;
            }
        }
    }

    tokens[position] = NULL;
    return tokens;
}

/**
 * tokenizer_path - Split the environment variable PATH into an array of tokens
 * @input: Pointer to environment variable PATH
 * Return: Pointer to the array of tokens
 */
char **tokenizer_path(char *input)
{
	int buffer = BUFSIZE, newBuffer = 0, position = 0;
	char **tokens = NULL, *token = NULL;
	char **backup_tokens = NULL;

	/* allocate memory for the array of tokens */
	tokens = malloc(buffer * sizeof(char *));
	if (tokens == NULL)
	{
		fprintf(stderr, "memory allocation error\n");
		exit(EXIT_FAILURE);
	}
	/* tokenize the PATH string, checking for deliminter :and replace it with \0 and stores resulting tokens i nthe tokens array*/
	token = strtok(input, ":");
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		/* reallocate the array of tokens if necessary*/
		if (position >= buffer)
		{
			newBuffer = BUFSIZE * 2; /* doubles the buffer size*/
			backup_tokens = tokens;
			tokens = _realloc(tokens, buffer, newBuffer * sizeof(char *));
			if (tokens == NULL)
			{
				free(backup_tokens);
				free(tokens);
				fprintf(stderr, "memory allocation error\n"); /* if error during realloc print error */
				exit(EXIT_FAILURE);
			}
		}
		/* once memory reallocation, continue processing the PATH string */
		token = strtok(NULL, ":");
	}
	/* null terminate the array of tokens and returns a pointer to the tokens array */
	tokens[position] = NULL;
	return (tokens);
}
