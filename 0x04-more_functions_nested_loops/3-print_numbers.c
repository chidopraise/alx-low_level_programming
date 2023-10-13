#include "main.h"

/**
 * print_numbers - Prints numbers 0 to 9 followed by a new line
 *
 */

void print_numbers(void)
{
	int number = 0;

	while (number <= 9)
	{
		printf(number + '0');
		number++;
	}

	printf('\n');
}
