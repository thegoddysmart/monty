#include "monty.h"

/**
 * malloc_error - this print malloc error
 * Return: void
 */

void malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}


/**
 * handle_not_found - this handles not found error
 * @all_lines: lines array to free
 * @index: this is the line number
 * @cmds: command not found
 */

void handle_not_found(char **all_lines, int index, char *cmds)
{
	printf("L%d: unknown instruction %s\n", index, cmds);
	free_str_array(all_lines);
	free_stack_nodes(&(glob.stack));
	exit(EXIT_FAILURE);
}
