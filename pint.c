#include "monty.h"

/**
 * pint - prints the value at the top of the stack, followed by a new line.
 * @stack: pointer to pointer of top node
 * @line_number: current .m file line number or position
 * Return: void
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack)
	{
		printf("%d\n", (*stack)->n);
		return;
	}
	dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
	exit(EXIT_FAILURE);
}
