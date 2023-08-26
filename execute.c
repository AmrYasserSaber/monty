#include "main.h"
/**
* execute - execute
* @our_head: head of the 
* @counter: line_counter
* @file: poiner to main.h file
* @content: line content
* Return: no return
*/

int execute(char *content, stack_t **our_head, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push",  f_push}, {"pall", f_pall}, {"pint", f_pint},
				{"pop",   f_pop},
				{"swap",  f_swap},
				{"add",   add_top_two},
				{"nop",   f_nop},
				{"sub",   f_sub},
				{"div",   fDiv},
				{"mul",   f_mul},
				{"mod",   fMod},
				{"pchar", f_pchar},
				{"pstr",  f_pstr},
				{"rotl",  f_rotl},
				{"rotr",  f_rotr},
				{"queue", f_queue},
				{"our_head", f_stack},
				{NULL, NULL}
				};

	unsigned int i = 0;
	char *op;


	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(our_head, counter);
			return (0);
		}
		i++;
	}

	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		freeAour_head(*our_head);
		exit(EXIT_FAILURE); }
	return (1);
}
