#include "main.h"

/**
 * get_bit - function that retrieved a bit from unsigned
 * long int number given the index.
 * @n: unsigned lng integer etracting the bit value.
 * @index: unsigned int, index of the it.
 * Return: 1
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int mask = 1UL << index;

	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	if ((n & mask) == 0)
		return (0);

	else
		return (1);
}

