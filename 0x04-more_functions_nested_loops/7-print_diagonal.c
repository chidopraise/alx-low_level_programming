#include "main.h"

/**
 * print_diagonal - Draws a diagonal line in the terminal
 * @n: The number of times the character '\' should be printed
 */

void print_diagonal(int n)
{
	int spaces;

	if (n <= 0)
	{
		_putchar('\n');
	}
	else
	{
		for (spaces = 0; spaces < n; spaces++)
		{
			int i;
			for (i = 0; i < spaces; i++)
				_putchar(' ');
			_putchar('\\');
			_putchar('\n');
		}
	}
}
