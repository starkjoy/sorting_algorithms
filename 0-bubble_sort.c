#include "sort.h"
#include <stdio.h>
#include <stdbool.h>

/**
 * bubble_sort - implements a bubble sort algorithm
 * @array: accepts an array of integers
 * @size: size of the array
 * Return: void or nothing
 */

void bubble_sort(int *array, size_t size)
{
	int temp;
	size_t i;
	bool swapped = true;

	if (array == NULL || size == 0)
		return;

	while (swapped)
	{
		swapped = false;

		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				swapped = true;

				print_array(array, size);
			}
		}
	}
}
