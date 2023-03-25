#include "monty.h"

/**
 * swap -  The opcode swap swaps the top two elements of the stack.
 * @stack: pointer to pointer of the address of the top element
 * @line_number: current reading line number in the file fdin
 * Return: void
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *new_top;

	int tempo;

	if (*stack)
	{
		new_top = (*stack)->prev;
		if (new_top)
		{
			tempo = new_top->n;
			new_top->n = (*stack)->n;
			(*stack)->n = tempo;
			return;
		}
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", line_number);
		free_dlist();
		exit(EXIT_FAILURE);
	}
	dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", line_number);
	free_dlist();
	exit(EXIT_FAILURE);
}
