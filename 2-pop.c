#include "monty.h"
/**
 * pop - removes the op character of the stack
 * @stack: points to the head of the stack
 * @line_number: number of lines in the file
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;
		free(temp);
	}
	else
	{
		fprintf(stderr, "L%u: cant pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
}
