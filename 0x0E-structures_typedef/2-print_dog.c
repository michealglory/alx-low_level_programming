#include <stdio.h>
#include "dog.h"

/**
 * print_dog - Prints the information of a struct dog.
 * @d: Pointer to the struct dog.
 *
 * Description: Prints the name, age, and owner of the struct dog.
 * If an element of d is NULL, it prints (nil) instead of the element.
 * If d is NULL, it does not print anything.
 */
void print_dog(struct dog *d)
{
	if (d == NULL)
		return;

	printf("Name: %s\n", (d->name != NULL) ? d->name : "(nil)");
	printf("Age: %.1f\n", d->age);
	printf("Owner: %s\n", (d->owner != NULL) ? d->owner : "(nil)");
}

