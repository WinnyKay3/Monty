#include <stdio.h>
#include "monty.h"
#include <ctype.h>

/**
 * _add - adds the first two nodes of the stack
 * @stack: the stack given by main
 * @line_number: the line number
 *
 * Return: void
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
		return;
	}
	(*stack)->next->n += (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}
