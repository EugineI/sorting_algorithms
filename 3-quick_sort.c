#include"sort.h"
/**
 * swap - swaps array elements
 * @a: first element
 * @b: second element
 * Return: nothing
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * partition - lomuto scheme
 * @array: array to sort
 * @low: start of partition
 * @high: end
 * @size: total size or array
 * Return: pivot element
 */
int partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high], i = low, j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != high)
	{
		swap(&array[i], &array[high]);
		print_array(array, size);
	}
	return (i);
}
/**
 * quick_sort_recursive - quicksort
 * @array: array to be sorted
 * @low: starting index
 * @high: ending index
 * @size: size of array
 * Return: nothing
 */
void quick_sort_recursive(int *array, size_t size, int low, int high)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, size, low, high);
		quick_sort_recursive(array, size, low, pivot - 1);
		quick_sort_recursive(array, size, pivot + 1, high);
	}
}
/**
 * quick_sort - quick sort
 * @array: array to b sorted
 * @size: size of array
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, size, 0, size - 1);
}
