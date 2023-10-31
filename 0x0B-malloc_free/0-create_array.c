#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * create_array - creates an array of chars and
 * initializes with a specific char
 * @size: the size of the array
 * @c: the character to initialize the array with
 *
 * Return: a pointer to the array, or NULL if it fails
 */
char *create_array(unsigned int size, char c)
{
	if (size == 0)
		return (NULL);

	char *array = (char *)malloc(size * sizeof(char));

	if (array == NULL)
		return (NULL); /* Memory allocation failed */

	unsigned int i;

	for (i = 0; i < size; i++)
		array[i] = c;

	return (array);
}
