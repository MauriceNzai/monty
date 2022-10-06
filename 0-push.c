#include "monty.h"

/**
 * push - pushes element to the stack
 * @stack: stack_t variable represents stack to push to
 * @number: int value to be pushed
 */

void push(stack_t **stack, unsigned int number)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		freestack(stack);
		exit(EXIT_FAILURE);
	}

	new->n = number;
	new->prev = NULL;
	new->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}
