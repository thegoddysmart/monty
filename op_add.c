#include "monty.h"

/**
 ** opp_add - adds both top elements of the stack
 ** @stack: double ptr to start of the stack
 ** @line_number: text line number
 ** Return: void always
 **/

void opp_add(stack_t **stack, unsigned int line_number)
{
	if (var.stack_len < 2)
	{
		dprintf(STDOUT_FILENO, "L%u: can't add, stack too short\n", line_number);

		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;

	m_pop(stack, line_number);
}
