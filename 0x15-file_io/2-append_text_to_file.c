#include "main.h"
#include <fcntl.h>
#include <unistd.h>

/**
 * append_text_to_file - Appends text content to an existing file.
 * @filename: The name of the file to which content will be appended.
 * @text_content: The content to append to the file.
 *
 * Return: On success, 1. On failure, -1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file_doc;
	int rwr_status;
	int ch_count;

	if (!filename)
		return (-1);

	/* Open the file for writing and append new content at the end */
	file_doc = open(filename, O_WRONLY | O_APPEND);

	if (file_doc == -1)
		return (-1);

	if (text_content)
	{
		/* Calculate the length of the text content */
		for (ch_count = 0; text_content[ch_count]; ch_count++)
			;

		/* Write the content to the file */
		rwr_status = write(file_doc, text_content, ch_count);

		if (rwr_status == -1)
		{
			close(file_doc);
			return (-1);
		}
	}

	close(file_doc);

	return (1);
}


