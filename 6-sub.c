#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * sub - subtracts the first two nodes of the stack
 * @stack: the stack given by the main
 * @line_number: the line number
 *
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	
	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: cant sub, stack too short\n",line_number);
		exit(EXIT_FAILURE);
		return;
	}
	(*stack)->next->n -= (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}


