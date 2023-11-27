#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>

/**
 * struct ssize_s - Custom data type for ssize_t.
 * @value: The value of ssize_t.
 *
 */
typedef struct ssize_s
{
	ssize_t value;
} ssize_t;

ssize_t read_textfile(const char *filename, size_t letters);

int create_file(const char *filename, char *text_content);

int append_text_to_file(const char *filename, char *text_content);

#endif /* MAIN_H */
