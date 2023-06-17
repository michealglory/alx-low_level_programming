#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints digits in lowercase, followed by a new line
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i;

	for (i = 0; i <= 9; i++)
	{
		printf("%d", i);
	}
	printf("\n");
	return (0);
}

