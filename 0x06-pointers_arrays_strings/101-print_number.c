#include "main.h"
#include <limits.h>

/**
 * print_number - Prints an integer.
 * @n: The integer to be printed.
 */
void print_number(int n)
{
	if (n == 0)
		_putchar('0');
	else if (n == INT_MIN)
	{
		_putchar('-');
		print_positive_number((unsigned int)INT_MAX + 1);
	}
	else if (n < 0)
	{
		_putchar('-');
		print_positive_number(-n);
	}
	else
		print_positive_number(n);
}

/**
 * print_positive_number - Prints a positive integer.
 * @n: The positive integer to be printed.
 */
void print_positive_number(unsigned int n)
{
	if (n / 10 != 0)
		print_positive_number(n / 10);

	_putchar('0' + (n % 10));
}

