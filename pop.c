#include "monty.h"
/**
 * pop - removes the top element of the stack.
 * @stack: double pointer to the head of the stack
 * @line_number: the current line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (*stack == NULL)/*if the stack is empty*/
	{/*also check if it is %u or %d*/
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		/*_free(*stack);*/
		/*clean_stack(stack);*/
		exit(EXIT_FAILURE);
	}
	top = *stack;
	*stack = (*stack)->next;

		if (*stack != NULL)/*if the stack is not empty*/
			(*stack)->prev = NULL;
	free(top);
}
