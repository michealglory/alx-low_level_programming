#include <stdlib.h>
#include <stdio.h>

/**
 * strtow - Split a string into words
 * @str: The string to split
 *
 * This function takes a string and splits it into individual words.
 * The words are stored in a dynamically allocated array of strings.
 * The array is terminated by a NULL pointer.
 *
 * Return: A pointer to the array of words, or NULL if an error occurs.
 */
char **strtow(char *str)
{
	if (str == NULL || *str == '\0')
		return (NULL);

	int word_count = count_words(str);

	if (word_count == 0)
		return (NULL);

	char **words = allocate_words(word_count);

	if (words == NULL)
		return (NULL);

	int i, j, k;
	int start = 0, end = 0;

	for (i = 0; i < word_count; i++)
	{
		while (str[start] == ' ')
			start++;

		end = start;
		while (str[end] != ' ' && str[end] != '\0')
			end++;

		words[i] = extract_word(str, start, end);

		start = end;
	}

	words[word_count] = NULL;

	return (words);
}

/**
 * count_words - Count the number of words in a string
 * @str: The string to count words in
 *
 * This function counts the number of words in a string. Words
 * are separated by spaces. If the string is empty or contains
 * only spaces, the function returns 0.
 *
 * Return: The number of words in the string.
 */
int count_words(char *str)
{
	int count = 0;
	int is_word = 0;

	while (*str)
	{
		if (*str != ' ' && !is_word)
		{
			count++;
			is_word = 1;
		}
		else if (*str == ' ')
		{
			is_word = 0;
		}

		str++;
	}

	return (count);
}

/**
 * allocate_words - Allocate memory for an array of words
 * @count: The number of words to allocate memory for
 *
 * This function allocates memory for an array of words.
 * The size of the array is determined by the count parameter.
 * The memory is allocated dynamically using malloc.
 *
 * Return: A pointer to the allocated memory, or NULL if an error occurs.
 */
char **allocate_words(int count)
{
	char **words = malloc((count + 1) * sizeof(char *));

	if (words == NULL)
		return (NULL);

	return (words);
}

/**
 * extract_word - Extract a word from a string
 * @str: The string to extract a word from
 * @start: The start position of the word in the string
 * @end: The end position of the word in the string
 *
 * This function extracts a word from a string. The word is
 * specified by the start and end positions in the string.
 * The extracted word is stored in a dynamically allocated string.
 * The memory is allocated using malloc.
 *
 * Return: A pointer to the extracted word, or NULL if an error occurs.
 */
char *extract_word(char *str, int start, int end)
{
	int length = end - start;
	char *word = malloc((length + 1) * sizeof(char));

	if (word == NULL)
		return (NULL);

	int i, j;

	for (i = start, j = 0; i < end; i++, j++)
		word[j] = str[i];

	word[length] = '\0';

	return (word);
}

