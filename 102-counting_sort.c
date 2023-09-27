#include "sort.h"

/**
 * get_max - Find the maximum value in an array of integers.
 *
 * This function searches the given array of integers and returns the maximum
 * integer found within it.
 *
 * @array: An array of integers to search.
 * @size: The number of elements in the array.
 *
 * Return: The maximum integer found in the array.
 */

int get_max(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * counting_sort - Sorts an array of integers in ascending order
 *                 using the counting sort algorithm.
 *
 * This function sorts the given array of integers in ascending order
 * using the counting sort algorithm. It also prints the counting array
 * after setting it up.
 *
 * @array: An array of integers to be sorted.
 * @size: The number of elements in the array.
 */

void counting_sort(int *array, size_t size)
{
	int *count, *sorted, max, i;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	max = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (i = 0; i < (max + 1); i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	for (i = 0; i < (max + 1); i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	free(sorted);
	free(count);
}
