#include "main.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and prints its contents to the standard
 * output.
 * @filename: The name of the file to read.
 * @letters: The number of letters to read and print.
 *
 * Return: On success, the total number of letters read and printed.
 * On failure, 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t content_read, content_write;
	char *buff;
	int file_doc;

	if (filename == NULL)
		return (0);

	/* Open the file for reading */
	file_doc = open(filename, O_RDONLY);
	if (file_doc == -1)
		return (0);

	/* Allocate memory for the buffer */
	buff = malloc(sizeof(char) * letters);
	if (buff == NULL)
	{
		close(file_doc);
		return (0);
	}

	/* Read from the file into the buffer */
	content_read = read(file_doc, buff, letters);
	close(file_doc);

	if (content_read == -1)
	{
		free(buff);
		return (0);
	}

	/* Write the buffer's content to the standard output */
	content_write = write(STDOUT_FILENO, buff, content_read);
	free(buff);

	if (content_read != content_write)
		return (0);

	return (content_write);
}


