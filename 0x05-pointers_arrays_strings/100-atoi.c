#include "main.h"

/**
 * _atoi - Converts a string to an integer
 * @s: The string to convert
 *
 * Return: The converted integer
 */
int _atoi(char *s)
{
	int sign = 1;  /* Sign of the number, initially positive */
	int result = 0;
	int i = 0;

	/* Skip leading whitespace */
	while (s[i] == ' ')
		i++;

	/* Check for optional sign character */
	while (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}

	/* Process digits until non-digit character */
	while (s[i] >= '0' && s[i] <= '9')
	{
		/* Accumulate value by multiplying result by 10 and adding digit */
		result = result * 10 + (s[i] - '0');
		i++;
	}

	/* Apply sign to the result */
	result *= sign;

	return (result);
}

