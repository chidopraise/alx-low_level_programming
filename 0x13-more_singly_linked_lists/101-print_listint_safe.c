#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list.
 * @head: Pointer to the head of the list.
 * Return: Number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *current = head;
	size_t count = 0;

	while (current != NULL)
	{
		printf("[%p] %d\n", (void *)current, current->n);

		count++;

		/* Check for loop */
		if (current <= current->next)
		{
			fprintf(stderr, "Linked list has a loop\n");
			exit(98);
		}

		current = current->next;
	}

	return (count);
}
