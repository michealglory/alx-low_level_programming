#include "main.h"

/**
 * flip_bits - Counts the number of bits needed to flip to transform one
 * number to another.
 *
 * @n: The first unsigned long integer.
 * @m: The second unsigned long integer.
 *
 * Return: The number of bits needed to flip to transform @n into @m.
 *
 * Description:
 * This function counts the number of bits that need to be flipped in order
 * to transform the first unsigned long integer @n into the second unsigned
 * long integer @m. It performs an XOR (^) operation between @n and @m to get
 * the bits that are different (exclusive bits). The function then iterates
 * through each bit of the exclusive bits to count the number of 1s, which
 * indicates the number of bits that need to be flipped.
 *
 * Example Usage:
 *  - flip_bits(10, 5) returns 3 (binary 10 -> 101, 3 bits flipped to
 * transform 10 to 5)
 *  - flip_bits(15, 15) returns 0 (no bits need to be flipped, as the numbers
 * are the same)
 *  - flip_bits(0, 4294967295) returns 32 (binary
 * 0 -> 11111111111111111111111111111111,
 * all 32 bits need to be flipped to transform 0 to 4294967295)
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int index, count = 0;
	unsigned long int exclusive = n ^ m;
	unsigned long int current;

	/* Iterate through each bit in the exclusive bits. */
	for (index = 63; index >= 0; index--)
	{
		current = exclusive >> index;
		if (current & 1)
		{
			count++; /* Increment the count if the current bit is 1. */
		}
	}

	return (count);
}


