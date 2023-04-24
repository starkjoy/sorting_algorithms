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
	size_t i = 0;
	size_t j = 0;
	bool swapped = true;

	while (swapped)
	{
		swapped = false;

		for (i = 0; i < size; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				swapped = true;

				for (j = 0; j < size; j++)
				{
					if (j < size - 1)
						printf("%d, ", array[j]);
					else
						printf("%d", array[j]);
				}
				printf("\n");
			}
		}
	}
}
