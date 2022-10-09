#include "monty.h"

/**
 * sub - Subtracts top element of stack from second top element
 * @stack: stack_t variable from which to get elements
 * @line_number: position in stack
 */

void sub(stack_t **stack, unsigned int line_number)
{
	unsigned int result;

	if ((*stack == NULL) || ((*stack)->next == NULL && (*stack)->prev == NULL))
	{
		fprintf(stderr, "L%d: can't sub, stack too shoort\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n - (*stack)->n;

	pop(stack, 0);
	pop(stack, 0);
	push(stack, result);
}
