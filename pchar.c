#include "monty.h"

/**
 * pchar - The opcode pchar prints the char
 * at the top of the stack, followed by a new line.
 * @stack: address node of the top element in the stack
 * @line_number: current instruction like number in the .m file
 * Return: EXIT_SUCCESS OR EXIT_FAILURE
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	int num;

	if (*stack)
	{
		num = (*stack)->n;
		if ((num >= 0) && (num <= 127))
		{
			printf("%c\n", num);
			return;
		}
		dprintf(STDERR_FILENO, "L%d: can't pchar, value out of range\n",
				line_number);
		free_dlist();
		exit(EXIT_FAILURE);
	}
	dprintf(STDERR_FILENO, "L%d: can't pchar, stack empty\n", line_number);
	exit(EXIT_FAILURE);
}
