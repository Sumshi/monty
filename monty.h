#ifndef _MONTY_H_
#define _MONTY_H_
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include<stdarg.h>
/**
 * struct cmd_s - cmd
 * @fd: file descriptor
 * @line: line
 */
typedef struct cmd_s
{
	FILE *fd;
	char *line;
} cmd_t;
extern cmd_t cmd;
extern int value;
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

stack_t *queue_node(stack_t **stack, const int n);
stack_t *add_node(stack_t **stack, const int n);
size_t print_stack(const stack_t *stack);
void free_stack(stack_t *stack);

void execute(char *argv);
int get_opc(stack_t **stack, char *arg, char *val, int line_number);

/*stack operations*/
stack_t *createNode(int n);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void divide(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);

/*memory*/
void _free(stack_t *stack);

/*error handlers*/
void usage_error(void);
void open_error(char *file);
void push_error(FILE *fd, char *line, stack_t *stack, int line_number);
void instr_error(FILE *fd, char *line, stack_t *stack, char *val, int line_number);
int _isdigit(char *c);

#endif
