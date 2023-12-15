#include "sort.h"

/**
 * swops_integrs - Swap 2 int in an list.
 * @m: The prevoius int to swap in a list.
 * @n: The next int to swap in a list.
 */
static void swops_integrs(int *m, int *n)
{
	int temprary;

	temprary = *m;
	*m = *n;
	*n = temprary;
}

/**
 * lomuto_partition - Order a subset of an array of integers  using
 *                    the Lomuto partition scheme
 * @arry: list of integers.
 * @range: size of the list.
 * @lft: The starting index of the subset to order.
 * @rght: The ending index of the subset to order.
 *
 * Return: This function takes a subset of an array of integers specified
 * by the indices 'left' and 'right' and orders it
 * using the Lomuto partition scheme.
 * The function returns
 * the final index of the pivot
 */
int lomuto_partition(int *arry, size_t range, int lft, int rght)
{
	int *opperator, p, don;

	opperator = arry + rght;
	for (p = don = lft; don < rght; don++)
	{
		if (arry[don] < *opperator)
		{
			if (p < don)
			{
				swops_integrs(arry + don, arry + p);
				print_array(arry, range);
			}
			p++;
		}
	}

	if (arry[p] > *opperator)
	{
		swops_integrs(arry + p, opperator);
		print_array(arry, range);
	}

	return (p);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @arry: A list to sort.
 * @range: The size of list.
 * @lft: The starting index of the subarray to sort.
 * @rght: The ending index of the subarray to sort.
 *
 * Description: This function sorts a sub-array (arry) of integers within specified boundaries (lft and rght)
 * while using the Lomuto partition scheme.
 */
void lomuto_sort(int *arry, size_t range, int lft, int rght)
{
	int fit;

	if (rght - lft > 0)
	{
		fit = lomuto_partition(arry, range, lft, rght);
		lomuto_sort(arry, range, lft, fit - 1);
		lomuto_sort(arry, range, fit + 1, rght);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * divides the array into sub-arrays, choosing the last
 * element of each sub-array as the pivot
 * @arry: An list of int.
 * @range: The size of list.
 *
 * Description: the Lomuto partition scheme.
 *              prints the swap of elements during partitioning.
 */
void quick_sort(int *arry, size_t range)
{
	if (arry == NULL || range < 2)
		return;

	lomuto_sort(arry, range, 0, range - 1);
}
