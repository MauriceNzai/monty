#include "monty.h"

/**
 * swap - swaps the top two elements of a stack
 * @stack: stack_t whose elements to swap
 * @line_number: position of swaped element
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	tmp = *stack;
	if (tmp == NULL || (tmp->next == NULL && tmp->prev == NULL))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp->prev = tmp->next;
	tmp->next->prev = NULL;
	tmp->next = tmp->next->next;
	tmp->prev->next = tmp;
	(*stack) = tmp->prev;
}
