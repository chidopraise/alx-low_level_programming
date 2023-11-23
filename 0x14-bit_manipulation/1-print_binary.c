#include <stdio.h>

/**
 * print_binary - Prints the binary representation of a number.
 * @n: The unsigned long int to be printed in binary.
 */
void print_binary(unsigned long int n)
{
	if (n > 1)
		print_binary(n >> 1);

	putchar((n & 1) + '0');
}

/**
 * main - prints the value of the concerted bit value.
 *
 * Return: Always return 0
 */
int main(void)
{
	unsigned long int number = 42; /* Replace with the desired number */

	printf("Binary representation of %lu: ", number);
	print_binary(number);
	printf("\n");

	return (0);
}
