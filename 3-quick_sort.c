#include "sort.h"

/**
 * quick_sort - Ordena un arreglo de enteros en orden ascendente usando Quick Sort
 * @array: Puntero al arreglo
 * @size: Tamaño del arreglo
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}

/**
 * quick_sort_recursive - Ordena recursivamente el arreglo usando Quick Sort
 * @array: Puntero al arreglo
 * @inicio: Índice inicial de la partición
 * @end: Índice final de la partición
 * @size: Tamaño del arreglo
 */
void quick_sort_recursive(int *array, int inicio, int end, size_t size)
{
	int pivot_index;

	if (inicio < end)
	{
		pivot_index = lomuto_partition(array, inicio, end, size);
		quick_sort_recursive(array, inicio, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, end, size);
	}
}

/**
 * lomuto_partition - Particiona el arreglo usando el esquema de Lomuto
 * @array: Puntero al arreglo
 * @inicio: Índice inicial de la partición
 * @end: Índice final de la partición
 * @size: Tamaño del arreglo
 * Return: La posición final del pivote
 */
int lomuto_partition(int *array, int inicio, int end, size_t size)
{
	int pivot = array[end];
	int i = inicio - 1, j, temp;

	for (j = inicio; j < end; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}

	if (array[i + 1] != array[end])
	{
		temp = array[i + 1];
		array[i + 1] = array[end];
		array[end] = temp;
		print_array(array, size);
	}

	return (i + 1);
}
