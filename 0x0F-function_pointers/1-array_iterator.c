#include <stdio.h>

/**
 * array_iterator - brief Iterates through an array and applies
 * a specified action to each element.
 *
 * @array: array The array to iterate over.
 * @size: size The size of the array.
 * @action: action The function to apply to each element.
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (array == NULL || action == NULL)
	{
		return;
	}

	for (i = 0; i < size; i++)
	{
		action(&array[i]);
	}
}
