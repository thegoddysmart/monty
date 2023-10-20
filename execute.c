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


/**
 * reader - this reads all lines from a file
 * @argv: filename
 * Return: An array of all lines
 */

char **reader(char *argv)
{
	FILE *fileptr;
	size_t bufsize = 1;
	ssize_t char_read = 0;
	char **lines_array = NULL, *line_buffer = NULL, *temp;
	int line_count = 0, total_lines = 0;

	fileptr = fopen(argv, "r");
	if (fileptr == NULL)
		handle_file_err(argv);
	while (getline(&line_buffer, &bufsize, fileptr) != -1)
		total_lines++;
	fclose(fileptr);
	lines_array = malloc(sizeof(char *) * (total_lines + 1));
	if (lines_array == NULL)
		malloc_error();

	fileptr = fopen(argv, "r");
	while ((char_read = getline(&line_buffer, &bufsize, fileptr)) != -1)
	{
		temp = strtok(line_buffer, "\n");
		if (temp == NULL)
			continue;

		lines_array[line_count] = dup_str(temp);
		line_count++;
	}
	lines_array[line_count] = NULL;
	fclose(fileptr);
	if (char_read == -1)
		free(line_buffer);
	return (lines_array);
}
