#include "monty.h"

/**
 * is_opcode - checks for opcodes entry
 * @buff: the input to check
 * @st: stack_t variable to check from
 * @ln: unsigned int variable
 * Return: Nothing
 */

void is_opcode(char *buff, stack_t **st, unsigned int ln)
{
	char **cmds;
	instruction_t opts[] = {
		{"push", push}, {"pall", pall}, {"pint", pint}, {"pop", pop},
		{"swap", swap}, {"nop", nop}, {"add", add}, {"sub", sub},
		{"div", division}, {"mul", mul}, {"mod", mod},/* {"pchar", pchar},*/
		/* {"pstr", pstr},*/	{NULL, NULL}
	};
	int i = 0, j = 0, len, b = 0, len2;

	cmds = parse(buff);
	while (cmds[i] != NULL)
	{
		j = 0;
		while (opts[j].opcode != NULL)
		{
			len = strlen(opts[j].opcode);
			len2 = strlen(cmds[i]);

			if (strncmp(opts[j].opcode, cmds[i], len) == 0 &&
					strncmp(opts[j].opcode, cmds[i], len2) == 0)
			{b = 1;
				if (j == 0)
					check_push(st, cmds, ln);
				else
					opts[j].f(st, ln);
				break;
			}
			j++;
		}
		if (b == 0)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", ln, cmds[i]);
			free(cmds), freestack(st);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	free(cmds);
}
