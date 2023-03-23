#include "monty.h"

/**
 * pall -prints all the values on the stack,
 * starting from the top of the stack
 * @stack: pointer to pointer of top node
 * @line_number: current .m file line number or position
 * Return: void
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *prev_display;

	(void) line_number;

	prev_display = *stack;
	while (prev_display)
	{
		printf("%d\n", prev_display->n);
		prev_display = prev_display->prev;
	}
}

