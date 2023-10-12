#include <stdio.h>
#include "main.h"

/**
 * print_times_table - Prints the n times table, starting with 0.
 * @n: The value to generate the times table for.
 */

void print_times_table(int n)
{
	if (n > 15 || n < 0)
	{
		return; // Do not print anything for invalid values of n
	}

	int row, column, result;

	for (row = 0; row <= n; row++)
	{
		for (column = 0; column <= n; column++)
		{
			result = row * column;

			if (column != 0)
			{
				printf(", ");
			}

			if (result < 10)
			{
				printf("   ");
			}
			else if (result < 100)
			{
				printf("%d", result);
			}
			printf("\n");
		}
}
