#include "monty.h"

/**
 * pop - removes top element of the stack
 * @stack: stack_t to remove top element from
 * @line_number: position of element in the stack
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	tmp = *stack;
	if ((tmp) == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (tmp->next == NULL)
	{
		(*stack) = NULL;
		free(tmp);
	}
	else
	{
		tmp = tmp->next;
		tmp->prev = NULL;
	}
}
