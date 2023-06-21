#include "monty.h"
/**
 * rotl - rotates the stack to the top
 * @stack: double pointer to the head of stack
 * @line_number: the line number
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *current, *last;

	(void)line_number;/*unused variable*/

	/*checks if stack is empty or if it has less than 2 elements*/
	if (*stack == NULL || (*stack)->next == NULL)
		return;/*nothing to rotate*/

	current = *stack;/*points to top of stack*/
	last = *stack;/*points to top of stack*/

	while (last->next != NULL)
		last = last->next;/*last node of the stack*/

	*stack = current->next;/*points to the second element*/
	current->next->prev = NULL;
	current->next = NULL;
	last->next = current;
	current->prev = last;
}
