#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * get_nodeint_at_index - returns nth node of a listint_t
 * @head: pointer to head of the list
 * @index: index of node, starting at 0
 *
 * Return: NULL
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int k;
	listint_t *current = head;

	for (k = 0; k < index && current != NULL; k++)
		current = current->next;

	return (current == NULL ? NULL : current);
}
