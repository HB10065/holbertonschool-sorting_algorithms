#include "sort.h"

/**
 *
 */

void bubble_sort(int *array, size_t size)
{
	size_t place, i = 0;
	int remp;

	while (i < size)
	{
		for (place = 0; place < size; place++)
		{
			if (array[place] > array[place + 1])
			{
				remp = array[place];
				array[place] = array[place + 1];
				array[place + 1] = remp;
			}
		}
		i++;
	}
}
