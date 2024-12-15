#include "sort.h"

/**
 * selection_sort - anashe
 * @array: pointer a array
 * @size: tamaÑo del array
 */

void selection_sort(int *array, size_t size)
{
	size_t a = 0, b = (size - 1), c, temp;

	while (a != b)
	{
		for (c = a + 1; c < size; c++)
		{
			if (array[a] > array[c])
			{
				temp = array[a];
				array[a] = array[c];
				array[c] = temp;
				print_array(array, size);
			}
		}
		a++;
	}
}
