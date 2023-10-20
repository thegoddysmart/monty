#include "monty.h"

/**
 ** op_add - adds both top elements of the stack
 ** @stack: double ptr to start of the stack
 ** @line_number: text line number
 ** Return: void always
 **/

void op_add(stack_t **stack, unsigned int line_number)
{
	if (var.stack_len < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	pop_op(stack, line_number);
}
