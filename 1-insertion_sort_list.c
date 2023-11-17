#include "sort.h"

/**
 * len_list - returns the length of a linked list
 * @h: pointer to the list
 *
 * Return: length of list
 */
int len_list(listint_t *h)
{
	int len = 0;

	while (h)
	{
		len++;
		h = h->next;
	}
	return (len);
}

/**
 * insertion_sort_list - sorts a linked list with the Insert Sort algorithm
 * @list: double pointer to the list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *prev, *temp;

	if (!list || !(*list) || len_list(*list) < 2)
		return;

	curr = (*list)->next;

	while (curr)
	{
		temp = curr;
		prev = curr->prev;

		while (prev && temp->n < prev->n)
		{
			/* Swap nodes */
			if (temp->next)
				temp->next->prev = prev;
			prev->next = temp->next;
			temp->prev = prev->prev;
			temp->next = prev;
			if (prev->prev)
				prev->prev->next = temp;
			else
				*list = temp;
			prev->prev = temp;

			/* Move temp and prev pointers */
			prev = temp->prev;
			temp = prev ? prev->next : *list;

			print_list(*list);
		}

		curr = curr->next;
	}
}
