#include <stdio.h>

/**
 * main - Prints the first 98 Fibonacci numbers
 *
 * Description:
 * This program calculates and prints the first 98 Fibonacci numbers,
 * starting with 1 and 2. The Fibonacci numbers are separated by commas
 * and followed by a new line.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	unsigned long int count, prev1, prev2, upper1, upper2, lower1, lower2;

	prev1 = 1;
	prev2 = 2;

	printf("%lu", prev1);

	for (count = 1; count < 91; count++)
	{
		printf(", %lu", prev2);
		prev2 += prev1;
		prev1 = prev2 - prev1;
	}

	upper1 = prev1 / 1000000000;
	upper2 = prev1 % 1000000000;
	lower1 = prev2 / 1000000000;
	lower2 = prev2 % 1000000000;

	for (count = 92; count < 99; ++count)
	{
		printf(", %lu", upper1 + (upper2 / 1000000000));
		printf("%lu", upper2 % 1000000000);
		upper1 += lower1;
		lower1 = upper1 - lower1;
		upper2 += lower2;
		lower2 = upper2 - lower2;
	}

	printf("\n");

	return (0);
}

