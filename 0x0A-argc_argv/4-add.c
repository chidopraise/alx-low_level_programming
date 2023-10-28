#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - Entry point
 * @argc: The number of command-line arguments
 * @argv: An array of strings containing the command-line arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	int sum __attribute__((unused)) = 0;

	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}

	for (int i = 1; i < argc; i++)
	{
		int num = atoi(argv[i]);

		if (num == 0 && *argv[i] != '0')
		{
			printf("Error\n");
			return (1);
		}

		if (num < 0)
		{
			printf("Error\n");
			return (1);
		}

		sum += num;
	}

	printf("%d\n", sum);

	return (0);
}
