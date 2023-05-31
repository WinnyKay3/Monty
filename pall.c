#include "monty.h"
/**
 * pall - prints all values on the stack
 * @stack: points to the head of the stack
 * @line_number: number of lines in the file
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current)
	{
		printf("%i\n", current->n);
		current = current->next;
	}
}
