#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

/**
 * Opens the source and destination files.
 * Exits the program with an error message if any issues occur.
 *
 * @param file_from The source file.
 * @param file_to The destination file.
 * @return The file descriptor of the source file.
 */
int open_files(const char *file_from, const char *file_to);

/**
 * Copies the content from the source file to the destination file.
 * Exits the program with an error message if any issues occur during copying.
 *
 * @param fd_from The file descriptor of the source file.
 * @param fd_to The file descriptor of the destination file.
 */
void copy_files(int fd_from, int fd_to);

/**
 * Closes the source and destination files.
 * Exits the program with an error message if closing any file descriptor fails.
 *
 * @param fd_from The file descriptor of the source file.
 * @param fd_to The file descriptor of the destination file.
 */
void close_files(int fd_from, int fd_to);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        dprintf(2, "Usage: cp file_from file_to\n");
        exit(97);
    }

    int fd_from, fd_to;
    fd_from = open_files(argv[1], argv[2]);
    copy_files(fd_from, fd_to);
    close_files(fd_from, fd_to);

    return 0;
}

int open_files(const char *file_from, const char *file_to) {
    int fd_from = open(file_from, O_RDONLY);
    if (fd_from == -1) {
        dprintf(2, "Error: Can't read from file %s\n", file_from);
        exit(98);
    }

    int fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
    if (fd_to == -1) {
        dprintf(2, "Error: Can't write to %s\n", file_to);
        close(fd_from);
        exit(99);
    }

    return fd_from;
}

void copy_files(int fd_from, int fd_to) {
    ssize_t read_bytes, write_bytes;
    char buffer[BUFFER_SIZE];

    while ((read_bytes = read(fd_from, buffer, BUFFER_SIZE)) > 0) {
        write_bytes = write(fd_to, buffer, read_bytes);
        if (write_bytes != read_bytes) {
            dprintf(2, "Error: Can't write to file\n");
            close(fd_from);
            close(fd_to);
            exit(99);
        }
    }

    if (read_bytes == -1) {
        dprintf(2, "Error: Can't read from file\n");
        close(fd_from);
        close(fd_to);
        exit(98);
    }
}

void close_files(int fd_from, int fd_to) {
    if (close(fd_from) == -1 || close(fd_to) == -1) {
        dprintf(2, "Error: Can't close file descriptor\n");
        exit(100);
    }
}
