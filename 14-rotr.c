#include "monty.h"
/**
 * rotr -used to rotate the stack to the bottom.
 * @stack: A pointer to the top of te stack
 * @line_number: The line number being executed.
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	stack_t *prev = NULL;
	(void)line_number;

	if (current == NULL || current->next == NULL)
		return;

	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}

	prev->next = NULL;
	current->next = *stack;

	*stack = current;
}
