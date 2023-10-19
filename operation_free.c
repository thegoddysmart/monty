#include "monty.h"

/**
 * free_str_array - this function frees an array of strings
 * @array: this is the pointer to the head of the array
 * Return: Always void
 */

void freeStringArray(char **array)
{
	int i = 0;

	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}


/**
 * free_stack_nodes - this free the nodes
 * @stack: Pointer to the head of the stack
 * Return: Always void
 */

void free_stack_nodes(stack_t **stack)
{
	stack_t *temp = NULL;

	while (*stack != NULL)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}


/**
 * free_all_data - this frees everything
 * Return: Always void
 */

void free_all_data(void)
{
	if (glob.all_lines != NULL)
	{
		free_str_array(glob.all_lines);
		glob.all_lines = NULL:
	}
	if (glob.stack != NULL)
	{
		free_stack_nodes(&(glob.stack));
		glob.stack = NULL;
	}
}
