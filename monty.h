#ifndef _MONTY_H
#define _MONTY_H

#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

/**
 ** struct stack_s - doubly linked list representation of a stack (or queue)
 ** @n: integer
 ** @prev: points to the previous element of the stack (or queue)
 ** @next: points to the next element of the stack (or queue)
 **
 ** Description: doubly linked list node structure
 ** for stack, queues, LIFO, FIFO
 **/
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 ** struct instruction_s - opcode and its function
 ** @opcode: the opcode
 ** @f: function to handle the opcode
 **
 ** Description: opcode and its function
 ** for stack, queues, LIFO, FIFO
 **/
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * struct globs - Structure of all globals
 * @TOS1: Value at top of stack
 * @TOS2: Value under top of stack
 * @arg: Argument to the opcode command
 * @top: Pointer to Node at the top
 * @bottom: Pointer to bottom of the stack
 * @stack: Pointer to the stack
 * @all_lines: All read lines
 *
 * Description: Structure of all global variables
 */

typedef struct globs
{
	int TOS1;
	int TOS2;
	char **arg;
	stack_t *top;
	stack_t *bottom;
	stack_t *stack;
} globs_t;


extern globs_t glob;


void opcode_pint(stack_t **stack, unsigned int line_number);
void push_op(stack_t **stack, unsigned int line_number);
void pop_op(stack_t **stack, unsigned int line_number);
void pall_op(stack_t **stack, unsigned int line_number);
void opcode_pint(stack_t **stack, unsigned int line_number);


void freeStringArray(char **array);
void free_stack_nodes(stack_t **stack);
void free_all_data(void);

stack_t *add_stack_node(stack_t **stack, const int value);
stack_t *stack_operation_delete(stack_t **head);

#endif /*_MONTY_H*/
