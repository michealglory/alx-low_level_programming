#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 * print_dog - Prints a struct dog.
 * @d: Pointer to the struct dog.
 *
 * Description: Prints the name, age, and owner of the struct dog.
 *              If an element of d is NULL, it prints (nil)
 *		instead of the element.
 *              If d is NULL, it does not print anything.
 */
void print_dog(struct dog *d)
{
	if (d == NULL)
		return;

	if (d->name == NULL)
		d->name = "(nil)";

	if (d->owner == NULL)
		d->owner = "(nil)";

	printf("Name: %s\nAge: %f\nOwner: %s\n", d->name, d->age, d->owner);
}

