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
	long long secondToLast = 1;
	long long last = 2;

	printf("%lld, %lld, ", secondToLast, last);
	int i = 2;

	while (i <= 50)
	{
		long long newFibo = last + secondToLast;

		printf("%lld", newFibo);
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

