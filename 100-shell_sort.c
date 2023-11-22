#include "sort.h"
#include <stdio.h>
#include "sort.h"
/**
* shell_sort - sorts an array of integers in ascending order
* using the Shell sort algorithm
* @array: array of integers
* @size: size of array
*/
void shell_sort(int *array, size_t size)
{
	size_t interval = 1;
	size_t i, j;
	int key;

	while (interval <= size / 3)
	{
		interval = interval * 3 + 1;
	}
	while (interval > 0)
	{
		for (i = interval; i < size; i++)
		{
			key = array[i];
			j = i;

			while (j >= interval && array[j - interval] > key)
			{
				array[j] = array[j - interval];
				j -= interval;
			}
			array[j] = key;
		}
		print_array(array, size);
		interval = (interval - 1) / 3;
	}
}
