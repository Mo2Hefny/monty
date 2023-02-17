#include "monty.h"

gvar var;

/**
 * main - LIFO, FIFO program
 * @ac: number of arguments
 * @av: arguments string array
 * Return: 0 on success
 */

int main(int ac, char **av)
{
  if (ac != 2)
  {
    fprintf(stderr, "USAGE: monty file\n");
    return (EXIT_FAILURE);
  }
  if (init_var(&var) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  var.file = fopen(av[1], "r");
  if (var.file == NULL)
  {
    fprintf(stderr, "Error: Can't open file %s\n", av[1]);
    free_var(&var);
    return (EXIT_FAILURE);
  }

  char *tokens;
  while (getline(&var.buff, &var.tmp, var.file) != EOF)
  {
    tokens = strtok(var.buff, " \r\t\n");
    if (tokens != NULL)
    {
      if (getFunction(&var, tokens) == EXIT_FAILURE)
      {
        free_var(&var);
        return (EXIT_FAILURE);
      }
    }
    var.line_number++;
  }
  free_var(&var);
  return 0;
}
