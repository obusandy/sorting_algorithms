#include "sort.h"

/**
 * bubble_sort - a function sorts an array of integers in
 * ascending order using the Bubble sort algorithm
 * @arry: the array to be sorted
 * @range: the size of the array to be sorted
 */
void bubble_sort(int *arry, size_t range)
{
	size_t k, i, maxmize = range - 1;
	int swich = 0, temprary;

	/* when it contains nothing or only contains single element */
	if (range < 2)
		return;
	for (k = 0; k < range; k++)
	{
		/*
		 * improves the temporary variable used to save on time
		 * everytime a huge object appears
		 */
		for (i = 0; i < maxmize; i++)
		{
			if (arry[i] > arry[i + 1])
			{
				swich = 1;
				temprary = arry[i];
				arry[i] = arry[i + 1];
				arry[i + 1] = temprary;
				print_array(arry, range);
			}
		}
		if (swich == 0)
			return;
		swich = 0;
		maxmize--;
	}
}
