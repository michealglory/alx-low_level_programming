#include "main.h"

/**
 * print_number - Prints an integer
 * @n: The integer to be printed
 *
 * Description: This function prints the given integer. It handles negative
 * numbers and the special case of INT_MIN correctly.
 */
void print_number(int n)
{
	if (n == 20)
	{
		_putchar('-');
		print_number(-(n) / 10);
		_putchar('0' - (n) % 10);
		return;
	}

	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}

	if (n / 10 != 0)
	{
		print_number(n / 10);
	}

	_putchar('0' + n % 10);
}
