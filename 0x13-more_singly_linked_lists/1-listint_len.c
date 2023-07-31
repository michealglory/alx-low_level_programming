#include "lists.h"

/**
 * listint_len - Calculates the number of nodes in a singly linked list.
 *
 * This function takes a pointer to the head of a singly linked list and
 * calculates the number of nodes in the list.
 *
 * @h: A pointer to the head of the singly linked list.
 *
 * Return: The number of nodes in the linked list. If the list is empty, it
 *         returns 0.
 */
size_t listint_len(const listint_t *h)
{
	/* Pointer to traverse the linked list */
	const listint_t *node = h;

	/* Variable to keep track of the number of nodes */
	size_t i = 0;

	/* Traverse the linked list and count the nodes */
	while (node != NULL)
	{
		/* Increment the node count */
		i += 1;

		/* Move to the next node */
		node = node->next;
	}

	/* Return the total number of nodes in the linked list */
	return (i);
}


