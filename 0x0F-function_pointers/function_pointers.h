#ifndef POINTER_TO_FUNCTION_H
#define POINTER_TO_FUNCTION_H

#include <stdlib.h>
#include <stddef.h>

void print_name(char *name, void (*f)(char *));
void array_iterator(int *array, size_t size, void (*action)(int));
int int_index(int *array, int size, int (*cmp)(int));

#endif /* POINTER_TO_FUNCTION_H */

