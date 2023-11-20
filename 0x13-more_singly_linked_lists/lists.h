#ifndef LISTS_H
#define LISTS_H

/**
 * struct listint_s - singly linked list
 * @n: integer data
 * @next: points to the next node in the list
 *
 * Description: A structure representing a node in a singly linked list.
 */
typedef struct listint_s
{
	int n; /* Data of the node (an integer in this case) */
	struct listint_s *next; /* Pointer to the next node in the list */
} listint_t;

size_t print_listint(const listint_t *h);

size_t listint_len(const listint_t *h);

listint_t *add_nodeint(listint_t **head, const int n);

listint_t *add_nodeint_end(listint_t **head, const int n);

void free_listint(listint_t *head);

void free_listint2(listint_t **head);

int pop_listint(listint_t **head);

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index);

int sum_listint(listint_t *head);

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n);

int delete_nodeint_at_index(listint_t **head, unsigned int index);

#endif /* LISTS_H */
