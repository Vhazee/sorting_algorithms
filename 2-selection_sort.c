#include "sort.h"

/**
 * swap_ints - Swaps two integers.
 *
 * This function takes two integer values and swaps their values.
 *
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - Sorts an array of integers in ascending order
 *                  using the selection sort algorithm.
 *
 * This function sorts the given array of integers in ascending order
 * using the selection sort algorithm. It also prints the array after
 * each swap operation.
 *
 * @array: An array of integers to be sorted.
 * @size: The number of elements in the array.
 */

void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			swap_ints(array + i, min);
			print_array(array, size);
		}
	}
}
