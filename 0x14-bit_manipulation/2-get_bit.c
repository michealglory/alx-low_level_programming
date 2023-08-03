#include"main.h"

/**
 * get_bit - Gets the value of a specific bit in an unsigned long integer.
 *
 * @n: The unsigned long integer from which to extract the bit value.
 * @index: The index of the bit to get (0-based, from the right).
 *
 * Return: The value of the bit at the given @index (0 or 1).
 *         If @index is invalid (greater than the number of bits in @n),
 *         return -1 to indicate an error.
 *
 * Description:
 * This function extracts the value of the bit at the specified @index in the
 * unsigned long integer @n. The @index is 0-based, where 0 represents the
 * rightmost bit (LSB), and the maximum valid index is the number of bits in
 * @n minus 1 (since the index starts from 0).
 *
 * The function performs a range check to ensure the @index is within the
 * valid
 * range (0 to sizeof(unsigned long int) * 8 - 1). If the @index is out of
 * range,
 * the function returns -1 to indicate an error. Otherwise, it calculates the
 * position of the target bit using a left shift operation and then performs
 * a bitwise AND operation to extract the value of the bit at the given
 * @index.
 *
 * Example Usage:
 *  - get_bit(5, 0) returns 1 (binary 5 is 101, and the rightmost bit is 1)
 *  - get_bit(5, 1) returns 0 (binary 5 is 101, and the bit at index 1 is 0)
 *  - get_bit(0, 0) returns 0 (binary 0 has only one bit, which is 0)
 *  - get_bit(10, 5) returns -1 (invalid index 5 for a 4-bit number)
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int divisor, bit;

	/* Check if the given @index is out of range. */
	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);

	/* Calculate the divisor to extract the bit at the specified @index. */
	divisor = 1 << index;
	bit = n & divisor;

	/* Return the value of the bit at the given @index (0 or 1). */
	if (bit == divisor)
		return (1);
	return (0);
}

