#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    /*int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};*/
    int array[] = {143, 65, 106, 139, 99, 150, 112, 52, 45, 38, 113, 35, 34, 19, 135, 100, 130, 148, 147, 8, 72, 124, 36, 56, 54, 30, 109, 5, 75, 77, 129, 93, 63, 90, 132, 128, 133, 31, 71, 29, 67, 69, 103, 89, 6, 55, 111, 137, 62, 3}; 
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    bubble_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
