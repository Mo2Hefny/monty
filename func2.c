#include "monty.h"

/**
 * _add - push element to list
 * @stack: Double linked list
 * @line_number: File line execution
 */
void _add(stack_t **stack, unsigned int line_number)
{
  stack_t *tmp = *stack, *tmp2;
  if (!tmp || !(tmp->next))
  {
    fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
    free_var(&var);
    exit(EXIT_FAILURE);
  }
  tmp->n = (*stack)->n + (*stack)->next->n;
  tmp2 = (*stack)->next->next;
  free(tmp->next);
  tmp->next = tmp2;
  tmp2->prev = tmp;
}

/**
 * _nop - push element to list
 * @stack: Double linked list
 * @line_number: File line execution
 */
void _nop(stack_t **stack, unsigned int line_number)
{
  (void)stack;
  (void)line_number;
}

/**
 * _sub - push element to list
 * @stack: Double linked list
 * @line_number: File line execution
 */
void _sub(stack_t **stack, unsigned int line_number)
{
  (void)stack;
  (void)line_number;
}

/**
 * _div - push element to list
 * @stack: Double linked list
 * @line_number: File line execution
 */
void _div(stack_t **stack, unsigned int line_number)
{
  (void)stack;
  (void)line_number;
}

/**
 * _mul - push element to list
 * @stack: Double linked list
 * @line_number: File line execution
 */
void _mul(stack_t **stack, unsigned int line_number)
{
  (void)stack;
  (void)line_number;
}