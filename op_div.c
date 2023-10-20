#include "monty.h"

/**
 ** op_div - Div the second value from the top of stack_t
 ** @stack: ptr to top mode of stack_t ll.
 ** @line_number: line number of a bytecodes file.
 ** Desc: The result is stored in the second value node
 **/

void op_div(stack_t **stack, unsigned int line_number)
{
	int numerator = (*stack)->n;                                                                                                            int denominator = (*stack)->next->n;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (denominator == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = denominator / numerator;
	pop_op(stack, line_number);

}
