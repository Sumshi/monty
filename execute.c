#include "monty.h"

cmd_t cmd = {NULL, NULL};

/**
 *execute - reads the file and executes the monty byte
 *@argv: argument vector
 */

void execute(char *argv)
{
	int line = 0, r = 0;
	size_t bufsize = 0;
	char *token = NULL, *val = NULL;
	stack_t *stack = NULL;

	cmd.fd = fopen(argv, "r");/*opens a file in read mode*/
	if (cmd.fd != NULL)
	{
		while (getline(&cmd.line, &bufsize, cmd.fd) != -1)
		{
			line++;
			token = strtok(cmd.line, " \n\t\r");/*stores first token*/
			if (token == NULL)
			{
				free(token);
				continue;
			}
			else if (*token == '#')
				continue;
			val = strtok(NULL, " \n\t\r");/*stores second token*/
			r = get_opc(&stack, token, val, line);
			if (r == 1) /*return 1 when the value is not digit */
				push_error(cmd.fd, cmd.line, stack, line); /** print push error*/
			else if (r == -1) /*return -1 if not the instruction */
				instr_error(cmd.fd, cmd.line, stack, token, line);
			/*print instruction error*/
		}
		free(cmd.line);
		_free(stack);
		fclose(cmd.fd);
	}
	else/*if the file cannot be opened*/
	{

		open_error(argv);

	}
}
