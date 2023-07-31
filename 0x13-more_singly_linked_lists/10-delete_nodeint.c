#include "lists.h"
/**
 * delete_nodeint_at_index - Deletes a node at a specified index in a singly
 * linked list.
 *
 * This function deletes the node at the specified index in a singly linked
 * list.
 * If the index is 0, the head node is deleted. If the specified index is out
 * of range,
 * the function returns -1, indicating an error, and does not modify the list.
 *
 * @head: A pointer to the pointer to the head of the singly linked list.
 *        It allows modifying the head pointer in the calling function.
 * @index: The index of the node to be deleted.
 *
 * Return: On success, 1 is returned. If the specified index is out of range or
 *         the list is empty (head is NULL), it returns -1.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	/* Create temporary node pointers to traverse and hold the current node */
	listint_t *temp_node, *cursor = *head;
	unsigned int node;

	/* Check if the list is empty (head is NULL) */
	if (cursor == NULL)
	{
		return (-1); /* Cannot delete from an empty list, return -1 */
	}

	/* If the index is 0, delete the head node */
	if (index == 0)
	{
		*head = (*head)->next; /* Update the head pointer to the next node */
		free(cursor); /* Free the memory of the deleted node */
		return (1); /* Successful deletion, return 1 */
	}

	/* Traverse the list to the node just before the specified index */
	for (node = 0; node < (index - 1); node++)
	{
		/* If current node's next node is NULL, the index is out of range */
		if (cursor->next == NULL)
			return (-1); /* Index out of range, return -1 */

		cursor = cursor->next;/* Move to the next node */
	}
	/* Store the node to be deleted in the temporary pointer */
	temp_node = cursor->next;

	/* Update the pointers to skip the node to be deleted */
	cursor->next = temp_node->next;

	/* Free the memory of the deleted node */
	free(temp_node);

	return (1);/* Successful deletion, return 1 */
}
