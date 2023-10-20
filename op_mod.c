#include "monty.h"

/**
 ** op_mod - Calculates the modulus of a stack_t ll
 ** @stack: A ptr to the top mode node
 ** @line_number: The current line no. of a Monty bytecodes file.
 **/
void op_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;                                                                                                                  stack_t *prev = top;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_all_data();
		exit(EXIT_FAILURE);
	}

	while (top->next)
	{
		prev = top;
		top = top->next;
	}
	if (top->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_all_data();
		exit(EXIT_FAILURE);
	}
	prev->n = prev->n % top->n;
	delete_stack_node(stack);
}
