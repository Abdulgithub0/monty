#include "monty.h"

/**
 * opcode_cmd_selector - clean, parser, and call
 * opcode command with argument.
 * @raw_buffer: address of pointer to single
 * line of chars read by getline func.
 * @current_line: current line number of fdin.
 * Return: void
 */

char *opcode_arg;

void opcode_cmd_selector(char *raw_buffer, unsigned int current_line)
{
	char *opcode_cmd, *delimiter;

	int i;

	instruction_t listof_op_cmd[] = {
		{"push", push}, {"pall", pall},
		{"pint", pint},	{"pop", pop},
		{"swap", swap}, {"add", add},
		{"nop", nop}, {NULL, NULL}
	};
	delimiter = "\n $";
	opcode_cmd = strtok(raw_buffer, delimiter);
	opcode_arg = strtok(NULL, delimiter);
	i = 0;
	if (opcode_cmd)
	while (listof_op_cmd[i].opcode != NULL)
	{
		if ((strcmp(listof_op_cmd[i].opcode, opcode_cmd)) == 0)
		{
			listof_op_cmd[i].f(&top_stack, current_line);
			return;
		}
		i++;
	}
	if (opcode_arg != NULL || listof_op_cmd[i].opcode == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n",
				current_line, opcode_cmd);
		free(raw_buffer);
		free_dlist();
		exit(EXIT_FAILURE);
	}
}
