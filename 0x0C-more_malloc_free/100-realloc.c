#include <stdio.h>
#include <stdlib.h>

/**
 * _realloc - reallocates a memory block
 * using malloc and free
 * @ptr: pointer to the previously allocated memory
 * @old_size: size, in bytes, of the
 * allocated space for ptr
 * @new_size: new size, in bytes, of the new memory block
 *
 * Return: pointer to the newly allocated
 * memory block, or NULL on failure
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;
	unsigned int min_size;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	min_size = (old_size < new_size) ? old_size : new_size;
	new_ptr = malloc(new_size);

	if (new_ptr == NULL)
		return (NULL);

	for (i = 0; i < min_size; i++)
	{
		*((char *)new_ptr + i) = *((char *)ptr + i);
	}

	free(ptr);

	return (new_ptr);
}
