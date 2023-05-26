#include "monty.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**
 * push - pushes element to the stack
 * @stack: double pointer to the head of the stack
 * @line_number: number of lines
 */

void push(stack_t **stack, unsigned int line_number)
{
	char *arg = strtok(NULL, "\t\n");
	stack_t *new_node;

	if (arg == NULL || !is_integer(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr,"Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(arg);
	new_node->prev = NULL;
	
	if (*stack != NULL)
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
	else
	{
		new_node->next = NULL;
	}

	*stack = new_node;
}
