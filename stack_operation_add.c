#include "monty.h"

/**
 * add_stack_node - this adds a node to the top
 * of the stack
 * @stack: Double pointer to the stack's top node
 * @n: New member value
 * Return: NULL or the new node address
 */

stack_t *add_stack_node(stack_t **stack, const int n)
{
	stack_t *newNode = NULL;
	stack_t *currentNode = *stack;

	newNode = malloc(sizeof(stack_t));
	if (!newNode)
	{
		free_all_data();
		malloc_error(); /*yet to implement */
	}

	newNode->n = n;

	if (*stack == NULL)
	{
		newNode->prev = *stack;
		newNode->next = NULL;
		*stack = newNode;
		glob.TOS1 = newNode->n;
		glob.top = newNode;
		glob.bottom = newNode->prev;
	}
	else
	{
		while (currentNode->next != NULL)
			currentNode = currentNode->next;

		newNode->prev = currentNode;
		currentNode->next = newNode;
		newNode->next = NULL;

		glob.TOS1 = newNode->n;
		glob.TOS2 = newNode->prev->n;
		glob.top = newNode;
		glob.bottom = newNode->prev;
	}

	return (newNode);
}
