#include "lists.h"

/**
 * free_listint - Frees all the nodes of a singly linked list.
 *
 * This function takes the head of a singly linked list and frees all the
 * memory allocated for each node in the list, effectively deallocating the
 * entire linked list and releasing the memory back to the system.
 *
 * @head: A pointer to the head of the singly linked list to be freed.
 */
void free_listint(listint_t *head)
{
	/* Create a temporary node pointer to traverse the list */
	listint_t *temp_node;

	/* Traverse the list and free each node */
	while (head != NULL)
	{
		/* Save the current node's address in the temporary pointer */
		temp_node = head;

		/* Move to the next node */
		head = head->next;

		/* Free the current node */
		free(temp_node);
	}
}

