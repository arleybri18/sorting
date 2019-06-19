#include "sort.h"
/**
 * shell_sort - Implementing shell sort algorithm with Knuth sequence
 *
 * @array: array to sort
 * @size: size of the array
 *
 * Return: Nothing, print the array sort
 **/

void shell_sort(int *array, size_t size)
{
	int gap, i, j, n, temp;

	n = size;
	/*n + 1 = n *3 + 1, change n for gap and find gap*/
	gap = (size / 3);
	/*start for with gap +1, decrement gap / 3*/
	gap += 1;
	for (; gap > 0; gap = gap / 3)
	{
		/* iterate from gap to right part of the array*/
		for (i = gap; i < n; i++)
		{
			/* save value to compare */
			temp = array[i];
			/* compare with the left part of the array*/
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				/*change value for greather value founded*/
				array[j] = array[j - gap];
			}
			/* move the value temp to pos j, value less*/
			array[j] = temp;
		}
		print_array(array, size);
	}
}
