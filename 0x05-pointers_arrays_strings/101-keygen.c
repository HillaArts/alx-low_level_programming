#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 32

/**
 * main - main function
 *
 * Return: always 0
 */

int main(void)
{
	char password[PASSWORD_LENGTH + 1] = {0};
	char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	int charset_length = sizeof(charset) - 1;

	srand(time(NULL));

	for (int i = 0; i < PASSWORD_LENGTH; i++)
	{
		password[i] = charset[rand() % charset_length];
	}

	printf("%s\n", password);

	return (0);
}
