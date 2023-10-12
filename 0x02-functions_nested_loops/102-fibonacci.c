#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	long int fib1 = 1, fib2 = 2, next, count;

	printf("%ld, %ld", fib1, fib2);

	for (count = 2; count < 50; count++)
	{
		next = fib1 + fib2;
		printf(", %ld", next);
		fib1 = fib2;
		fib2 = next;
	}

	printf("\n");

	return (0);
}
