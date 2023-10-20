#include "monty.h"

/**
 ** op_mul - multiplies the top element to the second top element of the stack
 ** @doubly: head of the linked list
 ** @line_number: line number
 ** Return: void alw
 **/

void op_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	stack_t *second = top->next;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_all_data();
		exit(EXIT_FAILURE);
	}
		
	while (top->next)
		top = top->next;

	second->n *= top->n;

	delete_stack_node(stack);
}
