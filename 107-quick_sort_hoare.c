#include "sort.h"

/**
 * quick_sort - sort array with quick_sort algorithm
 *
 * @array: is the array to sort
 * @size: size of the array to sort
 *
 * Return: Nothing
 */


void quick_sort_hoare(int *array, size_t size)
{
	int first, last;

	if (size < 2)
		return;

	/* set the first and last position*/
	first = 0;
	last = size - 1;

	/* call the quick_sort function recursive*/
	quick_sort_hoare_r(array, first, last, size);

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

void quick_sort_hoare_r(int *array, int first, int last, size_t size)
{
	int pivot;


	if (first < last)
	{
		pivot = partition(array, first, last, size);
		/*sort the left part*/
		quick_sort_hoare_r(array, first, pivot, size);
		/*sort the rigth part*/
		quick_sort_hoare_r(array, pivot + 1, last, size);
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
	j = last + 1;

	while (1)
	{
		do
		{
			i++;
		} while (array[i] < pivot);
	
		do
		{
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);

		/*swap elements*/
		printf("first es %d last es %d i es %d j es %d\n", first, last, i, j);
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		print_array(array, size);
	}
	
	print_array(array, size);
}
