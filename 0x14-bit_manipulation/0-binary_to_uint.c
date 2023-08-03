#include "main.h"

/**
 * binary_to_uint - Converts a binary string to an unsigned integer.
 *
 * @b: A pointer to a string containing a binary number.
 *
 * Return: The unsigned integer representation of the binary number.
 *         If `b` is NULL or contains non-binary characters, return 0.
 *
 * Description:
 * This function takes a string `b` representing a binary number (0s and 1s)
 * and converts it to its unsigned integer representation. The binary number
 * must be null-terminated. The function iterates through the binary string
 * to check if it contains valid binary digits (0s and 1s). If any other
 * character is encountered, the function returns 0 to indicate an error.
 *
 * The conversion is performed by iterating through the binary string from
 * left to right. At each step, the function shifts the current result left
 * by 1 bit (using `num_uint <<= 1`) to make room for the next bit and then
 * adds the value of the current bit to the result if it is '1'
 * (using `num_uint += 1`).
 * The final result is the unsigned integer representation of the binary
 * number.
 *
 * Example Usage:
 *  - binary_to_uint("1101") returns 13 (1*2^3 + 1*2^2 + 0*2^1 + 1*2^0 = 13)
 *  - binary_to_uint("10101") returns 21 (1*2^4 + 0*2^3 + 1*2^2 + 0*2^1 +
 * 1*2^0 = 21)
 *  - binary_to_uint("0") returns 0 (single digit 0 represents the number 0)
 *  - binary_to_uint(NULL) returns 0 (NULL input is considered invalid)
 *  - binary_to_uint("10201") returns 0 (non-binary character '2' is invalid)
 */
unsigned int binary_to_uint(const char *b)
{
	int index;
	unsigned int num_uint;

	num_uint = 0;
	if (!b)
	{
		return (0);
	}
	for (index = 0; b[index] != '\0'; index++)
	{
		if (b[index] != '0' && b[index] != '1')
		{
			return (0);
		}
	}
	for (index = 0; b[index] != '\0'; index++)
	{
		num_uint <<= 1;
		if (b[index] == '1')
		{
			num_uint += 1;
		}
	}
	return (num_uint);
}

