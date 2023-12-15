#include "sort.h"

/**
 * swop_nodes - sorts a doubly linked list of integers in ascending order
 * using the Insertion sort algorithm
 * @j: A pointer to the start of the list.
 * @node1: A pointer to the first node to swap.
 * @node2: The 2nd node to swap.
 */
void swop_nodes(listint_t **j, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;

	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;

	else
		*j = node2;

	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the insertion sort algorithm.
 * @listt: A pointer to the start of a doubly-linked list of integers.
 *
 * Description: This function takes the head of a doubly-linked list
 * of integers and sorts it in ascending order using the insertion sort algorithm.
 * it places elements in their correct position
 */
void insertion_sort_list(listint_t **listt)
{
	listint_t *itertion, *insertion, *temprary;

	if (listt == NULL || *listt == NULL || (*listt)->next == NULL)
		return;

	for (itertion = (*listt)->next; itertion != NULL; itertion = temprary)
	{
		temprary = itertion->next;
		insertion = itertion->prev;

		while (insertion != NULL && itertion->n < insertion->n)
		{
			swop_nodes(listt, &insertion, itertion);
			print_list((const listint_t *)*listt);
		}
	}
}
