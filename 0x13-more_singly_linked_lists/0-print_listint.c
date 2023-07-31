#include "lists.h"

/**
 * print_listint - Prints the elements of a singly linked list of integers.
 *
 * This function takes a pointer to the head of a singly linked list and prints
 * the integer value of each node in the list. It also returns the total number
 * of nodes in the linked list.
 *
 * @h: A pointer to the head of the singly linked list.
 *
 * Return: The number of nodes in the linked list. If the list is empty, it
 *         returns 0.
 */
size_t print_listint(const listint_t *h)
{
	/* Pointer to traverse the linked list */
	const listint_t *node = h;

	/* Variable to keep track of the number of nodes */
	size_t i = 0;

	/* Traverse the linked list and print the elements */
	while (node != NULL)
	{
		printf("%d\n", node->n);

		/* Increment the node count */
		i += 1;

		/* Move to the next node */
		node = node->next;
	}

	/* Return the total number of nodes in the linked list */
	return (i);
}
