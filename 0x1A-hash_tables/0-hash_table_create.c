#include "hash_tables.h"

/**
 * hash_table_create - Create a new hash table
 * @size: The size of the hash table
 *
 * Return: A pointer to the newly created hash table, or NULL if it fails
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hash_table_nw;
	unsigned long int count;

	/* allocate space for the hash table */
	hash_table_nw = malloc(sizeof(hash_table_t));

	if (hash_table_nw == NULL)
		return (NULL);

	hash_table_nw->size = size;
	hash_table_nw->array = malloc(sizeof(hash_node_t *) * size);

	if (hash_table_nw->array == NULL)
		return (NULL);

	for (count = 0; count < size; count++)
	{
		hash_table_nw->array[count] = NULL;
	}

	return (hash_table_nw);
}
