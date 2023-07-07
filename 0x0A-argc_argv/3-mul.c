#include "main.h"

/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array of strings representing the arguments
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	int num1, num2, result;

	if (argc != 3)
	{
		_puts("Error");
		return (1);
	}

	num1 = _atoi(argv[1]);
	num2 = _atoi(argv[2]);
	result = num1 * num2;

	if (result < 0)
	{
		_putchar('-');
		result = -result;
	}

	_puts(_itoa(result));
	_putchar('\n');

	return (0);
}

/**
 * _atoi - Converts a string to an integer
 * @str: The string to be converted
 * Return: The converted integer
 */
int _atoi(char *str)
{
	int i = 0;
	int sign = 1;
	int result = 0;

	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}

	while (str[i] != '\0')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}

	return (result * sign);
}

/**
 * _puts - Prints a string to stdout
 * @str: The string to be printed
 */
void _puts(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _itoa - Converts an integer to a string
 * @num: The integer to be converted
 * Return: The converted string
 */
char *_itoa(int num)
{
	static char buffer[12];
	int i = 10;

	buffer[11] = '\0';

	if (num == 0)
	{
		buffer[i] = '0';
		return (&buffer[i]);
	}

	while (num != 0)
	{
		buffer[i] = (num % 10) + '0';
		num /= 10;
		i--;
	}

	return (&buffer[i + 1]);
}

