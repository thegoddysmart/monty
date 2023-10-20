#include "monty.h"

/**
 * swap_op - this swaps the top two items in the stack
 * @stack: The stack itself
 * @line_number: This is where command is
 * Return: Always Void
 */

void swap_op(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack, *temp = NULL;

	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_all_data();
		exit(EXIT_FAILURE);
	}

	while (current->next != NULL)
		current = current->next;

	temp = current->prev;
	temp->next = current->next;
	current->prev = temp->prev;
	current->next = temp;
	temp->prev = current;
}


/**
 * nop_op - this does nothing
 * @stack: The stack itself
 * @line_number: this is where command is
 * Return: Always Void
 */

void nop_op(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}


/**
 * mod_op - computes the rest of the division of the second top
 * element of the stack by the top element of the stack
 * @stack: The stack itself
 * @line_number: this is where command is
 * Return: Always Void
 */

void mod_op(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	int val = 0;

	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_all_data();
		exit(EXIT_FAILURE);
	}

	while (current->next != NULL)
		current = current->next;

	val = (current->prev->n % current->n);
	current->prev->n = val;
	delete_stack_node(stack);
}
