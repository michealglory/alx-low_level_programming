#include <stdio.h>

#define DIGITS 1000

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
	int count, digit;
	unsigned int fib1[DIGITS] = {0}, fib2[DIGITS] = {0}, fib3[DIGITS] = {0};

	fib1[DIGITS - 1] = 1;
	fib2[DIGITS - 1] = 2;

	printf("%d", fib2[DIGITS - 1]);

	for (count = 3; count <= 98; count++)
	{
		for (digit = DIGITS - 1; digit >= 0; digit--)
		{
			fib3[digit] += fib1[digit] + fib2[digit];

			if (fib3[digit] > 9)
			{
				fib3[digit - 1] += fib3[digit] / 10;
				fib3[digit] %= 10;
			}
		}

		printf(", ");

		/* Print leading zeros if necessary */
		for (digit = 0; digit < DIGITS; digit++)
		{
			if (fib3[digit] != 0)
				break;
		}

		for (; digit < DIGITS; digit++)
			printf("%d", fib3[digit]);

		/* Shift the digits for the next iteration */
		for (digit = 0; digit < DIGITS; digit++)
		{
			fib1[digit] = fib2[digit];
			fib2[digit] = fib3[digit];
			fib3[digit] = 0;
		}
	}

	printf("\n");

	return 0;
}

