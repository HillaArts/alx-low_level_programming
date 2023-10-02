#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"

#define BUFFER_SIZE 1024

/**
 * error_exit - Handle errors and exit with a specific code and message.
 * @code: The exit code.
 * @message: The error message to display.
 *
 * Description:
 * This function prints an error message to the standard error stream (stderr)
 * using dprintf and then exits the program with the specified exit code.
 */
void error_exit(int code, const char *message)
{
	dprintf(2, "%s\n", message);
	exit(code);
}

/**
 * main - Copy the content of one file to another.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 *
 * Return:
 * 0 on successful execution, or the corresponding error code on failure.
 *
 * Description:
 * This program copies the content of one file (specified as file_from) to
 * another
 * file (specified as file_to) while handling various error conditions
 * as follows:
 * - If the number of arguments is incorrect, it exits with code 97.
 * - If the source file cannot be read, it exits with code 98.
 * - If the destination file cannot be written or created, it exits with
 *   code 99.
 * - If there are issues with closing file descriptors, it exits with code 100.
 * The program reads data from the source file in chunks and writes it to the
 * destination file, effectively copying the content.
 */

int main(int argc, char *argv[])
{
	const char *file_from = argv[1];
	const char *file_to = argv[2];
	int fd_source = open(file_from, O_RDONLY);
	int fd_dest = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read, bytes_written;

	if (argc != 3)
	error_exit(97, "Usage: cp file_from file_to");

	if (fd_source == -1)
	error_exit(98, "Error: Can't read from file");


	if (fd_dest == -1)
	error_exit(99, "Error: Can't write to file");

	while ((bytes_read = read(fd_source, buffer, BUFFER_SIZE)) > 0)
	bytes_written = write(fd_dest, buffer, bytes_read);
	if (bytes_written == -1)
	error_exit(99, "Error: Can't write to file");


	if (bytes_read == -1)
	error_exit(98, "Error: Can't read from file");


	if (close(fd_source) == -1)
	error_exit(100, "Error: Can't close fd");


	if (close(fd_dest) == -1)
	error_exit(100, "Error: Can't close fd");


	return (0);
}

