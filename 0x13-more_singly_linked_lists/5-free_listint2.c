#include "lists.h"

/**
 * free_listint2 - frees the linked list
 * @head : pointer to list
 * Return: nothing
 */
void free_listint2(listint_t **head)
{
	listint_t *emp;

	if (head == NULL)
		return;
	while (*head)
	{
		emp = *head;
		*head = (*head)->next;
		free(emp);
	}
	head = NULL;
}
