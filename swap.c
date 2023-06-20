#include "monty.h"
/**
 * swap - swaps the top two elements of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: the current line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	int temp;

/*check if stack is empty or if it contains less than 2 elements*/
	if (top == NULL || top->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else/*if stack is not empty*/
	{
		temp = top->n;/*holds the first element*/
		top->n = top->next->n;
		top->next->n = temp;
/*this is like temp = a, a = b, b = a*/
	}
}
