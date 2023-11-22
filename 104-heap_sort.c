#include "sort.h"
/**
 * heapify - implements a heapsort data structure.
 * @array: The array.
 * @size: The size of the array.
 * @n: the current index.
 * @i: The root.
 * Return: Nothing.
 */
void heapify(int *array, size_t size, size_t n, int i)
{
	int temp, largest;
	size_t left, right;

	largest = i;
	left = 2 * i + 1;
	right = 2 * i + 2;
	if (left < n && array[left] > array[largest])
		largest = left;
	if (right < n && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		temp = array[i];
		array[i] = array[largest];
		array[largest] = temp;
		print_array(array, size);
		heapify(array, size, n, largest);
	}
}

/**
 * heap_sort - sorts an array using the heap sort algorythm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * Return: Nothing.
 */
void heap_sort(int *array, size_t size)
{
	int i, temp;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, size, i);
	for (i = size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;

		print_array(array, size);
		heapify(array, size, i, 0);
	}
}
