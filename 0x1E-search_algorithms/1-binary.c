#include "search_algos.h"

/**
 * binary_search - Searches for a value in a sorted array using binary
 * search algorithm.
 *
 * @array: Pointer to the first element of the sorted array.
 * @size: Number of elements in the array.
 * @value: Value to search for in the array.
 *
 * Return: Index of the value if found, otherwise -1.
 */

int binary_search(int *array, size_t size, int value)
{
	int low, mid, high;
	int i;

	if (array == NULL)
	{
		return (-1);
	}

	low = 0;
	high = size - 1;

	while (low <= high)
	{
		mid = (low + high) / 2;

		printf("Searching in array: ");
		for (i = low; i <= high; i++)
			printf("%i%s", array[i], i == high ? "\n" : ", ");

		if (array[mid] < value)
			low = mid + 1;
		else if (array[mid] > value)
			high = mid - 1;
		else
			return (mid);
	}

	return (-1);
}
