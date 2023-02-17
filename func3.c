#include "monty.h"

/**
 * _pchar - push element to list
 * @stack: Double linked list
 * @line_number: File line execution
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
  int tmp;
  if (!*stack)
  {
    fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
    free_var(&var);
    exit(EXIT_FAILURE);
  }
  tmp = (*stack)->n;
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
    if (!tmp->n || tmp->n < 0 || tmp->n > 127)
      break;
    printf("%c", tmp->n);
    tmp = tmp->next;
  }
  printf("\n");
  (void)line_number;
}

/**
 * _rotl - push element to list
 * @stack: Double linked list
 * @line_number: File line execution
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
  stack_t *tmp = *stack, *tmp2;
  (void)line_number;

  if (!tmp || !tmp->next)
    return;

  tmp2 = (*stack)->next;
  tmp2->prev = NULL;

  while (tmp->next)
    tmp = tmp->next;

  tmp->next = *stack;
  (*stack)->prev = tmp;
  (*stack)->next = NULL;
  *stack = tmp2;
}

/**
 * _rotr - push element to list
 * @stack: Double linked list
 * @line_number: File line execution
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
  stack_t *tmp = *stack, *tmp2;
  (void)line_number;

  if (!tmp || !tmp->next)
    return;

  while (tmp->next->next)
    tmp = tmp->next;
  tmp2 = tmp->next;
  tmp->next = NULL;

  (*stack)->prev = tmp2;
  tmp2->prev = NULL;
  tmp2->next = (*stack);
  *stack = tmp2;
}