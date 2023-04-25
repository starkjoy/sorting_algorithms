#include "sort.h"

/**
 * quicksort - recursive process for quick sort
 *
 * @array: array of integers
 * @low: lowest index of partition
 * @high: highest index of partition
 * @size: size of array
 */

void quicksort(int *array, size_t size, int low, int high)
{
	int pivot, tmp, i, j;

	if (low < high)
	{
		pivot = array[high];
		i = low - 1;
		for (j = low; j <= high - 1; j++)
		{
			i++;
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
		if (array[i + 1] != array[high])
		{
			tmp = array[i + 1];
			array[i + 1] = array[high];
			array[high] = tmp;
			print_array(array, size);
		}
		quicksort(array, size, low, i);
		quicksort(array, size, i + 2, high);
	}
}

/**
 * quick_sort - quick sort algoritm
 *
 * @array: array of integers
 * @size: size of the array
 * Return: nothing
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, size, 0, size - 1);
}
