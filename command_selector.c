#include "monty.h"
#include <string.h>

void semi_clean_opcode(char **raw_op);

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
		{"pint", pint},	{NULL, NULL}
	};
	delimiter = "\n $";
	/*semi_clean_opcode(&raw_buffer);*/
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

/**
 * semi_clean_opcode - this function helpers to reduce
 * strtok delim argument to single delim char
 * @raw_op: unclean opcode read from fdin in the main function
 * Return: void
 */

void semi_clean_opcode(char **raw_op)
{
	char *s;

	int i, len;

	s = *raw_op;
	len = strlen(s);
	i = 0;
	while (s[i] != '\n')
	{
		if (s[i] == ' ' || s[i] == '\n' || s[i] == '$' || s[i] == '\0')
			s[i] = '$';
		i++;
	}
	if (s[len - 1] == '\n')
		s[len - 1] = '\0';
	*raw_op = s;
}

