#include "hash_tables.h"

/**
 * hash_table_get - Retrieve the value associated with a key in a hash table
 * @ht: The hash table from which to retrieve the value
 * @key: The key for which to retrieve the value
 *
 * Return: The value associated with the key, or NULL if the key is not found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *node_new;
	unsigned long int i;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	i = key_index((const unsigned char *)key, ht->size);
	if (i >= ht->size)
		return (NULL);

	node_new = ht->array[i];
	while (node_new && strcmp(node_new->key, key) != 0)
		node_new = node_new->next;

	return ((node_new == NULL) ? NULL : node_new->value);
}
