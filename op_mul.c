/**
 ** op_mul - multiplies the top element to the second top element of the stack
 ** @doubly: head of the linked list
 ** @cline: line number
 ** Return: void alw
 **/

void op_mul(stack_t **doubly, unsigned int line_number)
{
	if (var.stack_len < 2)
	{
		dprintf(STDOUT_FILENO, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*doubly)->next->n *= (*doubly)->n;
	_pop(doubly, line_number);
}
