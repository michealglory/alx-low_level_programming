#include "main.h"

/**
 * print_alphabet_x10 - prints a to z 10 times in lowercase using only _putchar
 *
 * Return: void
 */
void print_alphabet_x10(void)
{
	char i;
	int k;

	for (k = 0; k < 10; k++)
	{
		for (i = 'a'; i <= 'z'; i++)
		{
			_putchar(i);
		}
		_putchar('\n');
	}
}

