#include <stdlib.h>
#include "main.h"

/**
 * _strdup - Returns a pointer to a newly allocated space in memory,
 *           which contains a copy of the string given as a parameter.
 * @str: The string to duplicate.
 *
 * Return: Pointer to the duplicated string, or NULL if str is NULL
 *         or if insufficient memory was available.
 */
char *_strdup(char *str)
{
	char *duplicate;
	unsigned int length, i;

	if (str == NULL)
		return (NULL);

	/* Determine the length of the string */
	length = 0;
	while (str[length] != '\0')
		length++;

	/* Allocate memory for the duplicate string */
	duplicate = malloc((length + 1) * sizeof(char));

	if (duplicate == NULL)
		return (NULL);

	/* Copy the string to the duplicate */
	for (i = 0; i <= length; i++)
		duplicate[i] = str[i];

	return (duplicate);
}

