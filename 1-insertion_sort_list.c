#include "sort.h"

/**
 * insertion_sort_list - implements an insertion sort on a doubly linked list
 * @list: list pointer
 * Return: void or nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current;

	if (list == NULL)
		return;

	current = (*list)->next;
	while (current)
	{
		while(current->prev && current->n < current->prev->n)
		{
			current->prev->next = current->next;
			if(current->next)
				current->next->prev = current->prev;
			current->next = current->prev;
			current->prev = current->prev->prev;
			current->next->prev = current;
			if(current->prev == NULL)
				*list = current;
			else
				current->prev->next = current;
			print_list(*list);
		}
		current = current->next;
	}
}
