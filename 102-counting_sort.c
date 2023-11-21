counting sort

```
#include "sort.h"
#include <stdlib.h>
/**
 * counting_sort - sorts an array using counting sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * Return: Nothing.
 */

void counting_sort(int *array, size_t size)
{
    int *output, *count;
    size_t i, max;

    if (array == NULL || size < 2)
        return;

    max = 0;

    for (i = 0; i < size; i++)
    {
        if (array[i] > (int)max)
            max = array[i];
    }
    count = malloc((max + 1) * sizeof(int));
    output = malloc(size * sizeof(int));
    for (i = 0; i < size; i++)
        count[array[i]]++;
    for (i = 1; i <= max; i++)
        count[i] += count[i - 1];
    print_array(count, max + 1);
    for (i = 0; i < size; i++)
        output[i] = array[i];
    for (i = size - 1; i > 0; i--)
    {
        output[count[array[i]] - 1] = array[i];
        count[array[i]] -= 1;
    }
    output[count[array[0]] - 1] = array[0];
    count[array[0]] -= 1;

    for (i = 0; i < size; i++)
        array[i] = output[i];

    free(count);
    free(output);
}
```
