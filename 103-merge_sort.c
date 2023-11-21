#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * copy_array - copies an array.
 * @from: the array to be copied from.
 * @to: The array to be copied to.
 * @size: The size of the array.
 * Return: nothing.
 */
void copy_array(int *from, int *to, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
		to[i] = from[i];
}

/**
 * merge - merges the given arrays in an ascending order.
 * @first: The array to be merged to.
 * @begin: The begining of the array.
 * @middle: The middle of the array.
 * @end: The end of the array.
 * @second: the second array.
 * Return: Nothing.
 */
void merge(int *first, int begin, int middle, int end, int *second)
{
	int i, j, k;

	i = begin;
	j = middle;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(second + begin, middle - begin);
	printf("[right]: ");
	print_array(second + middle, end - middle);
	for (k = begin; k < end; k++)
	{
		if (i < middle && (j >= end || second[i] <= second[j]))
		{
			first[k] = second[i];
			i++;
		}
		else
		{
			first[k] = second[j];
			j++;
		}
	}
	printf("[Done]: ");
	print_array(first + begin, end - begin);
}

/**
 * split_merge - splits an array and mergs them to sort the array.
 * @first: The first original array.
 * @begin: The start of the array.
 * @end: The end of the array.
 * @second: The array to merge from.
 * Return: Nothing.
 */
void split_merge(int *first, int begin, int end, int *second)
{
	int middle;

	if (end - begin <= 1)
		return;

	middle = begin + (end - begin) / 2;

	split_merge(second, begin, middle, first);
	split_merge(second, middle, end, first);
	merge(first, begin, middle, end, second);
}
/**
 * merge_sort - sorts an array using merge sort algorythm.
 * @array: The array.
 * @size: The size of the array.
 * Return: Nothing.
 */
void merge_sort(int *array, size_t size)
{
	int *result;

	result = malloc(sizeof(int) * size);
	copy_array(array, result, size);
	split_merge(array, 0, size, result);
	free(result);
}
