#ifndef _MAIN_H
#define _MAIN_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/** node - A data structure representing a
 *  singly linked list node.
 *
 *  The node struct is used to create nodes
 *  for a singly linked list. Each
 *  node contains a string pointer 'str', an
 *  unsigned integer 'len' to store
 *  the length of the string (excluding the
 *  null-terminator), and a pointer
 *  'next' that points to the next node in the list.
 */
typedef struct node
{
	char *str;
	unsigned int len;
	struct node *next;
} list_t;

size_t print_list(const list_t *h);
size_t list_len(const list_t *h);
list_t *add_node(list_t **head, const char *str);
list_t *add_node_end(list_t **head, const char *str);
void free_list(list_t *head);

#endif
