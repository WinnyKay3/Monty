#include "monty.h"
#include <stdio.h>
#include <sys/types.h>
#include <strings.h>
#include <unistd.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024


/* Function prototype for line parsing */
void parseLine(char *line, stack_t **stack, unsigned int line_number);

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 *
 * Return: 0 on success, or exit with failure on error.
 */

int main(int argc, char *argv[])
{
	FILE *file;
	char line[MAX_LINE_LENGTH];
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, MAX_LINE_LENGTH, file) != NULL)
	{
		line_number++;
		line[strcspn(line, "$")] = '\0';
		parseLine(line, &stack, line_number);
	}

	fclose(file);
	while (stack != NULL)
	{

		stack_t *temp = stack;

		stack = stack->next;

		free(temp);
	}
	return (0);
}
