#include "main.h"

/**
 * get_endianness - Determines the endianness of the system.
 *
 * Return: 0 if the system is big-endian, 1 if the system is little-endian.
 *
 * Description:
 * This function determines the endianness of the system it is running on.
 * Endianness refers to the byte order used to store multi-byte data types
 * such as integers in memory.
 *
 * The function creates a 4-byte integer variable `value` with the value 1 and
 * then uses a pointer `address` to access its individual bytes. The function
 * then
 * returns the value of the byte pointed to by `address`, which represents the
 * least significant byte of the integer `value`. If the returned value is 1,
 * the system is little-endian, meaning the least significant byte is stored
 * at the lowest memory address. If the returned value is 0, the system is
 * big-endian, meaning the most significant byte is stored at the lowest
 * memory address.
 *
 * Example Usage:
 *  - int endianness = get_endianness();
 *    if (endianness == 0)
 *        printf("The system is big-endian.\n");
 *    else
 *        printf("The system is little-endian.\n");
 */
int get_endianness(void)
{
	int value;
	char *address;

	value = 1;
	address = (char *)&value;

	/* Return value of the least significant byte of the integer `value`. */
	return (*address);
}


