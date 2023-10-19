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
