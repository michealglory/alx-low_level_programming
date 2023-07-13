#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * string_nconcat - Concatenates two strings
 * @s1: First string
 * @s2: Second string
 * @n: Number of bytes to concatenate from s2
 *
 * Return: Pointer to the concatenated string
 *         If function fails, returns NULL
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *concat;
	unsigned int len1, len2, concat_len, i, j;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	len1 = strlen(s1);
	len2 = strlen(s2);

	if (n >= len2)
		n = len2;

	concat_len = len1 + n;

	concat = malloc(sizeof(char) * (concat_len + 1));

	if (concat == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		concat[i] = s1[i];

	for (j = 0; j < n; j++)
		concat[i++] = s2[j];

	concat[i] = '\0';

	return (concat);
}

