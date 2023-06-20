#include "monty.h"
/**
 * sub - subtracts the top element of the stack from the second top element
 * @stack: double pointer to the head of the stack
 * @line_number: the current line number
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

/*checks if stack is empty or it has less than 2 elements*/
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		/*clean_stack(stack);*/
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	temp->n -= (*stack)->n;
	pop(stack, line_number);/*Remove the top element from the stack*/
}
