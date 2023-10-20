#include "monty.h"

/**
 ** op_sub - subtract top element of stack from next element and push result
 ** @stack: The Stack
 ** @line_number: Line of the command
 ** Return: Always Void
 **/

void op_sub(stack_t **stack, unsigned int line_number)
{
	int diff = (*stack)->next->n - (*stack)->n;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	
	(*stack)->next->n = diff;
	pop_op(stack, line_number);
}
