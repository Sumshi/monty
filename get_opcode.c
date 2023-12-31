#include "monty.h"
/**
 * get_opc - retrieves the corresponding opcode function based on the given cmd
 * @stack: pointer to the stack or queue
 * @arg: the command string
 * @val: the value string
 * @line_number: the line number in the program
 * Return: 0 on success || 1 if not a digit || -1 on error
 */
int get_opc(stack_t **stack, char *arg, char *val, int line_number)
{
	int i = 0;/*to iterate through op array*/

	instruction_t op[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"nop", nop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", divide},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"queue", f_queue}, {"stack", f_stack},
		{NULL, NULL}
	};
	while (op[i].opcode)
	{
		if (strcmp(arg, op[i].opcode) == 0)
		{
			if (strcmp(arg, "push") == 0)
			{
				if (_isdigit(val) == 1)
					value = atoi(val);
				else/*indicates error*/
					return (1);/** if not digit*/
			}
			op[i].f(stack, (unsigned int)line_number);
			break;
		}
		i++;
	}
	if (!op[i].opcode)/*if opcode was not found*/
		return (-1);/*indicates error*/
	return (0);
}
