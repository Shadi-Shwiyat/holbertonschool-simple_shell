#include "shell.h"

/**
 * str_concat - Concatenate two strings
 * @s1: String 1
 * @s2: String 1
 * Return: Pointer to the concatenated string
 *
 * Overall this is helping in the validator.c file to check if a file exist
 * and if not continues to check the next file by taking two strings and
 * combines them returns a new string containing the concatenated strings
 */
char *str_concat(char *s1, char *s2)
{
	char *s;
	unsigned int i;
	unsigned int j;
	unsigned int k;

	/* if either strings are empty the function treats it as an empty strings*/
	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	/*determines the length of each input string by going through the loops */
	for (i = 0; s1[i] != '\0'; i++)
		continue;

	for (j = 0; s2[j] != '\0'; j++)
		continue;

	j = j + 1; /*making room for the NULL terminator*/
	/*stores the combined strings into "s" to dynamically allocate memory*/
	s = malloc((i + j) * sizeof(char));
	if (s == NULL) /*if malloc fails, the function returns NULL*/
		return (0);
	/*loop goes through each character and based on it position puts in s1 or s2*/
	for (k = 0; k < (i + j) ; k++)
	{
		if (k < i)
			s[k] = s1[k];
		if (k >= i)
			s[k] = s2[k - i];
	}
	return (s);
}

/**
 * _realloc - Reallocate a memory block
 * @ptr: Pointer to array
 * @old_size: Old size
 * @new_size: New size
 * Return: A pointer to the allocated memory
 *
 * Overall this is used to resize a previous allocated memory block
 * taking care of operations in a safe way
 * Also provides option to free memory if new_size is 0
 */

 /*ptr is previous allocated memory block, old_size old size of the*/
 /* memory block, new_size new size of the memory block*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *s;
	char *ptr1;
	unsigned int i;

	/*allows the function to treat memory block as an array of chars*/
	ptr1 = (char *)ptr;
	/*if ptr is NULL, returns a poniter to newly allocated memory block*/
	if (ptr == NULL)
		return (malloc(new_size));
	/*free memory block pointed to by ptr and returns NULL*/
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size == old_size)/*returns ptr without doing anything*/
		return (ptr);

	s = malloc((new_size) * sizeof(char));
	if (s == NULL)
	{
		free(s);
		return (NULL);
	}
	/*allocates a new memory block of size new_size copies contents*/
	/*of old memory block into the new one using loop then free old lock*/
	if (new_size > old_size)
	{
		for (i = 0; i < old_size; i++)
			s[i] = ptr1[i];
	}
	/*allocates a new memory block of size new_size copies necessary*/
	/*amount of data from old block to new one and free old memory block*/
	if (new_size < old_size)
	{
		for (i = 0; i < new_size; i++)
			s[i] = ptr1[i];
	}
	free(ptr1);
	return (s);
}
