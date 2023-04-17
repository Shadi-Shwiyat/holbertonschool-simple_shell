#include "shell.h"

/**
 * hsh_tokenizer - Split the input string into a array of arguments (tokens)
 * @input: String from input (main function)
 * Return: Pointer to the array of tokens
 *
 * Overall, this function provides a useful way
 * to tokenize a string into an array of tokens,
 * which can be used for further processing in a shell program
 *
 * At the start char**tokens initializes variables for the buffer size (buffer)
 * a new buffersize in case a reallocation is needed (newBuffer), the current
 * position in the array of tokens (position)
 */
char **hsh_tokenizer(char *input)
{
	char **tokens = NULL, *token = NULL;
	int buffer = BUFSIZE, newBuffer = 0, position = 0;
	char **backup_tokens = NULL;
	/*allocate memory for the array of tokens */
	tokens = malloc(buffer * sizeof(char *));
	if (tokens == NULL)
	{
		fprintf(stderr, "memory allocation error\n");
		exit(EXIT_FAILURE);
	}
	/* tokenize the input string, checking for delimiter to split*/
	/*the string and replace them with \0 */
	token = strtok(input, DELIM);
	while (token != NULL)
	{
		/*the array of tokens and the position variable is incremeneted*/
		tokens[position] = token;
		position++;
		/*if position variable is greater than or qual to buffer size, reallocate*/
		/*memory for the array of tokens*/
		if (position >= buffer)
		{
			newBuffer = BUFSIZE * 2;
			backup_tokens = tokens;
			tokens = _realloc(tokens, buffer, newBuffer * sizeof(char *));
			/*if fail,frees backup array of tokens,frees current token,& prints error*/
			if (tokens == NULL)
			{
				free(backup_tokens);
				free(tokens);
				fprintf(stderr, "memory allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		/*once memory reallocation, continue processing the input string */
		token = strtok(NULL, DELIM);
	}
	/*null terminate the array of tokens */
	tokens[position] = NULL;
	return (tokens);
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
	/*allocate memory for the array of tokens */
	tokens = malloc(buffer * sizeof(char *));
	if (tokens == NULL)
	{
		fprintf(stderr, "memory allocation error\n");
		exit(EXIT_FAILURE);
	}
	/*tokenize the PATH string, checking for deliminter :and replace it*/
	/*with \0 and stores resulting tokens i nthe tokens array*/
	token = strtok(input, ":");
	while (token != NULL)
	{
		tokens[position] = token;
		position++;
		/*reallocate the array of tokens if necessary*/
		if (position >= buffer)
		{
			/*doubles the buffer size*/
			newBuffer = BUFSIZE * 2;
			backup_tokens = tokens;
			tokens = _realloc(tokens, buffer, newBuffer * sizeof(char *));
			if (tokens == NULL)
			{
				free(backup_tokens);
				free(tokens);
				/*if error during realloc print error */
				fprintf(stderr, "memory allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		/*once memory reallocation, continue processing the PATH string */
		token = strtok(NULL, ":");
	}
	/*null terminate the array of tokens and*/
	/*returns a pointer to the tokens array */
	tokens[position] = NULL;
	return (tokens);
}
