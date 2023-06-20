#include "monty.h"
/**
 * pall - prints all the values of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: the current line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;
	(void)line_number;/*unused parameter*/

	tmp = *stack;/*it is assinged to top/head of stack*/

	while (tmp != NULL)/*tmp traverses the stack till end*/
	{
		fprintf(stdout, "%d\n", tmp->n);
		tmp = tmp->next;
	}
}
