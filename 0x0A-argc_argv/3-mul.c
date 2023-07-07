#include "main.h"

/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	int num1, num2, result;

	if (argc != 3)
	{
		_putchar("Error\n");
		return (1);
	}

	num1 = _atoi(argv[1]);
	num2 = _atoi(argv[2]);

	result = num1 * num2;

	_putchar(result + '0');
	_putchar('\n');

	return (0);
}

/**
 * _atoi - Convert a string to an integer
 * @str: The string to convert
 *
 * Return: The converted integer
 */
int _atoi(char *str)
{
	int sign = 1;
	int result = 0;
	int i = 0;

	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}

	for (; str[i] != '\0'; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			result = result * 10 + (str[i] - '0');
		}
		else
		{
			break;
		}
	}

	return (sign * result);
}

