#include <limits.h>
#include "main.h"

/**
 * _atoi - Converts a string to an integer
 * @s: The string to convert
 *
 * Return: The converted integer
 */
int _atoi(char *s)
{
	int sign = 1; /* Sign of the number, initially positive */
	int result = 0;
	int i = 0;

	while (s[i] == ' ')
		i++;

	while (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}

	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			if (result > INT_MAX / 10 ||
			(result == INT_MAX / 10 && (s[i] - '0') > INT_MAX % 10))
			{
				return (-2147483648);
			}
			result = result * 10 + (s[i] - '0');
		}
		else if (s[i] == '-')
		{
			sign *= -1;
		}
		else if (result != 0)
		{
			break;
		}

		i++;
	}

	result *= sign;

	return (result);
}

