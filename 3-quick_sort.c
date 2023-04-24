#include "sort.h"
#include <stdlib.h>

/**
 * partition - Lomuto partition scheme
 *
 * @array: array of integers
 * @low: lowest index of partition
 * @high: highest index of partition
 * @size: size of array
 *
 * Return: index of pivot element
 */

size_t partition(int *array, int low, int high, size_t size)
{
	int pivot, tmp, i, j;

	i = low - 1;
	pivot = array[high];

	for (j = low; j <= high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			print_array(array, size);
		}
	}
	tmp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = tmp;
	print_array(array, size);
	return (i + 1);
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
	int low, high;
	size_t pi;

	low = 0;
	high = size - 1;

	if (array == NULL || size < 2)
		return;

	if (low < high)
	{
		pi = partition(array, low, high, size);
		if (pi > 0)
			quick_sort(array, pi);
		quick_sort(array + pi + 1, size - pi - 1);
	}
} 
