#include <stdio.h>
#include <math.h>

/**
 * largest_prime_factor - Finds the largest
 * prime factor of a number
 * @n: The number to find the largest
 * prime factor of a number
 *
 * Return: The largest prime factor
 */

long largest_prime_factor(long n)
{
	long factor = 2;

	while (n > factor)
	{
		if (n % factor == 0)
		{
			n = n / factor;
		}
		else
		{
			factor++;
		}
	}

	return (factor);
}

int main(void)
{
	long number = 612852475143;
	long largest = largest_prime_factor(number);

	printf("%ld\n", largest);

	return (0);
}
