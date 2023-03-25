#include "monty.h"

/**
 * mul -  The opcode mul multiply the top two elements of the stack.
 * @stack: pointer to pointer of the address of the top element
 * @line_number: current reading line number in the file fdin
 * Return: void
 */

void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *new_top;

	if (*stack)
	{
		new_top = (*stack)->prev;
		if (new_top)
		{
			new_top->n *= (*stack)->n;
			free(*stack);
			*stack = new_top;
			return;
		}
		dprintf(STDERR_FILENO, "L%d: can't mul, stack too short\n", line_number);
		free_dlist();
		exit(EXIT_FAILURE);
	}
	dprintf(STDERR_FILENO, "L%d: can't mul, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}
