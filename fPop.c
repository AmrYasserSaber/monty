#include "monty.h"
/**
 * fPop - prints the top
 * @pStack: stack pStack
 * @c: line_number
 * Return: no return
*/
void fPop(stack_t **pStack, unsigned int c)
{
	stack_t *h;

	if (*pStack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", c);
		fclose(bus.file);
		free(bus.content);
		freeAStack(*pStack);
		exit(EXIT_FAILURE);
	}
	h = *pStack;
	*pStack = h->next;
	free(h);
}
