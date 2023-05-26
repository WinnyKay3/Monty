#include <stdio.h>
#include "monty.h"
#include <ctype.h>

/**
 * _add - adds the first two nodes of the stack
 * @stack: the stack given by main
 * @line_cnt: the line counter
 *
 * Return: void
 */
void _add(stack_t **stack, unsigned int line_cnt)
{
	stack_t *temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_cnt);
		exit(EXIT_FAILURE);
		return;
	}
	(*stack)->next->n += (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}
