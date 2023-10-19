/**
 ** op_sub - subtract top element of stack from next element and push result
 ** @stack: The Stack
 ** @line_number: Line of the command
 ** Return: Always Void
 **/

void op_sub(stack_t **stack, unsigned int line_number)
{
	if (var.stack_len < 2)
	{
		dprintf(STDOUT_FILENO, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->prev->n -= (*stack)->n;
	del_dnodeint_end(stack);
}
