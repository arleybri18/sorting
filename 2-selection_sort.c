#include "sort.h"

/**
 * selection_sort - implement selection sort algorithm
 *
 * @array: array to sort
 * @size: size of the array
 *
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, j, min;
	int temp = 0, n = size;

	/*iterate over array*/
	for (i = 0; i < size - 1; i++)
	{
		/*set the i like min position*/
		min = i;
		/* iterate seraching the min value*/
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				/*set the min position found*/
				min = j;
			}
		}
		/* validate if min position is different fo i*/
		if (min != i)
		{
			/* swap positions*/
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
			print_array(array, n);
		}
	}

}
