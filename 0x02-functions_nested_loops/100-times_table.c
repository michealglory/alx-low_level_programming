#include "main.h"

/**
 * print_times_table - Prints the multiplication table up to a given number
 * @n: The number up to which the table is printed
 *
 * Description: This function prints the multiplication table from 0 to n,
 * where n should be between 0 and 15 (inclusive).
 */
void print_times_table(int n)
{
	int i, j;

	if (n < 15 && n >= 0)
	{
		for (i = 0; i < n + 1; i++)
		{
			for (j = 0; j < n + 1; j++)
			{
				print_to_output(i, j);
				if (j != n)
				{
					_putchar(',');
					_putchar(' ');
					if (i * (j + 1) < 100)
					{
						_putchar(' ');
					}
				}
				else
				{
					_putchar('\n');
				}
			}
		}
	}
}

/**
 * print_to_output - Prints the product of two numbers
 * @i: The first number
 * @j: The second number
 *
 * Description: This function calculates the product of two
 * numbers and prints the result using the _putchar function.
 * It takes care of formatting the output.
 */
void print_to_output(int i, int j)
{
	int value = i * j;

	if (value < 10)
	{
		if (j != 0)
		{
			_putchar(' ');
		}
		_putchar(value + '0');
	}
	else if (value < 100)
	{
		_putchar((value / 10) + '0');
		_putchar((value % 10) + '0');
	}
	else
	{
		int temp = value % 100;

		_putchar((value / 100) + '0');
		_putchar((temp / 10) + '0');
		_putchar((temp % 10) + '0');
	}
}

