#include "monty.h"

/**
 * pstr - The opcode pchar prints the string starting
 * at the top of the stack, followed by a new line.
 * @stack: address node of the top element in the stack
 * @line_number: current instruction like number in the .m file
 * Return: EXIT_SUCCESS OR EXIT_FAILURE
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	int num;

	stack_t *traveler;

	(void) line_number;
	traveler = *stack;
	while (traveler)
	{
		num = traveler->n;
		if ((num > 0) && (num <= 127))
		{
			printf("%c", num);
			traveler = traveler->prev;
		}
		else
			break;
	}
	printf("\n");
}
