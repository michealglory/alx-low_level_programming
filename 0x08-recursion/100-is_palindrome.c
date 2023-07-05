#include "main.h"

/**
 * is_palindrome - Checks if a string is a palindrome
 * @s: The string to check
 *
 * Return: 1 if @s is a palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
	int length = 0;
	int i, j;

	/* Get the length of the string */
	while (s[length])
		length++;

	/* Compare characters from both ends of the string */
	for (i = 0, j = length - 1; i < j; i++, j--)
	{
		/* If characters at current positions don't match, it's not a palindrome */
		if (s[i] != s[j])
			return (0);
	}

	/* If the loop completes without returning, the string is a palindrome */
	return (1);
}

