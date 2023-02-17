#include "monty.h"

/**
 * _push - push element to list
 * @stack: Double linked list
 * @line_number: File line execution
 */
void _push(stack_t **stack, unsigned int line_number)
{
  stack_t *tmp = NULL, *tmp2 = *stack;
  char *n;

	n = strtok(NULL, " \r\t\n");
  if (n == NULL || !isnumber(n))
  {
    fprintf(stderr, "L%u: usage: push integer\n", line_number);
    free_var(&var);
		exit(EXIT_FAILURE);
  }
  tmp = malloc(sizeof(stack_t));
  if (!tmp)
  {
    fprintf(stderr, "Error: malloc failed\n");
  	free_var(&var);
		exit(EXIT_FAILURE);
  }
  tmp->n = atoi(n);
  if (var.MODE == 0 || !*stack)
  {
    tmp->next = *stack;
    tmp->prev = NULL;
    if (*stack)
      (*stack)->prev = tmp;
    *stack = tmp;
  }
  else
  {
    while (tmp2->next)
      tmp2 = tmp2->next;
    tmp2->next = tmp;
    tmp->prev = tmp2;
    tmp->next = NULL;
  }
}

/**
 * _pall - push element to list
 * @stack: Double linked list
 * @line_number: File line execution
 */
void _pall(stack_t **stack, unsigned int line_number)
{
  stack_t* tmp = *stack;
  if (!tmp)
    return;
  while (tmp)
  {
    printf("%d\n", tmp->n);
    tmp = tmp->next;
  }
  (void) line_number;
}

/**
 * _pint - push element to list
 * @stack: Double linked list
 * @line_number: File line execution
 */
void _pint(stack_t **stack, unsigned int line_number)
{
  stack_t* tmp = *stack;
  if (!tmp)
  {
    fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
    free_var(&var);
    exit(EXIT_FAILURE);
  }
  printf("%d\n", tmp->n);
}

/**
 * _pop - push element to list
 * @stack: Double linked list
 * @line_number: File line execution
 */
void _pop(stack_t **stack, unsigned int line_number)
{
  stack_t* tmp = *stack;
  if (!tmp)
  {
    fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
    free_var(&var);
    exit(EXIT_FAILURE);
  }
  *stack = tmp->next;
  if (tmp->next)
    (*stack)->prev = NULL;
  free (tmp);
}

/**
 * _swap - push element to list
 * @stack: Double linked list
 * @line_number: File line execution
 */
void _swap(stack_t **stack, unsigned int line_number)
{
  (void) stack;
  (void) line_number;
}