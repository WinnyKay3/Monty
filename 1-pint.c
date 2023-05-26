#include "monty.h"

/**
 * pint - prints the value at the top of stack
 * @stack: points to the head of the stack
 * @line_number: number of lines
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack)
		printf("%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}
