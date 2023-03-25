#include "monty.h"

/**
 * rotr - The opcode rotr rotates the stack to the bottom.
 * @stack: address node of the top element in the stack
 * @line_number: current instruction like number in the .m file
 * Return: EXIT_SUCCESS OR EXIT_FAILURE
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *traveler, *new_top, *last_stack;

	(void) line_number;
	traveler = *stack;
	if (*stack)
	{
		traveler = *stack;
		new_top = traveler->prev;
		if (!new_top)
			return;
		while (traveler)
		{
			last_stack = traveler;
			traveler = traveler->prev;
		}
		new_top = last_stack;
		last_stack->next->prev = NULL;
		new_top->prev = *stack;
		new_top->next = NULL;
		traveler = *stack;
		traveler->next = new_top;
		*stack = new_top;
	}
}
