#include "lists.h"

/**
 * listint_len - returns the number of elements in a linked listint_t list.
 * @h: pointer to the head of the list.
 * Return: the number of nodes in the list.
 */
size_t listint_len(const listint_t *h)
{
	size_t thecount = 0;

	while (h != NULL)
	{
	thecount++;
	h = h->next;
	}
	return (thecount);
}

