#include <stdio.h>

/**
 * main - prints the sum of multiples of 3,5 upto 1024
 *
 * Return: always 0
 */

int main(void)
{
	int m, n = 0;

	while (m < 1024)
	{
		if ((m % 3 == 0) || (m % 5 == 0))
		{
			n += m;
		}

		m++;
	}

	printf("%d\n", n);
	return (0);
}
