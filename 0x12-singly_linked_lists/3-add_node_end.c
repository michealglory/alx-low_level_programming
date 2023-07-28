#include "lists.h"

/**
 * add_node_end - Adds a new node at the end of a linked list.
 *
 * This function creates a new node containing a copy of the given
 * string 'str' and adds it to the end of a linked list of type list_t.
 * If memory allocation for the new node or string copy fails, the
 * function returns NULL.
 *
 * @head: A pointer to a pointer to the head node of the linked list.
 * @str: The string to be stored in the new node.
 *
 * Return: If the function is successful, it returns a pointer to the
 * head of the linked list. Otherwise, it returns NULL on failure
 * (e.g., memory allocation error).
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *node_new, *existing_node;
	size_t node_size;

	node_new = malloc(sizeof(list_t));
	if (node_new == NULL)
	{
		return (NULL);
	}
	node_new->str = strdup(str);

	for (node_size = 0; str[node_size]; node_size++)
		;

	node_new->len = node_size;
	node_new->next = NULL;
	existing_node = *head;

	if (existing_node == NULL)
	{
		*head = node_new;
	}
	else
	{
		while (existing_node->next != NULL)
			existing_node = existing_node->next;
		existing_node->next = node_new;
	}

	return (*head);
}
