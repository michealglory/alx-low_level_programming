#include "main.h"

/**
 * jack_bauer - Prints every minute of Jack Bauer's day
 */
void jack_bauer(void)
{
	int min;
	int hour;

	for (min = 0; min < 24; min++)
	{
		for (hour = 0; hour < 60; hour++)
		{
			if (min < 10)
			{
				_putchar('0');
				_putchar(min + '0');
			}
			else
			{
				_putchar((min / 10) + '0');
				_putchar((min % 10) + '0');
			}

			_putchar(':');

			if (hour < 10)
			{
				_putchar('0');
				_putchar(hour + '0');
			}
			else
			{
				_putchar((hour / 10) + '0');
				_putchar((hour % 10) + '0');
			}

			_putchar('\n');
		}
	}
}

