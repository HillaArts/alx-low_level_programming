#include "function_pointers.h"

/**
 * array_iterator - Executes a function on each element of an array
 *
 * @array: The array to iterate over
 * @size: The size of the array
 * @action: The function to execute on each element of the array
 *
 * Return: void
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (array && action)
	{
		for (i = 0; i < size; i++)
		{
			action(array[i]);
		}
	}
}
