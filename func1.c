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
  if (n == NULL || !isdigit(n))
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
  
}

/**
 * _pint - push element to list
 * @stack: Double linked list
 * @line_number: File line execution
 */
void _pint(stack_t **stack, unsigned int line_number)
{

}

/**
 * _pop - push element to list
 * @stack: Double linked list
 * @line_number: File line execution
 */
void _pop(stack_t **stack, unsigned int line_number)
{

}

/**
 * _swap - push element to list
 * @stack: Double linked list
 * @line_number: File line execution
 */
void _swap(stack_t **stack, unsigned int line_number)
{

}