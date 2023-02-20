@@ -0,0 +1,17 @@
#include <stdio.h>

/**
 * main - function
 *
 * Return: always 0
 */

int main(void)
{
	char i;

	for (i = 'a' ; i <= 'z' ; i++)
		putchar(i);
	putchar('\n');
	return (0);
}
