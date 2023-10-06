#include "hash_tables.h"

/**
 * hash_table_set - Add or update a key-value pair in a hash table
 * @ht: The hash table in which to add or update the key-value pair
 * @key: The key to add or update
 * @value: The value associated with the key
 *
 * Return: 1 if successful, 0 if an error occurs
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *node_new;
	char *value_temp;
	unsigned long int index, count;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	value_temp = strdup(value);
	if (value_temp == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	for (count = index; ht->array[count]; count++)
	{
		if (strcmp(ht->array[count]->key, key) == 0)
		{
			free(ht->array[count]->value);
			ht->array[count]->value = value_temp;
			return (1);
		}
	}

	node_new = malloc(sizeof(hash_node_t));
	if (node_new == NULL)
	{
		free(value_temp);
		return (0);
	}
	node_new->key = strdup(key);
	if (node_new->key == NULL)
	{
		free(node_new);
		return (0);
	}
	node_new->value = value_temp;
	node_new->next = ht->array[index];
	ht->array[index] = node_new;

	return (1);
}
