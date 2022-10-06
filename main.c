#include "monty.h"

/**
 * main - entry point
 * @ac: numner of arguments
 * @av: array of pointers to arguments
 *
 * Return: 0
 */

int main(int ac, char **av)
{
	stack_t *st = NULL;
	char *buffer = NULL;
	size_t buff_size = 0;
	int line_count = 0;
	ssize_t line_size = 0;
	FILE *fp = NULL;

	if (ac != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);

	fp = fopen(av[1], "r");
	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	while ((line_size = getline(&buffer, &buff_size, fp)) != -1)
	{
		line_count++;
		if (buffer[0] != '#')
			is_opcode(buffer, &st, line_count);
	}

	free(buffer);
	freestack(&st);
	fclose(fp);
	return (0);
}

