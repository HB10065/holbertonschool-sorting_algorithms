#include "sort.h"

/**
 * selection_sort - anashe
 * @array: pointer a array
 * @size: tamaÑo del array
 */

void selection_sort(int *array, size_t size)
{
	size_t a, c, min_idx, temp;

	if (!array || size < 2)
		return;

	a = 0;

	while (a < size - 1)
	{
		min_idx = a;

		for (c = a + 1; c < size; c++)
		{
			if (array[c] < array[min_idx])
				min_idx = c;
		}

		if (min_idx != a)
		{
			temp = array[a];
			array[a] = array[min_idx];
			array[min_idx] = temp;

			print_array(array, size);
		}

		a++;
	}
}
