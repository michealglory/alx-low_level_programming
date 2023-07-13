#include "main.h"
#include <stdlib.h>

/**
 * _realloc - Reallocates a memory block using malloc and free
 * @ptr: Pointer to the memory previously allocated with malloc
 * @old_size: Size of the allocated space for ptr
 * @new_size: New size of the memory block
 *
 * Return: Pointer to the reallocated memory block
 *         If new_size > old_size, the added memory is uninitialized
 *         If new_size == old_size, returns ptr without reallocation
 *         If ptr is NULL, equivalent to malloc(new_size)
 *         If new_size is zero and ptr is not NULL, equivalent to free(ptr)
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;
	char *temp_ptr;
	char *temp_new_ptr;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		new_ptr = malloc(new_size);
		return (new_ptr);
	}

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);

	if (new_size > old_size)
		new_size = old_size;

	temp_ptr = ptr;
	temp_new_ptr = new_ptr;

	for (i = 0; i < new_size; i++)
		temp_new_ptr[i] = temp_ptr[i];

	free(ptr);

	return (new_ptr);
}

