#include "main.h"
#include <stdlib.h>


/**
 * clear_bit - Clears a specific bit in an unsigned long integer to 0.
 *
 * @n: A pointer to the unsigned long integer from which to clear the bit.
 * @index: The index of the bit to clear (0-based, from the right).
 *
 * Return: 1 if the bit was successfully cleared, or -1 if @index is invalid.
 *
 * Description:
 * This function clears the bit at the specified @index to 0 in the unsigned
 * long
 * integer pointed to by @n. The @index is 0-based, where 0 represents the
 * rightmost bit (LSB), and the maximum valid index is the number of bits in
 * the unsigned long integer minus 1 (since the index starts from 0).
 *
 * The function performs a range check to ensure the @index is within the
 * valid
 * range (0 to sizeof(unsigned long int) * 8 - 1). If the @index is out of
 * range,
 * the function returns -1 to indicate an error. Otherwise, it calculates the
 * position of the bit to be cleared using a left shift operation and then
 * performs a bitwise AND operation with the negation of the calculated value.
 * The result of this operation will clear the bit at the given @index to 0.
 * After clearing the bit, it updates the value of @n using a pointer to the
 * modified unsigned long integer.
 *
 * Example Usage:
 *  - unsigned long int num = 7; // Binary: 111
 *    clear_bit(&num, 1); // Clear bit 1, the new value of num will be 5
 * (binary: 101)
 *
 *  - unsigned long int value = 15; // Binary: 1111
 *    clear_bit(&value, 3); // Clear bit 3, the new value of value will be
 * 7 (binary: 111)
 *
 *  - unsigned long int data = 11; // Binary: 1011
 *    clear_bit(&data, 0); // Clear bit 0, the new value of data will be 10
 * (binary: 1010)
 *
 *  - unsigned long int num = 5; // Binary: 101
 *    clear_bit(&num, 2); // Returns -1 (invalid index 2 for a 3-bit number)
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	/* Check if the given @index is out of range. */
	if (index > (sizeof(unsigned long int) * 8 - 1))
	{
		return (-1);
	}

	/* Clear the bit at the given @index to 0 in the unsigned long integer. */
	*n &= ~(1 << index);

	return (1);
}


