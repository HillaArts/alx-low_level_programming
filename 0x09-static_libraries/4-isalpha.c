#include "main.h"

/**
 * _isalpha - checks all alphabetic characters
 *
 * @c: parameter to be checked
 *
 * Return: 1 if it is a letter
 * and 0 otherwise
 */

int _isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}
