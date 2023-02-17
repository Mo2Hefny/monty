#ifndef _MONTY_
#define _MONTY_

#define  _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <ctype.h>

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

/**
 * struct glob_var - golbal variables
 * @file: file name
 * @buff: Getline buffer
 * @buff_size: Getline counter
 * @dict: instruction dictionary
 * @head: pointer to list
 * @line_number: Stores file current line
 * @MODE: Program configuration stack or queue
 */
typedef struct glob_var
{
	FILE *file;
	char *buff;
	size_t buff_size;
	instruction_t *dict;
	stack_t *head;
	unsigned int line_number;
	int MODE;
} gvar;

extern gvar var;

void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **doubly, unsigned int cline);
void _pop(stack_t **doubly, unsigned int cline);
void _swap(stack_t **doubly, unsigned int cline);
void _add(stack_t **doubly, unsigned int cline);
void _nop(stack_t **doubly, unsigned int cline);
void _sub(stack_t **doubly, unsigned int cline);
void _div(stack_t **doubly, unsigned int cline);
void _mul(stack_t **doubly, unsigned int cline);
void _mod(stack_t **doubly, unsigned int cline);
void _pchar(stack_t **doubly, unsigned int cline);
void _pstr(stack_t **doubly, unsigned int cline);
void _rotl(stack_t **doubly, unsigned int cline);
void _rotr(stack_t **doubly, unsigned int cline);
void _queue(stack_t **doubly, unsigned int cline);
void _stack(stack_t **doubly, unsigned int cline);

/* initializing */
int init_var(gvar*);
instruction_t* init_instruction(void);
void free_var(gvar*);
int getFunction(gvar* var_ptr, char* tokens);
int isnumber(char*);

#endif