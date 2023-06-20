#include "main.h"

/**
 * print_to_98 - Prints all numbers from n to 98
 * @n: Starting number
 *
 * Return: void
 */
void print_to_98(int n)
{
	int i;

	if (n <= 98)
	{
		for (i = n; i <= 98; i++)
		{
			int k = prepare_k(i);

			print_to_output(k);
			add_spacer(i);
		}
	}
	else
	{
		for (i = n; i >= 98; i--)
		{
			int k = prepare_k(i);

			print_to_output(k);
			add_spacer(i);
		}
	}
}

/**
 * print_to_output - Prints the number to output
 * @k: Number to print
 *
 * Return: void
 */
void print_to_output(int k)
{
	if (k < 10)
	{
		_putchar(k + '0');
	}
	else if (k < 100)
	{
		_putchar((k / 10) + '0');
		_putchar((k % 10) + '0');
	}
	else
	{
		int temp = k % 100;

		_putchar((k / 100) + '0');
		_putchar((temp / 10) + '0');
		_putchar((temp % 10) + '0');
	}
}

/**
 * add_spacer - Adds a spacer after the number
 * @i: Current number
 *
 * Return: void
 */
void add_spacer(int i)
{
	if (i != 98)
	{
		_putchar(',');
		_putchar(' ');
	}
}

/**
 * prepare_k - Prepares the number for printing
 * @i: Current number
 *
 * Return: The prepared number
 */
int prepare_k(int i)
{
	if (i < 0)
	{
		_putchar('-');
		return (-i);
	}
	else
	{
		return (i);
	}
}

