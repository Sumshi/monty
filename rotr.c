#include "monty.h"
/**
 * rotr - rotates the stack to the bottom
 * @stack: double pointer to the head of stack
 * @line_number: the line number
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *bottom;
	stack_t *prev;

	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	bottom = *stack;

	while (bottom->next != NULL)
		bottom = bottom->next;

	prev = bottom->prev;
		bottom->next = *stack;
	bottom->prev = NULL;
	prev->next = NULL;
	(*stack)->prev = bottom;
	*stack = bottom;
}
