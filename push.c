#include "monty.h"

/**
 * push - pushes an element to the top of stack.
 * @stack: address node of the top element in the stack
 * @line_number: current instruction like number in the .m file
 * Return: EXIT_SUCCESS OR EXIT_FAILURE
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *push_data;

	int converted_op_arg;

	converted_op_arg = atoi(opcode_arg);
	if ((strcmp(opcode_arg, "0") != 0) && (converted_op_arg == 0))
	{
		printf("L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	push_data = malloc(sizeof(stack_t));
	if (!push_data)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (*stack == NULL)
	{
		push_data->n = converted_op_arg;
		push_data->prev = *stack;
		push_data->next = NULL;
		*stack = push_data;
	}
	else
	{
		push_data->n = converted_op_arg;
		push_data->prev = *stack;
		push_data->next = NULL;
		(*stack)->next = push_data;
		*stack = push_data;
	}
}

