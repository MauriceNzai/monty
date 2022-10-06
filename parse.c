#include "monty.h"

/**
 * parse - parses user input
 * @buffer: the input to parse
 *
 * Return: parsed commands (cmds)
 */

char **parse(char *buffer)
{
	char **cmds, *cmd, *delim;
	int i = 0;

	delim = "\t \n";
	cmds = malloc(sizeof(char *) * 3);
	if (cmds == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(buffer);
		exit(EXIT_FAILURE);
	}

	cmd = strtok(buffer, delim);
	while (cmd != NULL && i < 2)
	{
		cmds[i] = cmd;
		cmd = strtok(NULL, delim);
		i++;
	}
	cmds[i] = NULL;
	return (cmds);
}
