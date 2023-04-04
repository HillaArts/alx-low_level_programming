#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * sum_listint - calculates sum of all data in listint inked list
 * @head: pointer to head of the list
 *
 * Return: sum of data in list || if empty
 */

int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *current = head;

	while (current != NULL)
	{
		sum += current->n;
		current = current->next;
	}

	return (sum);
}
