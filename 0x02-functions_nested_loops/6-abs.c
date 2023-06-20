#include "main.h"
#include <limits.h>
/**
 * _abs - Computes the absolute value of an integer
 *
 * @n: The integer
 *
 * Return: The absolute value of n
 */
int _abs(int n)
{
	if (n == INT_MIN)
	{
		return (INT_MAX);
	}
	else if (n < 0)
	{
		return (-n);
	}
	else
	{
		return (n);
	}
}
