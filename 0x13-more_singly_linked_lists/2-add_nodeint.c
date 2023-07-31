#include "lists.h"

/**
 * add_nodeint - Adds a new node at the beginning of a singly linked list.
 *
 * This function creates a new node and adds it at the beginning of the singly
 * linked list. The new node contains the given integer value and becomes the
 * new head of the list.
 *
 * @head: A pointer to the pointer to the head of the singly linked list.
 *        It allows modifying the head pointer in the calling function.
 * @n: The integer value to be stored in the new node.
 *
 * Return: A pointer to the newly created node. If memory allocation fails, it
 *         returns NULL.
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *node_new;

	node_new = malloc(sizeof(listint_t));

	if (node_new != NULL)
	{
		node_new->n = n;
		node_new->next = *head;
	}
	else
	{
		return (NULL);
	}
	if (*head != NULL)
	{
		node_new->next = *head;
	}

	*head = node_new;
	return (node_new);
}

