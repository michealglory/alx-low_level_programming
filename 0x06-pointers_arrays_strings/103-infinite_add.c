#include <stdio.h>
/**
 * get_length - Computes the length of a string.
 * @str: The input string.
 *
 * Return: The length of the string.
 */
int get_length(char *str)
{
	int length = 0;

	while (str[length] != '\0')
		length++;

	return (length);
}

/**
 * reverse_string - Reverses a string in-place.
 * @str: The string to be reversed.
 * @length: The length of the string.
 */
void reverse_string(char *str, int length)
{
	int start = 0;
	int end = length - 1;
	char temp;

	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

/**
 * infinite_add - Adds two numbers.
 * @n1: The first number as a string.
 * @n2: The second number as a string.
 * @r: The buffer to store the result.
 * @size_r: The size of the buffer.
 *
 * Return: A pointer to the result if successful, 0 otherwise.
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int carry = 0;
	int sum, i = 0;
	int len_n1 = get_length(n1);
	int len_n2 = get_length(n2);

	if (len_n1 > size_r - 1 || len_n2 > size_r - 1)
		return (0);

	while (len_n1 > 0 || len_n2 > 0)
	{
		sum = carry;

		if (len_n1 > 0)
			sum += n1[--len_n1] - '0';

		if (len_n2 > 0)
			sum += n2[--len_n2] - '0';

		carry = sum / 10;
		r[i++] = (sum % 10) + '0';
	}

	if (carry != 0)
	{
		if (i >= size_r - 1)
			return (0);

		r[i++] = carry + '0';
	}

	r[i] = '\0';
	reverse_string(r, i);
	return (r);
}
