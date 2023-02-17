#include "monty.h"

/**
 * _pchar - push element to list
 * @stack: Double linked list
 * @line_number: File line execution
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
  int tmp = (*stack)->n;
  if (!*stack)
  {
    fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
     free_var(&var);
    exit(EXIT_FAILURE);
  }
  if (tmp < 0 || tmp > 127)
  {
    fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
    free_var(&var);
    exit(EXIT_FAILURE);
  }
  printf("%c\n", (*stack)->n);
}

/**
 * _pstr - push element to list
 * @stack: Double linked list
 * @line_number: File line execution
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
  stack_t *tmp = *stack;
  while (tmp)
  {
    if (!tmp->n || !iswascii(tmp->n))
      break;
    printf("%c", tmp->n);
    tmp = tmp->next;
  }
  printf("\n");
  (void) line_number;
}

/**
 * _rotl - push element to list
 * @stack: Double linked list
 * @line_number: File line execution
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
  (void)stack;
  (void)line_number;
}

/**
 * _rotr - push element to list
 * @stack: Double linked list
 * @line_number: File line execution
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
  (void)stack;
  (void)line_number;
}