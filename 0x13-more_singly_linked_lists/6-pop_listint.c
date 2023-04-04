#include "lists.h"

/**
 * pop_listint - Deletes the head node of a listint_t linked list.
 * @head: A pointer to a pointer to the first node of the list.
 * Return: The data (n) of the deleted node, or 0 if the list is empty.
 */
int pop_listint(listint_t **head)
{
	int deleted_data;

	listint_t *temp;

	if (*head == NULL)
	return (0);

	temp = *head;
	deleted_data = temp->n;
	*head = (*head)->next;
	free(temp);

	return (deleted_data);
}
