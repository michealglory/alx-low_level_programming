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
	/* Base cases */
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	if (*s2 == '*')
	{
		/* If s2 is '*', recursively check for matches by advancing s1 */
		if (*s1 != '\0' && wildcmp(s1 + 1, s2))
			return (1);

		/* If s2 is '*', recursively check for matches by advancing s2 */
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

