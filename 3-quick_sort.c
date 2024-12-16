#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order using quick sort
 * @array: pointer al inicio del array
 * @size: tamaño del array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}

/**
 * quick_sort_recursive - sort an array using quick sort
 * @array: pointer sl inicio del array
 * @inicio: inicio del array
 * @end: fin del array
 * @size: Size of the array
 */
void quick_sort_recursive(int *array, int inicio, int end, size_t size)
{
	int i, j, pivot, temp;

	if (inicio >= end)
		return;

	pivot = array[end];
	i = inicio - 1;

	for (j = inicio; j < end; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}

	temp = array[i + 1];
	array[i + 1] = array[end];
	array[end] = temp;

	print_array(array, size);

	quick_sort_recursive(array, inicio, i, size);
	quick_sort_recursive(array, i + 2, end, size);
}