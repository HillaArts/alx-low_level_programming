#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * insert_nodeint_at_index - inserrts new node at given position
 * @head: pointer to head of linked list
 * @idx: index of list where it should be added
 * @n: value of new code
 *
 * Return: address of new node || NULL if failed
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node, *current_node;
	unsigned int k;

	/*check head if NULL*/
	if (head == NULL || idx == 0)
		return (add_nodeint_end(head, n));

	/*traverse list until index is reached*/
	current_node = *head;
	for (k = 0; k < idx - 1 && current_node->next != NULL; k++)
		current_node = current_node->next;

	/*check index out of range*/
	if (current_node == NULL)
		return (NULL);

	/*adding new node to list*/
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	new_node->next = current_node->next;
	current_node->next = new_node;

	return (new_node);
}
