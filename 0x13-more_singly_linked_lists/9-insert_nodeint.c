#include "lists.h"
/**
 * insert_nodeint_at_index - Inserts a new node at a specified index in a
 * singly linked list.
 *
 * This function inserts a new node with a given integer value at the specified
 * index in a singly linked list. If the index is 0, the new node becomes the
 * new head of the list. If the specified index is out of range, the function
 * returns NULL and does not modify the list.
 *
 * @head: A pointer to the pointer to the head of the singly linked list.
 *        It allows modifying the head pointer in the calling function.
 * @idx: The index at which the new node should be inserted.
 * @n: The integer value to be stored in the new node.
 *
 * Return: A pointer to the newly created node. If memory allocation fails or
 *         the specified index is out of range, it returns NULL.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	/* Create a new node and allocate memory for it */
	listint_t *new_node, *temp_node = *head;
	unsigned int node;

	new_node = malloc(sizeof(listint_t));

	/* Check if memory allocation was successful and initializes the new node*/
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;

	/* Insert the new node at the specified index */
	if (idx == 0)
	{
		/* If the index is 0, make the new node the new head */
		new_node->next = temp_node;
		*head = new_node;
		return (new_node);
	}

	/* Traverse the list to the node just before the specified index */
	for (node = 0; node < (idx - 1); node++)
	{
		/* If current node or next node is NULL, the index is out of range */
		if (temp_node == NULL || temp_node->next == NULL)
			return (NULL);

		/* Move to the next node */
		temp_node = temp_node->next;
	}

	/* Insert the new node at the specified index */
	new_node->next = temp_node->next;
	temp_node->next = new_node;

	/* Return the newly created node */
	return (new_node);
}
