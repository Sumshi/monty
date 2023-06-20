#include "monty.h"
/**
 * pchar -  prints the ASCII character represented by the value at the top
 * @stack: double pointer to the head of stack
 * @line_number: the line number
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)/*checks if stack is empty*/
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n >= 0 && (*stack)->n <= 127)/*checks if value is thin ascii*/
		printf("%c\n", (*stack)->n);
	else/*if it is not within valid ascii range*/
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		/*_free(*stack);*/
		exit(EXIT_FAILURE);
	}

}
