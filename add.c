#include "monty.h"
/**
 * add - adds the top two elements of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: the current line number
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;/*points to top element of stack*/
	int sum;

/*checks if stack is empty or has less than 2 elements*/
	if (top == NULL || top->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = top->n + top->next->n;/*adds top and second top element*/
	top->next->n = sum;

	*stack = top->next;/*updates stack to point to second top element*/
	free(top);/*frees top which was removed*/
}
