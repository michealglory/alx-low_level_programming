#include "main.h"

/**
 * _atoi - Converts a string to an integer
 * @s: The string to convert
 *
 * Return: The converted integer
 */
int _atoi(char *s)
{
	int sign = 1;
	int result = 0;
	int i = 0;

	/* Skip any leading whitespace characters */
	while (s[i] == ' ')
	{
		i++;
	}

	/* Check for optional sign character */
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (s[i] == '+')
	{
		i++;
	}

	/* Process the digits until a non-digit character is encountered */
	while (s[i] >= '0' && s[i] <= '9')
	{
		/* Accumulate the value by multiplying by 10 and adding the digit */
		result = result * 10 + (s[i] - '0');
		i++;
	}

	/* Apply the sign to the result */
	result *= sign;

	return (result);
}
