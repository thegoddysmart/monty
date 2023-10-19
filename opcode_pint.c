#include "monty.h"

/**
 ** opcode_pint - Pushes an item on the stack
 ** @stack: Stack
 ** @line_number: Line where command is
 ** Return: Void
 **/

#include "monty.h"

void opcode_pint(stack_t **stack, unsigned int line_number)
{
	if (var.stack_len == 0)
	{
		dprintf(STDOUT_FILENO, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
