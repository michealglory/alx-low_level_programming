#include "main.h"

/**
 * print_sign - Checks for lowercase character
 *
 * @n: The character to be checked
 *
 * Return: 1 if n is greater than 0, -1 if n is lower than 0 and 0 otherwise
 */
int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);

	}
	else if (n < 0)
	{
		_putchar('-');
		return (-1);
	}
	else
	{
		_putchar(n + '0');
		return (0);
	}

}
