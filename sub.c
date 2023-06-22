#include "monty.h"
/**
 * sub - substracts the top two elements of the stack.
 * @stack: double pointer to the head of the stack
 * @line_number: the line number
 */

void sub(stack_t **stack, unsigned int line_number)
{
	int result;

	/*checks if stack is empty or has more than 2 elements*/
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		/*_free(*stack);*/
		exit(EXIT_FAILURE);
	}
	result = ((*stack)->next->n) - ((*stack)->n);
	pop(stack, line_number);
	(*stack)->n = result;/*result is now new top of stack*/
}
