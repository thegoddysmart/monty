#include "monty.h"

/**
 ** op_add - adds both top elements of the stack
 ** @stack: double ptr to start of the stack
 ** @line_number: text line number
 ** Return: void always
 **/

void op_add(stack_t **stack, unsigned int line_number)
{
	stack_t *current_node = NULL;
	int addition_result = 0;

	current_node = *stack;

	if (current_node == NULL || current_node->next == NULL)
	{
		printf("L%d: can't add, stack too short\n", line_number);

		exit(EXIT_FAILURE);
	}
	addition_result = current_node->n + current_node->next->n;
	current_node->next->n = addition_result;

	pop_op(stack, line_number);
}
