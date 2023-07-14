#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_result - Prints the result string
 * @result: The result string
 * @length: The length of the string
 *
 * Return: void
 */
void print_result(char *result, int length)
{
	int i, j;

	i = j = 0;
	while (i < length)
	{
		if (result[i] != '0')
			j = 1;
		if (j || i == length - 1)
			_putchar(result[i]);
		i++;
	}

	_putchar('\n');
	free(result);
}

/**
 * multiply_strings - Multiplies a char with a string and
 * places the answer into the result string
 * @n: The char to multiply
 * @num: The string to multiply
 * @num_length: The length of the num string
 * @result: The destination string for the multiplication
 * @result_index: The highest index to start addition
 *
 * Return: Pointer to the result string, or NULL on failure
 */
char *multiply_strings(char n, char *num, int num_length,
		char *result, int result_index)
{
	int j, k, product, product_remainder, sum, sum_remainder;

	product_remainder = sum_remainder = 0;
	for (j = num_length, k = result_index; j >= 0; j--, k--)
	{
		product = (n - '0') * (num[j] - '0') + product_remainder;
		product_remainder = product / 10;
		sum = (result[k] - '0') + (product % 10) + sum_remainder;
		sum_remainder = sum / 10;
		result[k] = sum % 10 + '0';
	}
	for (sum_remainder += product_remainder; k >= 0 && sum_remainder; k--)
	{
		sum = (result[k] - '0') + sum_remainder;
		sum_remainder = sum / 10;
		result[k] = sum % 10 + '0';
	}
	if (sum_remainder)
	{
		return (NULL);
	}
	return (result);
}

/**
 * is_digit - Checks if the arguments are digits
 * @args: The array of arguments
 *
 * Return: 0 if digits, 1 if not
 */
int is_digit(char **args)
{
	int i, j;

	for (i = 1; i < 3; i++)
	{
		for (j = 0; args[i][j]; j++)
		{
			if (args[i][j] < '0' || args[i][j] > '9')
				return (1);
		}
	}
	return (0);
}

/**
 * initialize_string - Initializes a string with '0'
 * @str: The string to initialize
 * @length: The length of the string
 *
 * Return: void
 */
void initialize_string(char *str, int length)
{
	int i;

	for (i = 0; i < length; i++)
		str[i] = '0';
	str[i] = '\0';
}

/**
 * main - Multiplies two numbers
 * @argc: The number of arguments
 * @argv: The argument vector
 *
 * Return: 0 on success, or exit status of 98 on failure
 */
int main(int argc, char *argv[])
{
	int length1, length2, result_length, ti, i;
	char *result;
	char *temp;
	char error_message[] = "Error\n";

	if (argc != 3 || is_digit(argv))
	{
		for (ti = 0; error_message[ti]; ti++)
			_putchar(error_message[ti]);
		exit(98);
	}
	for (length1 = 0; argv[1][length1]; length1++)
		;
	for (length2 = 0; argv[2][length2]; length2++)
		;
	result_length = length1 + length2 + 1;
	result = malloc(result_length * sizeof(char));
	if (result == NULL)
	{
		for (ti = 0; error_message[ti]; ti++)
			_putchar(error_message[ti]);
		exit(98);
	}
	initialize_string(result, result_length - 1);
	for (ti = length2 - 1, i = 0; ti >= 0; ti--, i++)
	{
		temp = multiply_strings(argv[2][ti], argv[1], length1 - 1,
				result, (result_length - 2) - i);
		if (temp == NULL)
		{
			for (ti = 0; error_message[ti]; ti++)
				_putchar(error_message[ti]);
			free(result);
			exit(98);
		}
	}
	print_result(result, result_length - 1);
	return (0);
}
