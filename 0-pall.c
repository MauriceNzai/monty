#include "monty.h"

/**
 * pall - prints all elements of the stack
 * @stack: stack_t whose elements are to be printed
 * @line_number: position of the element
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void)line_number;

	tmp = *stack;
	if (tmp == NULL)
		return;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
