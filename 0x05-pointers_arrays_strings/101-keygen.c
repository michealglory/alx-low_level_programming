#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"

#define PASSWORD_LENGTH 10

/**
 * generate_password - Generates a random password
 *
 * Return: Pointer to the generated password
 */
char *generate_password(void)
{
	static const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	char *password = malloc((PASSWORD_LENGTH + 1) * sizeof(char)); /* +1 for the null terminator */
	int i;

	srand(time(NULL));

	for (i = 0; i < PASSWORD_LENGTH; i++)
	{
		int index = rand() % (sizeof(charset) - 1);
		password[i] = charset[index];
	}

	password[PASSWORD_LENGTH] = '\0'; /* Add null terminator */

	return password;
}

/**
 * main - Entry point of the program
 *
 * Return: Always 0
 */
int main(void)
{
	char *password = generate_password();

	printf("%s\n", password);

	free(password);

	return 0;
}

