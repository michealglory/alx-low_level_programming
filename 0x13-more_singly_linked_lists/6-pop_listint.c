#include "lists.h"

/**
 * pop_listint - Removes the head node of a singly linked list and returns
 * its value.
 *
 * This function removes the head node of a singly linked list and returns its
 * integer value. It updates the head pointer to point to the new head node
 * (the second node in the list) after removing the old head node.
 *
 * @head: A pointer to a pointer to the head of the singly linked list.
 *
 * Return: The integer value of the removed head node. If the list is empty
 *         (head is NULL), it returns 0.
 */
int pop_listint(listint_t **head)
{
	/* Create a temporary node pointer to hold the current head */
	listint_t *temp_node;

	/* Variable to store the value of the removed head node */
	int n;

	/* Store the current head node in the temporary pointer */
	temp_node = *head;

	/* Check if the list is empty (head is NULL) */
	if (temp_node == NULL)
	{
		return (0); /* Nothing to remove, return 0 */
	}

	/* Update the head pointer to point to the new head node */
	*head = temp_node->next;

	/* Store the value of the removed head node */
	n = temp_node->n;

	/* Free the memory allocated for the removed head node */
	free(temp_node);

	/* Return the value of the removed head node */
	return (n);
}


