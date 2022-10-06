#include "monty.h"

/**
 * pint - prints value of the top element
 * @stack: stack_t whose top is to be printed
 * @line_number: position of the item in stack
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
