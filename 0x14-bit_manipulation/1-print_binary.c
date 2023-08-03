#include "main.h"

/**
 * _pow - Computes the power of an integer.
 *
 * @base: The base value to be raised to the power.
 * @power: The exponent value.
 *
 * Return: The result of @base raised to the power of @power.
 *
 * Description:
 * This function calculates the result of @base raised to the power of @power.
 * It returns the computed value as an unsigned long integer.
 *
 * Example Usage:
 *  - _pow(2, 3) returns 8 (2^3 = 8)
 *  - _pow(3, 4) returns 81 (3^4 = 81)
 *  - _pow(5, 0) returns 1 (Any number raised to the power of 0 is 1)
 *  - _pow(10, 1) returns 10 (Any number raised to the power of 1 is the
 * number itself)
 *  - _pow(0, 5) returns 0 (0 raised to any power is 0, except when the power
 * is 0)
 */
unsigned long int _pow(unsigned int base, unsigned int power)
{
	unsigned long int num;
	unsigned int i;

	num = 1;

	/* Calculate the result of @base raised to the power of @power. */
	for (i = 1; i <= power; i++)
		num *= base;

	return (num);
}


/**
 * print_binary - Prints the binary representation of an unsigned long integer.
 * @n: The unsigned long integer to be converted and printed.
 *
 * Return: void (no explicit return value).
 *
 * Description:
 * This function takes an unsigned long integer `n` as input and prints its
 * binary representation to the standard output (stdout). It does not return
 * any value directly; instead, it prints the binary representation character
 * by character using the `_putchar` function.
 */
void print_binary(unsigned long int n)
{
	char status;
	unsigned long int divisor, is_bit_1;

	status = 0;
	divisor = _pow(2, sizeof(unsigned long int) * 8 - 1);

	/* Iterate through the bits of the unsigned long integer `n`. */
	while (divisor != 0)
	{
		/* Use bitwise AND to check if the current bit is 1. */
		is_bit_1 = n & divisor;
		if (is_bit_1 == divisor)
		{
			/* Set the status to indicate that the first '1' has been found. */
			status = 1;
			/* Print '1' if the current bit is 1. */
			_putchar('1');
		}
		else if (status == 1 || divisor == 1)
		{
			/* Print '0' if the current bit is 0, or if all 1s have been processed. */
			_putchar('0');
		}
		/* Right shift the divisor to process the next bit. */
		divisor >>= 1;
	}
}

