#include "sort.h"

/**
 *
 */

void bubble_sort(int *array, size_t size)
{
	size_t place, print = size;
	int remp;

	while (size != 0)
	{
		for (place = 0; place < size - 1; place++)
		{
			if (array[place] > array[place + 1])
			{
				remp = array[place];
				array[place] = array[place + 1];
				array[place + 1] = remp;

				print_array(array, print);
			}
		}
		size--;
	}
}
