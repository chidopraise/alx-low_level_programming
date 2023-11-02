#include <stdio.h>
#include <stdlib.h>

/**
 * _calloc - allocates memory for an array
 * and initializes it to zero
 * @nmemb: number of elements in the array
 * @size: size in bytes of each element
 *
 * Return: a pointer to the allocated memory,
 * or NULL if it fails
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int total_size;
	void *ptr;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);

	total_size = nmemb * size;
	ptr = malloc(total_size);

	if (ptr == NULL)
		return (NULL);

	for (i = 0; i < total_size; i++)
	{
		*((char *)ptr + i) = 0;
	}

	return (ptr);
}
