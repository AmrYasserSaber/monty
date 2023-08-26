#include "monty.h"
/**
  *fSub- subtracts the top element from the second top element
  *@pStack: stack pStack
  *@c: line_number
  *Return: no return
 */
void fSub(stack_t **pStack, unsigned int c)
{
	stack_t *aux;
	int sus, nodes;

	aux = *pStack;
	for (nodes = 0; aux != NULL; nodes++)
		aux = aux->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", c);
		fclose(bus.file);
		free(bus.content);
		freeAStack(*pStack);
		exit(EXIT_FAILURE);
	}
	aux = *pStack;
	sus = aux->next->n - aux->n;
	aux->next->n = sus;
	*pStack = aux->next;
	free(aux);
}
