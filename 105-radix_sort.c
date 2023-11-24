#include "sort.h"
#include <stdlib.h>
/**
 * count_sort - sorts an array using a counting sort algorithm.
 * @array: The array to be sorted.
 * @place: The place of the digit.
 * @size: The size of the array.
 * Return: Nothing
 */
void count_sort(int *array, int place, size_t size)
{
	int *output;
	int count[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	output = malloc(size * sizeof(int));
	for (i = 0; i < size; i++)
		count[(array[i] / place) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = size - 1; i > 0; i--)
	{
		output[count[(array[i] / place) % 10] - 1] = array[i];
		count[(array[i] / place) % 10]--;
	}
	output[count[(array[0] / place) % 10] - 1] = array[0];
	count[(array[0] / place) % 10]--;

	for (i = 0; i < size; i++)
		array[i] = output[i];
	print_array(array, size);
	free(output);
}

/**
 * radix_sort - sorts an array using radix sort algorithm.
 * @array: The array to be sorted.
 * @size: the size of the array.
 * Return: Nothing.
 */
void radix_sort(int *array, size_t size)
{
	int max, place;
	size_t i;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	for (place = 1; max / place > 0; place *= 10)
		count_sort(array, place, size);
}
