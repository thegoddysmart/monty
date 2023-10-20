#include "monty.h"

/**
 * execute_opcode - Execute the opcode instructions
 * @opcodes_arr: Array of function and opcode
 * @all_lines: Array of pointers to lines
 * Return: Void
 */

void execute_opcode(instruction_t opcodes_arr[], char **all_lines)
{
	char *cmds[2] = {NULL, NULL};
	char *token = NULL;
	int index = 0, found = 0, i = 0;
	stack_t *stack_head = NULL;

	while (all_lines[index] != NULL)
	{
		i = 0, token = strtok(all_lines[index], " ");
		cmd[0] = token;
		token = strtok(NULL, " ");
		cmds[1] = token, glob.arg = cmds;

		for (i = 0; opcodes_arr[i].opcode != NULL; i++)
		{
			found = 0;
			if (strcmp(cmds[0], opcodes_arr[i].opcode) == 0)
			{
				opcodes_arr[i].f(&stack_head, index + 1);
				found = 1;
				break;
			}
		}
		glob.stack = stack_head;
		if (found == 0)
			handle_not_found(all_lines, index + 1, cmds[0]);
		index++;
	}
	free_all_data();
}
