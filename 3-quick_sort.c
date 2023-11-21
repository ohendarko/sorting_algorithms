#include "sort.h"
#include <stdio.h>
/**
* swap - swaps two elements
* @a: 1st element
* @b: 2nd element
*/
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/**
* lomuto_partition - lomuto partition
* @array: array
* @low: low
* @high: high
* @size: size
* Return: appropriately
*/
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);
	print_array(array, size);

	return (i + 1);
}
/**
* quick_sort_recursive - quick_sort_recursive
* @array: array
* @low: low
* @high: high
* @size: size
*/
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = lomuto_partition(array, low, high, size);
		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}
/**
* quick_sort - sorts an array of integers in ascending order
* using the Quick sort algorithm
* @array: array of integers
* @size: size of array
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;
	quick_sort_recursive(array, 0, size - 1, size);
}
