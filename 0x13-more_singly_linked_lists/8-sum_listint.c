#include <stdio.h>
#include "lists.h"
/**
 * sum_listint - Calculates the sum of all elements in a singly linked list.
 *
 * This function takes the head of a singly linked list of integers and
 * calculates the sum of all elements in the list.
 *
 * @head: A pointer to the head of the singly linked list.
 *
 * Return: The sum of all elements in the linked list. If the list is empty
 *         (head is NULL), it returns 0.
 */
int sum_listint(listint_t *head)
{
	/* Variable to store the total sum of elements in the list */
	int total = 0;

	/* Traverse the list and add the value of each node to the total */
	while (head != NULL)
	{
		total += head->n;
		head = head->next;
	}

	/* Return the total sum of elements in the linked list */
	return (total);
}
