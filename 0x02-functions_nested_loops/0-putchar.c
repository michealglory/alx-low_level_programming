#include <stdio.h>

/**
 * _putchar - Writes a character to the standard output
 * @c: The character to be written
 *
 * Return: void
 */
void _putchar(char c)
{
	putchar(c);
}

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (success)
 */
int main(void)
{
	char str[] = "_putchar\n";
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}

	return 0;
}
