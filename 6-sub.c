#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * sub - subtracts the first two nodes of the stack
 * @stack: the stack given by the main
 * @line_cnt: the line counter
 *
 * Return: void
 */
void_sub(stack_t **stack, unsigned int line_cnt)
{
	int value;
	
	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: cant sub, stack too short\n",line_cnt);
		status = EXIT_FAILURE;
		return;
	}
	value = ((*stack)->next->n) - ((*stack)->n);
	pop(stack, line_cnt);
	(*stack)->n = value;
}
