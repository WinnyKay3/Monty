#include "monty.h"

/**
 * rotl -it rotates the stack to the top
 * @stack: pointer to the head of the stack
 * @line_number: line number of the instructions in the Monty file
 */

void rotl(stack_t **stack, unsigned int line_number)
{

	stack_t *current;
	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	current = *stack;
	while (current->next != NULL)
		current = current->next;

	current->next = *stack;
	*stack = (*stack)->next;
	current->next->next = NULL;
}
