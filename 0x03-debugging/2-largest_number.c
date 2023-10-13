#include "main.h"

/**
 * largest_number - returns the largest of 3 numbers
 * @a: first integer
 * @b: second integer
 * @c: third integer
 * Return: largest number
 */

int largest_number(int a, int b, int c)
{
	int largest;

	largest = a; /*Assume 'a' is the largest initially*/

	if (b > largest)
	{
		largest = b; /*If 'b' is larger, update 'largest'*/
	}

	if (c > largest)
	{
		largest = c; /*If 'c' is larger, update 'largest'*/
	}

	return (largest);
}
