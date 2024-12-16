#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort
 * @array: Pointer to the array
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}

/**
 * quick_sort_recursive - Helper function to implement Quick Sort recursively
 * @array: Array to sort
 * @low: Start index
 * @high: End index
 * @size: Total size of the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int i, j, pivot, temp;

	if (low >= high)
		return;

	pivot = array[high];
	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}

	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;

	print_array(array, size);

	quick_sort_recursive(array, low, i, size);
	quick_sort_recursive(array, i + 2, high, size);
}
