#include "sort.h"

/**
 * insertion_sort_list - implements an insertion sort on a doubly linked list
 * @list: list pointer
 * Return: void or nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next_node, *prev_node;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		next_node = current->next;
		prev_node = current->prev;

		while (prev_node != NULL && prev_node->n > current->n)
		{
			if (next_node != NULL)
				next_node->prev = prev_node;
			prev_node->next = next_node;
			current->prev = prev_node->prev;
			if (prev_node->prev != NULL)
				prev_node->prev->next = current;
			else
				*list = current;
			prev_node->prev = current;
			current->next = prev_node;
			print_list(*list);
		}
		current = next_node;
	}
}
