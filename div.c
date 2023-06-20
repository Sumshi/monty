#include "monty.h"
/**
 * divide - divides the second top element of the stack by the top element
 * @stack: double pointer to the head of the stack
 * @line_number: the current line number
 */
void divide(stack_t **stack, unsigned int line_number)
{
        stack_t *temp;

/*checks if stack is empty r if it contains less than 2 elements*/
        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
                clean_stack(stack);
                exit(EXIT_FAILURE);
        }

        if ((*stack)->n == 0)
        {
                fprintf(stderr, "L%u: division by zero\n", line_number);
                clean_stack(stack);
                exit(EXIT_FAILURE);
        }

        temp = (*stack)->next;
        temp->n /= (*stack)->n;

        pop(stack, line_number);
}
