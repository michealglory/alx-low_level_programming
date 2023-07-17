#include <stdio.h>
#include <string.h>

/**
 * get_filename - Extracts the file name from the given path.
 * @path: The full path of the file.
 *
 * Return: The extracted file name.
 */
const char *get_filename(const char *path)
{
	const char *filename = path;

	while (*path != '\0')
	{
		if (*path == '/' || *path == '\\')
			filename = path + 1;

		path++;
	}

	return (filename);
}

/**
 * main - Entry point of the program.
 *
 * Return: Always 0 (Success).
 */
int main(void)
{
	const char *filename = get_filename(__FILE__);

	printf("Compiled from file: %s\n", filename);


	return (0);
}

