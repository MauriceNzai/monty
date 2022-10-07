#include "monty.h"

/**
 * mul - multiplies second top element by the top element
 * @stack: stack_t variable from which to divied elements
 * @line_number: Position in stack
 */

void mul(stack_t **stack, unsigned int line_number)
{
	unsigned int result;

	if ((*stack == NULL) || ((*stack)->next == NULL && (*stack)->prev == NULL))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n / (*stack)->n;

	pop(stack, 0);
	pop(stack, 0);
	push(stack, result);
}
