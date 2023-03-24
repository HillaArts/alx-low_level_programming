#include "3-calc.h"
#include <stdlib.h>
#include <stdio.h>

/**
  * op_add - add function
  * @a: parameter a
  * @b: parameter b
  *
  * Return: success
  */
int op_add(int a, int b)
{
	return (a + b);
}

/**
  * op_sub - subtract function
  * @a: parameter a
  * @b: parameter b
  *
  * Return: success
  */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
  * op_mul - multiplication function
  * @a: parameter a
  * @b: parameter b
  *
  * Return: success
  */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
  * op_div - division function
  * @a: parameter a
  * @b: parameter b
  *
  * Return: success
  */
int op_div(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	return (a / b);
}

/**
  * op_mod - modulus function
  * @a: parameter a
  * @b: parameter b
  *
  * Return: remainder
  */
int op_mod(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	return (a % b);
}
