#include "monty.h"

/**
 * stack_operation_delete - this deletes the last node of the stack
 * @head: Double pointer to the head node of the stack
 * Return: NULL or new address
 */

stack_t *stack_operation_delete(stack_t **head)
{
	stack_t *prevNode = NULL;
	stack_t *current = *head;

	if (current == NULL)
		return (NULL);

	while (current->next != NULL)
		current = current->next;

	if (current->prev == NULL)
	{
		glob.TSO1 = -99;
		glob.TSO2 = -99;
		glob.top = NULL;
		glob.bottom = NULL;
		free(current);
		*head = NULL;
	}
	else
	{
		prevNode = current->prev;
		prevNode->next = current->next;
		glob.TSO1 = prevNode->n;

		if (prevNode->prev != NULL)
			glob.TSO2 = prevNode->prev->n;

		glob.top = prevNode;
		glob.bottom = prevNode->prev;

		free(current);
	}

	return (prevNode);
}
