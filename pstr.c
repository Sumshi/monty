#include "monty.h"
/**
 * pstr - Prints the string starting at the top of the stack,
 *		   followed by a new line
 * @stack: The head of the stack
 * @line_number: Line number of the command in the bytecode file
 *
 * Return: Nothing
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void) line_number;

	while (current != NULL)/*stack not empty*/
	{
		if (current->n == 0 || current->n < 0 || current->n > 127)
			break;
		printf("%c", current->n);/*else part prints the char*/
		current = current->next;/*goes to the next node*/
	}
	/*if stack is empty print new  line*/
	printf("\n");
}
