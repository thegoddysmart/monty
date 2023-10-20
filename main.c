#include "monty.h"

/**
 * main - Entry Point of the Monty interpreter
 * @argc: Argument counter
 * @argv: Argument vector
 * Return: Always 0 on success, 1 on failure
 */

int main(int argc, char **argv)
{
	char **all_lines = NULL;

	instruction_t ops_array[] = {
		{"push", push_op},
		{"pop", pop_op},
		{"pall", pall_op},
		{"pint", pint_op},
		{"swap", swap_op},
		{"add", op_add},
		{"nop", nop_op},
		{NULL, NULL}};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	glob.TOS1 = -99;
	all_lines = reader(argv[1]);
	glob.all_lines = all_lines;

	execute_opcode(ops_array, all_lines);

	return (0);
}
