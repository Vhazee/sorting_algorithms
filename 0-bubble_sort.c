#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array.
 *
 * This function swaps the values of two integers in an array.
 *
 * @a: The first integer to be swapped.
 * @b: The second integer to be swapped.
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - Sorts an array of integers in ascending order using
 *               the bubble sort algorithm.
 *
 * This function sorts an array of integers in ascending order using the
 * bubble sort algorithm. It takes an array and its size as input and prints
 * the array after each swap operation.
 *
 * @array: An array of integers to be sorted.
 * @size: The size of the array.
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
