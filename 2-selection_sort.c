#include "sort.h"

/**
 * swops_integer - Swaps 2 int in a list.
 * @m: The prev integer to swap.
 * @n: The nxt integer to swap.
 */

void swops_integer(int *m, int *n)
{
	int temprary;

	temprary = *m;
	*m = *n;
	*n = temprary;
}

/**
 * selection_sort -  function that sorts an array of integers in
 * ascending order using the Quick sort algorithm
 * @arry: A list.
 * @range: size of list.
 *
 * Description: Prints the list.
 */
void selection_sort(int *arry, size_t range)
{
	int *minmm;
	size_t c, d;

	if (arry == NULL || range < 2)
		return;

	for (c = 0; c < range - 1; c++)
	{
		minmm = arry + c;
		for (d = c + 1; d < range; d++)
			minmm = (arry[d] < *minmm) ? (arry + d) : minmm;

		if ((arry + c) != minmm)
		{
			swops_integer(arry + c, minmm);
			print_array(arry, range);
		}
	}
}
