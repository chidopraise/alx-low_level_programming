#include <stdio.h>
#include "main.h"

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
		_putchar("\n");
		/*return;*/
	}

	for (i = 0; i < size; i += 10)
	{
		_putchar("%08x: ", i);

		for (j = 0; j < 10; j++)
		{
			if (i + j < size)
			{
				_putchar("%02x", b[i + j]);
			}
			else
			{
				_putchar("  ");
			}

			if (j % 2 == 1)
				_putchar(" ");

			if (j == 9)
				_putchar(" ");
		}

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

		_putchar("\n");
	}
}
