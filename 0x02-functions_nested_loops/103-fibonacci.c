#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Description: Calculates the sum of even-valued terms in the Fibonacci sequence
 *              up to a limit of 4,000,000 and prints the result.
 *
 * Return: 0 (Success)
 */
int main(void)
{
	unsigned long secondToLast = 1;
	unsigned long last = 2;
	unsigned long even_sum = 2;

	while (last < 4000000)
	{
		unsigned long newFibo = last + secondToLast;

		if (newFibo % 2 == 0)
		{
			even_sum += newFibo;
		}

		secondToLast = last;
		last = newFibo;
	}

	printf("%lu\n", even_sum);

	return (0);
}

