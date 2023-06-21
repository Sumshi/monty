#include "monty.h"
/*0 for stack, 1 for queue */
int data_format = 0;
/**
 * stack - sets the format of the data to a stack (LIFO)
 * @stack: double pointer to the head of stack
 * @line_number: the line number
 */
void stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	data_format = 0;
}
/**
 * queue - sets the format of the data to a queue (FIFO)
 * @stack: double pointer to the head of stack
 * @line_number: the line number
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	data_format = 1;
}
/**
 * push_t - pushes an element to the stack or queue based on the data format
 * @stack: double pointer to the head of stack or queue
 * @line_number: the line number
 * @value: the value to push
 */
void push_t(stack_t **stack, unsigned int line_number, int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	(void)line_number;

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	if (data_format == 0)/* Stack (LIFO) behavior */
	{
		new_node->next = *stack;
		if (*stack)
			(*stack)->prev = new_node;
		*stack = new_node;
	}
	else if (data_format == 1)
	{/* Queue (FIFO) behavior */
		stack_t *current = *stack;

		if (!current)
		{
			new_node->next = NULL;
			*stack = new_node;
		}
		else
		{
			while (current->next)
				current = current->next;
			current->next = new_node;
			new_node->next = NULL;
			new_node->prev = current;
		}
	}
	else
	{
		fprintf(stderr, "Error: Invalid data format\n");
		exit(EXIT_FAILURE);
	}
}
