#include "main.h"

/**
 * print_triangle - Prints a triangle followed by a new line
 * @size: The size of the triangle
 */
void print_triangle(int size)
{
	int row, space;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}

	for (row = 1; row <= size; row++)
	{
		for (space = 1; space <= size; space++)
		{
			if (space <= size - row)
			{
				_putchar(' ');
			}
			else
			{
				_putchar('#');
			}
		}

		_putchar('\n');
	}
}

