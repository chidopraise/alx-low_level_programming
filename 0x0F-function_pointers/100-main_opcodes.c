#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prints the opcodes of its own main function
 * @argc: The number of arguments
 * @argv: The array of arguments
 *
 * Return: Always 0 if successful, 1 for incorrect number
 * of arguments, 2 for negative number of bytes
 */
int main(int argc, char *argv[])
{
	int bytes, i;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	bytes = atoi(argv[1]);

	if (bytes < 0)
	{
		printf("Error\n");
		return (2);
	}

	for (i = 0; i < bytes; i++)
	{
		printf("%02hhx", *((char *)main + i));

		if (i < bytes - 1)
			printf(" ");
		else
			printf("\n");
	}

	return (0);
}
