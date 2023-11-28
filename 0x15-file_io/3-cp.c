#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

int copy_file(const char *source, const char *destination);

/**
 * main - Entry point for the file copy program.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 *
 * Return: 0 on success, 97 on incorrect arguments,
 * 98 on read error, 99 on write error, 100 on close error.
 */
int main(int argc, char *argv[])
{
	const char *file_from;
	const char *file_to;

	if (argc != 3)
	{
		dprintf(2, "Usage: %s file_from file_to\n", argv[0]);
		exit(97);
	}

	file_from = argv[1];
	file_to = argv[2];

	if (copy_file(file_from, file_to) != 0)
	{
		exit(98);
	}

	return (0);
}

/**
 * copy_file - Copies the content of one file to another.
 * @source: Path to the source file.
 * @destination: Path to the destination file.
 *
 * Return: 0 on success, 1 on error.
 */
int copy_file(const char *source, const char *destination)
{
	int fd_from = open(source, O_RDONLY);
	int fd_to;
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read, bytes_written;

	if (fd_from == -1)
	{
		dprintf(2, "Error: Can't read from file %s\n", source);
		return (1);
	}

	fd_to = open(destination, O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

	if (fd_to == -1)
	{
		dprintf(2, "Error: Can't write to file %s\n", destination);
		close(fd_from);
		return (1);
	}

	while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);

		if (bytes_written == -1)
		{
			dprintf(2, "Error: Can't write to file %s\n", destination);
			close(fd_from);
			close(fd_to);
			return (1);
		}
	}

	if (bytes_read == -1)
	{
		dprintf(2, "Error: Can't read from file %s\n", source);
		close(fd_from);
		close(fd_to);
		return (1);
	}

	if (close(fd_from) == -1 || close(fd_to) == -1)
	{
		dprintf(2, "Error: Can't close fd\n");
		return (1);
	}

	return (0);
}
