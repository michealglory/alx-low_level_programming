#include "lists.h"

/**
 * free_listint2 - Frees all the nodes of a singly linked list and sets the
 *                 head pointer to NULL.
 *
 * This function takes a pointer to a pointer to the head of a singly linked
 * list. It frees all the memory allocated for each node in the list,
 * effectively deallocating the entire linked list and releasing the memory
 * back to the system. Finally, it sets the head pointer to NULL in the
 * calling function to indicate an empty list.
 *
 * @head: A pointer to a pointer to the head of the singly linked list to be
 *        freed.
 */
void free_listint2(listint_t **head)
{
	/* Create a temporary node pointer to traverse the list */
	listint_t *temp_node;

	/* Check if the input head pointer is NULL */
	if (head == NULL)
	{
		return; /* Nothing to free, return early */
	}

	/* Traverse the list and free each node */
	while (*head != NULL)
	{
		/* Save the current node's address in the temporary pointer */
		temp_node = *head;

		/* Move to the next node */
		*head = (*head)->next;

		/* Free the current node */
		free(temp_node);
	}

	/* Set the head pointer in the calling function to NULL */
	*head = NULL;
}

