/**
 ** op_div - Div the second value from the top of stack_t
 ** @stack: ptr to top mode of stack_t ll.
 ** @line_number: line number of a bytecodes file.
 ** Desc: The result is stored in the second value node
 **/

void op_div(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "div"));
		return;
	}
	if ((*stack)->next->n == 0)
	{
		set_op_tok_error(div_error(line_number));
		return;
	}
	(*stack)->next->next->n /= (*stack)->next->n;
	pop_op(stack, line_number);
}
