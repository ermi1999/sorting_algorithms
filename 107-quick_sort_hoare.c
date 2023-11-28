#include "sort.h"

/**
 * partition - implements the partition for quick sort
 * algorithm with Hoare Partition scheme.
 * @array: The array.
 * @low: the the left side of the array.
 * @high: The right side of the array.
 * @size: The size of the array.
 * Return: the next pivot.
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j, temp;

	i = low - 1;
	j = high + 1;
	pivot = array[high];

	while (i < j)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i < j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
	}
	return (i);
}

/**
 * quick_sort_recursive - sorts an array using quick sort recursively.
 * @array: The array to be sorted.
 * @low: The left side of the array.
 * @high: The right side of the array.
 * @size: The size of the array.
 * Return: Nothing.
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);

		quick_sort_recursive(array, low, pivot - 1, size);
		quick_sort_recursive(array, pivot, high, size);
	}
}

/**
 * quick_sort_hoare - this function sorts an array
 * using quick sort algorithm with Hoare Partition scheme.
 * @array: The array to be sorted.
 * @size the size of the array.
 * Return: Nothing.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_recursive(array, 0, size - 1, size);
}
