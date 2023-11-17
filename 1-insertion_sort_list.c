#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list.
 * @list: The list.
 * Return: Nothing.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		listint_t *temp = current->next;
		listint_t *prev = current->prev;

		while (prev != NULL && prev->n > current->n)
		{
			prev->next = current->next;
			if (current->next != NULL)
				current->next->prev = prev;

			current->next = prev;
			current->prev = prev->prev;

			if (prev->prev != NULL)
				prev->prev->next = current;
			else
				*list = current;

			prev->prev = current;
			prev = current->prev;
			print_list(*list);
		}

		current = temp;
	}
}
