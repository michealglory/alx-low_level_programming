#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Description: Prints the first 50 numbers in the Fibonacci sequence.
 *              Each number is separated by a comma.
 *
 * Return: 0 (Success)
 */
int main(void)
{
	unsigned long secondToLast = 1;
	unsigned long last = 2;

	printf("%lu, %lu, ", secondToLast, last);
	int i = 2;

	while (i <= 50)
	{
		unsigned long newFibo = last + secondToLast;

		printf("%lu", newFibo);
		secondToLast = last;
		last = newFibo;

		if (i != 50)
		{
			printf(", ");
		}

		i += 1;
	}

	printf("\n");

	return (0);
}

