#include "lists.h"

/**
 * free_listp2 - Frees all the nodes of a linked list of listp_t and sets
 * the head pointer to NULL.
 *
 * This function takes a pointer to a pointer to the head of a linked list
 * of listp_t
 * and frees all the memory allocated for each node in the list, effectively
 * deallocating
 * the entire linked list and releasing the memory back to the system. Finally,
 * it sets
 * the head pointer in the calling function to NULL to indicate an empty list.
 *
 * @head: A pointer to a pointer to the head of the linked list of listp_t to
 * be freed.
 */
void free_listp2(listp_t **head)
{
	/* Create temporary node pointers to traverse and hold the current node */
	listp_t *temp_node;
	listp_t *cursor;

	/* Check if the input head pointer is not NULL */
	if (head != NULL)
	{
		/* Set cursor to point to the head of the list */
		cursor = *head;

		/* Traverse the list and free each node */
		while ((temp_node = cursor) != NULL)
		{
			/* Move to the next node before freeing the current node */
			cursor = cursor->next;

			/* Free the memory allocated for the current node */
			free(temp_node);
		}

		/* Set the head pointer in the calling function to NULL */
		*head = NULL;
	}
}


/**
 * free_listint_safe - Frees a singly linked list of integers safely.
 *
 * This function frees a singly linked list of integers while handling the case
 * of a loop (infinite loop) in the list. It uses a helper structure (listp_t)
 * to store the addresses of visited nodes in the list.
 *
 * @h: A pointer to the pointer to the head of the singly linked list.
 *     It allows modifying the head pointer in the calling function.
 *
 * Return: The number of nodes in the linked list. If the list contains a loop,
 *         the function stops freeing the list, sets the head pointer to NULL,
 *         and then returns the number of nodes before the loop.
 *
 * Note: The function uses a helper structure (listp_t) to store the addresses
 *       of visited nodes in the list. If memory allocation fails for the
 * helper
 *       structure, the function exits with an error code 98.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t nodes = 0;
	listp_t *node_addres, *new_node, *add;
	listint_t *cursor;

	node_addres = NULL;
	while (*h != NULL)
	{
		new_node = malloc(sizeof(listp_t));

		if (new_node == NULL)
			exit(98);

		new_node->p = (void *)*h;
		new_node->next = node_addres;
		node_addres = new_node;

		add = node_addres;

		while (add->next != NULL)
		{
			add = add->next;
			if (*h == add->p)
			{
				*h = NULL;
				free_listp2(&node_addres);
				return (nodes);
			}
		}

		cursor = *h;
		*h = (*h)->next;
		free(cursor);
		nodes++;
	}

	*h = NULL;
	free_listp2(&node_addres);
	return (nodes);
}

