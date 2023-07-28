#include "main.h"

/**
 * print_list - Prints all elements of a linked list
 * of type list_t.
 *
 * This function prints all the elements of a linked
 * list of type list_t,
 * starting from the head node 'h'. It also prints the
 * count of each node.
 * If the 'str' member of a node is NULL, it will print
 * "[0] (nil)" for that node.
 *
 * @h: A pointer to the head node of the list.
 *
 * Return: The number of nodes in the linked list.
 */

size_t print_list(const list_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		if (h->str == NULL)
			printf("[%d] %s\n", 0, "(nil)");
		else
			printf("[%d] %s\n", h->len, h->str);
		h = h->next;
		count++;
	}
	return (count);
}
