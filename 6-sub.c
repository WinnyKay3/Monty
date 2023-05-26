#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * sub - subtracts the first two nodes of the stack
 * @stack: the stack given by the main
 * @line_cnt: the line counter
 *
 */
void sub(stack_t **stack, unsigned int line_cnt)
{
	stack_t *temp;
	
	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: cant sub, stack too short\n",line_cnt);
		exit(EXIT_FAILURE);
		return;
	}
	(*stack)->next->n -= (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}


