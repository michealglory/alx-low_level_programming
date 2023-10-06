#include "hash_tables.h"

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);

/**
 * shash_table_create - Creates a sorted hash table
 * @size: The size of the sorted hash table
 *
 * This function creates a new sorted hash table with the specified size.
 *
 * Return: A pointer to the created sorted hash table, or NULL on failure.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int count;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
		return (NULL);
	for (count = 0; count < size; count++)
		ht->array[count] = NULL;
	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * shash_table_set - Adds or updates a key-value pair in a sorted hash table
 * @ht: A pointer to the sorted hash table
 * @key: The key to add or update
 * @value: The value associated with the key
 *
 * This function adds or updates a key-value pair in a sorted hash table.
 * If the key already exists, the value is updated. If the provided hash
 * table is NULL, or if key or value are NULL or empty, the function
 * returns 0.
 *
 * Return: 1 if successful, 0 on failure.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *node_new, *tmp_node;
	char *value_copy;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	value_copy = strdup(value);
	if (value_copy == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	tmp_node = ht->shead;
	while (tmp_node)
	{
		if (strcmp(tmp_node->key, key) == 0)
		{
			free(tmp_node->value);
			tmp_node->value = value_copy;
			return (1);
		}
		tmp_node = tmp_node->snext;
	}

	node_new = malloc(sizeof(shash_node_t));
	if (node_new == NULL)
	{
		free(value_copy);
		return (0);
	}
	node_new->key = strdup(key);
	if (node_new->key == NULL)
	{
		free(value_copy);
		free(node_new);
		return (0);
	}
	node_new->value = value_copy;
	node_new->next = ht->array[index];
	ht->array[index] = node_new;

	if (ht->shead == NULL)
	{
		node_new->sprev = NULL;
		node_new->snext = NULL;
		ht->shead = node_new;
		ht->stail = node_new;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		node_new->sprev = NULL;
		node_new->snext = ht->shead;
		ht->shead->sprev = node_new;
		ht->shead = node_new;
	}
	else
	{
		tmp_node = ht->shead;
		while (tmp_node->snext != NULL &&
		strcmp(tmp_node->snext->key, key) < 0)
			tmp_node = tmp_node->snext;
		node_new->sprev = tmp_node;
		node_new->snext = tmp_node->snext;
		if (tmp_node->snext == NULL)
			ht->stail = node_new;
		else
			tmp_node->snext->sprev = node_new;
		tmp_node->snext = node_new;
	}

	return (1);
}

/**
 * shash_table_get - Retrieves the value associated with a key in a sorted
 * hash table
 * @ht: A pointer to the sorted hash table
 * @key: The key for which to retrieve the value
 *
 * This function retrieves the value associated with a specific key in a
 * sorted hash table.
 * If the key is not found or if the provided hash table is NULL or if key
 * is NULL or empty, the function returns NULL.
 *
 * Return: The value associated with the key, or NULL if the key is not found.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *node_temp;
	unsigned long int arr_index;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	arr_index = key_index((const unsigned char *)key, ht->size);
	if (arr_index >= ht->size)
		return (NULL);

	node_temp = ht->shead;
	while (node_temp != NULL && strcmp(node_temp->key, key) != 0)
		node_temp = node_temp->snext;

	return ((node_temp == NULL) ? NULL : node_temp->value);
}

/**
 * shash_table_print - Prints the content of a sorted hash table
 * @ht: A pointer to the sorted hash table
 *
 * This function prints the key-value pairs stored in the sorted hash table
 * in a format resembling a Python dictionary. If the provided sorted hash
 * table is NULL, it does nothing.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node_temp;

	if (ht == NULL)
		return;

	node_temp = ht->shead;
	printf("{");
	while (node_temp != NULL)
	{
		printf("'%s': '%s'", node_temp->key, node_temp->value);
		node_temp = node_temp->snext;
		if (node_temp != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints the content of a sorted hash table in
 * reverse
 * @ht: A pointer to the sorted hash table
 *
 * This function prints the key-value pairs stored in the sorted hash table
 * in a format resembling a Python dictionary, but in reverse order.
 * If the provided sorted hash table is NULL, it does nothing.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node_tmp;

	if (ht == NULL)
		return;

	node_tmp = ht->stail;
	printf("{");
	while (node_tmp != NULL)
	{
		printf("'%s': '%s'", node_tmp->key, node_tmp->value);
		node_tmp = node_tmp->sprev;
		if (node_tmp != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table and its elements
 * @ht: A pointer to the sorted hash table to be deleted
 *
 * This function deletes a sorted hash table along with its elements.
 * It frees the memory occupied by the sorted hash table, its key-value
 * pairs, and nodes, including their keys and values. If the provided
 * sorted hash table is NULL, it does nothing.
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_table_t *head = ht;
	shash_node_t *node_tmp, *tmp;

	if (ht == NULL)
		return;

	node_tmp = ht->shead;
	while (node_tmp)
	{
		tmp = node_tmp->snext;
		free(node_tmp->key);
		free(node_tmp->value);
		free(node_tmp);
		node_tmp = tmp;
	}

	free(head->array);
	free(head);
}
