/**
 ** op_mul - multiplies the top element to the second top element of the stack
 ** @doubly: head of the linked list
 ** @line_number: line number
 ** Return: void alw
 **/

void op_mul(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "mul"));
		return;
	}
	stack_t *second = (*stack)->next;
	stack_t *top = second->next;
	second->n *= top->n;
	second->next = top->next;

	if (top->next != NULL)
		top->next->prev = second;
	free(top);
}
