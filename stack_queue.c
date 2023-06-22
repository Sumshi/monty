#include "monty.h"
/**
 * f_stack - sets the format of the data to a stack (LIFO).
 * @stack: double pointer to the beginning of the stack/queue
 * @line_number: line number of current opcode
 */
void f_stack(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
}
/**
 * f_queue - sets the format of the data to a queue (FIFO).
 * @stack: double pointer to the beginning of the stack/queue
 * @line_number: line number of current opcode
 */
void f_queue(stack_t **stack, unsigned int line_number)
{
	stack_t *last = *stack;
	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	/* Traverse till end of list */
	while (last->next != NULL)
		last = last->next;

	/* Swap first and last nodes */
	(*stack)->prev = last;
	last->prev->next = NULL;
	last->next = (*stack);
	 (*stack)->prev = NULL;
	(*stack) = last;
}
