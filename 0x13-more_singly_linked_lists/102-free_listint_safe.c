#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t list,
 * handling possible loops.
 * @h: Pointer to the head of the list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *current, *next;
	size_t size = 0;

	if (h == NULL || *h == NULL)
		return (0);

	current = *h;

	while (current)
	{
		size++;
		next = current->next;

		/* Check if the node is part of a loop */
		if (current <= next)
		{
			free(current);
			*h = NULL;
			break;
		}

		free(current);
		current = next;
	}

	return (size);
}
