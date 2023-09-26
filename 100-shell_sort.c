#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array.
 *
 * This function swaps the values of two integers in an array.
 *
 * @a: A pointer to the first integer to be swapped.
 * @b: A pointer to the second integer to be swapped.
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - Sorts an array of integers in ascending order using
 *              the shell sort algorithm.
 *
 * This function sorts an array of integers in ascending order using the
 * shell sort algorithm with the Knuth interval sequence. It takes an
 * array and its size as input.
 *
 * @array: An array of integers to be sorted.
 * @size: The size of the array.
 */

void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				swap_ints(array + j, array + (j - gap));
				j -= gap;
			}
		}
		print_array(array, size);
	}
}
