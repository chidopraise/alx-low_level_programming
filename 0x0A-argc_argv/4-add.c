#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * is_positive_number - checks if a string
 * is a positive number
 * @s: the string to check
 * Return: 1 if it's a positive number, 0 otherwise
 */
int is_positive_number(char *s)
{
	if (*s == '\0')
		return (0);

	while (*s)
	{
		if (!isdigit(*s))
			return (0);
		s++;
	}

	return (1);
}

/**
 * main - adds positive numbers
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 for success, 1 for error
 */
int main(int argc, char *argv[])
{
	int i, sum = 0;

	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}

	for (i = 1; i < argc; i++)
	{
		if (is_positive_number(argv[i]))
			sum += atoi(argv[i]);
		else
		{
			printf("Error\n");
			return (1);
		}
	}

	printf("%d\n", sum);

return (0);
}
