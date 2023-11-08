#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"

/**
 * main - Performs simple operations
 * @argc: The number of arguments
 * @argv: The array of arguments
 *
 * Return: 0 if successful
 */
int main(int argc, char *argv[])
{
	int num1, num2, result;
	int (*op_func)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		return (98);
	}

	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);
	op_func = get_op_func(argv[2]);

	if (!op_func)
		return (99);

	result = op_func(num1, num2);
	printf("%d\n", result);

	return (0);
}
