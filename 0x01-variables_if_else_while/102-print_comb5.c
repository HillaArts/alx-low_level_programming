#include <stdio.h>
/**
 * main - main function
 *
 * Return: always 0
 */
int main(void)
{
	int i;
	int j;
	for (i = 0 ; i < 100 ; i++)
	{
		for (j = i ; j < 100 ; j++)
			if (i != j)
			{
				putchar('0' + i / 10);
				putchar('0' + i % 10);
				putchar(',');
				putchar(' ');
				putchar('0' + j / 10);
				putchar('0' + j % 10);
				putchar(',');
				putchar(' ');
			}
	}
	putchar('\n')
	return (0);
}
