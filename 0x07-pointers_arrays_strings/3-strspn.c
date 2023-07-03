#include "main.h"

/**
 * _strspn - Gets the length of a prefix substring.
 * @s: The string to search.
 * @accept: The characters to match.
 *
 * Return: The number of bytes in the initial segment of s which consist
 *         only of bytes from accept.
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	int i, j;
	int is_match;

	for (i = 0; s[i] != '\0'; i++)
	{
		is_match = 0;
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
			{
				is_match = 1;
				break;
			}
		}

		if (is_match == 0)
		{
			break;
		}

		count++;
	}

	return (count);
}

