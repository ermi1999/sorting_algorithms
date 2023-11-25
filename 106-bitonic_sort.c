#include "sort.h"
/**
 * bitonic_sort - sorts an array using bitonic sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * Return: Nothing.
 */
void bitonic_sort(int *array, size_t size)
{
	size_t i, j, k, l;
	int temp;

	if (array == NULL || size < 2)
		return;
	for (k = 2; k <= size; k *= 2)
	{
		for (j = k / 2; j > 0; j /= 2)
		{
			for (i = 0; i < size; i++)
			{
				l = i ^ j;
				if (l > i)
				{
					if (((i & k) == 0) && (array[i] > array[l]))
					{
						temp = array[i];
						array[i] = array[l];
						array[l] = temp;
					}
					if (((i & k) != 0) && (array[i] < array[l]))
					{
						temp = array[i];
						array[i] = array[l];
						array[l] = temp;
					}
				}
			}
		}
	}
}
