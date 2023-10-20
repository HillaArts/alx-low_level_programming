#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include "main.h"
/**
 * create_file - Create a file with the specified name and content.
 * @filename: The name of the file to create.
 * @text_content: A NULL-terminated string to write to the file (can be NULL).
 *
 * Return: 1 on success, -1 on failure.
 *
 * Description:
 * - Creates a file with the given filename.
 * - If the file already exists, its content is truncated.
 * - If text_content is not NULL, the function writes it to the file.
 * - The file permissions are set to rw------- (read and write for owner).
 * - If any error occurs during file creation or writing, -1 is returned.
 */
int create_file(const char *filename, char *text_content)
{
	int fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0600);
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

