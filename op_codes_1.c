#include "monty.h"

/**
 * push_op - this pushes an item onto the stack
 * @stack: The stack itself
 * @line_number: this is where the command is
 * Return: Always void
 */

void push_op(stack_t **stack, unsigned int line_number)
{
	int val = 0;

	(void)stack;
	(void)line_number;

	if (glob.arg[1] == NULL || (_atoi(glob.arg[1]) == -99))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_all_data();
		exit(EXIT_FAILURE);
	}

	val = _atoi(glob.arg[1]);
	add_stack_node(stack, val);
}


/**
 * pop_op - this pops the top item from the stack
 * @stack: The stack itself
 * @line_number: this is where the command is
 * Return: Always void
 */

void pop_op(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		free_all_data();
		exit(EXIT_FAILURE);
	}
	stack_operation_delete(stack);
}


/**
 * pall_op - this prints all items in the stack
 * @stack: The stack itself
 * @line_number: this is where command is
 * Return: Always Void
 */

void pall_op(stack_t **stack, unsigned int line_number)
{
	stack_t *top = NULL, *current = NULL;

	(void)line_number;

	if (*stack == NULL)
		return;

	current = *stack;

	while (current->next != NULL)
		current = current->next;

	top = current;

	while (top != NULL)
	{
		printf("%d\n", top->n);
		top = top->prev;
	}
}


/**
 * pint_op - this prints the top item in the stack
 * @stack: The stack itself
 * @line_number: this is where command is
 * Return: Always Void
 */

void pint_op(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	if (glob.TOS1 == -99)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_all_data();
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", glob.TOS1);
}
