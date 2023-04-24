#include "sort.h"

/**
 * selection_sort - implements a selection sort algorithm
 * @array: a list  of numbers
 * @size: size of the array
 * Return: void or nothing
 */

void selection_sort(int *array, size_t size)
{
	size_t current_index;
	size_t minimum_index;
	size_t unsorted_index;
	int minimum_value;

	if (array == NULL || size == 0)
		return;

	for (current_index = 0; current_index < size - 1; current_index++)
	{
		minimum_index = current_index;

		for (unsorted_index = current_index + 1; unsorted_index < size;
				unsorted_index++)
		{
			if (array[unsorted_index] < array[minimum_index])
				minimum_index = unsorted_index;
		}

		minimum_value = array[current_index];
		array[current_index] = array[minimum_index];
		array[minimum_index] = minimum_value;

		print_array(array, size);
	}
}
