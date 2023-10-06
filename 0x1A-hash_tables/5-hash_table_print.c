#include "./hash_tables.h"

/**
 * hash_table_print - Prints the content of a hash table
 * @ht: A pointer to the hash table
 *
 * This function prints the key-value pairs stored in the hash table
 * in a format resembling a Python dictionary. If the provided hash
 * table is NULL, it does nothing.
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *node;
	unsigned long int count;
	unsigned char comma_sep = 0;

	if (ht == NULL)
		return;

	printf("{");
	for (count = 0; count < ht->size; count++)
	{
		if (ht->array[count] != NULL)
		{
			if (comma_sep == 1)
				printf(", ");

			node = ht->array[count];
			while (node != NULL)
			{
				printf("'%s': '%s'", node->key, node->value);
				node = node->next;
				if (node != NULL)
					printf(", ");
			}
			comma_sep = 1;
		}
	}
	printf("}\n");
}
