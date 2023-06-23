#include "monty.h"
/**
 * f_stack - sets the format of the data to a stack (LIFO).
 * @stack: double pointer to the beginning of the stack/queue
 * @line_number: line number of current opcode
 */
void f_stack(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
	input.flag = 0;
}
/**
 * f_queue - sets the format of the data to a queue (FIFO).
 * @stack: double pointer to the beginning of the stack/queue
 * @line_number: line number of current opcode
 */
void f_queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	input.flag = 1;
}
