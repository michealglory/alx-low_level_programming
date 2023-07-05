#include "main.h"

/**
 * _sqrt_recursion - Calculates the natural square root of a number.
 * @n: The number.
 *
 * Return: The natural square root of n,
 *         or -1 if n does not have a natural square root.
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	else if (n == 0 || n == 1)
		return (n);
	else
		return (sqrt_helper(n, 1));
}

/**
 * sqrt_helper - Helper function to calculate the square root.
 * @n: The number.
 * @guess: The current guess for the square root.
 *
 * Return: The natural square root of n.
 */
int sqrt_helper(int n, int guess)
{
	if (guess * guess == n)
		return (guess);
	else if (guess * guess > n)
		return (-1);
	else
		return (sqrt_helper(n, guess + 1));
}

