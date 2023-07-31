#include "lists.h"

/**
 * reverse_listint - Reverses a singly linked list in place.
 *
 * This function reverses a singly linked list in place by changing the next
 * pointers of each node. The head pointer is updated to point to the new head
 * of the reversed list.
 *
 * @head: A pointer to the pointer to the head of the singly linked list.
 *        It allows modifying the head pointer in the calling function.
 *
 * Return: A pointer to the new head of the reversed list. If the input list
 *         is empty (head is NULL), it returns NULL.
 */
listint_t *reverse_listint(listint_t **head)
{
	/* Create two temporary node pointers to traverse the list*/
	listint_t *current_node;
	listint_t *next_node;

	/* Initialize the temporary pointers to NULL */
	current_node = NULL;
	next_node = NULL;

	/* Traverse the list and reverse the next pointers of each node */
	while (*head != NULL)
	{
		/* Save the next node's address in the next_node */
		next_node = (*head)->next;

		/* Reverse the next pointer of the current node */
		(*head)->next = current_node;

		/* Move current_node to the current node */
		current_node = *head;

		/* Move to the next node in the original list */
		*head = next_node;
	}

	/* Update the head pointer to point to the new head of the reversed list */
	*head = current_node;

	/* Return the new head of the reversed list */
	return (*head);
}


