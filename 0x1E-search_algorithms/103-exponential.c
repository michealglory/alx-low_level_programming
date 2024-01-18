#include "search_algos.h"

int binary_search_helper(int *array, int value,
			 size_t low, size_t high);
size_t min(size_t a, size_t b);

/**
 * min - returns the minimum of two size_t values
 * @a: first value
 * @b: second value
 *
 * Return: `a` if lower or equal to `b`, `b` otherwise
 */
size_t min(size_t a, size_t b)
{
	return (a <= b ? a : b);
}

/**
 * binary_search_helper - Helper function for binary search algorithm.
 *
 * @array: Pointer to the first element of the array.
 * @value: Value to search for in the array.
 * @low: The starting index for the search.
 * @high: The ending index for the search.
 *
 * Return: Index of the value if found, otherwise -1.
 */

int binary_search_helper(int *array, int value,
			 size_t low, size_t high)
{
	size_t mid, i;

	if (!array)
		return (-1);

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
			return ((int)mid);
	}

	return (-1);
}

/**
 * exponential_search - Searches for a value in a sorted array using
 * exponential search algorithm.
 *
 * @array: Pointer to the first element of the sorted array.
 * @size: Number of elements in the array.
 * @value: Value to search for in the array.
 *
 * Return: Index of the value if found, otherwise -1.
 */

int exponential_search(int *array, size_t size, int value)
{
	size_t low, high, e_bound = 1;

	if (!array || size == 0)
		return (-1);

	while (e_bound < size && array[e_bound] < value)
	{
		printf("Value checked array[%lu] = [%d]\n",
		       e_bound, array[e_bound]);
		e_bound *= 2;
	}

	low = e_bound / 2;
	high = min(e_bound, size - 1);

	printf("Value found between indexes [%lu] and [%lu]\n", low, high);
	return (binary_search_helper(array, value, low, high));
}
