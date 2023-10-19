#include <stdio.h>

/**
 * print_buffer - Prints a buffer in a specified format
 * @b: Pointer to the buffer
 * @size: Size of the buffer
 */

void print_buffer(char *b, int size)
{
	int i, j;

	if (size <= 0)
	{
		printf("\n");
		return;
	}

	for (i = 0; i < size; i += 10)
	{
		printf("%08x: ", i);

		for (j = 0; j < 10; j++)
		{
			if (i + j < size)
			{
				printf("%02x", b[i + j]);
			}
			else
			{
				printf("  ");
			}

			if (j % 2 == 1)
				printf(" ");
		}

		printf(" ");

		for (j = 0; j < 10; j++)
		{
			if (i + j < size)
			{
				if (b[i + j] >= 32 && b[i + j] <= 126)
				{
					_putchar(b[i + j]);
				}
				else
				{
					_putchar('.');
				}
			}
		}

		printf("\n");
	}
}
