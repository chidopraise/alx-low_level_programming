#include <stdio.h>

/**
 * get_endianness - Checks the endianness of the system.
 *
 * UNION - union brings together a collection of variables.
 *
 * Return: 0 if big endian, 1 if little endian.
 */
int get_endianness(void)
{
	union
	{
		int i; /* Integer to check endianness */
		char c[sizeof(int)]; /* Array of characters to check endianness */
	} check_endian;

	check_endian.i = 1; /* Set the integer to 1 */

	/* If the first byte of the character array is 1, it's little endian */
	return ((check_endian.c[0] == 1) ? 1 : 0);
}
