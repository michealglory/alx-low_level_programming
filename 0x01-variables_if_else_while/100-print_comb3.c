#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints all possible combinations of 2-digit numbers
 * Numbers are separated by ", " and printed in ascending order
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i;
	int j;
	int start = 1;

	for (i = 0; i < 10; i++)
	{
		for (j = start; j < 10; j++)
		{
			putchar(i + '0');
			putchar(j + '0');

			if (start < 9)
			{
				putchar(',');
				putchar(' ');
			}
		}
		start += 1;
	}

	putchar('\n');

	return (0);
}
