#include "monty.h"
/**
 * mod - computes the rest of the division of the second top element
 * @stack: double pointer to the head of the stack
 * @line_number: the current line number
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		/*_free(*stack);*/
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)/*checks if top element of stack is 0*/
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		/*_free(*stack);*/
		exit(EXIT_FAILURE);
	}
	result = ((*stack)->next->n) % ((*stack)->n);
	pop(stack, line_number);/*removes the top element*/
	(*stack)->n = result;
}
