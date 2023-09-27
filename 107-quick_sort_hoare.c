#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_ints - Swaps the two integers in an array.
 * @a: first integer to swap.
 * @b: second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - Order a subset of an array of integers
 *                   according to the Hoare partition scheme.
 * This function orders a specified subset of an array of integers in
 * accordance with the Hoare partition scheme. The subset to be ordered
 * is defined by the indices 'left' and 'right'. It uses the last element
 * of the partition as the pivot and prints the array after each swap of
 * two elements during the partitioning process.
 *
 * @array: The array of integers.
 * @size: The total size of the array.
 * @left: The starting index of the subset to be ordered.
 * @right: The ending index of the subset to be ordered.
 *
 * Return: The final index of the pivot element after partitioning.
 */

int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap_ints(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * hoare_sort - Sort an array of integers using the quicksort algorithm.
 * This function recursively sorts a specified partition of an array of
 * integers in ascending order using the quicksort algorithm with the Hoare
 * partition scheme. The partition to be sorted is defined by the indices
 * 'left' and 'right'.
 *
 * @array: An array of integers to be sorted.
 * @size: The total size of the array.
 * @left: The starting index of the partition to be sorted.
 * @right: The ending index of the partition to be sorted.
 */

void hoare_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, part - 1);
		hoare_sort(array, size, part, right);
	}
}

/**
 * quick_sort_hoare - Sorts the array of integers in ascending
 * order using the quicksort algorithm.
 * @array: an array of integers.
 * @size: the size of the array.
 *
 * Description: Uses the Hoare partition scheme.
 * Prints the array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
