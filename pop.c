#include "monty.h"

/**
 * pop -  removes the top element of the stack.
 * @stack: pointer to pointer of the address of the top element
 * @line_number: current reading line number in the file fdin
 * Return: void
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *new_top;

	if (*stack)
	{
		new_top = (*stack)->prev;
		free(*stack);
		*stack = new_top;
		return;
	}
	dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_number);
	exit(EXIT_FAILURE);
}
