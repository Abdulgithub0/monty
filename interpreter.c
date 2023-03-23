#include "monty.h"

void opcode_cmd_selector(char **raw_buffer, unsigned int current_line);
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
	size_t buffer_size, current_line;

	ssize_t total_read;

	FILE *fdin;

	char *monty_file, *buffer;

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
	while ((total_read = getline(&buffer, &buffer_size, fdin)) != -1)
	{
		opcode_cmd_selector(&buffer, current_line);
		current_line++;
	}
	fclose(fdin);
	return (EXIT_SUCCESS);
}
