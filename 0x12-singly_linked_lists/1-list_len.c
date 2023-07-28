#include "lists.h"
/**
 * list_len - Counts the number of nodes in a linked list.
 *
 * This function counts the number of nodes in a linked
 * list of type list_t,
 * starting from the head node 'h'.
 *
 * @h: A pointer to the head node of the linked list.
 *
 * Return: The number of nodes in the linked list.
 */

size_t list_len(const list_t *h)
{
	size_t num_nodes;

	num_nodes = 0;
	while (h != NULL)
	{
		h = h->next;
		num_nodes++;
	}
	return (num_nodes);
}
