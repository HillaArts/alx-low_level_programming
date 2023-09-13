#include "function_pointers.h"

/**
 * int_index - Searches for an integer in an array
 *
 * @array: The array to search
 * @size: The size of the array
 * @cmp: The function to use to compare values
 *
 * Return: 0, -1
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array && cmp && size > 0)
	{
		for (i = 0; i < size; i++)
		{
			if (cmp(array[i]) != 0)
			{
				return (i);
			}
		}
	}

	return (-1);
}

