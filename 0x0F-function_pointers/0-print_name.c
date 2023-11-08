#include <stdio.h>

/**
 * print_name - this function prints names passed through
 * the parameter.
 *
 * @name: is a variable pointer that collects names to be printed
 * @f: is a function pointer that points to a function
 * RETURN: it returns Null or the name in the
 * parameter
 */

void print_name(char *name, void (*f)(char *))
{
	if (name != NULL && f != NULL)
	{
		f(name);
	}
}
