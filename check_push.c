#include "monty.h"

/**
 * check_push - Checks the push entry
 * @st: stack_t to check from
 * @cmds: value to check
 * @ln: position of value
 */

void check_push(stack_t **st, char **cmds, unsigned int ln)
{
	int i = 0, b = 0;
	char *cmds1;

	if (cmds[1] == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", ln);
		free(cmds), freestack(st);
		exit(EXIT_FAILURE);
	}
	cmds1 = cmds[1];
	while (cmds1[i] != '\0')
	{
		if (cmds1[0] == '-' && b == 0)
			i++, b = 1;
		if (_isdigit(cmds1[i]) == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", ln);
			free(cmds), freestack(st);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	push(st, atoi(cmds1));
}
