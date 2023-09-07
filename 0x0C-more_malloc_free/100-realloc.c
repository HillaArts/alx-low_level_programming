#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to reallocate memory
 * @old_size: size in bytes of allocated memory
 * @new_size: newsize of memory block in bytes
 * Return: void pointer to new allocation of memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;
	unsigned int j;

	if (ptr == NULL)
	{
		p = malloc(new_size);
		return (p);
	}
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (old_size == new_size)
		return (ptr);
	p = malloc(new_size);
	if (p == NULL)
		return (NULL);
	for (j = 0; j < old_size && j < new_size; j++)
		p[j] = ((char *)ptr)[j];
	free(ptr);
	return (p);
}

