#include "lists.h"
/**
 * find_listint_loop - Finds the start node of a loop in a singly linked list.
 *
 * This function detects if a singly linked list has a loop and finds the start
 * node of the loop, if one exists. If no loop is found, it returns NULL.
 *
 * @head: A pointer to the head of the singly linked list.
 *
 * Return: If a loop is found, it returns a pointer to the start node of the
 * loop.
 *         Otherwise, it returns NULL.
 */
listint_t *find_listint_loop(listint_t *head)
{
	/* Create two pointers to traverse the list: node and next_node */
	listint_t *node, *next_node;

	/* Check if the list is empty or contains only one node (no loop) */
	if (head == NULL || head->next == NULL)
		return (NULL);

	/* Initialize pointers: node moves 1 step and next_node moves 2 steps */
	node = head->next;
	next_node = (head->next)->next;

	/* Traverse the list until the next_node becomes NULL (reached the end) */
	while (next_node)
	{
		/* If a loop is detected (node and next_node point to the same node) */
		if (node == next_node)
		{
			/* Reset node to the head and move both pointers until they meet */
			node = head;

			while (node != next_node)
			{
				node = node->next;
				next_node = next_node->next;
			}

			/* Return the start node of the loop */
			return (node);
		}

		/* Move node one step and next_node two steps ahead */
		node = node->next;
		next_node = (next_node->next)->next;
	}

	/* If the loop is not found, return NULL */
	return (NULL);
}

