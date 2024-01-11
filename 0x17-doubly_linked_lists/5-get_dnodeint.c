#include <stdlib.h>
#include "lists.h"

/**
 * get_dnodeint_at_index - Returns the nth
 * node of a dlistint_t linked list
 * @head: Pointer to the head of the list
 * @index: Index of the node to retrieve, starting from 0
 *
 * Return: The nth node of the list, or NULL
 * if the node does not exist
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i;
	dlistint_t *current = head;

	for (i = 0; current != NULL && i < index; i++)
		current = current->next;

	return current;
}
