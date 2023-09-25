#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - Swaps the two integers in an array.
 * @a: The first integer used to swap.
 * @b: The second integer used to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Orders a subset of an array of integers
 * using the Lomuto partition scheme.
 *
 * This function orders a specified subset of an array of
 * integers according to the Lomuto partition scheme with the
 * last element as the pivot. It rearranges
 * the elements in the given range [left, right] so that elements
 * less than or equal to the pivot are on the left, and elements
 * greater than the pivot are on the right.
 *
 * @array: The array of integers.
 * @size: The total size of the array.
 * @left: The starting index of the subset to be ordered.
 * @right: The ending index of the subset to be ordered.
 *
 * Return: The final index of the pivot element after partitioning.
 */

int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - Implement the quicksort algorithm with Lomuto
 * partition scheme.
 *
 * This function recursively sorts a partition of an array of integers
 * in ascending order using the quicksort algorithm with the Lomuto
 * partition scheme.
 * It operates on the specified range of indices from 'left' to 'right'
 * (inclusive), effectively sorting the elements within that range.
 *
 * @array: An array of integers to be sorted.
 * @size: The total size of the array.
 * @left: The starting index of the partition to be sorted.
 * @right: The ending index of the partition to be sorted.
 */

void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the quicksort algorithm with Lomuto partition scheme.
 *
 * This function sorts the given array of integers in ascending order
 * using the quicksort algorithm with the Lomuto partition scheme. It
 * prints the array after each swap of two elements during the sorting
 * process.
 *
 * @array: An array of integers to be sorted.
 * @size: The number of elements in the array.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
