#include <stdio.h>
#include "main.h"

/**
 * print_diagsums - Prints the sum of the diagonals in a square matrix
 * @a: The square matrix
 * @size: The size of the matrix
 */
void print_diagsums(int *a, int size)
{
	int i, diag1 = 0, diag2 = 0;

	for (i = 0; i < size; i++)
	{
		diag1 += a[i * size + i];
		diag2 += a[i * size + (size - i - 1)];
	}

	printf("%d, %d\n", diag1, diag2);
}
