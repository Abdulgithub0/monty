#include "monty.h"

/**
 * rotl - The opcode rotl rotates the stack to the top, top
 * element becomes the last and second top element becomes the first.
 * @stack: address node of the top element in the stack
 * @line_number: current instruction like number in the .m file
 * Return: EXIT_SUCCESS OR EXIT_FAILURE
 */

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *traveler, *new_top, *last_stack;

	(void) line_number;
	traveler = *stack;
	if (*stack)
	{
		traveler = *stack;
		new_top = traveler->prev;
		new_top->next = NULL;
		if (!new_top)
			return;
		while (traveler)
		{
			last_stack = traveler;
			traveler = traveler->prev;
		}
		traveler = *stack;
		traveler->next = last_stack;
		traveler->prev = NULL;
		last_stack->prev = traveler;
		*stack = new_top;
	}
}
