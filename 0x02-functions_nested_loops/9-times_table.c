#include "main.h"

/**
 * times_table - Prints the multiplication table from 0 to 9
 */
void times_table(void)
{
	int i, j;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
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
			else
			{
				_putchar((value / 10) + '0');
				_putchar((value % 10) + '0');
			}

			if (j != 9)
			{
				_putchar(',');
				_putchar(' ');
			}
			else
			{
				_putchar('\n');
			}
		}
	}
}

