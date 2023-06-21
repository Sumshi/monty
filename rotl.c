#include "monty.h"
/**
 * rotl - rotates the stack to the top
 * @stack: double pointer to the head of stack
 * @line_number: the line number
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *current, *last;

	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	current = *stack;
	last = *stack;

	while (last->next != NULL)
		last = last->next;

	*stack = current->next;
	current->next->prev = NULL;
	current->next = NULL;
	last->next = current;
	current->prev = last;
}
