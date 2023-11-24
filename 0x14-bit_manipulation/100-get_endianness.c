#include "main.h"

/**
 * get_endianness - Checks the endianness of the system.
 *
 * Return: 0 if the system is big endian, 1 if it's little endian.
 */
int get_endianness(void)
{
	unsigned int x = 1;
	char *c = (char *)&x;

	/* Dereference the pointer to the char array to access the byte */
	/* and return the value indicating the endianness. */
	return (*c);
}
