#include "monty.h"
/**
 * fSwap - adds the top two elements of the stack.
 * @pStack: stack head
 * @c: line_number
 * Return: no return
*/
void fSwap(stack_t **pStack, unsigned int c)
{
	stack_t *head;
	int len = 0, aux;

	head = *pStack;
	while (head)
	{
		head = head->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", c);
		fclose(bus.file);
		free(bus.content);
		freeAStack(*pStack);
		exit(EXIT_FAILURE);
	}
	head = *pStack;
	aux = head->n;
	head->n = head->next->n;
	head->next->n = aux;
}
