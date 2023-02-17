#include "monty.h"

/**
 * init_var - initialize global variables.
 * @var_ptr: global variables
 * Return: 0 on success, 1 otherwise.
*/
int init_var(gvar *var_ptr)
{
    var_ptr->file = NULL;
    var_ptr->buff = NULL;
    var_ptr->head = NULL;
    var_ptr->line_number = 1;
    var_ptr->buff_size = 0;
    var_ptr->MODE = 0;
    var_ptr->dict = init_instruction();
    if (var_ptr->dict == NULL)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

/**
 * init_instruction - initialize functions in dictionary
 * Return: dictionary pointer;
*/

instruction_t* init_instruction(void)
{
    instruction_t *func = malloc(sizeof(instruction_t) * 18);

    if (func == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
	  	  return (NULL);
    }

    func[0].opcode = "push", func[0].f = _push;
    func[1].opcode = "pall", func[1].f = _pall;
    func[2].opcode = "pint", func[2].f = _pint;
    func[3].opcode = "pop", func[3].f = _pop;
    func[4].opcode = "swap", func[4].f = _swap;
    func[5].opcode = "add", func[5].f = _add;
    func[6].opcode = "nop", func[6].f = NULL;
    func[7].opcode = "sub", func[7].f = _sub;
    func[8].opcode = "div", func[8].f = _div;
    func[9].opcode = "mul", func[9].f = _mul;
    func[10].opcode = "mod", func[10].f = _mod;
    func[11].opcode = "pchar", func[11].f = _pchar;
    func[12].opcode = "pstr", func[12].f = _pstr;
    func[13].opcode = "rotl", func[13].f = _rotl;
    func[14].opcode = "rotr", func[14].f = _rotr;
    func[15].opcode = "queue", func[15].f = _queue;
    func[16].opcode = "stack", func[16].f = _stack;
    func[17].opcode = NULL, func[17].f = NULL;

    return (func);
}

/**
 * free_var - free global variables
 * @var_ptr: global variables.
*/
void free_var(gvar *var_ptr)
{
    if (var_ptr->buff != NULL)
		  free(var_ptr->buff);
	  if (var_ptr->file != NULL)
		  fclose(var_ptr->file);
	  free(var_ptr->dict);
	  if (var_ptr->head != NULL)
	  {
		    while (var_ptr->head->next != NULL)
		    {
			      var_ptr->head = var_ptr->head->next;
			      free(var_ptr->head->prev);
		    }
		    free(var_ptr->head);
	  }
}

/**
 *  getFunction - calls the needed function from the dictionary
 * @var_ptr: global variables.
 * @tokens: command.
 * Return: 0 on succes, 1 otherwise.
*/
int getFunction(gvar* var_ptr, char* tokens)
{
  int i;
  for (i = 0; var_ptr->dict[i].opcode; i++)
  {
    if (strcmp(var_ptr->dict[i].opcode, tokens) == 0)
    {
      if (var_ptr->dict[i].f == NULL)
        return (EXIT_SUCCESS);
      var_ptr->dict[i].f(&(var_ptr->head), var_ptr->line_number);
      return (EXIT_SUCCESS);
    }
  }
  if (strlen(tokens) != 0 && tokens[0] != '#')
  {
    fprintf(stderr, "L%u: unknown instruction %s\n", var_ptr->line_number, tokens);
    return (EXIT_FAILURE);
  }
  return (EXIT_SUCCESS);
}

/**
 * isnumber - checks if the string is a number.
 * @str: passed string.
 * Return: 1 if number, 0 otherwise.
*/
int isnumber(char* str)
{
  int len, i;
  len = strlen(str);
  for (i = 0; i < len; i++)
  {
    if (!i && str[i] == '-')
      continue;
    if (str[i] < '0' || str[i] > '9')
      return 0;
  }
  return 1;
}