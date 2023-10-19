#include "monty.h"

/**
 * add_stack_node - Adds a node to the top
 * of the stack (end of the list)
 * @stack: Double pointer to the stack's top node
 * @n: New member value
 * Return: NULL or the new node address
 */

stack_t *add_stack_node(stack_t **stack, const int value)
{
	stack_t *newNode = NULL;
	stack_t *currentNode = *stack;

	newNode = malloc(sizeof(stack_t));
	if (!newNode)
	{
		free_all_data();
		malloc_error();
	}

	newNode->n = n;

	if (*stack == NULL)
	{
		newNode->prev = *stack;
		newNode->next = NULL;
		*stack = newNode;
		global.TOS1 = newNode->n;
		global.stack_top = newNode;
		global.stack_bottom = newNode->prev;
	}
	else
	{
		while (currentNode->next != NULL)
			currentNode = currentNode->next;

		newNode->prev = currentNode;
		currentNode->next = newNode;
		newNode->next = NULL;

		global.TOS1 = newNode->n;
		global.TOS2 = newNode->prev->n;
		global.stack_top = newNode;
		global.stack_bottom = newNode->prev;
	}

	return (newNode);
}
