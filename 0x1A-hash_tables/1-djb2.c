#include "hash_tables.h"

/**
 * hash_djb2 - Hash a string using the djb2 algorithm
 * @str: The string to be hashed
 *
 * Return: The computed hash value
 */

unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int count;

	hash = 5381;
	while ((count = *str++))
		hash = ((hash << 5) + hash) + count; /* hash * 33 + count */

	return (hash);
}
