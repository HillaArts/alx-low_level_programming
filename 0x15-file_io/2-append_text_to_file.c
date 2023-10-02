#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"
#include <string.h>
/**
 * append_text_to_file - Appends text to the end of a file.
 * @filename: The name of the file to append to.
 * @text_content: A NULL-terminated string to add at the end of
 * the file (can be NULL).
 *
 * Return: 1 on success, -1 on failure.
 *
 * Description:
 * - Opens the specified file for write-only access and appends the
 *   given text content to it.
 * - If the file doesn't exist, or if the user lacks the necessary
 *   permissions to write the file, it returns -1.
 * - If text_content is NULL, nothing is added to the file, but it
 *   still returns 1 on success.
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int fd = open(filename, O_WRONLY | O_APPEND);
	ssize_t bytes_written = write(fd, text_content, strlen(text_content));

	if (filename == NULL)
	return (-1);

	if (fd == -1)
	return (-1);

	if (text_content != NULL)
	{
	if (bytes_written == -1)
	{
	close(fd);
	return (-1);
	}
	}

	close(fd);
	return (1);
}

