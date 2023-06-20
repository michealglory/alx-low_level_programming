#include "main.h"
/**
 * _abs - Computes the absolute value of an integer
 *
 * @n: The integer
 *
 * Return: The absolute value of n
 */
int _abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

/**
 * print_last_digit - prints last digit of a number
 *
 * @n: The number
 *
 * Return: The last digit of a number
 */
int print_last_digit(int n)
{
	int last_digit = _abs(n) % 10;

	_putchar(last_digit + '0');

	return (last_digit);
}

