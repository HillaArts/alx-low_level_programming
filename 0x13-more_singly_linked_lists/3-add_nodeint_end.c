#include "lists.h"

/**
 * add_nodeint_end - adds a new node at the end of a listint_t list.
 * @head: pointer to a pointer to the head of the list.
 * @n: the integer to be stored in the new node.
 * Return: the address of the new element, or NULL if it failed.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *end_node, *temp;

	if (head == NULL)
		return (NULL);

	end_node = malloc(sizeof(listint_t));
	if (end_node == NULL)
		return (NULL);
	end_node->n = n;
	end_node->next = NULL;

	if (*head == NULL)
	{
	*head = end_node;
	}
		else
	{
	temp = *head;
	while (temp->next != NULL)
	{
	temp = temp->next;
	}
	temp->next = end_node;
	}
	return (end_node);
}

