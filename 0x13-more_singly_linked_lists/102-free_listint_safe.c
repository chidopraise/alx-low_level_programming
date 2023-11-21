#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t linked list.
 * @h: Pointer to the head of the list.
 * Return: Size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *current = *h, *next;
	size_t count = 0;

	while (current != NULL)
	{
		count++;

		/* Store next node before freeing current node */
		next = current->next;

		/* Check for loop and break the loop */
		if (current <= next)
		{
			*h = NULL;
			return (count);
		}

		free(current);

		current = next;
	}

	*h = NULL;
	return (count);
}
