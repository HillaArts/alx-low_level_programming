#include <stdio.h>

/**
 * main - entry point
 *
 * Return: always 0
 */

int main(void)
{
	char n;
	int i;

	for (i = 0 ; i < 10 ; i++)
		putchar(i + '0');
	for (n = 'a' ; n <= 'f' ; n++)
		putchar(n);
	putchar('\n');
	return (0);
}
