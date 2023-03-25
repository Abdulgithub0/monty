#include "monty.h"

/**
 * _div -  divides the second top element of the
 * stack by the top element of the stack.
 * @stack: pointer to pointer of the address of the top element
 * @line_number: current reading line number in the file fdin
 * Return: void
 */

void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *new_top;

	if (*stack)
	{
		if ((*stack)->n == 0)
		{
			dprintf(STDERR_FILENO, "L%d: division by zero\n", line_number);
			free_dlist();
			exit(EXIT_FAILURE);
		}
		new_top = (*stack)->prev;
		if (new_top)
		{
			new_top->n /= (*stack)->n;
			free(*stack);
			*stack = new_top;
			return;
		}
		dprintf(STDERR_FILENO, "L%d: can't div, stack too short\n", line_number);
		free_dlist();
		exit(EXIT_FAILURE);
	}
	dprintf(STDERR_FILENO, "L%d: can't div, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}
