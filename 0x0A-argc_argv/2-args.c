#include "main.h"

/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
	{
		while (*argv[i])
		{
			_putchar(*argv[i]);
			argv[i]++;
		}
		_putchar('\n');
	}

	return (0);
}

