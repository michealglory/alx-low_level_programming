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
void free_listp(listp_t **head)
{
	listp_t *temp_node;
	listp_t *cursor;

	if (head != NULL)
	{
		cursor = *head;
		while ((temp_node = cursor) != NULL)
		{
			cursor = cursor->next;
			free(temp_node);
		}
		*head = NULL;
	}
}

/**
 * print_listint_safe - Prints a singly linked list of integers safely.
 *
 * This function prints the integer value of each node in the singly linked
 * list while handling the case of a loop (infinite loop) in the list.
 *
 * @head: A pointer to the head of the singly linked list.
 *
 * Return: The number of nodes in the linked list. If the list contains a
 * loop,
 *         the function prints the loop node and its value, and then returns
 *         the number of nodes before the loop.
 *
 * Note: The function uses a helper structure (listp_t) to store the
 * addresses
 *       of visited nodes in the list. If memory allocation fails for the
 * helper
 *       structure, the function exits with an error code 98.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nodes = 0;
	listp_t *node_address, *new_node, *add;

	node_address = NULL;
	while (head != NULL)
	{
		new_node = malloc(sizeof(listp_t));

		if (new_node == NULL)
			exit(98);

		new_node->p = (void *)head;
		new_node->next = node_address;
		node_address = new_node;

		add = node_address;

		while (add->next != NULL)
		{
			add = add->next;
			if (head == add->p)
			{
				printf("-> [%p] %d\n", (void *)head, head->n);
				free_listp(&node_address);
				return (nodes);
			}
		}

		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
		nodes++;
	}

	free_listp(&node_address);
	return (nodes);
}

