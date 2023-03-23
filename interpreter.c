#include "monty.h"

/**
 * main - program entry
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 or 1
 */

stack_t *top_stack;
char *opcode_arg;
int status;

int main(int argc, char **argv)
{
	int i, status;

	size_t buffer_size, current_line;

	ssize_t total_read;

	FILE *fdin;

	char *monty_file, *buffer, *delimiter, *token;

	instruction_t opcode_cmd[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	monty_file = argv[1];
	fdin = fopen(monty_file, "r");
	if (fdin == NULL)
	{
		printf("Error: Can't open file %s\n", monty_file);
		exit(EXIT_FAILURE);
	}
	current_line = 1;
	buffer_size = 0;
	buffer = NULL;
	delimiter = " \n";
	token = NULL;
	status = 1;
	while ((total_read = getline(&buffer, &buffer_size, fdin)) != -1)
	{
		token = strtok(buffer, delimiter);
		i = 0;
		while (opcode_cmd[i].opcode != NULL)
		{
			if ((strcmp(opcode_cmd[i].opcode, token)) == 0)
			{
				status = 0;
				opcode_arg = strtok(NULL, delimiter);
			       	opcode_cmd[i].f(&top_stack, current_line);
				break;
			}
			i++;
		}	
		if (status != 0)
		{
			printf("L%ld: unknown instruction %s\n", current_line, token);
			free(buffer);
			exit(EXIT_FAILURE);
		}
		current_line++;
	}
	free(buffer);
	fclose(fdin);
	return (EXIT_SUCCESS);
}

