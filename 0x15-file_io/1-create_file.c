#include "main.h"
#include <fcntl.h>
#include <unistd.h>

/**
 * create_file - Creates a file and writes content to it.
 * @filename: The name of the file to create.
 * @text_content: The content to write to the file.
 *
 * Return: On success, 1. On failure, -1.
 */
int create_file(const char *filename, char *text_content)
{
	int ch;
	int rwr_status;
	int file_doc;

	if (!filename)
		return (-1);

	/* Open file, create it doesn't exist and truncating if it does */
	file_doc = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (file_doc == -1)
		return (-1);

	if (!text_content)
		text_content = "";

	/* Calculate the length of the text content */
	for (ch = 0; text_content[ch]; ch++)
		;

	/* Write the content to the file */
	rwr_status = write(file_doc, text_content, ch);

	if (rwr_status == -1)
	{
		close(file_doc);
		return (-1);
	}

	close(file_doc);

	return (1);
}
