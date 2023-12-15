#ifndef SORT_H
#define SORT_H

#include <stddef.h>

/* Bubble Sort.c function*/
void bubble_sort(int *arry, size_t range);

/* Insertion Sort */
typedef struct listint_s
{
    int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

void insertion_sort_list(listint_t **listt);
void print_list(const listint_t *list);

/* Selection Sort */
void selection_sort(int *arry, size_t range);
/* Quick Sort */
void quick_sort(int *arry, size_t range);

/* Shell Sort */
void shell_sort(int *arry, size_t range);

/* Helper function to print an array */
void print_array(const int *array, size_t size);

#endif /* SORT_H */
