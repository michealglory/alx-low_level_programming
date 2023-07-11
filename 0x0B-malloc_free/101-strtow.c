#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * count_words - Counts the number of words in a string.
 * @str: The string to count words from.
 * Return: The number of words.
 */
int count_words(char *str)
{
	int count = 0;
	int len = strlen(str);
	int i;

	for (i = 0; i < len; i++)
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			count++;
	}

	return (count);
}

/**
 * allocate_words - Allocates memory for an array of words.
 * @count: The number of words to allocate.
 * Return: Pointer to the allocated memory or NULL if it fails.
 */
char **allocate_words(int count)
{
	char **words = malloc(sizeof(char *) * (count + 1));

	if (words == NULL)
		return (NULL);

	return (words);
}

/**
 * extract_word - Extracts a word from a string.
 * @str: The string to extract the word from.
 * @start: The starting index of the word.
 * @end: The ending index of the word.
 * Return: The extracted word or NULL if it fails.
 */
char *extract_word(char *str, int start, int end)
{
	int word_length = end - start;
	char *word = malloc(sizeof(char) * (word_length + 1));

	if (word == NULL)
		return (NULL);

	strncpy(word, &str[start], word_length);
	word[word_length] = '\0';

	return (word);
}

/**
 * strtow - Splits a string into words.
 * @str: The string to be split.
 * Return: Pointer to an array of strings (words) or NULL if it fails.
 */
char **strtow(char *str)
{
	int i, j, k, len, count = 0;
	char **words, *word;

	if (str == NULL || *str == '\0')
		return (NULL);

	len = strlen(str);
	count = count_words(str);
	words = allocate_words(count);

	if (words == NULL)
		return (NULL);

	j = 0;
	for (i = 0; i < len; i++)
	{
		if (str[i] != ' ')
		{
			k = i;
			while (str[k] != ' ' && str[k] != '\0')
				k++;
			word = extract_word(str, i, k);
			if (word == NULL)
			{
				free(words);
				return (NULL);
			}
			words[j] = word;
			j++;
			i = k - 1;
		}
	}

	words[j] = NULL;

	return (words);
}
