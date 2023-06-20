#include "monty.h"
/**
 * mul - multiplies the second top element of the stack with the top element
 * @stack: double pointer to the head of the stack
 * @line_number: the current line number
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		_free(*stack);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	temp->n *= (*stack)->n;/*multiplies second top by top element*/

	pop(stack, line_number);/*removes top element from stack*/
}
