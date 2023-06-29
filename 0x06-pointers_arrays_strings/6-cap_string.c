#include "main.h"

/**
 * isSeparator - Checks if a character is a separator.
 * @c: The character to check.
 *
 * Return: 1 if the character is a separator, 0 otherwise.
 */
int isSeparator(char c)
{
	char separators[] = " \t\n,;.!?\"(){}";
	int numSeparators = sizeof(separators) / sizeof(separators[0]);
	int i;

	for (i = 0; i < numSeparators; i++)
	{
		if (c == separators[i])
			return (1);
	}

	return (0);
}

/**
 * cap_string - Capitalizes all words of a string.
 * @str: The input string.
 *
 * Return: A pointer to the modified string.
 */
char *cap_string(char *str)
{
	int capitalize = 1;
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] > 0)
		{
			capitalize = (isSeparator(str[i - 1]));
		}

		if (capitalize && (str[i] >= 'a' && str[i] <= 'z'))
		{
			str[i] = str[i] - ('a' - 'A');
		}
	}

	return (str);
}
