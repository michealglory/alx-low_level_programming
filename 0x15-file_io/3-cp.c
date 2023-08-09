#include "main.h"
/**
 * main - copies the content of a file to another file
 * @argc: number of arguments
 * @argv: arguments
 *
 * Return: 1 on success, exit otherwise
 */
int main(int argc, char *argv[])
{
	unsigned int fileMode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	int srcFile, destFile, bytesRead = 1024, bytesWritten, closeSrc, closeDest;
	char buffer[1024];

	/* Check command line arguments */
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(1);
	}

	/* Open the source file for reading */
	srcFile = open(argv[1], O_RDONLY);
	handleException(srcFile, -1, argv[1], 'O');

	/* Open or create the destination file for writing */
	destFile = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, fileMode);
	handleException(destFile, -1, argv[2], 'W');

	/* Copy content from source to destination using buffer */
	while (bytesRead == 1024)
	{
		bytesRead = read(srcFile, buffer, sizeof(buffer));
		if (bytesRead == -1)
			handleException(-1, -1, argv[1], 'O');

		bytesWritten = write(destFile, buffer, bytesRead);
		if (bytesWritten == -1)
			handleException(-1, -1, argv[2], 'W');
	}

	/* Close source and destination files */
	closeSrc = close(srcFile);
	handleException(closeSrc, srcFile, NULL, 'C');
	closeDest = close(destFile);
	handleException(closeDest, destFile, NULL, 'C');

	return (0);
}

/**
 * handle_exception - Handles file-related exceptions and exits with
 * appropriate error codes.
 * @descriptor: The file descriptor being checked for errors.
 * @file_doc: The file descriptor used in the context of the exception.
 * @filename: The name of the file being operated on.
 * @rw_mode: The read/write mode in which the error occurred ('C' for
 * close, 'O' for read, 'W' for write).
 *
 * This function prints an error message to stderr based on the exception
 * type and exits with specific error codes to indicate the type of error.
 */
void handleException(int descriptor, int file_doc, char *filename,
		char rw_mode)
{
	if (rw_mode == 'C' && descriptor == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close file_doc %d\n", file_doc);
		exit(100);
	}
	else if (rw_mode == 'O' && descriptor == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
		exit(98);
	}
	else if (rw_mode == 'W' && descriptor == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
		exit(99);
	}
}


