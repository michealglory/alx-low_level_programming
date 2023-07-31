#include "lists.h"

/**
 * add_nodeint_end - Adds a new node at the end of a singly linked list.
 *
 * This function creates a new node and adds it at the end of the singly
 * linked list. The new node contains the given integer value and becomes
 * the last node of the list.
 *
 * @head: A pointer to the pointer to the head of the singly linked list.
 *        It allows modifying the head pointer in the calling function.
 * @n: The integer value to be stored in the new node.
 *
 * Return: A pointer to the newly created node. If memory allocation fails, it
 *         returns NULL.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	/* Create a new node and allocate memory for it */
	listint_t *node_new;
	listint_t *node = *head;

	node_new = malloc(sizeof(listint_t));

	/* Check if memory allocation was successful */
	if (node_new != NULL)
	{
		/* Initialize the new node */
		node_new->n = n;
		node_new->next = NULL;
	}
	else
	{
		/* Return NULL if memory allocation fails */
		return (NULL);
	}

	/* Check if the list is not empty */
	if (node != NULL)
	{
		/* Traverse the list to find the last node */
		while (node->next != NULL)
		{
			node = node->next;
		}

		/* Add the new node at the end of the list */
		node->next = node_new;
	}
	else
	{
		/* If the list is empty, make the new node as the head */
		*head = node_new;
	}

	/* Return the newly created node */
	return (node_new);
}

