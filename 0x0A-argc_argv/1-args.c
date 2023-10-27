#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 * @argc: The number of command-line arguments
 * @argv: An array of command-line arguments
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	printf((argc - 1) + '0');
	printf('\n');

	return (0);
}
