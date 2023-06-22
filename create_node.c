#include "monty.h"
int value;/*holds the value to be pushed to stack*/
/**
 * createNode - creates a new node
 * @n: the value of the node
 * Return: new node
 */

stack_t *createNode(int n)
{
	stack_t *new = NULL;/*new node is created*/

	new = malloc(sizeof(stack_t));/*allocates memory to the new node*/
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;/*sets the value of new node*/
	new->next = NULL;
	new->prev = NULL;

	return (new);/*new node is returned*/
}
