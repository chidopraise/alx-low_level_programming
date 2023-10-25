#include "main.h"

/**
 * _sqrt_recursion - Returns the natural square root of a number
 * @n: The number to calculate the square root for
 *
 * Return: The natural square root of n, or -1 if no natural square root exists
 */
int _sqrt_recursion(int n)
{
	return (find_square_root(n, 1));
}

/**
 * find_square_root - Helper function to find the square root
 * @n: The number to calculate the square root for
 * @guess: The current guess for the square root
 *
 * Return: The natural square root of n, or -1 if no natural square root exists
 */
int find_square_root(int n, int guess)
{
	if (guess * guess == n)
	{
		return (guess);
	}
	else if (guess * guess > n)
	{
		return (-1);
	}
	else
	{
		return (find_square_root(n, guess + 1));
	}
}
