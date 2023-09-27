#include "sort.h"

void swap_ints(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integers within an array.
 * This function swaps the values of two integers located within an array.
 *
 * @a: Pointer to the first integer to swap.
 * @b: Pointer to the second integer to swap.
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * max_heapify - Reorganize an array to maintain the max heap property.
 * This function reorganizes an array of integers, which represents a binary tree,
 * to maintain the max heap property starting from the specified root node. It
 * adjusts the elements in the array to ensure that the parent node has a value
 * greater than or equal to its children.
 *
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @base: The index of the base row of the tree.
 * @root: The index of the root node in the binary tree.
 */

void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		swap_ints(array + root, array + large);
		print_array(array, size);
		max_heapify(array, size, base, large);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 *             using the sift-down heap sort algorithm.
 *
 * This function sorts the given array of integers in ascending order
 * using the sift-down heap sort algorithm. During the sorting process,
 * it prints the array after each swap operation.
 *
 * @array: An array of integers to be sorted.
 * @size: The number of elements in the array.
 */

void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		max_heapify(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap_ints(array, array + i);
		print_array(array, size);
		max_heapify(array, size, i, 0);
	}
}
