#include <stdio.h>
#include <stdlib.h>

/**
 * is_digit - Check if a string
 * contains only digits.
 * @str: The string to check.
 * Return: 1 if all characters are digits,
 * 0 otherwise.
 */
int is_digit(char *str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}

/**
 * main - Multiplies two positive numbers.
 * @argc: The number of command line arguments.
 * @argv: An array of command line argument strings.
 * Return: 0 on success, 98 on invalid arguments.
 */
int main(int argc, char *argv[])
{
	unsigned long num1;
	unsigned long num2;

	if (argc != 3)
	{
		printf("Error\n");
		return (98);
	}

	if (!is_digit(argv[1]) || !is_digit(argv[2]))
	{
		printf("Error\n");
		return (98);
	}

	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);

	printf("%lu\n", num1 * num2);

	return (0);
}
