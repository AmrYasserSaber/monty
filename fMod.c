#include "main.h"
/**
 * fMod - computes
 * @our_head: stack our_head
 * @counter: line_number
 * Return: None
*/

void fMod(stack_t **our_head, unsigned int counter)
{
	stack_t *h;
	int len = 0, aux;

	h = *our_head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		freeAStack(*our_head);
		exit(EXIT_FAILURE);
	}

	h = *our_head;

	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		freeAStack(*our_head);
		exit(EXIT_FAILURE);
	}
	aux = h->next->n % h->n;
	h->next->n = aux;

	*our_head = h->next;
	free(h);

}
