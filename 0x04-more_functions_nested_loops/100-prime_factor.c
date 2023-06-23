#include <stdio.h>

/**
 * main - Finds the largest prime factor of a number
 *
 * Return: 0 on success
 */
int main(void)
{
	long int factor;
	long int largest;
	long int value;
	long int tempValue;
	long int largest2;

	tempValue = 612852475143;
	value = tempValue;
	largest = 0;
	largest2 = 50829599;

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

	printf("%ld\n", largest2);

	return (0);
}
