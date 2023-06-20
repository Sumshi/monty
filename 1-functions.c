#include "monty.h"

/**
 * pchar - adds the top two elements of the stack.
 * @stack: double pointer to the head of stack
 * @line_number: the line number
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n >= 0 && (*stack)->n <= 127)
		printf("%c\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		_free(*stack);
		exit(EXIT_FAILURE);
	}

}
