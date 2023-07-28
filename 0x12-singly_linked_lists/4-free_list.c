#include "lists.h"

/**
 * free_list - Frees the memory allocated for a linked list.
 *
 * This function deallocates the memory used by a linked list of type list_t,
 * including the strings stored in each node. It starts from the head node
 * 'head' and iterates through the entire list, freeing memory for each node
 * and its string.
 *
 * @head: A pointer to the head node of the linked list to be freed.
 */

void free_list(list_t *head)
{
	list_t *existing_node;

	while ((existing_node = head) != NULL)
	{
		head = head->next;
		free(existing_node->str);
		free(existing_node);
	}
}
