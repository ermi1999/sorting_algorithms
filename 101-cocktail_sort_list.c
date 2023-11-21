#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a linked list.
 * @list: The list containing the nodes.
 * @node1: The first node to be swapped.
 * @node2: The second node to be swapped.
 * Return: Nothing.
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next != NULL)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}

/**
 * cocktail_sort_list - Sorts a linked list using the cocktail sort algorithm.
 * @list: The list to be sorted.
 * Return: Nothing.
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *current, *next, *prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	current = *list;
	for (;;)
	{
		swapped = 0;
		while (current->next != NULL)
		{
			next = current->next;
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				swapped = 1;
				print_list(*list);
			}
			current = next;
		}
		if (!swapped)
			break;
		swapped = 0;
		while (current->prev != NULL)
		{
			prev = current->prev;
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current->prev, current);
				swapped = 1;
				print_list(*list);
			}
			current = prev;
		}
		if (!swapped)
			break;
	}
}
