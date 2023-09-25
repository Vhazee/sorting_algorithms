#include "sort.h"

/**
 * swap_nodes - Swaps the positions of two nodes in a listint_t doubly-linked
 * list.
 *
 * This function swaps the positions of two nodes in a doubly-linked list
 * provided the pointers to the head of the list and the two nodes to swap.
 *
 * @h: A pointer to the head of the doubly-linked list.
 * @n1: A pointer to the first node to be swapped.
 * @n2: A pointer to the second node to be swapped.
 */

void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers using the
 *                       insertion sort algorithm.
 *
 * This function sorts a doubly-linked list of integers using the insertion
 * sort algorithm. It takes a pointer to the head of the list as input and
 * prints the list after each swap.
 *
 * @list: A pointer to the head of a doubly-linked list of integers.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			swap_nodes(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}

