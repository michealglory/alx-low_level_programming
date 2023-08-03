#include "main.h"

/**
 * set_bit - Sets a specific bit in an unsigned long integer to 1.
 *
 * @n: A pointer to the unsigned long integer in which to set the bit.
 * @index: The index of the bit to set (0-based, from the right).
 *
 * Return: 1 if the bit was successfully set, or -1 if @index is invalid.
 *
 * Description:
 * This function sets the bit at the specified @index to 1 in the unsigned long
 * integer pointed to by @n. The @index is 0-based, where 0 represents the
 * rightmost bit (LSB), and the maximum valid index is the number of bits in
 * the unsigned long integer minus 1 (since the index starts from 0).
 *
 * The function performs a range check to ensure the @index is within the valid
 * range (0 to sizeof(unsigned long int) * 8 - 1). If the @index is out of
 * range,
 * the function returns -1 to indicate an error. Otherwise, it calculates the
 * position of the bit to be set using a left shift operation and then performs
 * a bitwise OR operation with the existing value of @n to set the bit to 1.
 * After setting the bit, it updates the value of @n using a pointer to the
 * modified unsigned long integer.
 *
 * Example Usage:
 *  - unsigned long int num = 5; // Binary: 101
 *    set_bit(&num, 1); // Set bit 1, the new value of num will be 7 (binary:
 * 111)
 *
 *  - unsigned long int value = 0; // Binary: 000
 *    set_bit(&value, 3); // Set bit 3, the new value of value will be 8
 * (binary:1000)
 *
 *  - unsigned long int data = 10; // Binary: 1010
 *    set_bit(&data, 0); // Set bit 0, the new value of data will be 11
 * (binary: 1011)
 *
 *  - unsigned long int num = 3; // Binary: 11
 *    set_bit(&num, 2); // Returns -1 (invalid index 2 for a 2-bit number)
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int value;

	/* Check if the given @index is out of range. */
	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);

	/* Calculate the value with the specific bit set to 1. */
	value = 1 << index;

	/* Set the bit at the given @index to 1 in the unsigned long integer. */
	*n = *n | value;

	return (1);
}


