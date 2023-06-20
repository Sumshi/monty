#include "monty.h"
/**
 * pint - prints the value at the top of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: the current line number
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || stack == NULL)/*means that stack is empty*/
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		clean_stack(stack);
		exit(EXIT_FAILURE);
	}
	else/*if the stack is not empty*/
		fprintf(stdout, "%d\n", (*stack)->n);/*prints value at the top*/

}
/**
 * clean_stack - Free all and close files
 * @stack: Stack
 */

void clean_stack(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (tmp != NULL)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
	fclose(cmd.fd);
	free(cmd.line);
}
