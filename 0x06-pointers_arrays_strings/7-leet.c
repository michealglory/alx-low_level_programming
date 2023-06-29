#include "main.h"

/**
 * leet - Encodes a string into 1337.
 * @str: The input string to be encoded.
 *
 * Return: A pointer to the encoded string.
 */
char *leet(char *str)
{
	int i, j;
	char leetChars[] = "4433007711";
	char originalChars[] = "aAeEoOtTlL";

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; originalChars[j] != '\0'; j++)
		{
			if (str[i] == originalChars[j])
			{
				str[i] = leetChars[j];
				break;
			}
		}
	}

	return (str);
}

