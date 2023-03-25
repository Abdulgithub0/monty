#include "monty.h"

/**
 * nop - The opcode nop doesn’t do anything.
 * @stack: pointer to pointer of top node
 * @line_number: current .m file line number or position
 * Return: void
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
