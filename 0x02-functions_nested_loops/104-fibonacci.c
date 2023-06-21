#include <stdio.h>

#define DIGITS 1000

void print_number(const int *number);
void add_numbers(const int *num1, const int *num2, int *result);

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
	int fib1[DIGITS] = {0}, fib2[DIGITS] = {0}, fib3[DIGITS] = {0};

	fib1[DIGITS - 1] = 1;
	fib2[DIGITS - 1] = 2;

	printf("%d, ", 1);
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
		print_number(fib3);

		for (digit = 0; digit < DIGITS; digit++)
		{
			fib1[digit] = fib2[digit];
			fib2[digit] = fib3[digit];
			fib3[digit] = 0;
		}
	}

	printf("\n");

	return (0);
}

/**
 * print_number - Prints a number represented by an array of digits
 * @number: The array representing the number
 */
void print_number(const int *number)
{
	int digit;

	/* Find the first non-zero digit */
	for (digit = 0; digit < DIGITS; digit++)
	{
		if (number[digit] != 0)
			break;
	}

	/* Print the remaining digits */
	for (; digit < DIGITS; digit++)
		printf("%d", number[digit]);
}

/**
 * add_numbers - Adds two numbers represented by arrays of digits
 * @num1: The first number to add
 * @num2: The second number to add
 * @result: The resulting sum
 */
void add_numbers(const int *num1, const int *num2, int *result)
{
	int carry = 0;
	int digit;

	for (digit = DIGITS - 1; digit >= 0; digit--)
	{
		result[digit] = num1[digit] + num2[digit] + carry;

		if (result[digit] > 9)
		{
			carry = result[digit] / 10;
			result[digit] %= 10;
		}
		else
		{
			carry = 0;
		}
	}
}

