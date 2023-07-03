#include "main.h"
#define NULL ((void *)0)

/**
 * _strchr - Locates a character in a string
 * @s: Pointer to the string to be searched
 * @c: Character to be located
 *
 * Return: Pointer to the first occurrence of the character c in the string s,
 *         or NULL if the character is not found
 */
char *_strchr(char *s, char c)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (s + i);

		i++;
	}

	if (s[i] == c)
		return (s + i);

	return (NULL);
}

