#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table and its elements
 * @ht: A pointer to the hash table to be deleted
 *
 * This function deletes a hash table along with its elements. It frees the
 * memory occupied by the hash table, its key-value pairs, and nodes, including
 * their keys and values. If the provided hash table is NULL, it does nothing.
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_table_t *head = ht;
	hash_node_t *node, *tmp;
	unsigned long int count;

	for (count = 0; count < ht->size; count++)
	{
		if (ht->array[count] != NULL)
		{
			node = ht->array[count];
			while (node != NULL)
			{
				tmp = node->next;
				free(node->key);
				free(node->value);
				free(node);
				node = tmp;
			}
		}
	}
	free(head->array);
	free(head);
}
