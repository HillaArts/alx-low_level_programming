#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * *create_array - creates an array of chars
 * @size: the parameter one
 * @c: the parameter one
 *
 * Return: return NULL if size is 0
 */

char *create_array(unsigned int size, char c)
{
	unsigned int y;
	char *ar;

	if (size == 0)
	{
		return (NULL);
	}

	ar = malloc(sizeof(char) * size);

	if (ar == NULL)
	{
		return (NULL);
	}

	for (y = 0; y < size; y++)
	{
		ar[y] = c;
	}

	return (ar);
}
