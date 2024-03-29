#include "monty.h"

/**
 * _queue - switch to queue mode
 * @stack: Double linked list
 * @line_number: File line execution
 */
void _queue(stack_t **stack, unsigned int line_number)
{
  (void) stack;
  (void) line_number;
  var.MODE = 1;
}

/**
 * _stack - swtich to stack mode
 * @stack: Double linked list
 * @line_number: File line execution
 */
void _stack(stack_t **stack, unsigned int line_number)
{
  (void) stack;
  (void) line_number;
  var.MODE = 0;
}