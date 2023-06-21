#include "main.h"

/**
 * largest_number - returns the largest of 3 numbers
 * @a: first integer
 * @b: second integer
 * @c: third integer
 * Return: largest number
 */
long long largest_number(long long a, long long b, long long c)
{
	long long numbers[3] = {a, b, c};
	long long largest = numbers[0];

	for (int i = 1; i < 3; i++)
	{
		if (numbers[i] > largest)
		{
			largest = numbers[i];
		}
	}

	return (largest);
}
