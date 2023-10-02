#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"
/**
 * read_textfile - Read and print a text file to standard output.
 * @filename: The name of the file to be read.
 * @letters: The number of letters to read and print.
 *
 * Return: The actual number of letters read and printed, or 0 on error.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd = open(filename, O_RDONLY);
	char *buffer = malloc(letters);
	ssize_t bytes_read = read(fd, buffer, letters);
	ssize_t bytes_written = write(STDOUT_FILENO, buffer, bytes_read);

	if (filename == NULL)
	return (0);

	if (fd == -1)
	return (0);

	if (buffer == NULL)
	{
	close(fd);
	return (0);
	}

	if (bytes_read == -1)
	{
	free(buffer);
	close(fd);
	return (0);
	}

	free(buffer);
	close(fd);

	if (bytes_written == -1 || bytes_written != bytes_read)
	return (0);

	return (bytes_written);
}

