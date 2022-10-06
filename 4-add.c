#include "monty.h"

/**
 * add - adds the first two wlwments of a stack
 * @stack: stack_t whose two elements are to be added
 * @line_number: position of elements
 */

void add(stack_t **stack, unsigned int line_number)
{
	unsigned int sum;

	if ((*stack == NULL) || ((*stack)->next == NULL && (*stack)->prev == NULL))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->n + (*stack)->next->n;

	pop(stack, 0);
	pop(stack, 0);
	push(stack, sum);
}


