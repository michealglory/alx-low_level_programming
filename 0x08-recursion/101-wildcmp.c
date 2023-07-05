#include "main.h"

/**
 * wildcmp - Compares two strings and checks if they are identical
 * @s1: The first string
 * @s2: The second string
 *
 * Return: 1 if the strings are identical, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
	/* If both strings are empty, they are considered identical */
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	/*
	 * If s2 is '*', it can match with any string, so we recursively check
	 * for matches by advancing s1 and s2 to the next character in each
	 * recursive call until a match is found or the end of s1 is reached
	 */
	if (*s2 == '*')
	{
		/* Skip consecutive '*' characters in s2 */
		while (*(s2 + 1) == '*')
			s2++;

		/* If s2 is at the end, it matches with any remaining characters in s1 */
		if (*(s2 + 1) == '\0')
			return (1);

		/* Recursively check for matches by advancing s1 until a match is found */
		if (*s1 != '\0' && wildcmp(s1 + 1, s2))
			return (1);

		/* Recursively check for matches by advancing s2 until a match is found */
		if (wildcmp(s1, s2 + 1))
			return (1);
	}

	/*
	 * If the characters at the current positions match, recursively check
	 * the rest of the strings by advancing to the next character in each
	 * recursive call
	 */
	if (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
		return (wildcmp(s1 + 1, s2 + 1));

	/* If none of the above conditions are met, the strings are not identical */
	return (0);
}

