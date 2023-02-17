#include "monty.h"

/**
 * _add - get the sum of the top 2 elements.
 * @stack: Double linked list
 * @line_number: File line execution
 */
void _add(stack_t **stack, unsigned int line_number)
{
  if (!*stack || !(*stack)->next)
  {
    fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
    free_var(&var);
    exit(EXIT_FAILURE);
  }
  (*stack)->next->n += (*stack)->n;
  _pop(stack, line_number);
}

/**
 * _sub - get the difference between the top 2 elements.
 * @stack: Double linked list
 * @line_number: File line execution
 */
void _sub(stack_t **stack, unsigned int line_number)
{
  if (!*stack || !(*stack)->next)
  {
    fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
    free_var(&var);
    exit(EXIT_FAILURE);
  }
  (*stack)->next->n -= (*stack)->n;
  _pop(stack, line_number);
}

/**
 * _div - get the division of the top 2 elements.
 * @stack: Double linked list
 * @line_number: File line execution
 */
void _div(stack_t **stack, unsigned int line_number)
{
  if (!*stack || !(*stack)->next)
  {
    fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
    free_var(&var);
    exit(EXIT_FAILURE);
  }
  if (!(*stack)->n)
  {
    fprintf(stderr, "L%u: division by zero\n", line_number);
    free_var(&var);
    exit(EXIT_FAILURE);
  }
  (*stack)->next->n /= (*stack)->n;
  _pop(stack, line_number);
}

/**
 * _mul - get the multiplication of the top 2 elements.
 * @stack: Double linked list
 * @line_number: File line execution
 */
void _mul(stack_t **stack, unsigned int line_number)
{
  if (!*stack || !(*stack)->next)
  {
    fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
    free_var(&var);
    exit(EXIT_FAILURE);
  }
  (*stack)->next->n *= (*stack)->n;
  _pop(stack, line_number);
}

/**
 * _mod - get the modulus of the top 2 elements.
 * @stack: Double linked list
 * @line_number: File line execution
 */
void _mod(stack_t **stack, unsigned int line_number)
{
  if (!*stack || !(*stack)->next)
  {
    fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
    free_var(&var);
    exit(EXIT_FAILURE);
  }
  if (!(*stack)->n)
  {
    fprintf(stderr, "L%u: division by zero\n", line_number);
    free_var(&var);
    exit(EXIT_FAILURE);
  }
  (*stack)->next->n %= (*stack)->n;
  _pop(stack, line_number);
}