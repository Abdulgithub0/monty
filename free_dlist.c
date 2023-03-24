#include "monty.h"

/**
 * free_dlist - free stack_t structure
 * Return: void
 */

void free_dlist(void)
{
	stack_t *current;

	current = top_stack;
	while (top_stack)
	{
		current = top_stack->prev;
		free(top_stack);
		top_stack = current;
	}
}
