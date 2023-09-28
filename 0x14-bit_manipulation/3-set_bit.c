#include "main.h"

/**
 * set_bit - Sets the value of a bit to 1 at a given index.
 *
 * @n: Pointer to the unsigned long integer in which to set the bit.
 * @index: The index, starting from 0, of the bit to set.
 *
 * Return: 1 if it worked, or -1 if an error occurred (if the index
 * is out of bounds).
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
	return (-1);

	*n |= (1UL << index);
	return (1);
}

