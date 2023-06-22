#include "monty.h"
/**
 * mul - multiplies the second top element of the stack with the top element
 * @stack: double pointer to the head of the stack
 * @line_number: the current line number
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		/*_free(*stack);*/
		exit(EXIT_FAILURE);
	}

	result = ((*stack)->next->n) * ((*stack)->n);
	pop(stack, line_number);/*removes top element from stack*/
	(*stack)->n = result;
}
