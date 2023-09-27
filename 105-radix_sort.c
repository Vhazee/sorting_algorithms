#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * get_max - Find the maximum value in an array of integers.
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
 * radix_counting_sort - Sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * This function sorts the significant digits of the given array of integers
 * in ascending order using the counting sort algorithm, focusing on a specific
 * significant digit indicated by the `sig` parameter. The sorted result is stored
 * in the `buff` buffer.
 *
 * @array: An array of integers to be sorted.
 * @size: The number of elements in the array.
 * @sig: The significant digit to sort on.
 * @buff: A buffer to store the sorted array.
 */

void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / sig) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buff[count[(array[i] / sig) % 10] - 1] = array[i];
		count[(array[i] / sig) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buff[i];
}

/**
 * radix_sort - Sorts an array of integers in ascending order
 *              using the LSD radix sort algorithm.
 * This function sorts the given array of integers in ascending order
 * using the Least Significant Digit (LSD) radix sort algorithm. During
 * the sorting process, it prints the array after each increase in the
 * significance of the digits.
 *
 * @array: An array of integers to be sorted.
 * @size: The number of elements in the array.
 */

void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = get_max(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
