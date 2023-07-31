#include "lists.h"

/**
 * get_nodeint_at_index - Retrieves the node at a given index of a singly
 * linked list.
 *
 * This function traverses a singly linked list and retrieves the node located
 * at the specified index. The indexing starts from 0, where index 0
 * corresponds
 * to the head node, index 1 corresponds to the second node, and so on.
 *
 * @head: A pointer to the head of the singly linked list.
 * @index: The index of the node to be retrieved.
 *
 * Return: A pointer to the node at the specified index. If the given index is
 *         out of range or the list is empty (head is NULL), it returns NULL.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	/* Variable to keep track of the number of nodes traversed */
	size_t count;

	/* Traverse the list to the specified index or until the end of the list */
	for (count = 0; (count < index) && (head != NULL); count++)
	{
		head = head->next;
	}

	/* Check if the specified index is out of range */
	if (count < index)
	{
		return (NULL); /* Index out of range, return NULL */
	}

	/* Return a pointer to the node at the specified index */
	return (head);
}


