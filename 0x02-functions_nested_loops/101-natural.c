#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Description: This program calculates the sum of
 * all the numbers between 3 and 1023 (inclusive) that
 * are divisible by either 3 or 5, and prints the result.
 *
 * Return: Always 0 (indicating success)
 */
int main(void)
{
	int total = 0;
	int i;

	for (i = 3; i < 1024; i++)
	{
		if (i % 3 == 0 || i % 5 == 0)
		{
			total += i;
		}
	}

	printf("%d\n", total);

	return (0);
}

