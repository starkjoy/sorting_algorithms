#include "sort.h"

/**
 * insertion_sort_list - implements an insertion sort on a doubly linked list
 * @list: list pointer
 * Return: void or nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *head_node;
	listint_t *next_node;
	listint_t *temp;
	bool swapped;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	head_node = *list;
	next_node = head_node->next;
	while (next_node != NULL)
	{
		swapped = false;
		while (head_node != NULL && head_node->n > next_node->n)
		{
			temp = next_node->next;
			next_node->prev = head_node->prev;
			if (next_node->prev != NULL)
				next_node->prev->next = next_node;
			head_node->next = temp;
			if (temp != NULL)
				temp->prev = head_node;
			head_node->prev = next_node;
			next_node->next = head_node;
			if (*list == head_node)
				*list = next_node;
			head_node = next_node->prev;
			swapped = true;
			print_list(*list);
		}
		if (!swapped)
		{
			head_node = next_node;
			next_node = head_node->next;
		}
		else
			next_node = head_node->next;
	}
}
