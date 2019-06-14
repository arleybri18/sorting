#include "sort.h"

/**
 * bubble_sort - sort values if j value is greather than j+1
 *
 * @array: array to sort
 * @size: size of array
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int i, j;
	int temp = 0;
	int n = size;

	/* valdate size of array*/
	if (size > 2)
	{
		/* first for, decrease size*/
		for (i = 0; i < size; size--)
		{
			/* second for, move position over array*/
			for (j = 0; j < (size - 1); j++)
			{
				/* change vallues*/
				if (array[j] > array[j + 1])
				{
					temp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = temp;
					print_array(array, n);
				}
			}
		}
	}
}
