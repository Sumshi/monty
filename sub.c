#include "monty.h"
/**
 * sub - substracts the top two elements of the stack.
 * @stack: double pointer to the head of the stack
 * @line_number: the line number
 */

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *val = NULL;
	int sum = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		_free(*stack);
		exit(EXIT_FAILURE);
	}
	val = (*stack)->next;
	sum = val->n;
	sum -= (*stack)->n;
	pop(stack, line_number);
	val->n = sum;
}
