#include <stdio.h>
#include "main.h"

/**
 * _isdigit - Checks if a character is a digit (0-9)
 * @c: The character to check
 *
 * Return: 1 if c is a digit, 0 otherwise
 */

int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);/* Digit (0-9) */
	}
	else
	{
		return (0);/* Not a digit (0-9) */
	}
}
