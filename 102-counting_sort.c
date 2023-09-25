#include "sort.h"
#include <stdlib.h>
/**
* count_array - creates the count array
* @array: array of integers
* @size: size of array
* @k: largest number in unsorted array
* Return: the count array
*/
int *count_array(int *array, size_t size, int k)
{
	int *counter, i;
	size_t j;

	counter = malloc((k + 1) * sizeof(int));
	if (counter == NULL)
		return (NULL);
	for (i = 0; i < (k + 1); i++)
		counter[i] = 0;
	for (j = 0; j < size; j++)
		counter[array[j]]++;
	for (i = 1; i <= k; i++)
		counter[i] = counter[i] + counter[i - 1];
	print_array(counter, k + 1);
	return (counter);
}
/**
* counting_sort - sorts an array of integers in a ascending order
* using the Counting sort algorithm
* @array: array of integers
* @size: size of array
*/
void counting_sort(int *array, size_t size)
{
	int *b, k, *counter, j;
	size_t i;

	if (array == NULL || size < 2)
		return;
	k = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > k)
			k = array[i];
	}

	counter = count_array(array, size, k);
	if (counter == NULL)
		return;

	b = malloc(size * sizeof(int));
	if (b == NULL)
	{
		free(counter);
		return;
	}

	for (j = size - 1; j >= 0; j--)
		b[--counter[array[j]]] = array[j];
	for (i = 0; i < size; i++)
		array[i] = b[i];
	free(b);
	free(counter);
}