#include "sort.h"

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - Merge and sort a subarray of integers.
 * This function merges and sorts a subarray of integers represented by
 * the `subarr` parameter. The subarray is specified by the indices `front`,
 * `mid`, and `back`. The sorted result is stored in the `buff` buffer.
 *
 * @subarr: A subarray of integers to merge and sort.
 * @buff: A buffer to store the sorted subarray.
 * @front: The starting index of the subarray.
 * @mid: The middle index of the subarray.
 * @back: The ending index of the subarray.
 */

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; k++)
		buff[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
	for (; i < mid; i++)
		buff[k++] = subarr[i];
	for (; j < back; j++)
		buff[k++] = subarr[j];
	for (i = front, k = 0; i < back; i++)
		subarr[i] = buff[k++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - Recursively implement the merge sort algorithm.
 * This function recursively sorts a subarray of integers, specified by the
 * indices `front` and `back`, using the merge sort algorithm. The sorted
 * result is stored in the `buff` buffer.
 *
 * @subarr: A subarray of integers to be sorted.
 * @buff: A buffer to store the sorted subarray.
 * @front: The starting index of the subarray.
 * @back: The ending index of the subarray.
 */

void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, mid);
		merge_sort_recursive(subarr, buff, mid, back);
		merge_subarr(subarr, buff, front, mid, back);
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 *              using the top-down merge sort algorithm.
 * This function sorts the given array of integers in ascending order
 * using the top-down merge sort algorithm. It modifies the original array
 * to achieve the sorted result.
 *
 * @array: An array of integers to be sorted.
 * @size: The number of elements in the array.
 */

void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recursive(array, buff, 0, size);

	free(buff);
}
