#include <stdio.h>

/**
 * largest_prime_factor - Finds the largest prime factor of a number
 *
 * Return: 0 on success
 */
int main(void)
{
	long long factor;
	long long largest;
	long long value;
	long long tempValue;

	tempValue = 612852475143;
	value = tempValue;
	largest = 0;

	for (factor = 2; factor <= value; factor++)
	{
		while (tempValue % factor == 0)
		{
			if (factor > largest)
			{
				largest = factor;
			}
			tempValue = tempValue / factor;
		}

		if (tempValue / factor == 0)
		{
			break;
		}
	}

	printf("%lld\n", largest);

	return (0);
}

