#include "sort.h"

/**
 * quick_sort - sort array with quick_sort algorithm
 *
 * @array: is the array to sort
 * @size: size of the array to sort
 *
 * Return: Nothing
 */

void quick_sort(int *array, size_t size)
{
	int first, last;

	/* set the first and last position*/
	first = 0;
	last = size - 1;

	/* call the quick_sort function recursive*/
	quick_sort_r(array, first, last, size);

}

/**
 * quick_sort_r  - sort recursively
 *
 * @array: array to sort
 * @first: first position to iterate
 * @last: last position to iterate
 * @size: size of the array to sort
 *
 * Return: Nothing
 *
 **/

void quick_sort_r(int *array, int first, int last, size_t size)
{
	int pivot;


	if (first < last)
	{
		pivot = partition(array, first, last, size);
		/*sort the rigth part*/
		quick_sort_r(array, pivot + 1, last, size);
		/*sort the left part*/
		quick_sort_r(array, first, pivot, size);
	}
}

/**
 * partition - implement Lomuto partition scheme and swap elements
 *
 *@array: array to partition
 *@first: first position of the array to sort
 *@last: last position of the array to sort
 *@size: size of the array to sort
 *
 *Return: position i new pivot for recursion
 */

int partition(int *array, int first, int last, size_t size)
{
	int pivot, i, j, temp;
	/* set the pivot last position*/
	pivot = array[last];
	/* set i before de first position*/
	i = first - 1;
	/* iterate from the first position to last -1 position*/
	for (j = first; j < last; j++)
	{
		if (array[j] < pivot)
		{
			/*swap elements*/
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (i != j)
				print_array(array, size);
		}
	}
	/*swap pivot*/
	temp = array[i + 1];
	array[i + 1] = pivot;
	array[last] = temp;
	if (last != i + 1)
		print_array(array, size);
	/*return i the new pivot position*/
	return (i);
}
