#include "monty.h"
/**
 * fPush - add node to the stack
 * @pStack: stack pStack
 * @c: line_number
 * Return: no return
*/
void fPush(stack_t **pStack, unsigned int c)
{
	int i, j = 0, f = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			j++;
		for (; bus.arg[j] != '\0'; j++)
		{
			if (bus.arg[j] > 57 || bus.arg[j] < 48)
				f = 1; }
		if (f == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", c);
			fclose(bus.file);
			free(bus.content);
			freeAStack(*pStack);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", c);
		fclose(bus.file);
		free(bus.content);
		freeAStack(*pStack);
		exit(EXIT_FAILURE); }
	i = atoi(bus.arg);
	if (bus.lifi == 0)
		nodeadd(pStack, i);
	else
		addQueue(pStack, i);
}
