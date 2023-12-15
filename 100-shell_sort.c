#include "sort.h"
/**
 * shell_sort -function that sorts an array of integers in
 * ascending order using the Shell sort algorithm, using the Knuth sequence.
 * @arry: list of Int
 * @range: Size of list
 **/

void shell_sort(int *arry, size_t range)
{
	unsigned int p = 1, m, n;
	int temprary;

	if (arry == NULL)
		return;
	if (range < 2)
		return;
	while (p < range / 3)
		p = p * 3 + 1;

	while (p > 0)
	{
		for (m = p; m < range; m++)
		{
			temprary = arry[m];
			n = m;
			while (n >= p && arry[n - p] > temprary)
			{
				arry[n] = arry[n - p];
				n -= p;
			}
			arry[n] = temprary;
		}
		print_array(arry, range);
		p /= 3;
	}
}
