#include <stddef.h>

/**
 * int_index - Searches for an integer in an array
 * @array: The array to search
 * @size: The number of elements in the array
 * @cmp: A pointer to the function used to compare values
 *
 * Return: Index of the first element for which cmp
 * doesn't return 0,-1 if no match or size is 0
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	if (array && cmp && size > 0)
	{
		int i;

		for (i = 0; i < size; i++)
		{
			if (cmp(array[i]) != 0)
				return (i);
		}
	}

	return (-1);
}
