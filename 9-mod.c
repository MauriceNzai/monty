#include "monty.h"

/**
 * div - gets reminder of division second top element by the top element
 * @stack: stack_t variable from which to divied elements
 * @line_number: Position in stack
 */

void mod(stack_t **stack, unsigned int line_number)
{
	unsigned int result;
	(void)line_number;

	if ((*stack == NULL) || ((*stack)->next == NULL && (*stack)->prev == NULL))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n / (*stack)->n;

	pop(stack, 0);
	pop(stack, 0);
	push(stack, result);
}
