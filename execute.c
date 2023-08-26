#include "monty.h"
/**
* execute - execute
* @stack: head of the stack 
* @counter: line_counter
* @file: poiner to monty.h file
* @content: line content
* Return: no return
*/

int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
			{"push",  fPush}, {"pall", f_pall}, {"pint", fPint},
			{"pop",   fPop},
			{"swap",  fSwap},
			{"add",   add_top_two},
			{"nop",   f_nop},
			{"sub",   fSub},
			{"div",   fDiv},
			{"mul",   f_mul},
			{"mod",   fMod},
			{"pchar", f_pchar},
			{"pstr",  fPstr},
			{"rotl",  fRotl},
			{"rotr",  fRotr},
			{"queue", fQueue},
			{"stack", fStack},
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
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}

	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		freeAStack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
